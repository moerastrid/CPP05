/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:25:20 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/11 14:04:31 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
	private :
		const std::string	_name;
		int					_grade;
		Bureaucrat(void);								//default constructor

		void	message(std::string str);

	public :
		~Bureaucrat(void);								//default destructor
		Bureaucrat(const Bureaucrat &src);				//copy constructor
		Bureaucrat &operator=(const Bureaucrat &src);	// '=' sign operator
		Bureaucrat(std::string name, int grade);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		setGrade(int n);
		void		incrementGrade(int n);
		void		decrementGrade(int n);

		void		signForm(Form *form);

		class GradeTooHighException : public std::exception {
			public :
				virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char * what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i);

#endif