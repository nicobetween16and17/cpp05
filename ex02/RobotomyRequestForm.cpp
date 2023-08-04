#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("blank", 72, 45){
	std::cout << *this << "created\n";
}

RobotomyRequestForm::RobotomyRequestForm(int name): AForm(name, 72, 45){
	std::cout << *this << "created\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &c) : AForm(c){
	std::cout << *this << "created\n";
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << *this << "deleted\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &e){
	this->_name = e._name;
	this->_signed = e._signed;
	std::cout << e << "copied\n";
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const{
	int decision = rand() % 2;
	if ((const int)executor.getGrade() > this->_gradeToX)
		throw (AForm::GradeTooLowException());
	else
	{
		this->_signed = true;
		if (decision)
			std::cout << "Bzzzz\n" << executor << " has been robotomized successfully !\n";
	}
}
