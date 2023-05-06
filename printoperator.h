#ifndef PRINTOPERATOR_H
#define PRINTOPERATOR_H

#include <unit.h>

class PrintOperatorUnit:public Unit   // конкретная языковая конструкция оператора вывода некоторого языка
{


    public:

    explicit PrintOperatorUnit(const std::string &text)
    {
    m_name=text;
    }


virtual ~PrintOperatorUnit() = default;
protected:
        std::string m_name;            // текст, который должен вывести данный оператор


    };

#endif // PRINTOPERATOR_H

