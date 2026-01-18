/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/19 04:24:21 by toruinoue        ###   ########.fr       */
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
#include <sstream>

//listは双方向リストであることから、任意の位置での挿入と削除に優れている、
//でも今回はその機能使わないっぴ！
//というわけでvector使用。

void printOutput(bool useError, const char* color, const std::string& message, bool newline = true);
void test_subject();
void test_addRange();
void test_largeRange();
void test_capacityOverflow();
void test_insufficientElements();

int main() {
	// Seed random number generator
	std::srand(std::time(NULL));

	int choice;
	bool running = true;

	while (running) {
		printOutput(false, YELLOW_COLOR, "\n\n=== CPP08 Ex01: Span Test Menu ===");
		printOutput(false, nullptr, "=== CPP08 演習01 テストメニュー ===");
		printOutput(false, nullptr, "1: Test Subject (includes subject.pdf example)       課題書のテスト例");
		printOutput(false, nullptr, "2: Test addRange Function                           addRange関数テスト");
		printOutput(false, nullptr, "3: Test Large Range (999999 elements)               大量データテスト");
		printOutput(false, nullptr, "4: Test Capacity Overflow Exception                 容量オーバーフローテスト");
		printOutput(false, nullptr, "5: Test Insufficient Elements Exception             要素不足例外テスト");
		printOutput(false, nullptr, "0: Exit                                              終了");
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
					printOutput(false, nullptr, "Invalid selection. Please try again. / 無効な選択です。もう一度試してください。");
			}
		} catch (const std::exception &e) {
			printOutput(false, nullptr, std::string("⚠️ Exception caught: ") + e.what());
		}
	}

	return 0;
}

void test_subject() {
	printOutput(false, GREEN_COLOR, "\n=== Testing Subject Example ===");
	printOutput(false, nullptr, "=== 課題書のテスト例 ===");

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::ostringstream oss1;
		oss1 << "shortestSpan(): " << sp.shortestSpan();
		printOutput(false, nullptr, oss1.str());

		std::ostringstream oss2;
		oss2 << "longestSpan(): " << sp.longestSpan();
		printOutput(false, nullptr, oss2.str());

		printOutput(false, nullptr, "\n✅ Passed: Subject test / 課題書テスト成功");
	} catch (const std::exception &e) {
		printOutput(false, nullptr, std::string("❌ Failed: ") + e.what());
	}
}

void test_addRange() {
	printOutput(false, GREEN_COLOR, "\n=== Testing addRange Function ===");
	printOutput(false, nullptr, "=== addRange関数テスト ===");

	try {
		std::vector<int> sourceNumbers;
		sourceNumbers.push_back(1);
		sourceNumbers.push_back(5);
		sourceNumbers.push_back(3);
		sourceNumbers.push_back(9);
		sourceNumbers.push_back(2);

		Span bulkSpan(10);

		std::ostringstream oss;
		oss << "Source vector contains: ";
		for (std::vector<int>::size_type i = 0; i < sourceNumbers.size(); ++i) {
			oss << sourceNumbers[i];
			if (i < sourceNumbers.size() - 1)
				oss << " ";
		}
		printOutput(false, nullptr, oss.str());

		// addRangeを使用して一括追加!!!!!!!!!!!!!!!!!!!
		bulkSpan.addRange(sourceNumbers.begin(), sourceNumbers.end());

		std::ostringstream oss1;
		oss1 << "Shortest span: " << bulkSpan.shortestSpan();
		printOutput(false, nullptr, oss1.str());

		std::ostringstream oss2;
		oss2 << "Longest span: " << bulkSpan.longestSpan();
		printOutput(false, nullptr, oss2.str());

		printOutput(false, nullptr, "\n✅ Passed: addRange test / addRangeテスト成功");
	} catch (const std::exception& e) {
		printOutput(false, nullptr, std::string("❌ Failed: ") + e.what());
	}
}

