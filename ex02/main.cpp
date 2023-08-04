#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{
	ShrubberyCreationForm f("test");
	Bureaucrat b2;
	Bureaucrat b1("koko", 79);


	b1.signForm(f);
	b2.signForm(f);

}