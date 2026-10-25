Задание 1:

подстановки Барбары Лисков - Data наследуется от Printable, но не может корректно использоваться там, где ожидается Printable.
if (format_ != Format::kHTML) {
            throw std::runtime_error("Invalid format!");
        }

открытости/закрытости -Код не закрыт для модификации. Хороший вариант — сделать так, чтобы новый формат добавлялся новым классом, реализующим общий интерфейс, без изменения saveTo.
    switch (format)
    {
    case Data::Format::kText:
        file << printable.printAsText();
        break;
    case Data::Format::kJSON:
        file << printable.printAsJSON();
        break;
    case Data::Format::kHTML:
        file << printable.printAsHTML();
        break;
    }

разделения интерфейса - Data вынужден реализовывать все три метода, хотя корректно поддерживает только один.

    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;

Задание 2 - source.cpp
