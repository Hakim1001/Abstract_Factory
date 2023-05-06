#ifndef METHODUNITCSHARP_H
#define METHODUNITCSHARP_H
#include <methodunit.h>

class MethodUnitCsharp : public MethodUnit
{
public:
    MethodUnitCsharp(const std::string &name, const std::string &returnType, Flags flags)
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
        else if (m_flags & VIRTUAL)
        {
            result += "virtual ";
        }
        if(m_flags & SEALED||m_flags & FINAL)
       {
            result += "sealed ";
       }
        result += m_returnType + " ";
        result += m_name + "() {\n";

        for (const auto &b : m_body)
        {
            result += b->compile(level + 1);
        }

        result += generateShift(level) + "}\n";

        return result;
    }
};

#endif // METHODUNITCSHARP_H
