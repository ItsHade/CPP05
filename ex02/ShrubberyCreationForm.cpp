#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy)
    : AForm(copy._name, copy._gradeToSign, copy._gradeToExecute)
{
    *this = copy;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator =(ShrubberyCreationForm const & src)
{
    if (this != &src)
    {
        _signed = src._signed;
        _target = src._target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    (void)executor;
    std::ofstream outfile;

    outfile.open((_target + "_shrubbery").c_str());
    if (outfile.is_open() && outfile.good())
    {
        outfile << "   *   \n";
        outfile << "  / \\ \n";
        outfile << " /   \\\n";
        outfile << "/     \\\n";
        // outfile <<
        outfile << std::endl;
    }
    outfile.close();
    return ;
}