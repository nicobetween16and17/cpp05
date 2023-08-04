#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat("jerry", 151);
	}
	catch (std::exception &e)
	{
		e.what();
	}
	try
	{
		Bureaucrat("Leeroy Jenkins", 85);
	}
	catch (std::exception &e)
	{
		e.what();
	}
	try
	{
		Bureaucrat("Kyllian Mbappe", 0);
	}
	catch (std::exception &e)
	{
		e.what();
	}
}