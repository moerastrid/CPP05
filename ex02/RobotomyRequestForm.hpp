/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 16:56:24 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 20:37:46 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private :
		RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &src);
		void	message(std::string str) const;

	public :
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		std::string	getType(void);
};

#endif