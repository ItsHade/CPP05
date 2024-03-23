#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBYRYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

public :

    ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(ShrubberyCreationForm const & copy);
    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm & operator =(ShrubberyCreationForm const & src);

private :

    std::string _target;

};

#endif