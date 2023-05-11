/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:21:52 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 11:33:13 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

void	errorMessage(std::string	str) {
	std::cout << "\033[1;31m" << "Error - " << str << "\033[0m" << std::endl;
}

int	bureaucratTestTooHigh(void) {
	try {
		Bureaucrat A("A++", 3);
		A.incrementGrade(1);
		std::cout << A << std::endl;
		A.incrementGrade(3);
		std::cout << A << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		errorMessage(e.what());
		return (1);
	} 
	catch (Bureaucrat::GradeTooLowException &e) {
		errorMessage(e.what());
		return (1);
	}
	return (0);
}

int	bureaucratTestTooLow(void) {
	try {
		Bureaucrat Jerry("Jerry", 100);
		std::cout << Jerry << std::endl;
		Jerry.incrementGrade(20);
		std::cout << Jerry << std::endl;
		Jerry.decrementGrade(200);
		std::cout << Jerry << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		errorMessage(e.what());
		return (1);
	} 
	catch (Bureaucrat::GradeTooLowException &e) {
		errorMessage(e.what());
		return (1);
	}
	return (0);
}

int	bureaucratTestInvalidBureaucrat(void) {
	try {
		Bureaucrat Imposter("Izzy", 151);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		errorMessage(e.what());
		return (1);
	} 
	catch (Bureaucrat::GradeTooLowException &e) {
		errorMessage(e.what());
		return (1);
	}
	return (0);
}

int	formTestException(void) {
	try {
		Form monday("Monday", 120, 120);
		Form tuesday("Tuesday", 120, 1);
		Form wednesday("Wednesday", -1, 120);
		std::cout << monday << std::endl;
		std::cout << tuesday << std::endl;
		std::cout << wednesday << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		errorMessage(e.what());
		return (1);
	} 
	catch (Bureaucrat::GradeTooLowException &e) {
		errorMessage(e.what());
		return (1);
	}
	return (0);
}

int	main(void) {
	std::cout << std::endl;
	bureaucratTestTooHigh();
	std::cout << std::endl;
	bureaucratTestTooLow();
	std::cout << std::endl;
	bureaucratTestInvalidBureaucrat();
	std::cout << std::endl;
	formTestException();
	std::cout << std::endl;
	return (0);
}
