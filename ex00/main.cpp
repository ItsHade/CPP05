#include "Bureaucrat.hpp"

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

    return (0);
}