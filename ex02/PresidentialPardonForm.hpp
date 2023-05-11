/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 16:56:24 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 20:38:06 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private :
		PresidentialPardonForm(void);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);
		void	message(std::string str) const;

	public :
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		std::string	getType(void);
};

#endif