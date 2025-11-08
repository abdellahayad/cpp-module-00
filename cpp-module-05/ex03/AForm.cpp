#include "AForm.hpp"


AForm::AForm(const std::string& n, int gSign, int gExecute) 
    : name(n), isSigned(false), gradeToSign(gSign), gradeToExecute(gExecute)
{
    if (gSign < 1 || gExecute < 1)
        throw GradeTooHighException();
    if (gSign > 150 || gExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& copy)
 : name(copy.name) , isSigned(copy.isSigned), gradeToSign(copy.gradeToSign),
   gradeToExecute(copy.gradeToExecute) {}

AForm &AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const {return name;}
bool AForm::getIsSigned() const {return isSigned;}
int AForm::getGradeToSign() const {return gradeToSign;}
int AForm::getGradeToExecute() const {return gradeToExecute;}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Form grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << f.getName()
        << ", form grade to sign " << f.getGradeToSign()
        << ", grade to execute " << f.getGradeToExecute()
        << ", signed status: ";

    if (f.getIsSigned())
        out << "signed.";
    else
        out << "not signed.";
        
    return out;
}