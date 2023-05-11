/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 16:48:47 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 13:50:09 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
		AForm(void);						//default constructor
		AForm &operator=(const AForm &src);	//'=' sign operator

	protected :
		AForm(const AForm &src);				//copy constructor
		AForm(std::string str, int signGrade, int execGrade);
		virtual void	message(std::string str) const;

	public :
		virtual ~AForm(void);						//default destructor

		std::string			getName(void) const;
		bool				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		virtual std::string	getType(void) = 0;
		void				beSigned(Bureaucrat &signer);
		void				execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception {
			public :
				virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char * what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public :
				virtual const char * what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, AForm const &i);

#endif