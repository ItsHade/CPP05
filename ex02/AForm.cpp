#include "AForm.hpp"

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
    try
    {
        if (_gradeToSign < 1 || _gradeToExecute < 1)
            throw GradeTooHighException();
        if (_gradeToSign > 150 || _gradeToExecute > 150)
            throw GradeTooLowException();
    }
    catch (AForm::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

//const variable can only be assigned like this
AForm::AForm(AForm const & copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    try
    {
        if (_gradeToSign < 1 || _gradeToExecute < 1)
            throw GradeTooHighException();
        if (_gradeToSign > 150 || _gradeToExecute > 150)
            throw GradeTooLowException();
    }
    catch (AForm::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
    *this = copy;
    return ;
}

AForm::~AForm(void)
{
    return ;
}

AForm & AForm::operator =(AForm const & src)
{
    if (this != &src)
    {
        _signed = src._signed;
    }
    return (*this);
}

std::string AForm::getName(void) const
{
    return (_name);
}

unsigned int AForm::getGradeToSign(void) const
{
    return (_gradeToSign);
}

unsigned int AForm::getGradeToExecute(void) const
{
    return (_gradeToExecute);
}

bool AForm::getSigned(void) const
{
    return (_signed);
}

void AForm::beSigned(Bureaucrat const & b)
{

    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();

}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("EXCEPTION THROWN: AForm grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("EXCEPTION THROWN: AForm grade is too low!");
}

std::ostream & operator<<(std::ostream & o, AForm const & f)
{
    o << "AForm: \"" << f.getName() << "\" is ";
    if (f.getSigned() == true)
        o << "signed,";
    else
        o << "not signed,";
    o << std::endl << "needs grade " << f.getGradeToSign() << " to sign and grade " << f.getGradeToExecute() << " to execute!" << std::endl;
    return (o);
}