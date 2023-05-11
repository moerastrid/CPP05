/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 14:56:19 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 21:06:25 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <unistd.h>

void	RobotomyRequestForm::message(std::string	str) const {
	//std::cout << "\033[1;36m" << "RobotomyRequestForm - " << str << "\033[0m" << std::endl;
	(void)str;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	message("default constructor");
}

RobotomyRequestForm::~RobotomyRequestForm() {
	message("default destructor");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src) {
	message("copy constructor");
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	message("'=' sign constructor");
	(void)src;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	int mytime = time(NULL);
	message("constructor with attribute 'string'");
	for (int i(0); i < 3; i++) {
		std::cout << "\033[1;31m"  << "brrr ..." << "\033[0m" << std::endl;
		sleep(1);
	}
	if (mytime % 2 == false)
		std::cout << "\033[1;31m" << target << " has been robotomized successfully" << "\033[0m" << std::endl;
	else
		std::cout << "\033[1;31m" << "The robotomy failed" << "\033[0m" << std::endl;
}

std::string	RobotomyRequestForm::getType(void) {
	return ("RobotomyRequestForm");
}