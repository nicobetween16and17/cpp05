#pragma once
#include "Form.hpp"
class RobotomyRequestForm: public Form
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &c);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &e);
	RobotomyRequestForm(const std::string target);
	void execute(Bureaucrat const & executor) const;
};
