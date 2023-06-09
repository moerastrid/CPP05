/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:21:52 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/15 13:51:19 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <iostream>

void	errorMessage(std::string	str) {
	std::cout << "\033[1;31m" << "Error - " << str << "\033[0m" << std::endl;
}

//int	bureaucratTestTooHigh(void) {
//	try {
//		Bureaucrat A("A++", 3);
//		A.incrementGrade(1);
//		std::cout << A << std::endl;
//		A.incrementGrade(3);
//		std::cout << A << std::endl;
//	}
//	catch (Bureaucrat::GradeTooHighException &e) {
//		errorMessage(e.what());
//		return (1);
//	} 
//	catch (Bureaucrat::GradeTooLowException &e) {
//		errorMessage(e.what());
//		return (1);
//	}
//	return (0);
//}

//int	bureaucratTestTooLow(void) {
//	try {
//		Bureaucrat Jerry("Jerry", 100);
//		std::cout << Jerry << std::endl;
//		Jerry.incrementGrade(20);
//		std::cout << Jerry << std::endl;
//		Jerry.decrementGrade(200);
//		std::cout << Jerry << std::endl;
//	}
//	catch (Bureaucrat::GradeTooHighException &e) {
//		errorMessage(e.what());
//		return (1);
//	} 
//	catch (Bureaucrat::GradeTooLowException &e) {
//		errorMessage(e.what());
//		return (1);
//	}
//	return (0);
//}

//int	bureaucratTestInvalidBureaucrat(void) {
//	try {
//		Bureaucrat Imposter("Izzy", 151);
//	}
//	catch (Bureaucrat::GradeTooHighException &e) {
//		errorMessage(e.what());
//		return (1);
//	} 
//	catch (Bureaucrat::GradeTooLowException &e) {
//		errorMessage(e.what());
//		return (1);
//	}
//	return (0);
//}

//int	AformTestException(void) {
//	try {
//		AForm monday("Monday", 120, 120);
//		AForm tuesday("Tuesday", 120, INT_MAX);
//		AForm wednesday("Wednesday", INT_MIN, 120);
//		std::cout << monday << std::endl;
//		std::cout << tuesday << std::endl;
//		std::cout << wednesday << std::endl;
//	}
//	catch (AForm::GradeTooHighException &e) {
//		errorMessage(e.what());
//		return (1);
//	} 
//	catch (AForm::GradeTooLowException &e) {
//		errorMessage(e.what());
//		return (1);
//	}
//	return (0);
//}

//int	signingAForms(void) {
//	try {
//		Bureaucrat SuperVisor("SuperVisor", 10);
//		Bureaucrat Jerry("Jerry", 100);
//		std::cout << Jerry << std::endl;
//		AForm monday("Monday", 90, 90);
//		AForm tuesday("Tuesday", 10, 90);
//		AForm wednesday("Wednesday", 90, 10);
//		std::cout << monday << std::endl;
//		std::cout << tuesday << std::endl;
//		std::cout << wednesday << std::endl;
//		Jerry.signAForm(&monday);
//		Jerry.signAForm(&tuesday);
//		SuperVisor.signAForm(&wednesday);
//		Jerry.incrementGrade(20);
//		Jerry.signAForm(&wednesday);
//		monday.beSigned(SuperVisor);
//		std::cout << monday << std::endl;
//		std::cout << tuesday << std::endl;
//		std::cout << wednesday << std::endl << std::endl;

//		AForm	*today = NULL;
//		today = &monday;
//		AForm	*tomorrow = &tuesday;
//		std::cout << *today << std::endl;
//		std::cout << *tomorrow << std::endl;
//		Jerry.signAForm(today);
//		Jerry.signAForm(tomorrow);
//	}
//	catch (Bureaucrat::GradeTooHighException &e) {
//		errorMessage(e.what());
//		return (1);
//	} 
//	catch (Bureaucrat::GradeTooLowException &e) {
//		errorMessage(e.what());
//		return (1);
//	}
//	catch (AForm::GradeTooHighException &e) {
//		errorMessage(e.what());
//		return (1);
//	} 
//	catch (AForm::GradeTooLowException &e) {
//		errorMessage(e.what());
//		return (1);
//	}
//	return (0);
//}

//int	moreForms(void) {
//	try {
//		Bureaucrat SuperVisor("SuperVisor", 100);
//		Bureaucrat Jerry("Jerry", 145);
//		ShrubberyCreationForm Shrubby("home");
//		RobotomyRequestForm Robby("The bureaucrat");
//		PresidentialPardonForm Perry("Your mom");
//		Jerry.executeForm(Shrubby);
//		Jerry.executeForm(Robby);
//		Jerry.executeForm(Perry);
//		Jerry.signAForm(&Shrubby);
//		Jerry.signAForm(&Robby);
//		Jerry.signAForm(&Perry);
//		Jerry.executeForm(Shrubby);
//		SuperVisor.executeForm(Shrubby);
//		SuperVisor.signAForm(&Robby);
//		SuperVisor.signAForm(&Perry);
//		Bureaucrat Pro("Pro", 20);
//		Pro.signAForm(&Robby);
//		Pro.signAForm(&Perry);
//		Jerry.executeForm(Robby);
//		Jerry.executeForm(Perry);
//		SuperVisor.executeForm(Robby);
//		SuperVisor.executeForm(Perry);
//		Pro.executeForm(Robby);
//		Pro.executeForm(Perry);
//		Bureaucrat Corine("Corine", 1);
//		Corine.executeForm(Perry);
//	}
//	catch (Bureaucrat::GradeTooHighException &e) {
//		errorMessage(e.what());
//		return (1);
//	} 
//	catch (Bureaucrat::GradeTooLowException &e) {
//		errorMessage(e.what());
//		return (1);
//	}
//	catch (AForm::GradeTooHighException &e) {
//		errorMessage(e.what());
//		return (1);
//	} 
//	catch (AForm::GradeTooLowException &e) {
//		errorMessage(e.what());
//		return (1);
//	}
//	return (0);
//}

int	the_intern(void) {
	Intern someRandomIntern;
	AForm* forms[10];

	delete (int *)NULL;
	for (int i(0); i < 10; i++)
	{
		if (i % 5 == 0)
			forms[i] = someRandomIntern.makeForm("shrubbery creation", "Little robot");
		else if (i % 3 == 0)
			forms[i] = someRandomIntern.makeForm("robotomy request", "The bureaucrat");
		else if (i % 2 == 0)
			forms[i] = someRandomIntern.makeForm("presidental request", "Sir President");
		else
			forms[i] = someRandomIntern.makeForm("shrubbery creation", "the intern");
	}
	for (int i(0); forms[i]; i++)
		delete forms[i];
	return (0);
}

int	main(void) {
	//std::cout << std::endl;
	//bureaucratTestTooHigh();
	//std::cout << std::endl;
	//bureaucratTestTooLow();
	//std::cout << std::endl;
	//bureaucratTestInvalidBureaucrat();
	//std::cout << std::endl;
	//AformTestException();
	//std::cout << std::endl;
	//signingAForms();
	//std::cout << std::endl;
	//moreForms();
	std::cout << std::endl;
	the_intern();
	std::cout << std::endl;
	return (0);
}
