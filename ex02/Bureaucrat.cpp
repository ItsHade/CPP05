#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, unsigned int grade) : _name(name)
{
    try 
    {
        if (grade < MAX_GRADE)
            throw GradeTooHighException();
        else if (grade > MIN_GRADE)
            throw GradeTooLowException();
        else
            _grade = grade;
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy.getName())
{
    *this = copy;
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    return ;
}

Bureaucrat & Bureaucrat::operator =(Bureaucrat const & src)
{
    if (this != &src)
        _grade = src._grade;
    return (*this);
}

std::string const & Bureaucrat::getName(void) const
{
    return (_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
    try
    {
        if (_grade - 1 < MAX_GRADE)
            throw GradeTooHighException();
        else
            _grade--;
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

void Bureaucrat::decrementGrade(void)
{
    try
    {
        if (_grade + 1 > MIN_GRADE)
            throw GradeTooLowException();
        else
            _grade++;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return ;
}

void Bureaucrat::signForm(AForm & form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("EXCEPTION THROWN: Bureaucrat grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("EXCEPTION THROWN: Bureaucrat grade is too low!");
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (o);
}
