#include "Form.hpp"


Form::Form(const std::string& n, int gSign, int gExecute) 
    : name(n), isSigned(false), gradeToSign(gSign), gradeToExecute(gExecute)
{
    if (gSign < 1 || gExecute < 1)
        throw GradeTooHighException();
    if (gSign > 150 || gExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& copy)
 : name(copy.name) , isSigned(copy.isSigned), gradeToSign(copy.gradeToSign),
   gradeToExecute(copy.gradeToExecute) {}

Form &Form::operator=(const Form& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

Form::~Form() {}

std::string Form::getName() const {return name;}
bool Form::getIsSigned() const {return isSigned;}
int Form::getGradeToSign() const {return gradeToSign;}
int Form::getGradeToExecute() const {return gradeToExecute;}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &f)
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