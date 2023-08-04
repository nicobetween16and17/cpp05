#include "Bureaucrat.hpp"

const std::string Bureaucrat::getName() const{
	return this->_name;
}

int Bureaucrat::getGrade() const{
	return this->grade;
}

Bureaucrat::Bureaucrat(): _name("Michou"){
	this->grade = 150;
	std::cout << *this << " is engaged\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name){
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		this->grade = grade;
		std::cout << *this << " is engaged\n";
	}
}
Bureaucrat::~Bureaucrat(){
	std::cout << *this << " died from overworking, it was already passed 17\n";
}

Bureaucrat::Bureaucrat(Bureaucrat &b): _name(b._name){
	this->grade = b.grade;
}

void Bureaucrat::signForm(const AForm &f){
	try
	{
		f.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn't sign " << f << "because " << e.what() << std::endl;
		return ;
	}
	std::cout << *this << " signed " << f << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &b){
	if (this != &b)
	{
		this->grade = b.grade;
	}
	return *this;
}

void Bureaucrat::upgrade(){
	int grade;

	grade = this->grade - 1;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->grade = grade;
}

void Bureaucrat::downgrade(){
	int grade;

	grade = this->grade + 1;
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->grade = grade;
}

std::ostream &operator<<(std::ostream &out,const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

void Bureaucrat::executeForm(const AForm &f){
	try
	{
		f.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << *this << "could not execute the form because of " << e.what();
	}

}