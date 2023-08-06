#pragma once
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form{
	private:
		std::string const _name;
		int const _gradeToSign;
		int const _gradeToX;
		bool _signed;
	public:
		Form();
		virtual ~Form();
		Form(const std::string name, const int gradeToSign, const int gradeToX);
		int getGradeToSign() const;
		int getGradeToX() const;
		bool isSigned() const ;
		void beSigned(const Bureaucrat &b);
//		void setName(const std::string name);
//		void setGradeToSign(const int gts);
//		void setGradeToX(const int gtx);
//		void setSigned(bool b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		Form &operator=(const Form &b);
		Form(const Form &b);
		const std::string getName() const;
		class GradeTooLowException: public std::exception{
		public:
			const char * what () const throw(){return "GradeTooLowException";}};
		class GradeTooHighException: public std::exception{
		public:
			const char * what () const throw(){return "GradeTooHighException";}};
	class FormNotSignedException: public std::exception{
	public:
		const char * what () const throw(){return "FormNotSignedException";}};
};

std::ostream &operator<<(std::ostream &out, const Form &b);
