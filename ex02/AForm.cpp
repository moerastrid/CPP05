/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 16:55:02 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 13:54:29 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void	AForm::message(std::string	str) {
	std::cout << "\033[1;34m" << "AForm - " << str << "\033[0m" << std::endl;
}

AForm::AForm(void) : _name(""), _signGrade(150), _execGrade(150) {
	_isSigned = false;
	message("default constructor");
}

AForm::~AForm(void) {
	message("default destructor");
}

AForm::AForm(const AForm &src) : _signGrade(src._signGrade), _execGrade(src._execGrade) {
	message("copy constructor");
	*this = src;
}

AForm	&AForm::operator=(const AForm &src) {
	message("'=' sign operator");
	_isSigned = src._isSigned;
	return (*this);
}

AForm::AForm(std::string str, const int signGrade, const int execGrade) : _name(str), _signGrade(signGrade), _execGrade(execGrade) {
	_isSigned = false;
	message("constructor with name, signGrade, execGrade");
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

std::string	AForm::getName(void) const {
	return (_name);
}

bool	AForm::getIsSigned(void) const {
	return (_isSigned);
}

int	AForm::getSignGrade(void) const {
	return (_signGrade);
}

int	AForm::getExecGrade(void) const {
	return (_execGrade);
}

void	AForm::beSigned(Bureaucrat	&bureaucrat) {
	message("be signed called");
	if	(bureaucrat.getGrade() <= this->getSignGrade())
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char * AForm::GradeTooHighException::what() const throw() {
	return ("Grade exception : too high");
}

const char * AForm::GradeTooLowException::what() const throw() {
	return ("Grade exception : too low");
}

std::ostream	&operator<<(std::ostream &o, AForm const &i) {
	o << i.getName() << ", Aform status: ";
	if (i.getIsSigned() == true)
		o << "signed! ";
	else
		o << "unsigned! ";
	o << "With sign grade : " << i.getSignGrade() << " and exec grade : " << i.getExecGrade();
	return (o);
}
