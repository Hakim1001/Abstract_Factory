#ifndef PRINTOPERATORJAVA_H
#define PRINTOPERATORJAVA_H
#include <printoperator.h>

class PrintOperatorUnitJava : public PrintOperatorUnit
{
public:
    explicit PrintOperatorUnitJava(const std::string &text)
        : PrintOperatorUnit(text)
    {

    }

    std::string compile(unsigned int level = 0) const
    {
        return  generateShift(level) + "System.out.println(\"" + m_name + "\");\n";
    }
};
#endif // PRINTOPERATORJAVA_H
