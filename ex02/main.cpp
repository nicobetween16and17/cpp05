#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{
	ShrubberyCreationForm f("Home");
	//Bureaucrat b2;
	Bureaucrat b1("koko", 1);


	//b2.signForm(f);
	b1.executeForm(f);
	b1.signForm(f);
	b1.executeForm(f);

}