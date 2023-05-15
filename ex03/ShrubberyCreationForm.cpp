/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 14:56:36 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/15 13:45:44 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::message(std::string	str) const {
	std::cout << "\033[1;35m" << "ShrubberyCreationForm - " << str << "\033[0m" << std::endl;
	//(void)str;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
	message("default constructor");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	message("default destructor");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {
	message("copy constructor");
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	message("'=' sign constructor");
	(void)src;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
	message("constructor with attribute 'string'");
	std::string	filename = target;
	filename.append("_shrubbery");
	std::ofstream MyFile(filename, std::ios::trunc);
	MyFile << "ASCII trees" << std::endl;
	MyFile.close();
}

std::string	ShrubberyCreationForm::getType(void) {
	return ("ShrubberyCreationForm");
}