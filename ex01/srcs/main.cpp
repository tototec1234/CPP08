/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/20 00:11:45 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "AnsiColor.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

//コンテナ選択の理由：
//listは双方向リストであることから、任意の位置での挿入と削除に優れているが、
//本実装ではshortestSpan()でstd::sort()を使用する必要がある。
//std::sort()はランダムアクセスイテレータを要求するが、std::listはランダムアクセスイテレータを提供しない。
//そのため、std::listを使用する場合はlist::sort()（コンテナ固有メソッド）を使う必要がある。
//しかし、CPP08課題書（Chapter III Module-specific rules）では、
//"the Algorithms (defined in header <algorithm>)"の使用が明確に求められており、
//std::sort()などの<algorithm>ヘッダーのアルゴリズムを使用することが教育目的である。
//したがって、ランダムアクセスイテレータを提供するstd::vectorを使用する。

void printOutput(bool useError, const char* color, const std::string& message, bool newline = true);
void printVectorContents(const std::vector<int>& vec, const std::string& label);
void test_subject();
void test_addRange();
void test_largeRange();
void test_capacityOverflow();
void test_insufficientElements();
/* ************************************************************************** */	
int main() {
	// Seed random number generator
	std::srand(std::time(NULL));

	int choice;
	bool running = true;

	while (running) {
		printOutput(false, YELLOW_COLOR, "\n\n=== CPP08 Ex01: Span Test Menu ===");
		printOutput(false, NULL, "=== CPP08 演習01 テストメニュー ===");
		printOutput(false, NULL, "1: Test Subject (includes subject.pdf example)      課題書のテスト例");
		printOutput(false, NULL, "2: Test addRange Function                           addRange関数テスト");
		printOutput(false, NULL, "3: Test Large Range (123456 elements)               大量データテスト");
		printOutput(false, NULL, "4: Test Capacity Overflow Exception                 容量オーバーフローテスト");
		printOutput(false, NULL, "5: Test Insufficient Elements Exception             要素不足例外テスト");
		printOutput(false, NULL, "0: Exit                                             終了");
		std::cout << "Choose an option / 選択してください: ";

		if (!(std::cin >> choice)) {
			if (std::cin.eof()) {
				printOutput(false, NULL, "\nEOF detected. Exiting... / EOFが検出されました。終了します...");
				break;
			}
			printOutput(false, NULL, "⚠️ Invalid input! Please enter a number. / 無効な入力です！数字を入力してください。");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		try {
			switch (choice) {
				case 1:
					test_subject();
					break;
				case 2:
					test_addRange();
					break;
				case 3:
					test_largeRange();
					break;
				case 4:
					test_capacityOverflow();
					break;
				case 5:
					test_insufficientElements();
					break;
				case 0:
					running = false;
					break;
				default:
					printOutput(false, NULL, "Invalid selection. Please try again. / 無効な選択です。もう一度試してください。");
			}
		} catch (const std::exception &e) {
			printOutput(false, NULL, std::string("⚠️ Exception caught: ") + e.what());
		}
	}

	return 0;
}
/* ************************************************************************** */	
void test_subject() {
	printOutput(false, GREEN_COLOR, "\n=== 1: Testing Subject Example ===");
	printOutput(false, NULL, "=== 1: 課題書のテスト例 ===");

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		printOutput(false, NULL, "Span contents:");
		sp.printContents();

		std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;

		std::cout << "longestSpan(): " << sp.longestSpan() << std::endl;

		printOutput(false, NULL, "\n✅ Passed: Subject test / 課題書テスト成功");
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
}
/* ************************************************************************** */	
void test_addRange() {
	printOutput(false, GREEN_COLOR, "\n=== 2: Testing addRange Function ===");
	printOutput(false, NULL, "=== 2: addRange関数テスト ===");

	// 1. 基本的な使用例：空のSpanに一括追加
	printOutput(false, NULL, "\n----- Test 1: Basic addRange (empty Span) / 基本使用例（空のSpan） -----");
	try {
		std::vector<int> sourceNumbers;
		sourceNumbers.push_back(1);
		sourceNumbers.push_back(5);
		sourceNumbers.push_back(3);
		sourceNumbers.push_back(9);
		sourceNumbers.push_back(2);

		Span bulkSpan(10);
		printOutput(false, GREEN_COLOR, "Calling: Span bulkSpan(10)");
		bulkSpan.printContents();
		std::cout << std::endl;

		printVectorContents(sourceNumbers, "Source vector contains : sourceNumbers");

		// addRangeを使用して一括追加!!!!!!!!!!!!!!!!!!!
		printOutput(false, GREEN_COLOR, "Calling: bulkSpan.addRange(sourceNumbers.begin(), sourceNumbers.end())");
		bulkSpan.addRange(sourceNumbers.begin(), sourceNumbers.end());

		printOutput(false, NULL, "Span contents after addRange:");
		bulkSpan.printContents();
	} catch (const std::exception& e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}

	// 2. 実用的なケース：部分的に満たされたSpanへの追加
	printOutput(false, NULL, "\n----- Test 2: addRange to partially filled Span / 部分的に満たされたSpanへの追加 -----");
	try {
		Span span(10);
		span.addNumber(100);
		span.addNumber(200);
		span.printContents();

		std::vector<int> additionalNumbers;
		additionalNumbers.push_back(50);
		additionalNumbers.push_back(150);
		additionalNumbers.push_back(250);

		printVectorContents(additionalNumbers, "Additional vector contains");

		printOutput(false, GREEN_COLOR, "Calling: span.addRange(additionalNumbers.begin(), additionalNumbers.end())");
		span.addRange(additionalNumbers.begin(), additionalNumbers.end());

		span.printContents();
	} catch (const std::exception& e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}

	// 3. 複数回のaddRange呼び出し
	printOutput(false, NULL, "\n----- Test 3: Multiple addRange calls / 複数回のaddRange呼び出し -----");
	try {
		Span span(15);
		printOutput(false, GREEN_COLOR, "Calling: Span span(15)");
		span.printContents();

		std::vector<int> batch1;
		batch1.push_back(10);
		batch1.push_back(20);
		batch1.push_back(30);

		std::vector<int> batch2;
		batch2.push_back(40);
		batch2.push_back(50);

		std::vector<int> batch3;
		batch3.push_back(60);
		batch3.push_back(70);
		batch3.push_back(80);

		printVectorContents(batch1, "Batch1 vector contains");
		printOutput(false, GREEN_COLOR, "Calling: span.addRange(batch1.begin(), batch1.end())");
		span.addRange(batch1.begin(), batch1.end());
		span.printContents();

		printVectorContents(batch2, "Batch2 vector contains");
		printOutput(false, GREEN_COLOR, "Calling: span.addRange(batch2.begin(), batch2.end())");
		span.addRange(batch2.begin(), batch2.end());
		span.printContents();

		printVectorContents(batch3, "Batch3 vector contains");
		printOutput(false, GREEN_COLOR, "Calling: span.addRange(batch3.begin(), batch3.end())");
		span.addRange(batch3.begin(), batch3.end());
		span.printContents();
	} catch (const std::exception& e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}

	// 4. 境界値テスト：ちょうど容量に達する場合
	printOutput(false, NULL, "\n----- Test 4: Boundary test (exact capacity) / 境界値テスト（ちょうど容量） -----");
	try {
		Span span(5);
		printOutput(false, GREEN_COLOR, "Calling: Span span(5)");
		span.printContents();

		std::vector<int> exactFit;
		exactFit.push_back(1);
		exactFit.push_back(2);
		exactFit.push_back(3);
		exactFit.push_back(4);
		exactFit.push_back(5);

		printVectorContents(exactFit, "Exact fit vector contains");
		printOutput(false, GREEN_COLOR, "Calling: span.addRange(exactFit.begin(), exactFit.end())");
		span.addRange(exactFit.begin(), exactFit.end());

		span.printContents();
	} catch (const std::exception& e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}

	// 5. 部分的に満たされたSpanへのオーバーフローテスト
	printOutput(false, NULL, "\n----- Test 5: Overflow with partially filled Span / 部分的に満たされたSpanへのオーバーフロー -----");
	try {
		Span span(5);
		span.addNumber(10);
		span.addNumber(20);
		span.printContents();

		std::vector<int> tooMany;
		tooMany.push_back(30);
		tooMany.push_back(40);
		tooMany.push_back(50);
		tooMany.push_back(60);  // これで合計6要素になる（容量5を超える）

		printVectorContents(tooMany, "Too many vector contains");
		printOutput(false, GREEN_COLOR, "Calling: span.addRange(tooMany.begin(), tooMany.end()) - Expected to throw exception");
		span.addRange(tooMany.begin(), tooMany.end());
		std::cout << "❌ Failed: Exception should have been thrown!" << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "✅ Passed: Expected overflow exception: " << e.what() << std::endl;
	}

	// 6. 空の範囲の追加（begin == end）
	printOutput(false, NULL, "\n----- Test 6: Empty range (begin == end) / 空の範囲（begin == end） -----");
	try {
		Span span(10);
		span.addNumber(100);
		span.printContents();

		std::vector<int> emptyVec;
		std::cout << "Empty vector contains: (empty)" << std::endl;
		printOutput(false, GREEN_COLOR, "Calling: span.addRange(emptyVec.begin(), emptyVec.end()) - Empty range");
		span.addRange(emptyVec.begin(), emptyVec.end());  // 空の範囲

		span.printContents();

		std::cout << "✅ Passed: Empty range addition succeeded (should have no effect)" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}

	// 7. 部分範囲の追加（配列の一部のみを追加）
	printOutput(false, NULL, "\n----- Test 7: Partial range addition / 部分範囲の追加 -----");
	try {
		Span span(10);
		printOutput(false, GREEN_COLOR, "Calling: Span span(10)");
		span.printContents();

		std::vector<int> fullArray;
		fullArray.push_back(10);	// インデックス　0
		fullArray.push_back(20);	// インデックス　1
		fullArray.push_back(30);	// インデックス　2
		fullArray.push_back(40);	// インデックス　3
		fullArray.push_back(50);	// インデックス　4
		fullArray.push_back(60);	// インデックス　5
		fullArray.push_back(70);	// インデックス　6
		fullArray.push_back(80);	// インデックス　7

		printVectorContents(fullArray, "Full array contains");

		// 配列の一部（インデックス1から2まで、つまり{20,30}）のみを追加 ///////////////////////////////
		std::vector<int>::iterator start = fullArray.begin() + 1;  // インデックス1から
		std::vector<int>::iterator end = fullArray.begin() + 3;    // インデックス3まで（3は含まない）

		std::cout << "Partial range to add: ";
		for (std::vector<int>::iterator it = start; it != end; ++it) {
			std::cout << *it;
			if (it + 1 != end)
				std::cout << " ";
		}
		std::cout << " (indices 1-2 of full array)" << std::endl;

		printOutput(false, GREEN_COLOR, "Calling: span.addRange(fullArray.begin() + 1, fullArray.begin() + 3)");
		span.addRange(start, end);

		span.printContents();

		// さらに別の部分範囲（インデックス4から6まで、つまり{50,60,70}）を追加  ///////////////////////////////
		std::vector<int>::iterator start2 = fullArray.begin() + 4;  // インデックス4から
		std::vector<int>::iterator end2 = fullArray.begin() + 7;    // インデックス7まで（7は含まない）

		std::cout << "Partial range to add: ";
		for (std::vector<int>::iterator it = start2; it != end2; ++it) {
			std::cout << *it;
			if (it + 1 != end2)
				std::cout << " ";
		}
		std::cout << " (indices 4-6 of full array)" << std::endl;

		printOutput(false, GREEN_COLOR, "Calling: span.addRange(fullArray.begin() + 4, fullArray.begin() + 7)");
		span.addRange(start2, end2);

		span.printContents();

		// さらに別の部分範囲（インデックス0から1まで、つまり{10,20}）を追加  ///////////////////////////////
		std::vector<int>::iterator start3 = fullArray.begin() + 0;  // インデックス0から
		std::vector<int>::iterator end3 = fullArray.begin() + 2;    // インデックス2まで（2は含まない）

				std::cout << "Partial range to add: ";
		for (std::vector<int>::iterator it = start3; it != end3; ++it) {
			std::cout << *it;
			if (it + 1 != end3)
				std::cout << " ";
		}
		std::cout << " (indices 0-1 of full array)" << std::endl;

		
		printOutput(false, GREEN_COLOR, "Calling: span.addRange(fullArray.begin() + 0, fullArray.begin() + 2)");
		span.addRange(start3, end3);

		span.printContents();
		// // さらにfullArrayに9と10を追加
		// fullArray.push_back(9);
		// fullArray.push_back(10);
		// printVectorContents(fullArray, "Full array after adding 9 and 10 contains");

		// 全部を追加しようとする（現在7個入っているので、7+10=17個になり容量10を超える）
		std::cout << "Attempting to add all elements: ";
		for (std::vector<int>::size_type i = 0; i < fullArray.size(); ++i) {
			std::cout << fullArray[i];
			if (i < fullArray.size() - 1)
				std::cout << " ";
		}
		std::cout << " (all elements of full array, would cause overflow)" << std::endl;

		printOutput(false, GREEN_COLOR, "Calling: span.addRange(fullArray.begin(), fullArray.end()) - Expected to throw exception");
		try {
			span.addRange(fullArray.begin(), fullArray.end());
			std::cout << "❌ Failed: Exception should have been thrown!" << std::endl;
		} catch (const std::out_of_range& e) {
			std::cout << "✅ Passed: Expected overflow exception: " << e.what() << std::endl;
		}
	} catch (const std::exception& e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
}
/* ************************************************************************** */	
void test_largeRange() {
	printOutput(false, GREEN_COLOR, "\n=== 3: Testing Large Range ===");
	printOutput(false, NULL, "=== 3: 大量データテスト ===");

	try {
		printOutput(false, GREEN_COLOR, "Calling: Span largeSpan(123456)");
		Span largeSpan = Span(123456);
		std::vector<int> largeVec;
		std::srand(time(NULL));
		for (unsigned int i = 0; i < 123456; i++) {
			int random_int = rand() % 1234567890;
			largeVec.push_back(random_int);
		}

		printOutput(false, GREEN_COLOR, "Calling: largeSpan.addRange(largeVec.begin(), largeVec.end()) - Adding 123456 elements");
		largeSpan.addRange(largeVec.begin(), largeVec.end());

		std::cout << "shortest span: " << largeSpan.shortestSpan() << std::endl;

		std::cout << "longest span: " << largeSpan.longestSpan() << std::endl;

		printOutput(false, NULL, "\n✅ Passed: Large range test / 大量データテスト成功");
	} catch (const std::exception &e) {
		printOutput(false, NULL, std::string("❌ Failed: ") + e.what());
	}
}
/* ************************************************************************** */	
void test_capacityOverflow() {
	printOutput(false, GREEN_COLOR, "\n=== 4: Testing Capacity Overflow Exception ===");
	printOutput(false, NULL, "=== 4: 容量オーバーフローテスト ===");

	// addNumber の容量オーバーフローテスト	 //////////////////////////////////////
	printOutput(false, NULL, "\n----- Test: addNumber overflow / addNumberオーバーフロー -----");
	try {
		printOutput(false, GREEN_COLOR, "Calling: Span smallSpan(2)");
		Span smallSpan(2);  // 容量2のSpanを作成
		printOutput(false, GREEN_COLOR, "Calling: smallSpan.addNumber(1)");
		smallSpan.addNumber(1);
		printOutput(false, GREEN_COLOR, "Calling: smallSpan.addNumber(2)");
		smallSpan.addNumber(2);
		// 3つ目の要素を追加しようとする（例外が発生するはず）
		printOutput(false, GREEN_COLOR, "Calling: smallSpan.addNumber(3) - Expected to throw exception");
		smallSpan.addNumber(3);
		printOutput(false, NULL, "❌ Failed: Exception should have been thrown!");
	} catch (const std::out_of_range& e) {
		std::cout << "✅ Passed: Expected overflow exception caught: " << e.what() << std::endl;
	}

	// addRangeの容量オーバーフローテスト	 //////////////////////////////////////
	printOutput(false, NULL, "\n----- Test: addRange overflow / addRangeオーバーフロー -----");
	try {
		std::vector<int> tooManyNumbers;
		for (int i = 0; i < 5; ++i) {
			tooManyNumbers.push_back(i * 10);
		}
		printVectorContents(tooManyNumbers, "Source vector contains : tooManyNumbers");
		printOutput(false, GREEN_COLOR, "Calling: Span tinySpan(3)");
		Span tinySpan(3);
		printOutput(false, GREEN_COLOR, "Calling: tinySpan.addRange(tooManyNumbers.begin(), tooManyNumbers.end()) - Expected to throw exception");
		tinySpan.addRange(tooManyNumbers.begin(), tooManyNumbers.end());
		printOutput(false, NULL, "❌ Failed: addRange should have thrown exception!");
	} catch (const std::out_of_range& e) {
		std::cout << "✅ Passed: Expected addRange overflow exception: " << e.what() << std::endl;
	}

	printOutput(false, NULL, "\n✅ Capacity overflow test completed / 容量オーバーフローテスト完了");
}
/* ************************************************************************** */	
void test_insufficientElements() {	printOutput(false, GREEN_COLOR, "\n=== 5: Testing Insufficient Elements Exception ===");

	printOutput(false, NULL, "=== 5: 要素不足例外テスト ===");

	// empty span の shortestSpan テスト //////////////////////////////////////
	printOutput(false, NULL, "\n----- Test: Empty span shortestSpan / 空のSpan shortestSpan -----");
	try {
		printOutput(false, GREEN_COLOR, "Calling: Span emptySpan(5)");
		Span emptySpan(5);
		printOutput(false, GREEN_COLOR, "Calling: emptySpan.shortestSpan() - Expected to throw exception");
		emptySpan.shortestSpan(); // 例外が発生するはず
		printOutput(false, NULL, "❌ Failed: Empty span should throw exception!");
	} catch (const std::out_of_range& e) {
		std::cout << "✅ Passed: Empty span exception (shortest): " << e.what() << std::endl;
	}

	// empty span の longestSpan テスト //////////////////////////////////////
	printOutput(false, NULL, "\n----- Test: Empty span longestSpan / 空のSpan longestSpan -----");
	try {
		printOutput(false, GREEN_COLOR, "Calling: Span emptySpan(5)");
		Span emptySpan(5);
		printOutput(false, GREEN_COLOR, "Calling: emptySpan.longestSpan() - Expected to throw exception");
		emptySpan.longestSpan(); // 例外が発生するはず
		printOutput(false, NULL, "❌ Failed: Empty span should throw exception!");
	} catch (const std::out_of_range& e) {
		std::cout << "✅ Passed: Empty span exception (longest): " << e.what() << std::endl;
	}

	// single element span の shortestSpan テスト //////////////////////////////////////
	printOutput(false, NULL, "\n----- Test: Single element span shortestSpan / 単一要素Span shortestSpan -----");
	try {
		printOutput(false, GREEN_COLOR, "Calling: Span singleSpan(5)");
		Span singleSpan(5);
		printOutput(false, GREEN_COLOR, "Calling: singleSpan.addNumber(42)");
		singleSpan.addNumber(42);
		printOutput(false, GREEN_COLOR, "Calling: singleSpan.shortestSpan() - Expected to throw exception");
		singleSpan.shortestSpan(); // 例外が発生するはず
		printOutput(false, NULL, "❌ Failed: Single element span should throw exception!");
	} catch (const std::out_of_range& e) {
		std::cout << "✅ Passed: Single element span exception (shortest): " << e.what() << std::endl;
	}

	// single element span の longestSpan テスト  //////////////////////////////////////
	printOutput(false, NULL, "\n----- Test: Single element span longestSpan / 単一要素Span longestSpan -----");
	try {
		printOutput(false, GREEN_COLOR, "Calling: Span singleSpan(5)");
		Span singleSpan(5);
		printOutput(false, GREEN_COLOR, "Calling: singleSpan.addNumber(42)");
		singleSpan.addNumber(42);
		printOutput(false, GREEN_COLOR, "Calling: singleSpan.longestSpan() - Expected to throw exception");
		singleSpan.longestSpan(); // 例外が発生するはず
		printOutput(false, NULL, "❌ Failed: Single element span should throw exception!");
	} catch (const std::out_of_range& e) {
		std::cout << "✅ Passed: Single element span exception (longest): " << e.what() << std::endl;
	}

	printOutput(false, NULL, "\n✅ Insufficient elements test completed / 要素不足テスト完了");
}
/* ************************************************************************** */	
void printVectorContents(const std::vector<int>& vec, const std::string& label) {
	std::cout << label << ": ";
	for (std::vector<int>::size_type i = 0; i < vec.size(); ++i) {
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}
/* ************************************************************************** */	
void printOutput(bool useError, const char* color, const std::string& message, bool newline) {
	std::ostream& stream = useError ? std::cerr : std::cout;
	if (color != NULL) {
		stream << color << message << RESET_COLOR;
	} else {
		stream << message;
	}
	if (newline) {
		stream << std::endl;
	}
}
