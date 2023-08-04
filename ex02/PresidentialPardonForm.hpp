#pragma once
#include "AForm.hpp"
class PresidentialPardonForm: public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &c);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &e);
	PresidentialPardonForm(std::string target);
	void execute(Bureaucrat const & executor) const;
};