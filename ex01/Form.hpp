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
		~Form();
		Form(const std::string name, const int gradeToSign, const int gradeToX);
		Form &operator=(const Form &b);
		Form(const Form &b);

		const std::string getName() const;
		int getGradeToSign() const;
		int getGradeToX() const;
		bool isSigned() const;

		void beSigned(const Bureaucrat &b);



		class GradeTooLowException: public std::exception{
		public:
			const char * what () const throw(){return "GradeTooLowException";}
		};
		class GradeTooHighException: public std::exception{
		public:
			const char * what () const throw() {return "GradeTooHighException";}
		};
};

std::ostream &operator<<(std::ostream &out, const Form &b);