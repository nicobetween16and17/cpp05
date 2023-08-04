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
		void upgrade();
		void downgrade();
		int getGrade();
		void signForm(Form &f);
		Bureaucrat &operator=(Bureaucrat &b);
		Bureaucrat(Bureaucrat &b);
		const std::string getName();
		class GradeTooLowException: public std::exception{
		public:
			const char * what () const throw()
			{
				return "GradeTooLowException";
			}
		};

		class GradeTooHighException: public std::exception{
		public:
			const char * what () const throw()
			{
				return "GradeTooHighException";
			}
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &b);