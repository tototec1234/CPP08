/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:35:11 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/17 23:49:37 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <sstream>
#include <stdexcept>

class NoOccurrenceFoundException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Value not found in container";
	}
};

template <typename T>


typename T::iterator easyfind(T &container, int value){
	typename T::iterator found = std::find(container.begin(), container.end(), value);
		if (found == container.end())
			throw NoOccurrenceFoundException();
	return found;
}


#endif

/*
https://learn.microsoft.com/ja-jp/cpp/cpp/typename?view=msvc-170



https://zenn.dev/rt3mis10/articles/2e08c6c50d8a46
*/
