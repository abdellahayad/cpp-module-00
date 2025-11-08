#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Intern intern;
        AForm *form;
        Bureaucrat bureaucrat("abdellah", 1);
        std::cout << "==================" << std::endl;
        form = intern.makeForm("shrubbery creation", "home");
        if (form)
        {
            std::cout << *form << std::endl;
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            std::cout << *form << std::endl;
            delete form;
        }
        std::cout << "==================" << std::endl;
        form = intern.makeForm("robotomy request", "home");
        if (form)
        {
            std::cout << *form << std::endl;
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            std::cout << *form << std::endl;
            delete form;
        }
        std::cout << "==================" <<  std::endl;
        form = intern.makeForm("presidential pardon", "home");
        if (form)
        {
            std::cout << *form << std::endl;
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            std::cout << *form << std::endl;
            delete form;
        }
        std::cout << "==================" <<  std::endl;
        form = intern.makeForm("Unknown Form", "home");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }

        
    }
    
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
