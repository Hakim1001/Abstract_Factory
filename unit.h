#ifndef UNIT_H
#define UNIT_H
#include <vector>
#include <iostream>
#include <string>

class Unit
{
public:
using Flags = unsigned int;
public:
virtual ~Unit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags )
    {
             throw std::runtime_error( "Not supported" ); // так как не все конструкции поддерживают добавление других конструкций, данный метод реализуется по умолчанию и выбрасывает исключение

    }

virtual std::string compile( unsigned int level = 0 ) const = 0; // функция генерации кода программы
protected:
  virtual  std::string generateShift( unsigned int level ) const  // функция генерации отступов, на вход принимает количество отступов которые необходимо сделать
   {
    static const auto DEFAULT_SHIFT = " ";
    std::string result;
    for( unsigned int i = 0; i < level; ++i )
    {
    result += DEFAULT_SHIFT;
    }
   return result;
   }
};





#endif // UNIT_H
