#pragma once
#include "AForm.hpp"
class ShrubberyCreationForm: public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &c);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &e);
	ShrubberyCreationForm(std::string target);
	void beSigned(Bureaucrat &b) const;
	void execute(Bureaucrat const & executor) const;
};
