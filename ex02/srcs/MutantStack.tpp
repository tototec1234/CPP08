/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/19 14:44:44 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& src) : std::stack<T>(src){}

template<typename T>
MutantStack<T>::~MutantStack(){}

/* ************************************************************************** */	
// Overloaded operator
/* ************************************************************************** */	
template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src){
	if (this != &src)
	{
		// std::stackの保護メンバc（内部コンテナ）にアクセス
		// 継承により派生クラスからアクセス可能
		// 注: 'c'はC++標準規格（ISO/IEC 14882:2003, 23.2.2.4）で規定された名前
		// containerの略で、コンテナアダプタの内部コンテナを表す
		this->c = src.c;
	}
	return *this;
}
/* ************************************************************************** */	
// Public Methods
/* ******************** Iterator functions  ************************************************ */
// std::stackは保護メンバとして内部コンテナcを保持
// 継承により派生クラスからアクセス可能
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const{
	// 重要：cをconst参照としてキャストすることで、const_iteratorが確実に返される
	return static_cast<const typename std::stack<T>::container_type&>(this->c).begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const{
	return static_cast<const typename std::stack<T>::container_type&>(this->c).end();
}

/* ******************** Reverse iterator functions  ************************************************ */
template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(){
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const{
	return static_cast<const typename std::stack<T>::container_type&>(this->c).rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(){
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const{
	return static_cast<const typename std::stack<T>::container_type&>(this->c).rend();
}

/* ************************************************************************** */
// デバッグ用メソッドの実装
/* ************************************************************************** */
template<typename T>
void MutantStack<T>::printContents() const{
	if (this->c.empty())
	{
		std::cout << "empty stack" << std::endl;
		return;
	}
	for (typename std::stack<T>::container_type::size_type i = 0; i < this->c.size(); ++i)
		std::cout << "[" << this->c.at(i) << "] ";
	std::cout << std::endl;
}

/* ************************************************************************** */
// std::stackの保護メンバcについて
// 
// 'c'はC++標準規格（ISO/IEC 14882）で明示的に規定された名前です。
// - 標準規格: ISO/IEC 14882:2003 (C++98/C++03)
// - セクション: 23.2.2.4 Container adaptors
// - 規定: std::stackはprotectedメンバとして'c'という名前の内部コンテナを持つ
// 
// これは実装依存ではなく、標準で規定された名前のため、
// すべての標準準拠の実装で同じ名前が使用されます。
// 
// 参考:
// - cppreference.com: https://en.cppreference.com/w/cpp/container/stack
// - ISO/IEC 14882:2003, Section 23.2.2.4
/* ************************************************************************** */
