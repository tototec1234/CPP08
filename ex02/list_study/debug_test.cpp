#include <iostream>
#include <iterator>
#include <list>

int main(){
	std::list<int> ls1;
	for (int i = 0; i < 5; i++){
		ls1.push_back(i);
	}

	std::list<int>::iterator it = ls1.begin();
	
	// 元のリストの状態を確認
	std::cout << "Before insert:" << std::endl;
	for (std::list<int>::iterator it2 = ls1.begin(); it2 != ls1.end(); ++it2)
		std::cout << *it2 << " ";
	std::cout << std::endl;
	
	// itの現在位置
	std::cout << "it points to: " << *it << std::endl;
	
	// std::next(it, 20)の動作を確認
	std::list<int>::iterator it20 = std::next(it, 20);
	std::cout << "it20 == ls1.end()? " << (it20 == ls1.end() ? "true" : "false") << std::endl;
	
	// insertを実行
	ls1.insert(it20, 100);
	
	// 結果を確認
	std::cout << "After insert(std::next(it, 20), 100):" << std::endl;
	for (std::list<int>::iterator it2 = ls1.begin(); it2 != ls1.end(); ++it2)
		std::cout << *it2 << " ";
	std::cout << std::endl;
	
	// 比較: std::next(it, 2)の場合
	std::list<int> ls2;
	for (int i = 0; i < 5; i++){
		ls2.push_back(i);
	}
	std::list<int>::iterator it2_begin = ls2.begin();
	std::list<int>::iterator it2 = std::next(it2_begin, 2);
	std::cout << "\nComparison: insert(std::next(begin(), 2), 100)" << std::endl;
	std::cout << "it2 points to: " << *it2 << std::endl;
	ls2.insert(it2, 100);
	for (std::list<int>::iterator it3 = ls2.begin(); it3 != ls2.end(); ++it3)
		std::cout << *it3 << " ";
	std::cout << std::endl;
}
