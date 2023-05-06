#ifndef METHODUNIT_H
#define METHODUNIT_H
#include <unit.h>

#include <printoperator.h>

using namespace std;


class MethodUnit:public Unit                                 // конкретная языковая конструкция метода некоторого языка
{

public:
enum Modifier                                                // перечисление всех поддерживаемых модификаторов методов всех поддерживаемых языков
{
STATIC = 1,
CONST = 1 << 1,
VIRTUAL = 1 << 2,
FINAL = 1 << 3,
SEALED = 1 << 4
};

    public:


    virtual ~MethodUnit() = default;
    MethodUnit(const std::string &name, const std::string &returnType, Flags flags)
{
    m_name=name;
    m_returnType=returnType;
    m_flags=flags;
    }

    void add( const std::shared_ptr<Unit >& unit, Flags /* flags */ = 0 )
    {
        if (unit == nullptr)
        {
            throw std::runtime_error("The unit is nullptr.");
        }
      m_body.push_back( unit );
    }


    protected:
        virtual  std::string generateShift( unsigned int level ) const
         {
          static const auto DEFAULT_SHIFT = " ";
          std::string result;
          for( unsigned int i = 0; i < level; ++i )
          {
          result += DEFAULT_SHIFT;
          }
         return result;
         }



protected:
    std::string m_name;                                 // имя метода
    std::string m_returnType;                           // тип возвращаемого методом значения
    Flags m_flags;                                      // выбранные модификаторы метода
    std::vector< shared_ptr< Unit> > m_body;            // тело метода в котором хранятся принадлежащие ему языковые конструкции
    };









#endif // METHODUNIT_H
