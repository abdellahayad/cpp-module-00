#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat  b1("abdellah", 3);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;
    }

    catch(std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "=================================" << std::endl;
    
    try
    {
        Bureaucrat b2("yassine", 148);
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << b2 << std::endl;
    }

    catch(std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
