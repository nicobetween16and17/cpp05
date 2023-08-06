#pragma once
#include "Form.hpp"
class PresidentialPardonForm: public Form
{
private:
	const std::string _target;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &c);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &e);
	PresidentialPardonForm(const std::string target);
	void execute(Bureaucrat const & executor) const;
};