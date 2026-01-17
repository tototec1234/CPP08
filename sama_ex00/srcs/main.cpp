#include "../includes/easyfind.hpp"

// https://atcoder.jp/contests/apg4b/tasks/APG4b_aa?lang=ja%EF%BC%89%E3%81%AF%E3%80%81STL%E3%82%B3%E3%83%B3%E3%83%86%E3%83%8A%E3%81%AE%E5%85%A5%E9%96%80%E3%81%A8%E3%81%97%E3%81%A6%E6%9C%80%E9%81%A9%E3%81%AA%E3%82%B5%E3%82%A4%E3%83%88%E3%81%A7%E3%81%99%E3%80%82%E3%80%8Cstack%E3%81%AF%E3%80%8E%E6%96%B0%E3%81%97%E3%81%8F%E8%BF%BD%E5%8A%A0%E3%81%97%E3%81%9F%E3%82%82%E3%81%AE%E3%81%BB%E3%81%A9%E5%85%88%E3%81%AB%E5%8F%96%E3%82%8A%E5%87%BA%E3%81%95%E3%82%8C%E3%82%8B%E3%80%8F%E3%82%88%E3%81%86%E3%81%AA%E5%87%A6%E7%90%86%E3%82%92%E8%A1%8C%E3%81%86%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0%E3%80%8D
/* ************************************************************************** */
//std::vector と std::list はどちらも シーケンスコンテナ
int main()
{
	std::cout << "=== Testing with std::vector ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	// 成功ケースでインデックスを取得
	try {
		std::vector<int>::iterator result_it = easyfind(vec, 3);
		
		// イテレータからインデックスを計算
		long index = std::distance(vec.begin(), result_it);
		
		std::cout << "Found: " << *result_it << " at index: " << index << std::endl;
	} catch (const NoOccurrenceFoundException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator result_it = easyfind(vec, 42);
		
		// イテレータからインデックスを計算
		long index = std::distance(vec.begin(), result_it);
		
		std::cout << "Found: " << *result_it << " at index: " << index << std::endl;
	} catch (const NoOccurrenceFoundException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	// std::list でのテスト
	std::cout << "\n=== Testing with std::list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	// 成功
	try {
		std::list<int>::iterator result = easyfind(lst, 20);
		long index = std::distance(lst.begin(), result);
		std::cout << "Found: " << *result << " at index: " << index << std::endl;
	} catch (const NoOccurrenceFoundException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// 失敗
	try {
		std::list<int>::iterator result = easyfind(lst, 42);
		std::cout << "Found: " << *result << std::endl;
	} catch (const NoOccurrenceFoundException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}