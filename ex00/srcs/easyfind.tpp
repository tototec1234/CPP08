/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:35:11 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/20 00:14:47 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>

// テンプレート関数の実装
template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator found = std::find(container.begin(), container.end(), value);
	if (found == container.end())
		throw NoOccurrenceFoundException();
	return found;
}
