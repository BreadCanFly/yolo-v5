//#include "stdafx.h"
#include <memory>
#include <iostream> 

using namespace std;

class Base
{
public:
    virtual void f(void) = 0;
    virtual void g(void) = 0;
protected:
    Base() { std::cout << "Base()" << std::endl; }
    virtual ~Base() { std::cout << "~Base()" << std::endl; }
};

class A :public Base
{
public:
    A(void) { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }
    void f(void) { std::cout << "A::f()" << std::endl; }
    void g(void) { std::cout << "A::g()" << std::endl; }
};

class B :public Base {
public:
    B(void) { std::cout << "B()" << std::endl; }
    ~B(void) { std::cout << "~B()" << std::endl; }
    void f() { std::cout << "B::f()" << std::endl; }
    void g() { std::cout << "B::g()" << std::endl; }
};

class Factory {
public:
    static std::shared_ptr<Base> CreateA(void) {
        return std::make_shared<A>();
    }
    static std::shared_ptr<Base> CreateB(void) {
        return std::make_shared<B>();
    }
};


int main()
{
    std::shared_ptr<Base> pbase = Factory::CreateA();
    pbase->f();
    pbase->g();

    pbase = Factory::CreateB();
    pbase->f();
    pbase->g();

    return 0;
}