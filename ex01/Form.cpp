#include "Form.hpp"

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
    try
    {
        if (_gradeToSign < 1 || _gradeToExecute < 1)
            throw GradeTooHighException();
        if (_gradeToSign > 150 || _gradeToExecute > 150)
            throw GradeTooLowException();
    }
    catch (Form::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

//const variable can only be assigned like this
Form::Form(Form const & copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    try
    {
        if (_gradeToSign < 1 || _gradeToExecute < 1)
            throw GradeTooHighException();
        if (_gradeToSign > 150 || _gradeToExecute > 150)
            throw GradeTooLowException();
    }
    catch (Form::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
    *this = copy;
    return ;
}

Form::~Form(void)
{
    return ;
}

Form & Form::operator =(Form const & src)
{
    if (this != &src)
    {
        _signed = src._signed;
    }
    return (*this);
}

std::string Form::getName(void) const
{
    return (_name);
}

unsigned int Form::getGradeToSign(void) const
{
    return (_gradeToSign);
}

unsigned int Form::getGradeToExecute(void) const
{
    return (_gradeToExecute);
}

bool Form::getSigned(void) const
{
    return (_signed);
}

void Form::beSigned(Bureaucrat const & b)
{

    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();

}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("EXCEPTION THROWN: Form grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("EXCEPTION THROWN: Form grade is too low!");
}

std::ostream & operator<<(std::ostream & o, Form const & f)
{
    o << "Form: \"" << f.getName() << "\" is ";
    if (f.getSigned() == true)
        o << "signed,";
    else
        o << "not signed,";
    o << std::endl << "needs grade " << f.getGradeToSign() << " to sign and grade " << f.getGradeToExecute() << " to execute!" << std::endl;
    return (o);
}