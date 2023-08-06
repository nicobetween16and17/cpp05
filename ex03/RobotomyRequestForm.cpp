#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("blank"){
	std::cout << "RR Form created\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): Form("RobotomyRequestForm", 72, 55), _target(target){
	std::cout << "RR Form created\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &c) : Form(c){
	(std::string)_target = (std::string)c._target;
	std::cout << "RR Form created\n";
}

RobotomyRequestForm::~RobotomyRequestForm(){

	std::cout << "RR Form deleted\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &e){
	(std::string)_target = (std::string)e._target;
	return *this;
}
void RobotomyRequestForm::execute(const Bureaucrat &executor) const{
	int decision = rand() % 2;
	if ((const int)executor.getGrade() > this->getGradeToX())
		throw (Form::GradeTooLowException());
	else if (this->isSigned())
	{
		if (decision)
			std::cout << "Bzzzz\n" << _target << " has been robotomized successfully !\n";
	}
	else
		throw (Form::FormNotSignedException());
}
