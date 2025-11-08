#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& t)
    : AForm("RobotomyRequestForm", 72, 45), target(t) {}

RobotomyRequestForm::~RobotomyRequestForm() {}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    static bool rand = false;

    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "Bzzzzz... drilling noises..." << std::endl;
    
    if (rand)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << target << " robotomy failed." << std::endl;

    rand = !rand;
}