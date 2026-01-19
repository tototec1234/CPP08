#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

/*
 * ループ内での[]とat()の安全性の分析
 * 
 * 質問: for文で[]を使っているが、at()の方が安全か？それとも過剰か？
 *       ループ全体をtry内で行う方がいいのか？
 * 
 * コンパイル: 
 c++ -std=c++98 -Wall -Wextra -Werror loop_safety_analysis.cpp -o loop_safety_analysis
 */

void analyzeLoopSafety() {
	std::cout << "=== ループの安全性分析 ===" << std::endl;
	std::cout << std::endl;
	
	std::vector<int> sorted;
	for (int i = 1; i <= 5; i++) {
		sorted.push_back(i * 10);
	}
	
	std::cout << "sorted = [10, 20, 30, 40, 50]" << std::endl;
	std::cout << "sorted.size() = " << sorted.size() << std::endl;
	std::cout << std::endl;
	
	// ループ条件の分析
	std::cout << "=== ループ条件の分析 ===" << std::endl;
	std::cout << "for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i)" << std::endl;
	std::cout << "  i の範囲: 2 ～ " << (sorted.size() - 1) << std::endl;
	std::cout << "  sorted[i] の範囲: sorted[2] ～ sorted[" << (sorted.size() - 1) << "]" << std::endl;
	std::cout << "  sorted[i - 1] の範囲: sorted[1] ～ sorted[" << (sorted.size() - 2) << "]" << std::endl;
	std::cout << std::endl;
	
	// 有効性の確認
	std::cout << "=== 有効性の確認 ===" << std::endl;
	std::cout << "有効なインデックス: 0 ～ " << (sorted.size() - 1) << std::endl;
	std::cout << "sorted[i]: i = 2 ～ " << (sorted.size() - 1) << " → 有効範囲内" << std::endl;
	std::cout << "sorted[i - 1]: i - 1 = 1 ～ " << (sorted.size() - 2) << " → 有効範囲内" << std::endl;
	std::cout << "結論: ループ条件で範囲が保証されている" << std::endl;
	std::cout << std::endl;
}

void method1_BracketOperator() {
	std::cout << "=== 方法1: []演算子を使用 ===" << std::endl;
	std::vector<int> sorted;
	for (int i = 1; i <= 5; i++) {
		sorted.push_back(i * 10);
	}
	
	int minSpan = sorted[1] - sorted[0];
	for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i) {
		minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
	}
	
	std::cout << "コード: sorted[i] - sorted[i - 1]" << std::endl;
	std::cout << "結果: minSpan = " << minSpan << std::endl;
	std::cout << "評価:" << std::endl;
	std::cout << "  ✓ ループ条件で範囲が保証されているので安全" << std::endl;
	std::cout << "  ✓ パフォーマンスが良い（範囲チェックなし）" << std::endl;
	std::cout << "  - 万が一のバグが発生した場合、未定義動作" << std::endl;
	std::cout << std::endl;
}

void method2_AtOperator() {
	std::cout << "=== 方法2: at()を使用 ===" << std::endl;
	std::vector<int> sorted;
	for (int i = 1; i <= 5; i++) {
		sorted.push_back(i * 10);
	}
	
	int minSpan;
	try {
		minSpan = sorted.at(1) - sorted.at(0);
		for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i) {
			minSpan = std::min(minSpan, sorted.at(i) - sorted.at(i - 1));
		}
	} catch (const std::out_of_range& e) {
		std::cout << "例外が発生: " << e.what() << std::endl;
		throw;
	}
	
	std::cout << "コード: sorted.at(i) - sorted.at(i - 1) (try内)" << std::endl;
	std::cout << "結果: minSpan = " << minSpan << std::endl;
	std::cout << "評価:" << std::endl;
	std::cout << "  ✓ 範囲チェックにより防御的プログラミング" << std::endl;
	std::cout << "  ✓ 万が一のバグを検出できる" << std::endl;
	std::cout << "  - ループ条件で範囲が保証されているので、過剰な可能性がある" << std::endl;
	std::cout << "  - パフォーマンスへの影響は微々たるもの" << std::endl;
	std::cout << std::endl;
}

void method3_BracketWithTry() {
	std::cout << "=== 方法3: []演算子を使用（ループ全体をtry内）===" << std::endl;
	std::vector<int> sorted;
	for (int i = 1; i <= 5; i++) {
		sorted.push_back(i * 10);
	}
	
	int minSpan;
	try {
		minSpan = sorted[1] - sorted[0];
		for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i) {
			minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
		}
	} catch (...) {
		std::cout << "注意: []演算子は例外を投げないので、このcatchには到達しません" << std::endl;
		std::cout << "セグフォした場合は、このcatchにも到達しません" << std::endl;
	}
	
	std::cout << "コード: sorted[i] - sorted[i - 1] (try内)" << std::endl;
	std::cout << "結果: minSpan = " << minSpan << std::endl;
	std::cout << "評価:" << std::endl;
	std::cout << "  ✗ []演算子は例外を投げないので、try-catchは意味がない" << std::endl;
	std::cout << "  ✗ セグフォした場合も、catchで捕捉できない" << std::endl;
	std::cout << std::endl;
}

int main() {
	std::cout << "========================================" << std::endl;
	std::cout << "ループ内での[]とat()の安全性の分析" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << std::endl;
	
	analyzeLoopSafety();
	method1_BracketOperator();
	method2_AtOperator();
	method3_BracketWithTry();
	
	std::cout << "=== 推奨事項 ===" << std::endl;
	std::cout << "1. ループ条件で範囲が保証されている場合:" << std::endl;
	std::cout << "   → []演算子を使用（パフォーマンス重視）" << std::endl;
	std::cout << "   または at()を使用（防御的プログラミング重視）" << std::endl;
	std::cout << std::endl;
	std::cout << "2. ループ全体をtry-catchで囲む場合:" << std::endl;
	std::cout << "   → []演算子を使う場合: try-catchは意味がない（例外を投げない）" << std::endl;
	std::cout << "   → at()を使う場合: try-catchで例外を捕捉できる" << std::endl;
	std::cout << std::endl;
	std::cout << "3. このケースでの推奨:" << std::endl;
	std::cout << "   - ループ条件（i < sorted.size()）で範囲が保証されている" << std::endl;
	std::cout << "   - すでに50-51行目でsize >= 2をチェック済み" << std::endl;
	std::cout << "   - []演算子で十分安全（過剰ではない）" << std::endl;
	std::cout << "   - 防御的プログラミングを重視する場合は、at()も選択肢" << std::endl;
	std::cout << std::endl;
	
	return 0;
}
