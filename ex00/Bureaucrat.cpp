/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:21:26 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/09 12:52:37 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	Bureaucrat::message(std::string	str) {
	std::cout << "\033[1;33m" << "Bureaucrat - " << str << "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(void) : _name(""), _grade(150) {
	message("default constructor");
}

Bureaucrat::~Bureaucrat(void) {
	message("default destructor");
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	message("copy destructor");
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	message("'=' sign operator");
	//_name = src.getName();
	_grade = src.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {
	message("constructur with argument 'name'");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	message("constructur with argument 'name' & 'grade'");
	if (grade > 0 && grade <= 150)
		_grade = grade;
	// else : TODO exception
}

std::string	Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}