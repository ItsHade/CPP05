#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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


    ShrubberyCreationForm sForm("home");

    sForm.execute(a);
    
    return (0);
}