#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

public :

    RobotomyRequestForm(std::string const & target);
    RobotomyRequestForm(RobotomyRequestForm const & copy);
    ~RobotomyRequestForm(void);

    RobotomyRequestForm & operator =(RobotomyRequestForm const & src);

    int execute(Bureaucrat const & executor) const;

private :

    std::string _target;
};

#endif