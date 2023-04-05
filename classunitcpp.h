#ifndef CLASSUNITCPP_H
#define CLASSUNITCPP_H
#include <classunit.h>
#include <unit.h>
class ClassUnitCpp: public ClassUnit
{

public:
    static const std::vector<std::string> ACCESS_MODIFIERS;                         // набор модификаторов доступа, поддерижваемых данным языком

public:
    explicit ClassUnitCpp(const std::string &name)
        : ClassUnit(name)                                                           // передача базовому классу количества поддерживаемых модификаторов доступа
    {

    }

    void Add(std::shared_ptr<Unit> &unit, Flags flags)
    {
        if (unit == nullptr)
        {
            throw std::runtime_error("The unit is nullptr.");
        }

        size_t access_modifier = PRIVATE;

        if (flags < m_fields.size())                                               // отсеивание модификаторов доступа, не поддерживающихся данным языком
        {
            access_modifier = flags;
        }

        m_fields[access_modifier].push_back(unit); // добавление конструкции в поле с соотвествующим модификатором доступа
    }
    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift(level) + "class " + m_name + " {\n"; // имя класса

        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); i++) // перебор набора полей модификаторов доступа
        {
            if (m_fields[i].empty()) // если с данным модификатором доступа полей нет, не указываем его
            {
                continue;
            }

            result += generateShift(level) + ACCESS_MODIFIERS[i] + ":\n"; // указание блока модификатора доступа

            for (const auto &f : m_fields[i]) // перебор всех полей модификатора доступа
            {
                result += f->compile(level + 1); // вывод языковых конструкций, с учетом дополнительного уровня вложенности (отступа)
            }

            result += "\n";
        }

        result += generateShift(level) + "};\n"; // завершение генерации кода класса

        return result;

    }
};
const std::vector<std::string> ClassUnitCpp::ACCESS_MODIFIERS = { "public", "protected", "private" }; //поддерживаемые языком модификаторов доступа


#endif // CLASSUNITCPP_H
