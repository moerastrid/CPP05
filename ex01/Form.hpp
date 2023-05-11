/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 16:48:47 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 11:25:45 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
		Form(void);							//default constructor

		void	message(std::string str);

	public :
		~Form(void);						//default destructor
		Form(const Form &src);				//copy constructor
		Form &operator=(const Form &src);	//'=' sign operator
		Form(std::string str, int signGrade, int execGrade);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;

		void		beSigned(Bureaucrat	bureaucrat);

		class GradeTooHighException : public std::exception {
			public :
				virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char * what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Form const &i);

#endif