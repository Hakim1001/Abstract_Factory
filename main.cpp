#include "mainwindow.h"
//#include "unit.h"
#include <iostream>
#include "language_factory.h"

std::string GenerateCode(const std::shared_ptr<Language_Factory> &factory)
{

    auto tmp=factory->CreateClass("ClassA");
    tmp->add(factory->CreateMethod("TestFunctPrivate","void",0), ClassUnit::PRIVATE);
    tmp->add(factory->CreateMethod("TestFunctPublic","void",0), ClassUnit::PUBLIC);
//    tmp->add(factory->CreateMethod("TestFunctInternal","void",0), ClassUnit::INTERNAL);
//    tmp->add(factory->CreateMethod("TestFunctProtected_internal","void",0), ClassUnit::PROTECTED_INTERNAL);
//    tmp->add(factory->CreateMethod("TestFunctProtected_internal","void",0), ClassUnit::PRIVATE_PROTECTED);
    auto method_static=factory->CreateMethod("TestFucnt2","void",MethodUnit::STATIC);
    method_static->add(factory->CreatePrintOperator("Static Hello, world!"));
    tmp->add(method_static, ClassUnit::PROTECTED);
    auto method_virtual=factory->CreateMethod("TestFucnt2","void",MethodUnit::VIRTUAL);
    method_virtual->add(factory->CreatePrintOperator("Virtual Hello, world!"));
    tmp->add(method_virtual, ClassUnit::PROTECTED);
    auto method_const=factory->CreateMethod("TestFucnt2","void",MethodUnit::CONST);
    method_const->add(factory->CreatePrintOperator("Const Hello, world!"));
    tmp->add(method_const, ClassUnit::PROTECTED);
    auto method_final=factory->CreateMethod("TestFucnt2","void",MethodUnit::SEALED);
    method_final->add(factory->CreatePrintOperator("Final Hello, world!"));
    tmp->add(method_final, ClassUnit::PROTECTED);
    return tmp->compile();


};
int main(int argc, char *argv[])
{


    // C++
    std::cout << "-----------------------------------C++------------------------------------------" << std::endl;

    // обработка ошибок сделана для того чтобы ошибка при генерации программы на одном из языков, программы на других языках имели возможность быть сгенерированными, так как они слабо зависят друг от друга
    try
    {
        std::cout << GenerateCode(std::make_shared<CppFactory>()) << std::endl; // создание фабрики языка C++ и генерация кода программы на этом языке
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout<<"-----------------------------------Java------------------------------------------"<< std::endl;
    try
    {
        std::cout << GenerateCode(std::make_shared<JavaFactory>()) << std::endl; // создание фабрики языка C++ и генерация кода программы на этом языке
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout<<"-----------------------------------Csharp------------------------------------------"<< std::endl;

    try
    {
        std::cout << GenerateCode(std::make_shared<CsharpFactory>()) << std::endl; // создание фабрики языка C++ и генерация кода программы на этом языке
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }

}
