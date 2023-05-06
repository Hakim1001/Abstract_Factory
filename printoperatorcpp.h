#ifndef PRINTOPERATORCPP_H
#define PRINTOPERATORCPP_H
#include <printoperator.h>
//#include <unit.h>


class PrintOperatorUnitcpp : public  PrintOperatorUnit
{

public:

    explicit PrintOperatorUnitcpp(const std::string &text):  PrintOperatorUnit(text)
    {
    }

    std::string compile(unsigned int level = 0) const
    {
        // добавление отступов и необходимых конструкций для потокового вывода текста
        return generateShift(level) + "std::cout << \"" + m_name + "\" << std::endl;\n";
    }



};

#endif // PRINTOPERATORCPP_H
