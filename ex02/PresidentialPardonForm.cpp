#include "PresidentialPardonForm.hpp"
 
PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) 
    : AForm(copy._name, copy._gradeToSign, copy._gradeToExecute)
{
    *this = copy;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator =(PresidentialPardonForm const & src)
{
    if (this != &src)
    {
        _target = src._target;
    }
    return (*this);
}

int PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (_signed == false)
            throw FormNotSignedException();
        else if (executor.getGrade() > _gradeToExecute)
            throw GradeTooLowException();
        else
            std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }
    return (1);
}
