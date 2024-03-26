#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

public :

    PresidentialPardonForm(std::string const & target);
    PresidentialPardonForm(PresidentialPardonForm const & copy);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm & operator =(PresidentialPardonForm const & src);

    int execute(Bureaucrat const & executor) const;

private :

    std::string _target;
};

#endif