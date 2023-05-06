#ifndef CLASSUNITCSHARP_H
#define CLASSUNITCSHARP_H
#include <classunit.h>

class ClassUnitCsharp : public ClassUnit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

public:
    explicit ClassUnitCsharp(const std::string &name)
        : ClassUnit(name, ACCESS_MODIFIERS.size())
    {

    }

    void Add(const std::shared_ptr<Unit> &unit, Flags flags = 0)
    {
        if (unit == nullptr)
        {
            throw std::runtime_error("The unit is nullptr.");
        }

        size_t access_modifier = PRIVATE;

        if (flags < m_fields.size())
        {
            access_modifier = flags;
        }

        m_fields[access_modifier].push_back(unit);
    }

    std::string compile(unsigned int level = 0) const
    {
        std::string result = "class " + m_name + " {\n"; // класс также может быть подклассом с модификатором доступа, по этому за отступ первой строки отвечает вышестоящий обьект

        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); i++)
        {
            // так как в данном языке тело класса не делится на поля с модификаторами доступа, они являются частью определения метода
            // по этой причине за отступ первой строки элемента класса отвечает сам класс, и в начало объявления метода дописывается модификатор доступа
            for (const auto &f : m_fields[i])
            {
                result +=  generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level + 1);
            }
        }

        result +=  generateShift(level) + "};\n";

        return result;
    }
};

// в данном языке конструкций больше
const std::vector<std::string> ClassUnitCsharp::ACCESS_MODIFIERS = { "public", "protected", "private", "internal", "protected internal", "private protected" };

#endif // CLASSUNITCSHARP_H
