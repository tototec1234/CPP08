#include <vector>
#include <iostream>
#include <stdexcept>

/*
 * []演算子とat()の例外処理の違いを実験するテストコード
 * 
 * 質問: sorted[1] - sorted[0]にしても例外処理されることはなく
 *       未定義動作で異常な結果を出しながらプログラムが進行するか、
 *       セグフォ等でクラッシュする（catchできない）か？
 * 
 * コンパイル: 
 c++ -std=c++98 -Wall -Wextra -Werror bracket_vs_at_exception_test.cpp -o bracket_vs_at_exception_test; ./bracket_vs_at_exception_test
 */

int main() {
	std::cout << "=== []演算子とat()の例外処理の違いを実験 ===" << std::endl;
	std::cout << std::endl;

	// テスト1: 有効な範囲内でのアクセス（両方とも正常）
	std::cout << "=== テスト1: 有効な範囲内でのアクセス ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	
	std::cout << "vec.size() = " << vec.size() << std::endl;
	std::cout << "vec.at(1) - vec.at(0) = " << (vec.at(1) - vec.at(0)) << std::endl;
	std::cout << "vec[1] - vec[0] = " << (vec[1] - vec[0]) << std::endl;
	std::cout << "結果: 両方とも正常に動作" << std::endl;
	std::cout << std::endl;

	// テスト2: 範囲外アクセス（at()を使用 - 例外が発生）
	std::cout << "=== テスト2: 範囲外アクセス（at()を使用）===" << std::endl;
	std::vector<int> small_vec;
	small_vec.push_back(10);
	
	std::cout << "small_vec.size() = " << small_vec.size() << std::endl;
	std::cout << "small_vec.at(1) - small_vec.at(0) を試みます（範囲外）..." << std::endl;
	
	try {
		int result = small_vec.at(1) - small_vec.at(0);
		std::cout << "結果: " << result << std::endl;
		std::cout << "これは起こるべきではありません" << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "✓ 例外が発生: " << e.what() << std::endl;
		std::cout << "✓ at()は範囲チェックを行い、例外を投げました" << std::endl;
		std::cout << "✓ catchで例外を捕捉できました" << std::endl;
	}
	std::cout << std::endl;

	// テスト3: 範囲外アクセス（[]演算子を使用 - 例外は発生しない）
	std::cout << "=== テスト3: 範囲外アクセス（[]演算子を使用）===" << std::endl;
	std::cout << "small_vec[1] - small_vec[0] を試みます（範囲外）..." << std::endl;
	std::cout << "警告: []演算子は範囲チェックを行いません！" << std::endl;
	
	try {
		int result = small_vec[1] - small_vec[0];  // 未定義動作！
		std::cout << "結果: " << result << " (未定義動作の結果)" << std::endl;
		std::cout << "✗ 例外は発生しませんでした" << std::endl;
		std::cout << "✗ catchで例外を捕捉できません（例外が発生しないため）" << std::endl;
		std::cout << "✗ 未定義動作が発生しました" << std::endl;
		std::cout << "✗ 異常な値が返される可能性があります" << std::endl;
	} catch (const std::out_of_range& e) {
		// このブロックには到達しません（[]演算子は例外を投げない）
		std::cout << "例外が発生: " << e.what() << std::endl;
		std::cout << "これは表示されません（[]演算子は例外を投げないため）" << std::endl;
	} catch (...) {
		// セグフォの場合もここには到達しません（プログラムが終了する）
		std::cout << "予期しない例外が発生しました" << std::endl;
	}
	std::cout << "注意: セグフォした場合、このメッセージは表示されません" << std::endl;
	std::cout << std::endl;

	// テスト4: 空のベクターでの比較
	std::cout << "=== テスト4: 空のベクターでの比較 ===" << std::endl;
	std::vector<int> empty_vec;
	std::cout << "empty_vec.size() = " << empty_vec.size() << std::endl;
	
	std::cout << "empty_vec.at(0) を試みます..." << std::endl;
	try {
		int value = empty_vec.at(0);
		std::cout << "結果: " << value << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "✓ 例外が発生: " << e.what() << std::endl;
		std::cout << "✓ catchで例外を捕捉できました" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "-------------empty_vec[0] を試みます（未定義動作）..." << std::endl;
	try {
		int value = empty_vec[0];  // 未定義動作！セグフォの可能性が高い
		std::cout << "結果: " << value << " (未定義動作の結果)" << std::endl;
		std::cout << "✗ 例外は発生しませんでした" << std::endl;
		std::cout << "✗ catchで例外を捕捉できません" << std::endl;
	} catch (const std::out_of_range& e) {
		// このブロックには到達しません
		std::cout << "例外が発生: " << e.what() << std::endl;
	} catch (...) {
		// セグフォの場合もここには到達しません
		std::cout << "予期しない例外が発生しました" << std::endl;
	}
	std::cout << "注意: セグフォした場合、このメッセージは表示されません" << std::endl;
	std::cout << std::endl;

	// まとめ
	std::cout << "=== まとめ ===" << std::endl;
	std::cout << "質問への回答:" << std::endl;
	std::cout << "sorted[1] - sorted[0]に変更した場合:" << std::endl;
	std::cout << "1. 例外処理されることはない（[]演算子は例外を投げない）" << std::endl;
	std::cout << "2. catchで例外を捕捉できない（例外が発生しないため）" << std::endl;
	std::cout << "3. 未定義動作が発生する" << std::endl;
	std::cout << "4. 可能性1: 異常な結果を出しながらプログラムが進行する" << std::endl;
	std::cout << "5. 可能性2: セグフォ等でクラッシュする（catchできない）" << std::endl;
	std::cout << std::endl;
	std::cout << "結論: at()を使うべき理由" << std::endl;
	std::cout << "- 範囲チェックを行い、例外を投げる" << std::endl;
	std::cout << "- try-catchで例外を捕捉できる" << std::endl;
	std::cout << "- 安全にエラーハンドリングができる" << std::endl;

	return 0;
}
