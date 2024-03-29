#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"


class Bureaucrat;

class Form
{

public :

    Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
    Form(Form const & copy);
    ~Form(void);

    Form & operator =(Form const & src);

    std::string getName(void) const;
    unsigned int getGradeToSign(void) const;
    unsigned int getGradeToExecute(void) const;
    bool getSigned(void) const;

    void beSigned(Bureaucrat const & b);

    class GradeTooHighException : public std::exception {
        public :
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public :
            virtual const char* what() const throw();
    };

private :

    std::string const _name;
    unsigned int const _gradeToSign;
    unsigned int const _gradeToExecute;
    bool _signed;

};

std::ostream & operator<<(std::ostream & o, Form const & f);

#endif