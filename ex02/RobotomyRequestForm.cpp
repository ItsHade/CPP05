#include "RobotomyRequestForm.hpp"
 
RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) 
    : AForm(copy._name, copy._gradeToSign, copy._gradeToExecute)
{
    *this = copy;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator =(RobotomyRequestForm const & src)
{
    if (this != &src)
    {
        _target = src._target;
    }
    return (*this);
}

int RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static int i = 0;
    try
    {
        if (_signed == false)
            throw FormNotSignedException();
        else if (executor.getGrade() > _gradeToExecute)
            throw GradeTooLowException();
        else
        {
            std::cout << "*Drilling noises* Bzzz Prrrrr Brrrr" << std::endl;
            if (i % 2 == 0)
            {
                std::cout << _target << " has been robotomized successfully!" << std::endl;
            }
            if (i == 1000000)
                i = 0;
            i++;
        }
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }
    return (1);
}
