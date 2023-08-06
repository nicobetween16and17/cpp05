#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat{
	std::string const _name;
	int grade;

	public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat &operator=(const Bureaucrat &b);
	Bureaucrat(const Bureaucrat &b);

	void upgrade();
	void downgrade();

	int getGrade() const;

	void executeForm(Form const &f);
	void signForm(Form &f);

	const std::string getName() const;
	class GradeTooLowException: public std::exception{
	public:
		const char * what () const throw(){return "GradeTooLowException";}};
	class GradeTooHighException: public std::exception{
	public:
		const char * what () const throw(){return "GradeTooHighException";}};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);