#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{

public :

    ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(ShrubberyCreationForm const & copy);
    ~ShrubberyCreationForm(void);

    void execute(Bureaucrat const & executor) const;

    ShrubberyCreationForm & operator =(ShrubberyCreationForm const & src);

private :

    std::string _target;

};

#endif