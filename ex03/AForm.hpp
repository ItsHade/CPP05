#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

public :

    AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
    AForm(AForm const & copy);
    virtual ~AForm(void);

    AForm & operator =(AForm const & src);

    std::string getName(void) const;
    unsigned int getGradeToSign(void) const;
    unsigned int getGradeToExecute(void) const;
    bool getSigned(void) const;

    void beSigned(Bureaucrat const & b);
    virtual int execute(Bureaucrat const & executor) const = 0; //the class must be abstract

    class GradeTooHighException : public std::exception {
        public :
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public :
            virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
        public :
            virtual const char *what() const throw();
    };

protected :

    std::string const _name;
    unsigned int const _gradeToSign;
    unsigned int const _gradeToExecute;
    bool _signed;

};

std::ostream & operator<<(std::ostream & o, AForm const & f);

#endif