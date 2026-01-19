#include <vector>
#include <iostream>

/*
 * size()とmax_size()の違いを確認するテストコード
 * 
 * 質問: max_size()とsize()はこの場合等価ですか？
 * 回答: いいえ、全く異なります！
 * 
 * コンパイル: 
 c++ -std=c++98 -Wall -Wextra -Werror size_vs_max_size_test.cpp -o size_vs_max_size_test
 */

int main() {
	std::vector<int> vec;
	
	// 初期状態
	std::cout << "=== 初期状態（空のベクター）===" << std::endl;
	std::cout << "vec.size() = " << vec.size() << std::endl;
	std::cout << "vec.max_size() = " << vec.max_size() << std::endl;
	std::cout << std::endl;
	
	// 要素を追加
	std::cout << "=== 要素を5個追加後 ===" << std::endl;
	for (int i = 1; i <= 5; i++) {
		vec.push_back(i);
	}
	std::cout << "vec.size() = " << vec.size() << std::endl;
	std::cout << "vec.max_size() = " << vec.max_size() << std::endl;
	std::cout << std::endl;
	
	// 違いの説明
	std::cout << "=== size()とmax_size()の違い ===" << std::endl;
	std::cout << "size(): 現在の要素数" << std::endl;
	std::cout << "  - 実際に格納されている要素の数" << std::endl;
	std::cout << "  - この例では: " << vec.size() << std::endl;
	std::cout << std::endl;
	
	std::cout << "max_size(): 理論的に保持できる最大要素数" << std::endl;
	std::cout << "  - ベクターが理論的に保持できる最大の要素数" << std::endl;
	std::cout << "  - 実装依存だが、通常は非常に大きい値（2^64など）" << std::endl;
	std::cout << "  - この例では: " << vec.max_size() << std::endl;
	std::cout << std::endl;
	
	// ループでの使用例の比較
	std::cout << "=== ループでの使用例 ===" << std::endl;
	std::cout << "正しい使い方: for (size_t i = 2; i < vec.size(); ++i)" << std::endl;
	std::cout << "  ループ回数: " << vec.size() << " - 2 = " << (vec.size() - 2) << " 回" << std::endl;
	std::cout << std::endl;
	
	std::cout << "間違った使い方: for (size_t i = 2; i < vec.max_size(); ++i)" << std::endl;
	std::cout << "  ループ回数: " << vec.max_size() << " - 2 = 約" << (vec.max_size() - 2) << " 回" << std::endl;
	std::cout << "  問題: ほぼ無限ループになる可能性がある！" << std::endl;
	std::cout << "  問題: 範囲外アクセスが発生する！" << std::endl;
	std::cout << std::endl;
	
	// 実際の例
	std::cout << "=== 実際の例 ===" << std::endl;
	std::cout << "現在の要素数: " << vec.size() << std::endl;
	std::cout << "有効なインデックス: 0 ～ " << (vec.size() - 1) << std::endl;
	std::cout << std::endl;
	
	std::cout << "もし i < vec.max_size() を使った場合:" << std::endl;
	std::cout << "  i = 2 から i = " << vec.max_size() << " までループ" << std::endl;
	std::cout << "  問題1: vec[2] から vec[" << (vec.size() - 1) << "] までは有効" << std::endl;
	std::cout << "  問題2: vec[" << vec.size() << "] 以降は範囲外アクセス（未定義動作）" << std::endl;
	std::cout << "  問題3: 非常に長いループになる" << std::endl;
	std::cout << std::endl;
	
	// 結論
	std::cout << "=== 結論 ===" << std::endl;
	std::cout << "max_size()とsize()は全く異なります！" << std::endl;
	std::cout << "1. size(): 現在の要素数（実際に格納されている要素数）" << std::endl;
	std::cout << "2. max_size(): 理論的な最大要素数（非常に大きい値）" << std::endl;
	std::cout << std::endl;
	std::cout << "ループでは必ずsize()を使うべき:" << std::endl;
	std::cout << "  for (size_t i = 2; i < vec.size(); ++i)  // 正しい" << std::endl;
	std::cout << "  for (size_t i = 2; i < vec.max_size(); ++i)  // 間違い！" << std::endl;
	
	return 0;
}
