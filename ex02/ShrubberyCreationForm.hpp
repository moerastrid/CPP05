/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 16:56:24 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 21:11:20 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private :
		ShrubberyCreationForm(void);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);
		void	message(std::string str) const;

	public :
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		std::string	getType(void);
};

#endif