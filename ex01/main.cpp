#include "Form.hpp"
#include "Bureaucrat.hpp"
int main()
{
	Form f("test", 80, 150);
	Bureaucrat b1("koko", 79);
	Bureaucrat b2;

	b1.signForm(f);
	b2.signForm(f);

}