#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <methodunit.h>
#include "unit.h"
class ClassUnit:public Unit
{


public:                                                                                              // перечисление всех поддерживаемых модификаторов доступа всех поддерживаемых языков
enum AccessModifier
{
PUBLIC,
PROTECTED,
PRIVATE,
INTERNAL,
PROTECTED_INTERNAL,
PRIVATE_PROTECTED
};


public:

    public:
        explicit ClassUnit(const std::string &name,size_t t): m_name(name),m_fields(t)               // передача базовому классу количества поддерживаемых модификаторов доступа
        {
        }

void add( const std::shared_ptr<Unit>& unit, Flags flags )                     //Добавление методов и тела методов функций в класс
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
    if(flags > m_fields.size())
    {
       throw std::runtime_error( "Not supported" );
    }
  m_fields[access_modifier].push_back( unit );
}

    protected:
    std::string m_name;                                            // имя класса
    using Fields = std::vector< std::shared_ptr<Unit > >;          // тип данных для набора полей класса
    std::vector< Fields > m_fields;                                // каждому модификатору доступа соотвествует свой набор полей



};


#endif // CLASSUNIT_H
