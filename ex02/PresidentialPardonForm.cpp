#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("blank", 25, 5){
	std::cout << *this << "created\n";
}

PresidentialPardonForm::PresidentialPardonForm(int name): AForm(name, 25, 5){
	std::cout << *this << "created\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &c) : AForm(c){
	std::cout << *this << "created\n";
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << *this << "deleted\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &e){
	this->_name = e._name;
	this->_signed = e._signed;
	std::cout << e << "copied\n";
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const{
	if ((const int)executor.getGrade() > this->_gradeToX)
		throw (AForm::GradeTooLowException());
	else
	{
		this->_signed = true;
		std::cout << b << "has has been pardoned by Zaphod Beeblebrox.\n";
	}
}