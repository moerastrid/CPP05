/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 14:55:49 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/15 13:45:30 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::message(std::string	str) const {
	std::cout << "\033[1;34m" << "PresidentialPardonForm - " << str << "\033[0m" << std::endl;
	//(void)str;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	message("default constructor");
}

PresidentialPardonForm::~PresidentialPardonForm() {
	message("default destructor");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src) {
	message("copy constructor");
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	message("'=' sign constructor");
	(void)src;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	(void)target;
	message("constructor with attribute 'string'");
	std::cout << "\033[1;31m"  << target << " has been pardoned by Zaphod Beeblebrox" << "\033[0m" << std::endl;
}

std::string	PresidentialPardonForm::getType(void) {
	return ("PresidentialPardonForm");
}