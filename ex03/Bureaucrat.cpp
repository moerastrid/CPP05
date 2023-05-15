/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:21:26 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/15 13:37:50 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	Bureaucrat::message(std::string	str) const {
	std::cout << "\033[1;33m" << "Bureaucrat - " << str << "\033[0m" << std::endl;
	//(void)str;
}

Bureaucrat::Bureaucrat(void) : _name(""), _grade(150) {
	message("default constructor");
}

Bureaucrat::~Bureaucrat(void) {
	message("default destructor");
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	message("copy constructor");
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	message("'=' sign operator");
	_grade = src.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	message("constructur with argument 'name' & 'grade'");
	this->setGrade(grade);
}

std::string	Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

void	Bureaucrat::setGrade(int grade) {
	message("set grade called");
	if (grade > 0 && grade <= 150)
		_grade = grade;
	else if (grade <= 0)
		throw GradeTooHighException();
	else
		throw GradeTooLowException();
}

void	Bureaucrat::incrementGrade(int n) {
	message("increment grade called");
	this->setGrade(this->getGrade() - n);
}

void	Bureaucrat::decrementGrade(int n) {
	message("decrement grade called");
	this->setGrade(this->getGrade() + n);
}

void	Bureaucrat::signAForm(AForm *aform) {
	try {
		if (aform->getIsSigned() == true)
		{
			std::cout << this->getName() << " couldn't sign " << aform->getName();
			std::cout << " because it's already signed!" << std::endl;
			return ;
		}
		aform->beSigned(*this);
		if (aform->getIsSigned() == true)
			std::cout << this->getName() << " signed " << aform->getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << this->getName() << " couldn't sign " << aform->getName();
		std::cout << " because their grade is too low!" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &aform) {
	try {
		aform.execute(*this);
	} catch (AForm::GradeTooLowException &e) {
		std::cout << this->getName() << " couldn't execute " << aform.getName();
		std::cout << " because their grade is too low!" << std::endl;
		return ;
	} catch (AForm::FormNotSignedException &e) {
		std::cout << this->getName() << " couldn't execute " << aform.getName();
		std::cout << " because the form is not signed!" << std::endl;
		return ;
	}
	std::cout << this->getName() << " executed " << aform.getName() << std::endl;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade exception : too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade exception : too low");
}


std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return (o);
}