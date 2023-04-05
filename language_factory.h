#ifndef LANGUAGE_FACTORY_H
#define LANGUAGE_FACTORY_H
#include <iostream>
#include <classunit.h>
#include <methodunit.h>
#include <printoperator.h>
using namespace std;

class Language_Factory
{
public:
    virtual ~Language_Factory() = default;
    virtual std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const = 0;
    virtual std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type, Unit::Flags flags) const = 0;
    virtual std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const = 0;
};

class CppFactory : public Language_Factory
{

};

#endif // LANGUAGE_FACTORY_H
