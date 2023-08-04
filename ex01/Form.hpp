#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form{
	std::string const _name;
	int const _gradeToSign;
	int const _gradeToX;
	bool _signed;

	public:
		Form();
		virtual ~Form();
		Form(const std::string name, const int gradeToSign, const int gradeToX);
		int getGradeToSign();
		int getGradeToX();
		bool isSigned();
		void beSigned(Bureaucrat &b);
		Form &operator=(Form &b);
		Form(Form &b);
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

std::ostream &operator<<(std::ostream &out, Form &b);