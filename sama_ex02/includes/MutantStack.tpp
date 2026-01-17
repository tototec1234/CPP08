#include "MutantStack.hpp"

/* ************************************************************************** */
template<typename T>
MutantStack<T>::MutantStack()
{
    std::cout << "Default Constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& src)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& src)
{
    std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &src)
		this->c = src.c;
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
//std::stackは「protected」メンバーとして内部コンテナをcという名前で保持しているぞ！ // https://cpprefjp.github.io/reference/stack/stack.html
//　つまり、継承により派生クラスからアクセス可能だああああ!!!!!!!
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

/* ************************************************************************** */
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}
