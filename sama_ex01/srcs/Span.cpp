#include "../includes/Span.hpp"

/* ************************************************************************** */
Span::Span(unsigned int n) : _N(n) {}

Span::~Span(){}

Span::Span(const Span& src)
{
	*this = src;
}
Span& Span::operator=(const Span& src)
{
	if (this != &src)
	{
		this->_N = src._N;
		this->_vec = src._vec;
	}
	return (*this);
}

/* ************************************************************************** */
void Span::addNumber(int x)
{
	
	if (this->_vec.size() >= this->_N)
		throw std::out_of_range("ERROR : Span vector already full");
	this->_vec.push_back(x);
}

/* ************************************************************************** */
int Span::shortestSpan() const
{
	if (_vec.empty() || _vec.size() == 1)
		throw std::out_of_range("ERROR : Span vector has less than 2 values");
	
	std::vector<int>	tempvec = _vec;
	std::sort(tempvec.begin(), tempvec.end());
	int minspan = std::numeric_limits<int>::max();// INTMAX
	for (size_t i = 0; i < _vec.size() - 1; ++i)
	{
		int tempspan = tempvec[i + 1] - tempvec[i];
		if (tempspan < minspan)
			minspan = tempspan;
	}
	return (minspan);
}

/* ************************************************************************** */
int Span::longestSpan() const
{
	if (_vec.empty() || _vec.size() == 1)
		throw std::out_of_range("ERROR : Span vector has less than 2 values");
	std::vector<int>::const_iterator maxIt = std::max_element(_vec.begin(), _vec.end());
	std::vector<int>::const_iterator minIt = std::min_element(_vec.begin(), _vec.end());
	return (*maxIt - *minIt);
}

/* ************************************************************************** */
void Span::printVector() const
{
	if (_vec.empty())
	{
		std::cout << "empty vector \n";
		return;
	}
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << "[" << _vec[i] <<"] ";
	std::cout << std::endl;
}

/* ************************************************************************** */
void Span::multipleAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vec.size() + std::distance(begin, end) > this->_N)
		throw std::out_of_range("ERROR : Range Filling would outgrow the Span instance");
	this->_vec.insert(_vec.begin(), begin, end);
}
