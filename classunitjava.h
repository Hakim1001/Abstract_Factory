#ifndef CLASSUNITJAVA_H
#define CLASSUNITJAVA_H
#include <classunit.h>
class ClassUnitJava : public ClassUnit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

public:
    explicit ClassUnitJava(const std::string &name)
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
        std::string result = "class " + m_name + " {\n";

        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); i++)
        {
            for (const auto &f : m_fields[i])
            {
                result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level + 1);
            }
        }

        result += generateShift(level) + "};\n";

        return result;
    }
};

// данный язык поддерживает только три модификатора доступа
const std::vector<std::string> ClassUnitJava::ACCESS_MODIFIERS = { "public", "protected", "private" };

#endif // CLASSUNITJAVA_H
