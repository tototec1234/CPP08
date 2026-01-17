#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <exception>
#include <vector>
#include <list>
#include <deque>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <cstddef>
#include <cctype>
#include <string>
#include <limits>
#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>//public継承により、std::stackの全ての公開メンバー関数（push、pop、top、size、empty等）がMutantStackでも利用可能になるぞい！ // https://cpprefjp.github.io/reference/stack/stack.html

{
public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack& src);
	MutantStack<T>& operator=(const MutantStack<T>& src);
	
	//std::stackは内部的に他のコンテナ（デフォルトではstd::deque）を使用しており、その型をcontainer_typeとして公開しています。
	typedef typename std::stack<T>::container_type::iterator iterator;// その内部コンテナのイテレータ型
	//　今の「iteratorの意味って？」
	// 「std::stack<T> が内部で使っているコンテナ container_type （つまりstd::deque<T>）」が持っているイテレータを、 iterator という型名 (typename)で使えるようにしているということ。
	//つまり？　→ iteratorは内部コンテナのイテレータ！

	iterator begin();
	iterator end();
};

# include "MutantStack.tpp"

#endif