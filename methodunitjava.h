#ifndef METHODUNITJAVA_H
#define METHODUNITJAVA_H
#include <methodunit.h>
class MethodUnitJava : public MethodUnit
{
public:
    MethodUnitJava(const std::string &name, const std::string &returnType, Flags flags)
        : MethodUnit(name, returnType, flags) // проверка допустимых флагов осуществляется в функции Compile
    {

    }

    std::string compile(unsigned int level = 0) const
    {
        std::string result = "";

        if (m_flags & STATIC)
        {
            result += "static ";
        }
        // virtual в данном языке отсутствует

        if (m_flags & FINAL) // но зато добавляется новый файл - final
        {
            result += "final ";
        }

        result +=  m_returnType + " ";
        result += m_name + "() {\n"; // const так же не поддерживается

        for (const auto &b : m_body)
        {
            result += b->compile(level + 1);
        }

        result += generateShift(level) + "}\n";

        return result;
    }
};

#endif // METHODUNITJAVA_H
