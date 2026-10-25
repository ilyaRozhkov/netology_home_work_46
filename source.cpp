#include <fstream>
#include <string>
#include <utility>

class TextPrintable
{
public:
    virtual ~TextPrintable() = default;
    virtual std::string printAsText() const = 0;
};

class HTMLPrintable
{
public:
    virtual ~HTMLPrintable() = default;
    virtual std::string printAsHTML() const = 0;
};

class JSONPrintable
{
public:
    virtual ~JSONPrintable() = default;
    virtual std::string printAsJSON() const = 0;
};

class Data
{
public:
    explicit Data(std::string data)
        : data_(std::move(data)) {}

    virtual ~Data() = default;

protected:
    std::string data_;
};

// Каждый потомок отвечает за свой формат.
class TextData final : public Data, public TextPrintable
{
public:
    using Data::Data;

    std::string printAsText() const override
    {
        return data_;
    }
};

class HTMLData final : public Data, public HTMLPrintable
{
public:
    using Data::Data;

    std::string printAsHTML() const override
    {
        return "<html>" + data_ + "<html/>";
    }
};

class JSONData final : public Data, public JSONPrintable
{
public:
    using Data::Data;

    std::string printAsJSON() const override
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }
};

void saveTo(std::ofstream& file, const std::string& formattedData)
{
    file << formattedData;
}

void saveToAsText(std::ofstream& file, const TextPrintable& printable)
{
    saveTo(file, printable.printAsText());
}

void saveToAsHTML(std::ofstream& file, const HTMLPrintable& printable)
{
    saveTo(file, printable.printAsHTML());
}

void saveToAsJSON(std::ofstream& file, const JSONPrintable& printable)
{
    saveTo(file, printable.printAsJSON());
}
