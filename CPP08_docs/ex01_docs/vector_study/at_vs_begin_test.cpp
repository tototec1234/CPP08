#include <vector>
#include <iostream>

/*
 * at()とbegin()の違いを説明するテストコード
 * コンパイル: 
 c++ -std=c++98 -Wall -Wextra -Werror at_vs_begin_test.cpp -o at_vs_begin_test

 */

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	// at(0)の使用例
	std::cout << "=== at(0)の使用例 ===" << std::endl;
	int value_at = vec.at(0);  // int型の値を返す
	std::cout << "vec.at(0) = " << value_at << std::endl;
	std::cout << "型: int" << std::endl;
	std::cout << std::endl;

	// begin()の使用例
	std::cout << "=== begin()の使用例 ===" << std::endl;
	std::vector<int>::iterator it_begin = vec.begin();  // イテレータを返す
	std::cout << "vec.begin() = イテレータ（ポインタのようなもの）" << std::endl;
	std::cout << "*vec.begin() = " << *it_begin << std::endl;  // デリファレンスが必要
	std::cout << "型: std::vector<int>::iterator" << std::endl;
	std::cout << std::endl;

	// 等価な書き方の比較
	std::cout << "=== 等価な書き方の比較 ===" << std::endl;
	std::cout << "vec.at(0) = " << vec.at(0) << std::endl;
	std::cout << "*vec.begin() = " << *vec.begin() << std::endl;
	std::cout << "これらは等価: vec.at(0) == *vec.begin()" << std::endl;
	std::cout << std::endl;

	// 元のコードとの比較
	std::cout << "=== 元のコードとの比較 ===" << std::endl;
	std::cout << "元のコード: sorted.at(1) - sorted.at(0)" << std::endl;
	std::cout << "イテレータ版: *(sorted.begin() + 1) - *sorted.begin()" << std::endl;
	std::cout << "これらは等価です" << std::endl;
	std::cout << std::endl;

	// 実際の計算例
	std::cout << "=== 実際の計算例 ===" << std::endl;
	int result1 = vec.at(1) - vec.at(0);
	int result2 = *(vec.begin() + 1) - *vec.begin();
	std::cout << "vec.at(1) - vec.at(0) = " << result1 << std::endl;
	std::cout << "*(vec.begin() + 1) - *vec.begin() = " << result2 << std::endl;
	std::cout << "結果は等価: " << (result1 == result2 ? "true" : "false") << std::endl;

	return 0;
}
