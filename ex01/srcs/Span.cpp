/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/19 04:43:16 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "AnsiColor.hpp"
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span& src){ *this = src;}

Span::~Span(){}
/* ************************************************************************** */	
// Overloaded operator
/* ************************************************************************** */	
Span& Span::operator=(const Span& other){
	if (this != &other)
	{
		this->N = other.N;
		this->_vec = other._vec;
	}
	return *this;
}

/* ************************************************************************** */	
// Public Methods
/* ******************** Getters  ************************************************ */
int Span::shortestSpan() const{
	if (_vec.size() < 2)
		throw std::out_of_range("ERROR : Span has less than 2 values");

	std::vector<int> sorted(_vec);
	std::sort(sorted.begin(), sorted.end());

	int minSpan;
	try {
		// at()を使用: 範囲チェックあり、防御的プログラミング
		minSpan = sorted.at(1) - sorted.at(0);
		// ループ内もat()を使用: すべてのアクセスを安全にする
		// for (size_t i = 2; i < sorted.size(); ++i)
		// 注意: -Wsign-compareでも警告は出ない（size_tもstd::vector<int>::size_typeも符号なし整数型）
		// std::vector<int>::size_typeを使う利点: 型の意図を明確にする
		for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i)
			minSpan = std::min(minSpan, sorted.at(i) - sorted.at(i - 1));
	} catch (const std::out_of_range& e) {
		/* 防御的プログラミング: 万が一のバグを検出（既にsizeチェック済みだが念のため）
		方法1: 再スロー（元の例外をそのまま保持）*/
		throw;
		/* 方法2: 新しい例外を投げる（より詳細なメッセージ）
			利点: より詳細なエラーメッセージを追加できる
			欠点: 
				- <stdexcept>ヘッダーのインクルードが必要
				- 例外型がstd::out_of_rangeからstd::runtime_errorに変わる（例外型情報が失われる）
				- std::stringの連結処理が発生する（パフォーマンスへの影響は微々たるもの） */
		// throw std::runtime_error("ERROR : Unexpected range error in shortstSpan() - " + std::string(e.what()));
	}
	return minSpan;
}

	/* ************************************************************************** */
int Span::longestSpan() const{
	if (_vec.size() < 2)
		throw std::out_of_range("ERROR : Span has less than 2 values");
	int maxValue = *std::max_element(_vec.begin(), _vec.end());
	int minValue = *std::min_element(_vec.begin(), _vec.end());
	return maxValue - minValue;
}
	/* ************************************************************************** */	
/* ******************** Setters  ************************************************ */
void Span::addNumber(int x){
	if (this->_vec.size() >= this->N)
		throw std::out_of_range("ERROR : Span already full");
	this->_vec.push_back(x);
}
	/* ************************************************************************** */
void Span::addRange(	std::vector<int>::iterator begin,
						std::vector<int>::iterator end){
	if (_vec.size() + std::distance(begin, end) > this->N)
		throw std::out_of_range("ERROR : Range filling would outgrow the Span instance");
	this->_vec.insert(_vec.begin(), begin, end);
}

/* ************************************************************************** */
// デバッグ用（レビュー時に必要に応じてコメントを外す）
void Span::printContents() const
{
	if (_vec.empty())
	{
		std::cout << RED_COLOR << "empty vector" << RESET_COLOR << std::endl;
		return;
	}
	for (std::vector<int>::size_type i = 0; i < _vec.size(); ++i)
		std::cout << MAGENTA_COLOR << "[" << _vec.at(i) << "]" << RESET_COLOR << " ";
	std::cout << std::endl;
}

/* ************************************************************************** */

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
