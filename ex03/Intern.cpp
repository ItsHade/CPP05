#include "Intern.hpp"

Intern::Intern(void)
{
    return ;
}

Intern::Intern(Intern const & copy)
{
    *this = copy;
    return ;
}

Intern::~Intern(void)
{
    return ;
}

Intern & Intern::operator =(Intern const & src)
{
    (void)src;
    return (*this);
}

static AForm * makePresident(std::string const target)
{
    return (new PresidentialPardonForm(target));
}

static AForm * makeRobotomy(std::string const target)
{
    return (new RobotomyRequestForm(target));
}

static AForm * makeShrubbery(std::string const target)
{
    return (new ShrubberyCreationForm(target));
}

AForm * Intern::makeForm(std::string name, std::string target)
{
    int arraySize = 3;
    AForm *(*ptr[])(std::string const target) = {&makePresident, &makeRobotomy, &makeShrubbery};
    std::string array[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

    for (int i = 0; i < arraySize; i++)
    {
        if (name == array[i])
        {
            std::cout << "Intern created " << name << std::endl;
            return (ptr[i](target));
        }
    }    

    std::cout << "Intern could not create " << name << std::endl;
    return (NULL);
}