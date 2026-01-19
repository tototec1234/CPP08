/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/20 00:12:05 by torinoue         ###   ########.fr       */
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

/* ************************************************************************** */
// イテレータの範囲外アクセスについて
// 
// MutantStackはstd::stackを継承し、内部コンテナ（std::deque）のイテレータを
// そのまま使用しています。標準ライブラリのイテレータは、範囲外アクセスに対して
// 未定義動作（Undefined Behavior）を許容する設計です。
// 
// これはC++標準の仕様であり、実装側で範囲チェックを行う義務はありません。
// 
// 1. 課題書の要件範囲内
//    - 課題書は「イテレータを追加機能として提供」することのみを要求
//    - 範囲チェック機能の実装は要件に含まれていない
//    - 課題書のテスト例でも範囲外アクセスの防止は実装されていない
//    - 課題書のテスト例では、while (it != ite)という条件チェックのみが使用されている
// 
// 2. 標準ライブラリの設計思想
//    - 標準ライブラリのイテレータは、パフォーマンスを優先し、
//      範囲チェックのオーバーヘッドを避ける設計
//    - std::vector、std::deque、std::listなど、すべての標準コンテナのイテレータも
//      同様に範囲外アクセスをチェックしない
//    - MutantStackが標準ライブラリの動作に準拠することは、要件を満たしている
// 
// 3. 使用時の注意
//    - イテレータを使用する際は、必ず begin() から end() の範囲内で操作すること
//    - while (it != ite) のような条件チェックを適切に使用すること
//    - 範囲外アクセスは未定義動作を引き起こす可能性がある
// 
// 参考:
// - ISO/IEC 14882:2003, Iterator requirements
// - cppreference.com: Iterator invalidation rules
/* ************************************************************************** */

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
