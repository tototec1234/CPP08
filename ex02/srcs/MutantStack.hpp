/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/20 00:12:03 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

// MutantStack - std::stackをイテレート可能にしたコンテナアダプタ
// std::stackはLIFO（後入先出）のデータ構造を提供するが、イテレータを提供しない。
// このクラスはstd::stackを継承し、イテレータ機能を追加する。
// 課題要件:
// - std::stackを基に実装
// - すべてのメンバ関数を提供（継承により自動提供）
// - イテレータを追加機能として提供
template<typename T>
class MutantStack : public std::stack<T>
{
public:
	
	MutantStack();
	MutantStack(const MutantStack& src);
	
	~MutantStack();
	// Overloaded operator	
	MutantStack& operator=(const MutantStack& src);

	// Public Methods
	
	// Iterator types
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	// Iterator functions
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

	// Reverse iterator functions
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;
};

// テンプレート実装を.tppファイルからインクルード
#include "MutantStack.tpp"

#endif
