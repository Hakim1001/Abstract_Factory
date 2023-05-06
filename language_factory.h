#ifndef LANGUAGE_FACTORY_H
#define LANGUAGE_FACTORY_H

#include <memory>

#include <classunitcpp.h>
#include <methodunitcpp.h>
#include <printoperatorcpp.h>

#include <classunitcsharp.h>
#include <methodunitcsharp.h>
#include <printoperatorcsharp.h>


#include <classunitjava.h>
#include <methodunitjava.h>
#include <printoperatorjava.h>


class Language_Factory
{
public:
    virtual ~Language_Factory() = default;
    virtual std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const = 0;                                                      // интерфейс, создающий за создание Unit'а класса
    virtual std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type, Unit::Flags flags) const = 0; // интерфейс, создающий за создание Unit'а метода
    virtual std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const = 0;                                      // интерфейс, создающий за создание Unit'а оператора вывода
};

class CppFactory : public Language_Factory //Фабрика отвечающая за генарацию функций с++ методов классов и оператора вывода
{

    std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const
    {
        return std::make_shared<ClassUnitCpp >(name);
    }

    std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type,Unit::Flags flags) const
    {
        return std::make_shared<MethodUnitCpp>(name, return_type, flags); // динамическое создание Unit'а метода языка C++
    }

    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const
    {
        return std::make_shared<PrintOperatorUnitcpp>(name); // динамическое создание Unit'а оператора вывода языка C++
    }
};
 class CsharpFactory : public Language_Factory //Фабрика отвечающая за генарацию функций с# методов классов и оператора вывода
 {

     std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const
     {
         return std::make_shared<ClassUnitCsharp >(name);
     }

     std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type,Unit::Flags flags) const
     {
         return std::make_shared<MethodUnitCsharp>(name, return_type, flags); // динамическое создание Unit'а метода языка C#
     }

     std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const
     {
         return std::make_shared<PrintOperatorUnitCsharp>(name); // динамическое создание Unit'а оператора вывода языка C#
     }


};


 class JavaFactory : public Language_Factory   //Фабрика отвечающая за генарацию функций Java методов классов и оператора вывода
 {

     std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const
     {
         return std::make_shared<ClassUnitJava >(name);
     }

     std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type,Unit::Flags flags) const
     {
         return std::make_shared<MethodUnitJava>(name, return_type, flags); // динамическое создание Unit'а метода языка Java
     }

     std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const
     {
         return std::make_shared<PrintOperatorUnitJava>(name); // динамическое создание Unit'а оператора вывода языка Java
     }


};

#endif // LANGUAGE_FACTORY_H
