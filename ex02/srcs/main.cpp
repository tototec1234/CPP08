/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/19 17:40:25 by toruinoue        ###   ########.fr       */
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
template <typename T>
void printContainerContents(const T& container, const std::string& label = "");
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
		mstack.push(4200);
		mstack.push(4201);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(4202);
		mstack.push(4203);
		mstack.push(4204);
		mstack.push(4205);
		mstack.push(4206);
		mstack.push(4207);
		mstack.push(4208);
		mstack.push(4209);
		mstack.push(4210);
		mstack.push(4211);
		
		printContainerContents(mstack);
		MutantStack<int>::iterator it = mstack.begin();
		std::cout << "Step 1 - Iterator at begin(): " << *it << std::endl;
		++it;
		std::cout << "Step 2 - After ++it: " << *it << std::endl;
		++it;
		++it;
		std::cout << "Step 3 - After ++it (x2): " << *it << std::endl;
		--it;
		std::cout << "Step 4 - After --it: " << *it << std::endl;
		--it;
		--it;
		std::cout << "Step 5 - After --it (x2): " << *it << std::endl;
		++it;
		++it;
		++it;
		std::cout << "Step 6 - After ++it (x3): " << *it << std::endl;
		++it;
		++it;
		++it;
		++it;
		++it;
		++it;
		std::cout << "Step 7 - After ++it (x6): " << *it << std::endl;
		printContainerContents(mstack);
	}
	
	// std::listでの実行（同等の操作）
	printOutput(false, nullptr, "\n--- std::list output (should be identical) ---");
	{
		std::list<int> lst;
		lst.push_back(4200);    // push() → push_back()
		lst.push_back(4201);
		std::cout << lst.back() << std::endl;  // top() → back()
		lst.pop_back();      // pop() → pop_back()
		std::cout << lst.size() << std::endl;
		lst.push_back(4202);
		lst.push_back(4203);
		lst.push_back(4204);
		lst.push_back(4205);
		lst.push_back(4206);
		lst.push_back(4207);
		lst.push_back(4208);
		lst.push_back(4209);
		lst.push_back(4210);
		lst.push_back(4211);
		
		// イテレータの前後移動テスト（MutantStackと同じ動作）
		std::list<int>::iterator it = lst.begin();
		std::cout << "Step 1 - Iterator at begin(): " << *it << std::endl;
		++it;
		std::cout << "Step 2 - After ++it: " << *it << std::endl;
		++it;
		++it;
		std::cout << "Step 3 - After ++it (x2): " << *it << std::endl;
		--it;
		std::cout << "Step 4 - After --it: " << *it << std::endl;
		--it;
		--it;
		std::cout << "Step 5 - After --it (x2): " << *it << std::endl;
		++it;
		++it;
		++it;
		std::cout << "Step 6 - After ++it (x3): " << *it << std::endl;
		++it;
		++it;
		++it;
		++it;
		++it;
		++it;
		std::cout << "Step 7 - After ++it (x6): " << *it << std::endl;
		printContainerContents(lst);
	}
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
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int> emptyStack;");
		MutantStack<int> emptyStack;
		printOutput(false, GREEN_COLOR, "Calling: emptyStack.size()");
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
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int> singleStack;");
		MutantStack<int> singleStack;
		printOutput(false, GREEN_COLOR, "Calling: singleStack.push(42);");
		singleStack.push(42);
		std::cout << "Single element: ";
		printContainerContents(singleStack);
	}
	
	// 3. 大量の要素
	printOutput(false, nullptr, "\n--- Large stack (1000 elements) ---");
	{
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int> largeStack;");
		MutantStack<int> largeStack;
		printOutput(false, GREEN_COLOR, "Calling: for (int i = 0; i < 1000; ++i) { largeStack.push(i); }");
		for (int i = 0; i < 1000; ++i)
		{
			largeStack.push(i);
		}
		printContainerContents(largeStack);
		std::cout << "Stack size: " << largeStack.size() << std::endl;
		std::cout << "Top element: " << largeStack.top() << std::endl;
		
		// イテレータの移動を確認（スタックの底から順に）
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int>::iterator it = largeStack.begin();");
		MutantStack<int>::iterator it = largeStack.begin();
		std::cout << "Iterator at begin() (bottom of stack): " << *it << std::endl;
		
		printOutput(false, GREEN_COLOR, "Calling: ++it (x10 times)");
		for (int i = 0; i < 10; ++i)
		{
			++it;
		}
		std::cout << "After ++it (x10): " << *it << std::endl;
		
		printOutput(false, GREEN_COLOR, "Calling: --it (x5 times)");
		for (int i = 0; i < 5; ++i)
		{
			--it;
		}
		std::cout << "After --it (x5): " << *it << std::endl;
		
		// 最後の要素（top）の直前まで移動して確認
		printOutput(false, GREEN_COLOR, "Iterating to last element (top of stack)");
		MutantStack<int>::iterator it_end = largeStack.end();
		--it_end;  // end()の1つ前が最後の要素（top）
		std::cout << "Last element (top): " << *it_end << std::endl;
		
		// 現在位置から最後の要素までの距離を計算
		int distance = 0;
		MutantStack<int>::iterator it_temp = it;
		while (it_temp != largeStack.end())
		{
			++it_temp;
			++distance;
		}
		std::cout << "Distance from current position to end(): " << distance << std::endl;
	}
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
		printContainerContents(stringStack);
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
		printContainerContents(doubleStack);
		std::cout << "Top: " << doubleStack.top() << std::endl;
	}
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
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int> original;");
		MutantStack<int> original;
		printOutput(false, GREEN_COLOR, "Calling: original.push(10);");
		original.push(10);
		printOutput(false, GREEN_COLOR, "Calling: original.push(20);");
		original.push(20);
		printOutput(false, GREEN_COLOR, "Calling: original.push(30);");
		original.push(30);
		
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int> copied(original);");
		MutantStack<int> copied(original);
		
		std::cout << "Original size: " << original.size() << std::endl;
		std::cout << "Copied size: " << copied.size() << std::endl;
		
		std::cout << "Original contents: ";
		printContainerContents(original);
		
		std::cout << "Copied contents: ";
		printContainerContents(copied);
	}
	
	// 代入演算子
	// 要素数1個のMutantStackインスタンスに要素数4個のインスタンスを代入
	printOutput(false, nullptr, "\n--- Assignment: 1-element instance ← 4-element instance ---");
	{
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int> source;");
		MutantStack<int> source;
		printOutput(false, GREEN_COLOR, "Calling: source.push(100);");
		source.push(100);
		printOutput(false, GREEN_COLOR, "Calling: source.push(200);");
		source.push(200);
		printOutput(false, GREEN_COLOR, "Calling: source.push(300);");
		source.push(300);
		printOutput(false, GREEN_COLOR, "Calling: source.push(400);");
		source.push(400);
		
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int> target;");
		MutantStack<int> target;
		printOutput(false, GREEN_COLOR, "Calling: target.push(999);  // これは上書きされる");
		target.push(999);  // これは上書きされる
		
		std::cout << "Target before assignment - size: " << target.size() << std::endl;
		std::cout << "Target before assignment - contents: ";
		printContainerContents(target);
		
		printOutput(false, GREEN_COLOR, "Calling: target = source;");
		target = source;
		
		std::cout << "Source size: " << source.size() << std::endl;
		std::cout << "Target size: " << target.size() << std::endl;
		
		std::cout << "Target contents: ";
		printContainerContents(target);
	}
	
	// 要素数4個のMutantStackインスタンスに要素数1個のインスタンスを代入
	printOutput(false, nullptr, "\n--- Assignment: 4-element instance ← 1-element instance ---");
	{
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int> largeStack;");
		MutantStack<int> largeStack;
		printOutput(false, GREEN_COLOR, "Calling: largeStack.push(1000);");
		largeStack.push(1000);
		printOutput(false, GREEN_COLOR, "Calling: largeStack.push(2000);");
		largeStack.push(2000);
		printOutput(false, GREEN_COLOR, "Calling: largeStack.push(3000);");
		largeStack.push(3000);
		printOutput(false, GREEN_COLOR, "Calling: largeStack.push(4000);");
		largeStack.push(4000);
		
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int> smallStack;");
		MutantStack<int> smallStack;
		printOutput(false, GREEN_COLOR, "Calling: smallStack.push(50);");
		smallStack.push(50);
		
		std::cout << "largeStack before assignment - size: " << largeStack.size() << std::endl;
		std::cout << "largeStack before assignment - contents: ";
		printContainerContents(largeStack);
		
		std::cout << "smallStack size: " << smallStack.size() << std::endl;
		std::cout << "smallStack contents: ";
		printContainerContents(smallStack);
		
		printOutput(false, GREEN_COLOR, "Calling: largeStack = smallStack;");
		largeStack = smallStack;
		
		std::cout << "largeStack after assignment - size: " << largeStack.size() << std::endl;
		std::cout << "largeStack after assignment - contents: ";
		printContainerContents(largeStack);
	}
}
/* ************************************************************************** */	
// 拡張機能テスト
// const_iterator、reverse_iterator、const_reverse_iteratorの動作を確認する
void extended_features_test() {
	printOutput(false, GREEN_COLOR, "\n=== Extended Features Test ===");
	printOutput(false, nullptr, "=== 拡張機能テスト ===");
	
	// テスト用のスタックを準備
	MutantStack<int> testStack;
	testStack.push(1009);
	testStack.push(2008);
	testStack.push(3007);
	testStack.push(4006);
	testStack.push(5005);
	testStack.push(6004);
	testStack.push(7003);
	testStack.push(9002);
	testStack.push(11111);
		
	
	// 1. const_iteratorのテスト
	printOutput(false, nullptr, "\n--- const_iterator test / const_iteratorテスト ---");
	{
		const MutantStack<int>& constStack = testStack;
		
		printOutput(false, CYAN_COLOR, "Forward iteration with const_iterator: ", false);
		for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
		{
			std::cout << *cit << " ";
		}
		std::cout << std::endl;
		
		// const_iteratorは読み取り専用であることを確認
		printOutput(false, CYAN_COLOR, "const_iterator is read-only (cannot modify elements)");
	}
	
	// 2. reverse_iteratorのテスト
	printOutput(false, nullptr, "\n--- reverse_iterator test / reverse_iteratorテスト ---");
	{
		printOutput(false, CYAN_COLOR, "Reverse iteration with reverse_iterator: ", false);
		for (MutantStack<int>::reverse_iterator rit = testStack.rbegin(); rit != testStack.rend(); ++rit)
		{
			std::cout << *rit << " ";
		}
		std::cout << std::endl;
		printOutput(false, GREEN_COLOR, "Calling: printContainerContents(testStack);");
		printContainerContents(testStack);	
		
		// reverse_iteratorで要素を変更できることを確認
		printOutput(false, CYAN_COLOR, "Modifying elements with reverse_iterator: \n", false);
		MutantStack<int>::reverse_iterator mod_it = testStack.rbegin();
		printOutput(false, GREEN_COLOR, "Calling: MutantStack<int>::reverse_iterator mod_it = testStack.rbegin();");
		*mod_it = 99;
		printOutput(false, GREEN_COLOR, "Calling: *mod_it = 99;");
		printOutput(false, CYAN_COLOR, "Modified last element to: ", false);
		std::cout << *mod_it << std::endl;
		printContainerContents(testStack);
		// 元に戻す
		*mod_it = 5;
		printOutput(false, GREEN_COLOR, "Calling: *mod_it = 5;");
		printContainerContents(testStack);
	}
	
	// 3. const_reverse_iteratorのテスト
	printOutput(false, nullptr, "\n--- const_reverse_iterator test / const_reverse_iteratorテスト ---");
	{
		const MutantStack<int>& constStack = testStack;
		
		printOutput(false, CYAN_COLOR, "Reverse iteration with const_reverse_iterator: ", false);
		for (MutantStack<int>::const_reverse_iterator crit = constStack.rbegin(); crit != constStack.rend(); ++crit)
		{
			std::cout << *crit << " ";
		}
		std::cout << std::endl;
		printContainerContents(testStack);
		printOutput(false, CYAN_COLOR, "const_reverse_iterator is read-only (cannot modify elements)");
	}
	
	// 4. すべてのイテレータタイプの比較
	printOutput(false, nullptr, "\n--- Iterator type comparison / イテレータタイプの比較 ---");
	{
		printOutput(false, CYAN_COLOR, "Forward (begin to end): ", false);
		for (MutantStack<int>::iterator it = testStack.begin(); it != testStack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		printOutput(false, CYAN_COLOR, "Reverse (rbegin to rend): ", false);
		for (MutantStack<int>::reverse_iterator it = testStack.rbegin(); it != testStack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		const MutantStack<int>& constStack = testStack;
		printOutput(false, CYAN_COLOR, "Const forward: ", false);
		for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		printOutput(false, CYAN_COLOR, "Const reverse: ", false);
		for (MutantStack<int>::const_reverse_iterator it = constStack.rbegin(); it != constStack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	
	// 5. イテレータの前後移動テスト（reverse_iterator）
	printOutput(false, nullptr, "\n--- Reverse iterator increment/decrement test / リバースイテレータ前後移動テスト ---");
	{
		printContainerContents(testStack);
		MutantStack<int>::reverse_iterator rit = testStack.rbegin();
		std::cout << "Initial (rbegin): " << *rit << std::endl;
		++rit;
		printOutput(false, CYAN_COLOR, "After ++: ", false);
		std::cout << *rit << std::endl;
		--rit;
		printOutput(false, CYAN_COLOR, "After --: ", false);
		std::cout << *rit << std::endl;
		rit += 2;
		printOutput(false, CYAN_COLOR, "After += 2: ", false);
		std::cout << *rit << std::endl;
		rit -= 4;
		printOutput(false, CYAN_COLOR, "After -= 4: ", false);
		std::cout << *rit << std::endl;
	}
}
/* ************************************************************************** */	
// テンプレート関数として実装: std::listは[]演算子（Random Access）をサポートしていないため、
// すべてのコンテナタイプ（vector, list, deque, MutantStackなど）で共通して使用できるイテレータベースの実装が必要
template <typename T>
void printContainerContents(const T& container, const std::string& label) {
	if (!label.empty())
		std::cout << label << ": ";
	if (container.empty()) {
		std::cout << "empty container" << std::endl;
		return;
	}
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl;
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
