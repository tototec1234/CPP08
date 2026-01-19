#include <iostream>
#include <vector>
/*
c++ -std=c++98 -Wall -Wextra -Werror vector_explanation.cpp -o vector_explanation && ./vector_explanation
*/

int main(){
	std::vector<int> vec;

	// 9個の要素を追加（capacity=16になる）
	for (int i = 1; i <= 9; i++) {
		vec.push_back(i);
	}
	std::cout << "=== 初期状態 ===" << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
	std::cout << std::endl;

	// 5回pop_back（size=4になる、capacityは16のまま）
	for (int i = 0; i < 5; i++) {
		vec.pop_back();
	}
	std::cout << "=== pop_back後 ===" << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
	std::cout << "有効な要素: ";
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl << std::endl;

	// push_back(10)を追加
	vec.push_back(10);
	std::cout << "=== push_back(10)後 ===" << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
	std::cout << "有効な要素: ";
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl << std::endl;

	// 重要なポイント1: sizeとcapacityの違い
	std::cout << "=== size vs capacity ===" << std::endl;
	std::cout << "size: " << vec.size() << " (有効な要素数)" << std::endl;
	std::cout << "capacity: " << vec.capacity() << " (確保されているメモリ領域)" << std::endl;
	std::cout << "有効なインデックス: 0 ～ " << vec.size() - 1 << std::endl;
	std::cout << "確保されている領域: 0 ～ " << vec.capacity() - 1 << std::endl;
	std::cout << std::endl;

	// 重要なポイント2: メモリ上には古いデータが残っている
	std::cout << "=== メモリ上の実際の内容（未定義動作の可能性あり）===" << std::endl;
	std::cout << "注意: vec[5]以降は未定義動作です！" << std::endl;
	for (size_t i = 0; i < 16; i++) {
		if (i < vec.size()) {
			std::cout << "vec[" << i << "] = " << vec[i] << " (有効)" << std::endl;
		} else {
			// これは未定義動作だが、メモリ上には古いデータが残っている可能性がある
			std::cout << "vec[" << i << "] = " << vec[i] << " (未定義動作！古いデータが残っている可能性)" << std::endl;
		}
	}
	std::cout << std::endl;

	// 重要なポイント3: vec[15]より先にアクセスしてもセグフォしない理由
	std::cout << "=== なぜvec[15]より先にアクセスしてもセグフォしないのか？ ===" << std::endl;
	std::cout << "1. capacity=16なので、メモリは0～15のインデックス分確保されている" << std::endl;
	std::cout << "2. vec[16]やvec[17]は確保されたメモリ領域の外だが、" << std::endl;
	std::cout << "   メモリアロケータが余分に確保している可能性がある" << std::endl;
	std::cout << "3. しかし、これは**未定義動作（Undefined Behavior）**です！" << std::endl;
	std::cout << "4. セグフォしない保証はありません。環境によってはクラッシュします。" << std::endl;
	std::cout << std::endl;

	// 安全なアクセス方法
	std::cout << "=== 安全なアクセス方法: at() vs [] ===" << std::endl;
	std::cout << "現在のsize: " << vec.size() << std::endl;
	std::cout << "現在のcapacity: " << vec.capacity() << std::endl;
	std::cout << std::endl;

	// テストケース1: 有効な範囲内のアクセス
	std::cout << "--- テストケース1: 有効な範囲内のアクセス ---" << std::endl;
	for (size_t i = 0; i < vec.size(); i++) {
		try {
			std::cout << "vec.at(" << i << ") = " << vec.at(i) << " (成功)" << std::endl;
		} catch (const std::out_of_range& e) {
			std::cout << "vec.at(" << i << ") = 例外: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	// テストケース2: 範囲外アクセス（sizeを超える）
	std::cout << "--- テストケース2: 範囲外アクセス（size=" << vec.size() << "を超える）---" << std::endl;
	int test_indices[] = {5, 10, 15, 16, 17, 100};
	int test_indices_size = sizeof(test_indices) / sizeof(test_indices[0]);
	for (int i = 0; i < test_indices_size; i++) {
		int idx = test_indices[i];
		std::cout << "vec.at(" << idx << "): ";
		try {
			int value = vec.at(idx);
			std::cout << value << " (成功 - これは起こるべきではありません)" << std::endl;
		} catch (const std::out_of_range& e) {
			std::cout << "例外が発生: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	// テストケース3: 負のインデックス
	std::cout << "--- テストケース3: 負のインデックス ---" << std::endl;
	try {
		std::cout << "vec.at(-1): ";
		int value = vec.at(-1);
		std::cout << value << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "例外が発生: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// テストケース4: []演算子との比較（未定義動作）
	std::cout << "--- テストケース4: []演算子との比較（未定義動作）---" << std::endl;
	std::cout << "注意: []演算子は範囲チェックを行いません！" << std::endl;
	for (int i = 0; i < test_indices_size; i++) {
		int idx = test_indices[i];
		std::cout << "vec[" << idx << "] = " << vec[idx] 
		          << " (未定義動作、セグフォしない保証なし)" << std::endl;
	}
	std::cout << std::endl;

	// テストケース5: 実際のクラッシュケースの再現
	std::cout << "--- テストケース5: 実際のクラッシュケースの再現 ---" << std::endl;
	std::cout << "元のコードでは vec[17] にアクセスしていました。" << std::endl;
	std::cout << "at()を使った場合:" << std::endl;
	try {
		std::cout << "vec.at(17): " << vec.at(17) << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "例外が発生: " << e.what() << " (安全に捕捉されました)" << std::endl;
	}
	std::cout << "[]を使った場合:" << std::endl;
	std::cout << "vec[17]: " << vec[17] << " (未定義動作、たまたまセグフォしなかっただけ)" << std::endl;
	std::cout << std::endl;

	// まとめ
	std::cout << "=== まとめ ===" << std::endl;
	std::cout << "1. vec.at(index): 範囲チェックあり、範囲外ならstd::out_of_range例外を投げる" << std::endl;
	std::cout << "2. vec[index]: 範囲チェックなし、範囲外アクセスは未定義動作" << std::endl;
	std::cout << "3. 安全なコードを書くには、必ずat()を使うか、範囲チェックを自分で行う" << std::endl;
	std::cout << "4. try-catchで例外を捕捉すれば、クラッシュを防げる" << std::endl;

	return 0;
}
