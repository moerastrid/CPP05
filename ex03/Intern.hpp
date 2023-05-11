/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 21:59:42 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 22:02:36 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class	Intern {
	private :
		
	public :
		Intern(void);							//defcon
		~Intern(void);							//defdes
		Intern(const Intern &src);				//copcon
		Intern &operator=(const Intern &src);	//=sgnop
		
		AForm *makeForm(std::string formType, std::string	target);
};

#endif