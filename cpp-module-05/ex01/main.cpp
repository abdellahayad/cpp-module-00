#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat a("Abdellah", 1);
        Bureaucrat b("Omar", 150);

        Form f1("Form_A", 5, 10);
        Form f2("Form_B", 140, 130);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << "----------------------" << std::endl;

     
        a.signForm(f1);
        a.signForm(f2);

   
        b.signForm(f1);
        b.signForm(f2);

        std::cout << "----------------------" << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