void test_largeRange() {
	printOutput(false, GREEN_COLOR, "\n=== Testing Large Range ===");
	printOutput(false, nullptr, "=== 大量データテスト ===");

	try {
		Span largeSpan = Span(999999);
		std::vector<int> largeVec;
		std::srand(time(NULL));
		for (unsigned int i = 0; i < 999999; i++) {
			int random_int = rand() % 100000000;
			largeVec.push_back(random_int);
		}

		largeSpan.addRange(largeVec.begin(), largeVec.end());

		std::ostringstream oss1;
		oss1 << "shortest span: " << largeSpan.shortestSpan();
		printOutput(false, nullptr, oss1.str());

		std::ostringstream oss2;
		oss2 << "longest span: " << largeSpan.longestSpan();
		printOutput(false, nullptr, oss2.str());

		printOutput(false, nullptr, "\n✅ Passed: Large range test / 大量データテスト成功");
	} catch (const std::exception &e) {
		printOutput(false, nullptr, std::string("❌ Failed: ") + e.what());
	}
}

void test_capacityOverflow() {
	printOutput(false, GREEN_COLOR, "\n=== Testing Capacity Overflow Exception ===");
	printOutput(false, nullptr, "=== 容量オーバーフローテスト ===");

	// addNumber の容量オーバーフローテスト
	printOutput(false, nullptr, "\n----- Test: addNumber overflow / addNumberオーバーフロー -----");
	try {
		Span smallSpan(2);  // 容量2のSpanを作成
		smallSpan.addNumber(1);
		smallSpan.addNumber(2);
		// 3つ目の要素を追加しようとする（例外が発生するはず）
		
		smallSpan.addNumber(3);
		printOutput(false, nullptr, "❌ Failed: Exception should have been thrown!");
	} catch (const std::out_of_range& e) {
		std::ostringstream oss;
		oss << "✅ Passed: Expected overflow exception caught: " << e.what();
		printOutput(false, nullptr, oss.str());
	}

	// addRangeの容量オーバーフローテスト
	printOutput(false, nullptr, "\n----- Test: addRange overflow / addRangeオーバーフロー -----");
	try {
		std::vector<int> tooManyNumbers;
		for (int i = 0; i < 5; ++i) {
			tooManyNumbers.push_back(i * 10);
		}

		Span tinySpan(3);
		tinySpan.addRange(tooManyNumbers.begin(), tooManyNumbers.end());
		printOutput(false, nullptr, "❌ Failed: addRange should have thrown exception!");
	} catch (const std::out_of_range& e) {
		std::ostringstream oss;
		oss << "✅ Passed: Expected addRange overflow exception: " << e.what();
		printOutput(false, nullptr, oss.str());
	}

	printOutput(false, nullptr, "\n✅ Capacity overflow test completed / 容量オーバーフローテスト完了");
}

void test_insufficientElements() {
	printOutput(false, GREEN_COLOR, "\n=== Testing Insufficient Elements Exception ===");
	printOutput(false, nullptr, "=== 要素不足例外テスト ===");

	// empty span の shortestSpan テスト
	printOutput(false, nullptr, "\n----- Test: Empty span shortestSpan / 空のSpan shortestSpan -----");
	try {
		Span emptySpan(5);
		emptySpan.shortestSpan(); // 例外が発生するはず
		printOutput(false, nullptr, "❌ Failed: Empty span should throw exception!");
	} catch (const std::out_of_range& e) {
		std::ostringstream oss;
		oss << "✅ Passed: Empty span exception (shortest): " << e.what();
		printOutput(false, nullptr, oss.str());
	}

	// empty span の longestSpan テスト
	printOutput(false, nullptr, "\n----- Test: Empty span longestSpan / 空のSpan longestSpan -----");
	try {
		Span emptySpan(5);
		emptySpan.longestSpan(); // 例外が発生するはず
		printOutput(false, nullptr, "❌ Failed: Empty span should throw exception!");
	} catch (const std::out_of_range& e) {
		std::ostringstream oss;
		oss << "✅ Passed: Empty span exception (longest): " << e.what();
		printOutput(false, nullptr, oss.str());
	}

	// single element span のテスト
	printOutput(false, nullptr, "\n----- Test: Single element span / 単一要素Span -----");
	try {
		Span singleSpan(5);
		singleSpan.addNumber(42);
		singleSpan.shortestSpan(); // 例外が発生するはず
		printOutput(false, nullptr, "❌ Failed: Single element span should throw exception!");
	} catch (const std::out_of_range& e) {
		std::ostringstream oss;
		oss << "✅ Passed: Single element span exception: " << e.what();
		printOutput(false, nullptr, oss.str());
	}

	printOutput(false, nullptr, "\n✅ Insufficient elements test completed / 要素不足テスト完了");
}

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
