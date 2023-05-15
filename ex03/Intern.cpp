/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 21:55:52 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/15 13:50:04 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	Intern::message(std::string str) {
	std::cout << "\033[1;32m" << "Intern - " << str << "\033[0m" << std::endl;
}

Intern::Intern() {
	message("default constructor");
}

Intern::~Intern() {
	message("default destructor");
}

Intern::Intern(const Intern &src) {
	message("copy constructor");
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	(void)src;
	return (*this);
}

AForm *Intern::makeForm(std::string formType, std::string	target) {
	std::string types[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	if (target.empty() == true)
	{
		std::cerr << "An explicit error message!" << std::endl;
		return (NULL);
	}	
	for (int i(0); i < 3; i++) {
		if (formType.compare(types[i]) == 0)
		{
			switch (i)
			{
				case 0 : 
					std::cout << "\033[1;32m" << "Intern creates " << types[i] << "\033[0m" << std::endl;
					return (new PresidentialPardonForm(target));
				case 1 : 
					std::cout << "\033[1;32m" << "Intern creates " << types[i] << "\033[0m" << std::endl;
					return (new RobotomyRequestForm(target));
				case 2 :
					std::cout << "\033[1;32m" << "Intern creates " << types[i] << "\033[0m" << std::endl;
					return (new ShrubberyCreationForm(target));
			}
		}
	}
	std::cerr << "An explicit error message!" << std::endl;
	return (NULL);
}
