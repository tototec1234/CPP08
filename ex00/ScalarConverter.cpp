/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/07 23:43:30 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AnsiColor.hpp"
#include <sstream>

Bureaucrat::Bureaucrat()
	: _name("default"), _grade(LowestGrade) {
	std::cout << GREEN_COLOR << "Bureaucrat default constructor called" << RESET_COLOR << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade) {
	if (grade < HighestGrade)
		throw GradeTooHighException();
	if (grade > LowestGrade)
		throw GradeTooLowException();
	std::cout << GREEN_COLOR << "Bureaucrat created: " << _name 
		<< " (grade " << _grade << ")" << RESET_COLOR << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {
	std::cout << GREEN_COLOR << "Bureaucrat copy constructor called" << RESET_COLOR << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED_COLOR << "Bureaucrat destroyed: " << _name << RESET_COLOR << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= HighestGrade)
		throw GradeTooHighException();
	_grade--;
	std::cout << GREEN_COLOR << "Bureaucrat grade incremented: " << _name 
		<< " (grade " << _grade << ")" << RESET_COLOR << std::endl;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= LowestGrade)
		throw GradeTooLowException();
	_grade++;
	std::cout << GREEN_COLOR << "Bureaucrat grade decremented: " << _name 
		<< " (grade " << _grade << ")" << RESET_COLOR << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	static std::string message;
	if (message.empty()) {
		std::ostringstream oss;
		oss << "Grade is too high (must be >= " << Bureaucrat::HighestGrade << ")";
		message = oss.str();
	}
	return message.c_str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	static std::string message;
	if (message.empty()) {
		std::ostringstream oss;
		oss << "Grade is too low (must be <= " << Bureaucrat::LowestGrade << ")";
		message = oss.str();
	}
	return message.c_str();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

/*
https://cplusplus.com/reference/exception/exception/
*/

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

