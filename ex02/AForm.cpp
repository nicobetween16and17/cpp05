#include "AForm.hpp"

const std::string AForm::getName(){
	return this->_name;
}


AForm::AForm(): _name("blank"),  _gradeToSign(150), _gradeToX(150), _signed(false){
	std::cout << this << " is created\n";
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToX): _name(name), _gradeToSign(gradeToSign), _gradeToX(gradeToX){
	if (gradeToX < 1 || gradeToSign < 1)
		throw (AForm::GradeTooHighException());
	else if (gradeToX > 150 || gradeToSign > 150)
		throw (AForm::GradeTooLowException());
	else
	{
		this->_signed = false;
		std::cout<< "added " << *this << std::endl;
	}
}
AForm::~AForm(){
	std::cout << *this << " is obsolete and therefore is thrown to the trashcan as his place always should have been\n";
}

AForm::AForm(AForm &b): _name(b._name), _gradeToSign(b._gradeToSign), _gradeToX(b._gradeToX), _signed(b._signed){
}

AForm &AForm::operator=(AForm &b){
	if (this != &b)
	{
		this->_signed = b._signed;
	}
	return *this;
}


int AForm::getGradeToX(){
	return this->_gradeToX;
}

int AForm::getGradeToSign(){
	return this->_gradeToSign;
}

void AForm::beSigned(Bureaucrat &b){
	if ((const int)b.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());
}

bool AForm::isSigned(){ return this->_signed;}

void AForm::execute(const Bureaucrat &executor) const{
	(void)executor;
}

std::ostream &operator<<(std::ostream &out, AForm &b)
{
	out << "[AForm:\n\t\033[0;32mname:\033[0m " << b.getName() << "\n\t\033[0;32mgrade to sign:\033[0m " << b.getGradeToSign() << "\n\t\033[0;32mgrade to execute:\033[0m " << b.getGradeToX() << "\n\t\033[0;32msignature:\033[0m " << (b.isSigned()? "signed]\n" : "unsigned]\n");
	return out;
}
