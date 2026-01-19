/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/19 15:18:02 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "AnsiColor.hpp"
#include <iostream>
#include <exception>
#include <list>
#include <limits>
#include <string>

void printOutput(bool useError, const char* color, const std::string& message, bool newline = true);
void subject_test();
void comparison_test_with_list();
void edge_case_test();
void type_genericity_test();
void copy_semantics_test();
void extended_features_test();
/* ************************************************************************** */	
int main() {
	int choice;
	bool running = true;

	while (running) {
		printOutput(false, YELLOW_COLOR, "\n\n=== CPP08 Ex02: MutantStack Test Menu ===");
		printOutput(false, nullptr, "=== CPP08 演習02 テストメニュー ===");
		printOutput(false, nullptr, "1: Test Subject (includes subject.pdf example)    課題書のテスト例");
		printOutput(false, nullptr, "2: Comparison Test with std::list                 std::listとの比較テスト");
		printOutput(false, nullptr, "3: Edge Case Test                                 エッジケーステスト");
		printOutput(false, nullptr, "4: Type Genericity Test                           型汎用性テスト");
		printOutput(false, nullptr, "5: Copy Semantics Test                            コピーセマンティクステスト");
		printOutput(false, nullptr, "6: Extended Features Test                         拡張機能テスト");
		printOutput(false, nullptr, "0: Exit                                           終了");
		std::cout << "Choose an option / 選択してください: ";

		if (!(std::cin >> choice)) {
			if (std::cin.eof()) {
				printOutput(false, nullptr, "\nEOF detected. Exiting... / EOFが検出されました。終了します...");
				break;
			}
			printOutput(false, nullptr, "⚠️ Invalid input! Please enter a number. / 無効な入力です！数字を入力してください。");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		try {
			switch (choice) {
				case 1:
					subject_test();
					break;
				case 2:
					comparison_test_with_list();
					break;
				case 3:
					edge_case_test();
					break;
				case 4:
					type_genericity_test();
					break;
				case 5:
					copy_semantics_test();
					break;
				case 6:
					extended_features_test();
					break;
				case 0:
					running = false;
					break;
				default:
					printOutput(false, nullptr, "Invalid selection. Please try again. / 無効な選択です。もう一度試してください。");
			}
		} catch (const std::exception &e) {
			printOutput(false, nullptr, std::string("⚠️ Exception caught: ") + e.what());
		}
	}

	return 0;
}
/* ************************************************************************** */	
// 課題書で提供されたテスト例
// この関数は課題書のテスト例をそのまま実装している。
// 出力がstd::listと同じになることを確認するために使用する。
void subject_test() {
	printOutput(false, GREEN_COLOR, "\n=== Testing Subject Example ===");
	printOutput(false, nullptr, "=== 課題書のテスト例 ===");
	
	try {
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;  // 期待値: 17
		mstack.pop();
		std::cout << mstack.size() << std::endl;  // 期待値: 1
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
				printOutput(false, GREEN_COLOR, "\n----------------");
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		// std::stackへのコピー（課題書の要件）
		std::stack<int> s(mstack);
		std::cout << "Copied to std::stack, size: " << s.size() << std::endl;
		
		printOutput(false, nullptr, "\n✅ Passed: Subject test / 課題書テスト成功");
	} catch (const std::exception &e) {
		printOutput(false, nullptr, std::string("❌ Failed: ") + e.what());
	}
}
/* ************************************************************************** */	
// std::listとの比較テスト
// 課題書の要件：
// "MutantStackで最初に実行し、次にMutantStackをstd::listなどの他のコンテナに置き換えて
// 実行すると、2つの出力は同じになるはずです。"
void comparison_test_with_list() {
	printOutput(false, GREEN_COLOR, "\n=== Comparison Test: MutantStack vs std::list ===");
	printOutput(false, nullptr, "=== std::listとの比較テスト ===");
	
	// MutantStackでの実行
	printOutput(false, nullptr, "\n--- MutantStack output ---");
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		++it;
		--it;
		mstack.printContents();
	}
	
	// std::listでの実行（同等の操作）
	printOutput(false, nullptr, "\n--- std::list output (should be identical) ---");
	{
		std::list<int> lst;
		lst.push_back(5);    // push() → push_back()
		lst.push_back(17);
		std::cout << lst.back() << std::endl;  // top() → back()
		lst.pop_back();      // pop() → pop_back()
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	
	printOutput(false, nullptr, "\n✅ Passed: Comparison test / 比較テスト成功");
}
/* ************************************************************************** */	
// エッジケーステスト
// - 空のスタック
// - 単一要素のスタック
// - 大量の要素
void edge_case_test() {
	printOutput(false, GREEN_COLOR, "\n=== Edge Case Test ===");
	printOutput(false, nullptr, "=== エッジケーステスト ===");
	
	// 1. 空のスタック
	printOutput(false, nullptr, "\n--- Empty stack ---");
	{
		MutantStack<int> emptyStack;
		std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
		std::cout << "Is empty: " << (emptyStack.empty() ? "true" : "false") << std::endl;
		
		// イテレータはbegin() == end()になる
		if (emptyStack.begin() == emptyStack.end())
		{
			std::cout << "begin() == end() for empty stack (correct)" << std::endl;
		}
	}
	
	// 2. 単一要素のスタック
	printOutput(false, nullptr, "\n--- Single element stack ---");
	{
		MutantStack<int> singleStack;
		singleStack.push(42);
		std::cout << "Single element: ";
		singleStack.printContents();
	}
	
	// 3. 大量の要素
	printOutput(false, nullptr, "\n--- Large stack (1000 elements) ---");
	{
		MutantStack<int> largeStack;
		for (int i = 0; i < 1000; ++i)
		{
			largeStack.push(i);
		}
		std::cout << "Stack size: " << largeStack.size() << std::endl;
		std::cout << "Top element: " << largeStack.top() << std::endl;
		
		// 最初の5つを表示
		MutantStack<int>::iterator it = largeStack.begin();
		std::cout << "First 5 elements: ";
		for (int i = 0; i < 5 && it != largeStack.end(); ++i, ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	
	printOutput(false, nullptr, "\n✅ Passed: Edge case test / エッジケーステスト成功");
}
/* ************************************************************************** */	
// 型汎用性テスト
// テンプレートの汎用性を確認するため、異なる型でテストする。
void type_genericity_test() {
	printOutput(false, GREEN_COLOR, "\n=== Type Genericity Test ===");
	printOutput(false, nullptr, "=== 型汎用性テスト ===");
	
	// 1. std::string型
	printOutput(false, nullptr, "\n--- std::string type ---");
	{
		MutantStack<std::string> stringStack;
		stringStack.push("Hello");
		stringStack.push("World");
		stringStack.push("C++");
		stringStack.push("Templates");
		
		std::cout << "String stack contents: ";
		stringStack.printContents();
		std::cout << "Top: " << stringStack.top() << std::endl;
	}
	
	// 2. double型
	printOutput(false, nullptr, "\n--- double type ---");
	{
		MutantStack<double> doubleStack;
		doubleStack.push(3.14);
		doubleStack.push(2.71);
		doubleStack.push(1.41);
		
		std::cout << "Double stack contents: ";
		doubleStack.printContents();
	}
	
	// 3. イテレータの前後移動テスト
	printOutput(false, nullptr, "\n--- Iterator increment/decrement test ---");
	{
		MutantStack<int> testStack;
		testStack.push(1);
		testStack.push(2);
		testStack.push(3);
		testStack.push(4);
		testStack.push(5);
		
		MutantStack<int>::iterator it = testStack.begin();
		std::cout << "Initial: " << *it << std::endl;
		++it;
		std::cout << "After ++: " << *it << std::endl;
		--it;
		std::cout << "After --: " << *it << std::endl;
		it += 2;
		std::cout << "After += 2: " << *it << std::endl;
	}
	
	printOutput(false, nullptr, "\n✅ Passed: Type genericity test / 型汎用性テスト成功");
}
/* ************************************************************************** */	
// コピーセマンティクステスト
// コピーコンストラクタと代入演算子が正しく動作することを確認する。
void copy_semantics_test() {
	printOutput(false, GREEN_COLOR, "\n=== Copy Semantics Test ===");
	printOutput(false, nullptr, "=== コピーセマンティクステスト ===");
	
	// コピーコンストラクタ
	printOutput(false, nullptr, "\n--- Copy constructor ---");
	{
		MutantStack<int> original;
		original.push(10);
		original.push(20);
		original.push(30);
		
		MutantStack<int> copied(original);
		
		std::cout << "Original size: " << original.size() << std::endl;
		std::cout << "Copied size: " << copied.size() << std::endl;
		
		std::cout << "Original contents: ";
		original.printContents();
		
		std::cout << "Copied contents: ";
		copied.printContents();
	}
	
	// 代入演算子
	printOutput(false, nullptr, "\n--- Assignment operator ---");
	{
		MutantStack<int> source;
		source.push(100);
		source.push(200);
		
		MutantStack<int> target;
		target.push(999);  // これは上書きされる
		
		target = source;
		
		std::cout << "Source size: " << source.size() << std::endl;
		std::cout << "Target size: " << target.size() << std::endl;
		
		std::cout << "Target contents: ";
		target.printContents();
	}
	
	printOutput(false, nullptr, "\n✅ Passed: Copy semantics test / コピーセマンティクステスト成功");
}
/* ************************************************************************** */	
// 拡張機能テスト
// const_iterator、reverse_iterator、const_reverse_iteratorの動作を確認する
void extended_features_test() {
	printOutput(false, GREEN_COLOR, "\n=== Extended Features Test ===");
	printOutput(false, nullptr, "=== 拡張機能テスト ===");
	
	// テスト用のスタックを準備
	MutantStack<int> testStack;
	testStack.push(1);
	testStack.push(2);
	testStack.push(3);
	testStack.push(4);
	testStack.push(5);
	
	// 1. const_iteratorのテスト
	printOutput(false, nullptr, "\n--- const_iterator test / const_iteratorテスト ---");
	{
		const MutantStack<int>& constStack = testStack;
		
		std::cout << "Forward iteration with const_iterator: ";
		MutantStack<int>::const_iterator cit = constStack.begin();
		MutantStack<int>::const_iterator cite = constStack.end();
		for (; cit != cite; ++cit)
		{
			std::cout << *cit << " ";
		}
		std::cout << std::endl;
		
		// const_iteratorは読み取り専用であることを確認
		std::cout << "const_iterator is read-only (cannot modify elements)" << std::endl;
	}
	
	// 2. reverse_iteratorのテスト
	printOutput(false, nullptr, "\n--- reverse_iterator test / reverse_iteratorテスト ---");
	{
		std::cout << "Reverse iteration with reverse_iterator: ";
		MutantStack<int>::reverse_iterator rit = testStack.rbegin();
		MutantStack<int>::reverse_iterator rite = testStack.rend();
		for (; rit != rite; ++rit)
		{
			std::cout << *rit << " ";
		}
		std::cout << std::endl;
		
		// reverse_iteratorで要素を変更できることを確認
		std::cout << "Modifying elements with reverse_iterator: ";
		MutantStack<int>::reverse_iterator mod_it = testStack.rbegin();
		*mod_it = 99;
		std::cout << "Modified last element to: " << *mod_it << std::endl;
		testStack.printContents();
		// 元に戻す
		*mod_it = 5;
	}
	
	// 3. const_reverse_iteratorのテスト
	printOutput(false, nullptr, "\n--- const_reverse_iterator test / const_reverse_iteratorテスト ---");
	{
		const MutantStack<int>& constStack = testStack;
		
		std::cout << "Reverse iteration with const_reverse_iterator: ";
		MutantStack<int>::const_reverse_iterator crit = constStack.rbegin();
		MutantStack<int>::const_reverse_iterator crite = constStack.rend();
		for (; crit != crite; ++crit)
		{
			std::cout << *crit << " ";
		}
		std::cout << std::endl;
		
		std::cout << "const_reverse_iterator is read-only (cannot modify elements)" << std::endl;
	}
	
	// 4. すべてのイテレータタイプの比較
	printOutput(false, nullptr, "\n--- Iterator type comparison / イテレータタイプの比較 ---");
	{
		std::cout << "Forward (begin to end): ";
		for (MutantStack<int>::iterator it = testStack.begin(); it != testStack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		std::cout << "Reverse (rbegin to rend): ";
		for (MutantStack<int>::reverse_iterator it = testStack.rbegin(); it != testStack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		const MutantStack<int>& constStack = testStack;
		std::cout << "Const forward: ";
		for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		std::cout << "Const reverse: ";
		for (MutantStack<int>::const_reverse_iterator it = constStack.rbegin(); it != constStack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	
	// 5. イテレータの前後移動テスト（reverse_iterator）
	printOutput(false, nullptr, "\n--- Reverse iterator increment/decrement test / リバースイテレータ前後移動テスト ---");
	{
		MutantStack<int>::reverse_iterator rit = testStack.rbegin();
		std::cout << "Initial (rbegin): " << *rit << std::endl;
		++rit;
		std::cout << "After ++: " << *rit << std::endl;
		--rit;
		std::cout << "After --: " << *rit << std::endl;
		rit += 2;
		std::cout << "After += 2: " << *rit << std::endl;
	}
	
	printOutput(false, nullptr, "\n✅ Passed: Extended features test / 拡張機能テスト成功");
}
/* ************************************************************************** */	
void printOutput(bool useError, const char* color, const std::string& message, bool newline) {
	std::ostream& stream = useError ? std::cerr : std::cout;
	if (color != nullptr) {
		stream << color << message << RESET_COLOR;
	} else {
		stream << message;
	}
	if (newline) {
		stream << std::endl;
	}
}
