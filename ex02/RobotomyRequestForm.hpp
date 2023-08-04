#pragma once
#include "AForm.hpp"
class RobotomyRequestForm: public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &c);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &e);
	RobotomyRequestForm(std::string target);
	void beSigned(Bureaucrat &b);
	void execute(Bureaucrat const & executor) const;
};
