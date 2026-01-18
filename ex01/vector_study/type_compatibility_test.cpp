#include <vector>
#include <iostream>
#include <typeinfo>

/*
 * size_tとstd::vector<int>::size_typeの型の互換性を確認するテスト
 * 
 * コンパイル: 
 c++ -std=c++98 -Wall -Wextra -Werror -Wsign-compare type_compatibility_test.cpp -o type_compatibility_test
 */

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	
	std::cout << "=== 型の互換性テスト ===" << std::endl;
	std::cout << std::endl;
	
	// 型の確認
	size_t size_t_var = 0;
	std::vector<int>::size_type size_type_var = 0;
	
	// 比較テスト
	std::cout << "=== 比較テスト ===" << std::endl;
	std::cout << "size_t i = 2; i < vec.size(); の比較:" << std::endl;
	
	// size_tとsize_typeの比較
	size_t i = 2;
	std::vector<int>::size_type vec_size = vec.size();
	
	std::cout << "  size_t i = " << i << std::endl;
	std::cout << "  vec.size() = " << vec_size << std::endl;
	std::cout << "  i < vec.size() = " << (i < vec_size) << std::endl;
	std::cout << std::endl;
	
	// 型変換の確認
	std::cout << "=== 型変換の確認 ===" << std::endl;
	std::cout << "size_tからstd::vector<int>::size_typeへの代入:" << std::endl;
	std::vector<int>::size_type converted_from_size_t = i;
	std::cout << "  std::vector<int>::size_type var = size_t_value; 成功" << std::endl;
	std::cout << "  値: " << converted_from_size_t << std::endl;
	std::cout << std::endl;
	
	std::cout << "std::vector<int>::size_typeからsize_tへの代入:" << std::endl;
	size_t converted_from_size_type = vec_size;
	std::cout << "  size_t var = std::vector<int>::size_type_value; 成功" << std::endl;
	std::cout << "  値: " << converted_from_size_type << std::endl;
	std::cout << std::endl;
	
	// 符号の確認
	std::cout << "=== 符号の確認 ===" << std::endl;
	std::cout << "size_tは符号なし: " << std::boolalpha << (static_cast<size_t>(-1) > 0) << std::endl;
	std::cout << "std::vector<int>::size_typeは符号なし: " << std::boolalpha << (static_cast<std::vector<int>::size_type>(-1) > 0) << std::endl;
	std::cout << std::endl;
	
	// まとめ
	std::cout << "=== まとめ ===" << std::endl;
	std::cout << "質問: -Wsign-compareでコンパイルできた理由" << std::endl;
	std::cout << std::endl;
	std::cout << "回答:" << std::endl;
	std::cout << "1. ほとんどの実装で std::vector<int>::size_type は size_t の typedef" << std::endl;
	std::cout << "2. 同じ型なので、符号の違いによる警告（-Wsign-compare）は発生しない" << std::endl;
	std::cout << "3. -Wsign-compareは、符号付き整数と符号なし整数の比較を警告する" << std::endl;
	std::cout << "4. size_t と std::vector<int>::size_type は両方とも符号なしなので、警告なし" << std::endl;
	std::cout << std::endl;
	std::cout << "結論:" << std::endl;
	std::cout << "- size_tを使っても、型の互換性は問題ない（実装によっては同じ型）" << std::endl;
	std::cout << "- -Wsign-compare警告が出ないのは正常" << std::endl;
	std::cout << "- ただし、std::vector<int>::size_typeを使うことで、意図が明確になる" << std::endl;
	
	return 0;
}
