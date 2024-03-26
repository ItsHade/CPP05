#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat
{

public :

    Bureaucrat(std::string const & name, unsigned int grade);
    Bureaucrat(Bureaucrat const & copy);
    ~Bureaucrat(void);

    Bureaucrat & operator =(Bureaucrat const & src);

    std::string const & getName(void) const;
    unsigned int getGrade(void) const;

    void incrementGrade(void);
    void decrementGrade(void);
    void signForm(AForm & form) const;
    void executeForm(AForm const & form);

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
    unsigned int _grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b);

#endif