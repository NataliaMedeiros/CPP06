#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
    switch (std::rand() % 3)
    {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
        default:
            return (nullptr);
    }
}

void    identify(Base* ptr)
{
    if (dynamic_cast<A*>(ptr))//dynamic_cast: if ptr points to class A it returns a valid pointer, if not it recives NULL
        std::cout << "It's an A class" << std::endl;
    else if (dynamic_cast<B*>(ptr))
        std::cout << "It's a B class" << std::endl;
    else if (dynamic_cast<C*>(ptr))
        std::cout << "It's a C class" << std::endl;
    else
        std::cout << "It's an unknown class" << std::endl;
}

void    identify(Base& ptr)
{
    try
    {
        (void) dynamic_cast<A&>(ptr);
        std::cout << "It's an A class" << std::endl;
        return ;
    }
    catch (std::bad_cast& e) {}
    try
    {
        (void) dynamic_cast<B&>(ptr);
        std::cout << "It's a B class" << std::endl;
        return ;
    }
    catch(std::bad_cast& e) {}
    try
    {
        (void) dynamic_cast<C&>(ptr);
        std::cout << "It's a C class" << std::endl;
        return ;
    }
    catch(std::bad_cast& e) {}
    std::cout << "No matching type found" << std::endl;
}
