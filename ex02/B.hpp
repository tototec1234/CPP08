/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/07 23:43:35 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

// classes
class Bureaucrat
{
	public:
		/* Constructors & Destructors */
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

	// Overloaded operator
		Bureaucrat& operator=(const Bureaucrat& other);
		
	// Public Methods
		/* Getters */
		const std::string& getName() const;
		int getGrade() const;
		/* functions*/
		void incrementGrade(void);
		void decrementGrade(void);

	//Exceptions
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
	
	private:
		static const int 	HighestGrade	= 1;
		static const int 	LowestGrade		= 150;
		const std::string	_name;
		int 				_grade;
};

// ostream Overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif

/*
Please note that exception classes do not have to be designed in
Orthodox Canonical Form. However, every other class must follow it.
*/

/*
First, start with the smallest cog in this vast bureaucratic machine: the Bureaucrat.
A Bureaucrat must have:
•A constant name.
•A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
Any attempt to instantiate a Bureaucrat with an invalid grade must throw an excep-
tion:
either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

*/

