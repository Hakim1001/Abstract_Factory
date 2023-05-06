#ifndef PRINTOPERATORCSHARP_H
#define PRINTOPERATORCSHARP_H
#include <printoperator.h>

class PrintOperatorUnitCsharp : public PrintOperatorUnit
{
public:
    explicit PrintOperatorUnitCsharp(const std::string &text)
        : PrintOperatorUnit(text)
    {

    }

    std::string compile(unsigned int level = 0) const
    {
        return generateShift(level) + "Console.WriteLine(\"" + m_name + "\");\n";
    }
};

#endif // PRINTOPERATORCSHARP_H
