#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    int Number = rand() % 3;

    switch (Number)
    {
    case 0:
        return new A();
        break;
    case 1:
        return new B();
        break;
    case 2:
        return new C();
        break;
    default:
        break;
    }
    return NULL;
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}

    std::cout << "Unknown Type" << std::endl;
}

int main()
{
    std::srand(std::time(0));
    Base* randomBase = generate();
    Base* randomBase2 = generate();

    std::cout << "First identification by pointer: ";
    identify(randomBase);
    std::cout << "First identification by reference: ";
    identify(*randomBase);
    std::cout << "Second identification by pointer: ";
    identify(randomBase2);
    std::cout << "Second identification by reference: ";
    identify(*randomBase2);
    delete randomBase;
    delete randomBase2;
}