/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:35:11 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/17 22:05:42 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template <typename T>


template <class T>
class C1 : typename T::InnerType // Error - typename not allowed.
{};
template <class T>
class C2 : A<typename T::InnerType>  // typename OK.
{};


// void easyfind(T &first, int arg){
// 	T tmp = first;
// 	first = second;
// 	second = tmp;
// }

template <typename T>
const T& min(const T &first, const T &second){
	return first < second ? first : second;
}

template <typename T>
const T& max(const T &first, const T &second){
	return second < first ? first : second;
}

#endif

/*
https://learn.microsoft.com/ja-jp/cpp/cpp/typename?view=msvc-170



https://zenn.dev/rt3mis10/articles/2e08c6c50d8a46
*/