#include "Form.hpp"

const std::string Form::getName() const{
	return this->_name;
}


Form::Form(): _name("blank"),  _gradeToSign(150), _gradeToX(150), _signed(false){
	std::cout << *this << " is created\n";
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

Form::Form(const Form &b): _name(b._name), _gradeToSign(b._gradeToSign), _gradeToX(b._gradeToX), _signed(b._signed){
}

Form &Form::operator=(const Form &b){
	if (this != &b)
	{
		this->_signed = b._signed;
	}
	return *this;
}


int Form::getGradeToX() const {
	return this->_gradeToX;
}

int Form::getGradeToSign()const{
	return this->_gradeToSign;
}

void Form::beSigned(const Bureaucrat &b){
	if ((const int)b.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());
	else
		this->_signed = true;
}

bool Form::isSigned() const{ return this->_signed;}

void Form::execute(const Bureaucrat &executor) const{
	(void)executor;
}

std::ostream &operator<<(std::ostream &out, const Form &b)
{
	out << "Form : [" << b.getName() << ", " \
	<< b.getGradeToSign() << ", " << b.getGradeToX() << \
	", " << (b.isSigned()? "signed]" : "unsigned]");
	return out;
}
//
//void Form::setGradeToSign(const int gts) {_gradeToSign = gts;}
//
//int Form::setGradeToX(const int gtx) {_gradeToX = gtx;}
//
//void Form::setName(const std::string name) {_name = name;}
//
//void Form::setSigned(bool b) {_signed = b;}
