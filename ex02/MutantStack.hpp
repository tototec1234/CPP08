/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:35:11 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/18 23:05:14 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

/**
 * @brief MutantStack - std::stackをイテレート可能にしたコンテナアダプタ
 * 
 * std::stackはLIFO（後入先出）のデータ構造を提供するが、イテレータを提供しない。
 * このクラスはstd::stackを継承し、イテレータ機能を追加する。
 * 
 * 課題要件:
 * - std::stackを基に実装
 * - すべてのメンバ関数を提供（継承により自動提供）
 * - イテレータを追加機能として提供
 */
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();	//std::stack のデフォルトコンストラクタが呼び出される
		MutantStack(const MutantStack& src);
		~MutantStack();
		
		MutantStack& operator=(const MutantStack& src);

		//	  std::stackの内部コンテナ（デフォルトはstd::deque）のイテレータ型
		typedef typename std::stack<T>::container_type::iterator iterator;
			
}

#endif

/*
https://learn.microsoft.com/ja-jp/cpp/cpp/typename?view=msvc-170



https://zenn.dev/rt3mis10/articles/2e08c6c50d8a46
*/
