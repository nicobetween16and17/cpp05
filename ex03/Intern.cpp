#include "Intern.hpp"

Intern::Intern() {
	std::cout << "new Intern\n";
}

Intern::~Intern() {
	std::cout << "del Intern\n";

}

Intern::Intern(const Intern &c) {
	*this = c;
}

Intern &Intern::operator=(const Intern &c) {
	(void)c;
	return *this;
}

int str2int(std::string str, int h)
{
	int res = 0;
	while (++h < (int)str.length() - 1)
		res += str.at(h) * (h + 1);
	return res;
}

Form *Intern::makeForm(std::string name, std::string target) {
	int iName = str2int(name, -1);

	switch (iName) {
		case 23759 : return new PresidentialPardonForm(target);
		case 18136 : return new RobotomyRequestForm(target);
		case 21778 : return new ShrubberyCreationForm(target);
		default: return NULL;
	}
}
