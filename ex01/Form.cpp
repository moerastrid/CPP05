/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 16:55:02 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 11:27:20 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	Form::message(std::string	str) {
	std::cout << "\033[1;34m" << "Form - " << str << "\033[0m" << std::endl;
}

Form::Form(void) : _name(""), _signGrade(150), _execGrade(150) {
	_isSigned = false;
	message("default constructor");
}

Form::~Form(void) {
	message("default destructor");
}

Form::Form(const Form &src) : _signGrade(src._signGrade), _execGrade(src._execGrade) {
	message("copy constructor");
	*this = src;
}

Form	&Form::operator=(const Form &src) {
	message("'=' sign operator");
	_isSigned = src._isSigned;
	return (*this);
}

Form::Form(std::string str, const int signGrade, const int execGrade) : _name(str), _signGrade(signGrade), _execGrade(execGrade) {
	_isSigned = false;
	message("constructor with name, signGrade, execGrade");
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

std::string	Form::getName(void) const {
	return (_name);
}

bool	Form::getIsSigned(void) const {
	return (_isSigned);
}

int	Form::getSignGrade(void) const {
	return (_signGrade);
}

int	Form::getExecGrade(void) const {
	return (_execGrade);
}

void	Form::beSigned(Bureaucrat	bureaucrat) {
	if	(bureaucrat.getGrade() <= this->getSignGrade())
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char * Form::GradeTooHighException::what() const throw() {
	return ("Grade exception : too high");
}

const char * Form::GradeTooLowException::what() const throw() {
	return ("Grade exception : too low");
}

std::ostream	&operator<<(std::ostream &o, Form const &i) {
	o << i.getName() << ", form status: ";
	if (i.getIsSigned() == true)
		o << "signed! ";
	else
		o << "unsigned! ";
	o << "With sign grade : " << i.getSignGrade() << " and exec grade : " << i.getExecGrade();
	return (o);
}
