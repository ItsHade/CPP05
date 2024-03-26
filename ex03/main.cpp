#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Bureaucrat a("a", 1);
    Bureaucrat b("b", 150);
    Bureaucrat c("c", 0);
    Bureaucrat d("d", 156);

    a.incrementGrade();
    std::cout << a;
    b.decrementGrade();
    std::cout << b;
    b.incrementGrade();
    std::cout << b; 


    Bureaucrat lvl26("lvl26", 26);
    Bureaucrat president("president", 1);

    ShrubberyCreationForm sForm("home");
    RobotomyRequestForm rForm("john");
    PresidentialPardonForm pForm("you");
    
    std::cout << "\nTrying to sign forms not signed: " << std::endl;

    sForm.execute(lvl26);
    lvl26.executeForm(rForm);
    pForm.execute(lvl26);

    std::cout << "\nSigning forms: " << std::endl;

    president.signForm(sForm);
    president.signForm(rForm);
    lvl26.signForm(pForm);
    president.signForm(pForm);

    std::cout << "\nExecuting signed forms: " << std::endl;

    lvl26.executeForm(sForm);
    lvl26.executeForm(rForm);
    lvl26.executeForm(pForm); 
    president.executeForm(pForm);

    std::cout << "\nInter tests: " << std::endl;

    {
        Intern someRandomIntern;

        AForm* rrf;
        AForm* invalidForm;
        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        invalidForm = someRandomIntern.makeForm("HAHAHFORM", "uselessTarget");

        president.signForm(*rrf);
        delete rrf;
    }
    return (0);
}