#include "Form.hpp"

const std::string Form::getName(){
	return this->_name;
}


Form::Form(): _name("blank"),  _gradeToSign(150), _gradeToX(150), _signed(false){
	std::cout << this << " is created\n";
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToX): _name(name), _gradeToSign(gradeToSign), _gradeToX(gradeToX){
	if (gradeToX < 1 || gradeToSign < 1)
		throw (Form::GradeTooHighException());
	else if (gradeToX > 150 || gradeToSign > 150)
		throw (Form::GradeTooLowException());
	else
	{
		this->_signed = false;
		std::cout<< "added " << *this << std::endl;
	}
}
Form::~Form(){
	std::cout << *this << " is obsolete and therefore is thrown to the trashcan as his place always should have been\n";
}

Form::Form(Form &b): _name(b._name), _gradeToSign(b._gradeToSign), _gradeToX(b._gradeToX), _signed(b._signed){
}

Form &Form::operator=(Form &b){
	if (this != &b)
	{
		this->_signed = b._signed;
	}
	return *this;
}


int Form::getGradeToX(){
	return this->_gradeToX;
}

int Form::getGradeToSign(){
	return this->_gradeToSign;
}

void Form::beSigned(Bureaucrat &b){
	if ((const int)b.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());
	else
		this->_signed = true;
}

bool Form::isSigned(){ return this->_signed;}

std::ostream &operator<<(std::ostream &out, Form &b)
{
	out << "[Form:\n\t\033[0;32mname:\033[0m " << b.getName() << "\n\t\033[0;32mgrade to sign:\033[0m " \
	<< b.getGradeToSign() << "\n\t\033[0;32mgrade to execute:\033[0m " << b.getGradeToX() << \
	"\n\t\033[0;32msignature:\033[0m " << (b.isSigned()? "signed]\n" : "unsigned]\n");
	return out;
}