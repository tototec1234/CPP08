/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:35:11 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/20 00:11:39 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

// classes
class NoOccurrenceFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Value not found in container";
		}
};

// テンプレート関数の宣言
template <typename T>
typename T::iterator easyfind(T &container, int value);

// テンプレート実装を.tppファイルからインクルード
# include "easyfind.tpp"

#endif

/*
https://learn.microsoft.com/ja-jp/cpp/cpp/typename?view=msvc-170



https://zenn.dev/rt3mis10/articles/2e08c6c50d8a46
*/
