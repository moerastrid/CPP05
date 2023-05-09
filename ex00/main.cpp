/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:21:52 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/09 16:45:39 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return (o);
}

void	errorMessage(std::string	str) {
	std::cout << "\033[1;31m" << "Bureaucrat - " << str << "\033[0m" << std::endl;
}

int	test_too_high(void) {
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

int	test_too_low(void) {
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

int	test_invalid_bureaucrat(void) {
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

int	main(void) {
	test_too_high();
	test_too_low();
	test_invalid_bureaucrat();
	return (0);
}
