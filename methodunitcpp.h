#ifndef METHODUNITCPP_H
#define METHODUNITCPP_H
#include <methodunit.h>
//#include <unit.h>

class MethodUnitCpp : public MethodUnit
{



public:
    MethodUnitCpp(const std::string &name, const std::string &returnType, Flags flags):MethodUnit(name,returnType,flags)
    {
    }

//    MethodUnitCpp(const std::string &name, const std::string &returnType, Flags flags)		: m_name(name)
//      , m_returnType(returnType)
//      , m_flags(flags){}

    std::string compile( unsigned int level = 0 ) const
    {
      std::string result = generateShift( level );
      if( m_flags & STATIC )
      {
      result += "static ";
      } else if( m_flags & VIRTUAL )
      {
      result += "virtual ";
      }
      result += m_returnType + " ";
      result += m_name + "()";
      if( m_flags & CONST )
      {
      result += " const";
      }
      result += " {\n";
      for( const auto& b : m_body )
      {
      result += b->compile( level + 1 );
      }
      result += generateShift( level ) + "}\n";
    return result;
    }
    void add( const std::shared_ptr<Unit >& unit, Flags /* flags */ = 0 )
    {
        if (unit == nullptr)
        {
            throw std::runtime_error("The unit is nullptr.");
        }
      m_body.push_back( unit );
    }

};

#endif // METHODUNITCPP_H
