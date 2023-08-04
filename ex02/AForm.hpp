#pragma once
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm{
	protected:
		std::string const _name;
		int const _gradeToSign;
		int const _gradeToX;
		bool _signed;
	public:
		AForm();
		virtual ~AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToX);
		int getGradeToSign();
		int getGradeToX();
		bool isSigned();
		void beSigned(Bureaucrat &b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		AForm &operator=(AForm &b);
		AForm(AForm &b);
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

std::ostream &operator<<(std::ostream &out, AForm &b);
