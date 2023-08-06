#pragma once
#include "Form.hpp"
class ShrubberyCreationForm: public Form
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &c);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &e);
	ShrubberyCreationForm(std::string target);
	void execute(Bureaucrat const & executor) const;
};
