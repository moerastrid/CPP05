/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:21:52 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/09 12:52:59 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return (o);
}

int	main(void) {
	Bureaucrat Jerry("Jerry");
	std::cout << Jerry << std::endl;
	return (0);
}