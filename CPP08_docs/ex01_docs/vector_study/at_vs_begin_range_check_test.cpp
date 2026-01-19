#include <vector>
#include <iostream>
#include <stdexcept>

/*
 * at()とbegin()の範囲チェックの違いを実験するテストコード
 * 
 * 重要な違い:
 * - at(0): 範囲チェックあり（範囲外でstd::out_of_range例外）
 * - *begin(): 範囲チェックなし（範囲外アクセスは未定義動作）
 * 
 * コンパイル:
 c++ -std=c++98 -Wall -Wextra -Werror at_vs_begin_range_check_test.cpp -o at_vs_begin_range_check_test
 */

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	
	std::cout << "=== テスト準備 ===" << std::endl;
	std::cout << "vec.size() = " << vec.size() << std::endl;
	std::cout << "有効なインデックス: 0 ～ " << (vec.size() - 1) << std::endl;
	std::cout << std::endl;

	// テスト1: 有効な範囲内でのアクセス
	std::cout << "=== テスト1: 有効な範囲内でのアクセス ===" << std::endl;
	std::cout << "vec.at(0) = " << vec.at(0) << " (範囲チェックあり)" << std::endl;
	std::cout << "*vec.begin() = " << *vec.begin() << " (範囲チェックなし)" << std::endl;
	std::cout << "結果: 両方とも正常に動作" << std::endl;
	std::cout << std::endl;

	// テスト2: 範囲外アクセス（at()を使用）
	std::cout << "=== テスト2: 範囲外アクセス（at()を使用）===" << std::endl;
	std::cout << "vec.at(5) を試みます（範囲外）..." << std::endl;
	try {
		int value = vec.at(5);
		std::cout << "vec.at(5) = " << value << std::endl;
		std::cout << "これは起こるべきではありません" << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "✓ 例外が発生: " << e.what() << std::endl;
		std::cout << "✓ at()は範囲チェックを行い、安全に例外を投げました" << std::endl;
	}
	std::cout << std::endl;

	// テスト3: 範囲外アクセス（*begin()を使用）
	std::cout << "=== テスト3: 範囲外アクセス（*begin()を使用）===" << std::endl;
	std::cout << "*(vec.begin() + 5) を試みます（範囲外）..." << std::endl;
	std::cout << "注意: これは未定義動作です！" << std::endl;
	
	// 警告: これは未定義動作ですが、実験のために実行します
	// 実際のコードではこのようなアクセスをしてはいけません
	std::vector<int>::iterator it = vec.begin() + 5;
	int value = *it;  // 未定義動作！
	std::cout << "*(vec.begin() + 5) = " << value << std::endl;
	std::cout << "✗ 範囲チェックがないため、例外が発生せず、未定義動作が発生しました" << std::endl;
	std::cout << "✗ セグフォする可能性もありますが、たまたまセグフォしなかっただけです" << std::endl;
	std::cout << std::endl;

	// テスト4: 空のベクターでの比較
	std::cout << "=== テスト4: 空のベクターでの比較 ===" << std::endl;
	std::vector<int> empty_vec;
	std::cout << "empty_vec.size() = " << empty_vec.size() << std::endl;
	
	std::cout << "empty_vec.at(0) を試みます..." << std::endl;
	try {
		int value = empty_vec.at(0);
		std::cout << "empty_vec.at(0) = " << value << std::endl;
		std::cout << "これは起こるべきではありません" << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "✓ 例外が発生: " << e.what() << std::endl;
		std::cout << "✓ at()は範囲チェックを行い、安全に例外を投げました" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "*(empty_vec.begin()) を試みます..." << std::endl;
	if (empty_vec.empty()) {
		std::cout << "警告: 空のベクターなので、begin() == end() です" << std::endl;
		std::cout << "注意: これは未定義動作です！セグフォする可能性があります" << std::endl;
		std::cout << "実際にアクセスを試みます..." << std::endl;
		
		// 警告: これは未定義動作ですが、実験のために実行します
		// セグフォする可能性がありますが、実際の動作を確認します
		try {
			int value = *empty_vec.begin();  // 未定義動作！セグフォの可能性あり
			std::cout << "*(empty_vec.begin()) = " << value << std::endl;
			std::cout << "✗ セグフォしませんでしたが、これは未定義動作です" << std::endl;
			std::cout << "✗ 環境によってはクラッシュする可能性があります" << std::endl;
		} catch (...) {
			// セグフォの場合はここには到達しません（プログラムが終了する）
			std::cout << "-------------------------例外が発生しました（ただし、セグフォの場合はここには到達しません）" << std::endl;
		}
		std::cout << "=========注意: セグフォした場合、このメッセージは表示されません" << std::endl;
	}
	std::cout << std::endl;

	// まとめ
	std::cout << "=== まとめ ===" << std::endl;
	std::cout << "1. at(0): 範囲チェックあり → 範囲外アクセス時にstd::out_of_range例外を投げる" << std::endl;
	std::cout << "   - 安全なコードを書くには at() を使用" << std::endl;
	std::cout << "   - try-catch で例外処理が可能" << std::endl;
	std::cout << std::endl;
	std::cout << "2. *begin(): 範囲チェックなし → 範囲外アクセスは未定義動作" << std::endl;
	std::cout << "   - セグフォする可能性がある" << std::endl;
	std::cout << "   - たまたまセグフォしなくても、データの破壊や予期しない動作が発生する可能性がある" << std::endl;
	std::cout << "   - 自分で範囲チェックを行う必要がある" << std::endl;
	std::cout << std::endl;
	std::cout << "3. 推奨: 安全性を重視する場合は at() を使用" << std::endl;
	std::cout << "   - パフォーマンスが重要な場合は、事前に範囲チェックをしてから [] を使用" << std::endl;

	return 0;
}
