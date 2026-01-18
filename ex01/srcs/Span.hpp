/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/19 06:03:02 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <vector>

// classes
class Span
{
	private:
		std::vector<int>	_vec;
		unsigned int N;
	public:
		Span(unsigned int n);
		Span(const Span& src);
		~Span();

		// Overloaded operator
		Span& operator=(const Span& other);
			
		// Public Methods
			/* Getters */
		void addNumber(int x);
		int shortestSpan() const;
		int longestSpan() const;
		void addRange(	std::vector<int>::iterator begin,
						std::vector<int>::iterator end);
		// デバッグ用：constメソッドで状態を変更しない。他のメソッドからは呼び出されておらず補助関数にはなっていない
		void printContents() const;
		
};

#endif


/*

Develop a Span class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.
*/

/*
  This class will have a member function called addNumber() to add a single number
to the Span.
 It will be used in order to fill it.
  Any attempt to add a new element if there are already N elements stored should throw an exception.
*/

/*
Next, implement two member functions: shortestSpan() and longestSpan()

*/

/*
Implement a member function
to add multiple numbers to your Span in a single call.
*/

