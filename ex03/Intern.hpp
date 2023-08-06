#pragma once

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern {

public:
	Intern();
	Intern(const Intern& c);
	~Intern();
	Intern &operator=(const Intern& c);
	Form* makeForm(std::string name, std::string target);
};