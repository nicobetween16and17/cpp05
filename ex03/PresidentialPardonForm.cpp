#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("blank"){
	std::cout << "PP Form created\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): Form("PresidentialPardonForm", 25, 5), _target(target){
	std::cout << "PP Form created\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &c) : Form(c){
	(std::string)_target = (std::string)c._target;
	std::cout << "PP Form created\n";
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PP Form deleted\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &e){
	(std::string)_target = (std::string)e._target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const{
	if ((const int)executor.getGrade() > this->getGradeToX())
		throw (Form::GradeTooLowException());
	else if (this->isSigned())
	{
		std::cout << _target << "has has been pardoned by Zaphod Beeblebrox.\n";
	}
	else
		throw (Form::FormNotSignedException());
}
