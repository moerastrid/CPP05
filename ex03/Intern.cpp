/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 21:55:52 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 22:38:20 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	(void)src;
	return (*this);
}

AForm *Intern::makeForm(std::string formType, std::string	target) {
	std::string types[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	
	for (int i(0); i < 3; i++) {
		if (formType.compare(types[i]) == 0)
		{
			switch (i)
			{
				case 0 : 
					return (new PresidentialPardonForm(target));
				case 1 : 
					return (new RobotomyRequestForm(target));
				case 2 :
					return (new ShrubberyCreationForm(target));
			}
		}
	}
	std::cerr << "An explicit error message!" << std::endl;
	return (NULL);
}
