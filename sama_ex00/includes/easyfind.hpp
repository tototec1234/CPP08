#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>

//typenameはコンパイラに「変数ではなく型であること」を伝えるためにある。
class NoOccurrenceFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("No Occurrence Found");
		}
};

/* ************************************************************************** */
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator found = std::find(container.begin(), container.end(), value);
    if (found == container.end())
        throw NoOccurrenceFoundException();
    return found; // ← 見つかった「位置」を指すイテレータを返す
}

//機能的差異: テンプレートパラメータではclassとtypenameは全く同じ意味を持つ。　"template <class T>"=="template <typename T>"
// 歴史: classが先、typenameが後から追加
// 推奨: 現代ではtypenameを使う方が一般的
// 理由: 意味が明確で、一貫性があるため
#endif