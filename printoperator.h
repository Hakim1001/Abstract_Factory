#ifndef PRINTOPERATOR_H
#define PRINTOPERATOR_H
#include <unit.h>
#include <iostream>
#include <string>
using namespace std;

class PrintOperatorUnit:public Unit
{
public:
explicit PrintOperatorUnit( const std::string& text ) :
m_text( text ) { }
std::string compile( unsigned int level = 0 ) const
{
return generateShift( level ) + "printf( \"" + m_text+ "\" );\n";
}
private:
std::string m_text;
};

#endif // PRINTOPERATOR_H
