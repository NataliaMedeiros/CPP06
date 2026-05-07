#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    std::srand(std::time(0));

    Base* ptr = generate();

    identify(ptr);

    identify(*ptr);

    delete ptr;

    return 0;
}
