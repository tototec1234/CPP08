/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/19 15:03:27 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include "AnsiColor.hpp"
# include <limits>
# include <string>
# include <iostream>
# include <iterator>


// std::vector と std::list と std::deque はどれも sequenceコンテナ
// 課題書ではテンプレート関数として型Tを受け入れる設計（Tは整数のコンテナを想定）が求められているが、
// ただし: 連想コンテナ（associative containers : map/setなど）は扱う必要がない
// 課題書の原文: "You don't have to handle associative containers."
# include <vector>
# include <list>
# include <deque>
// # include <map>
// # include <set>

void printOutput(bool useError, const char* color, const std::string& message, bool newline = true);
template <typename T>
void printContainerContents(const T& container, const std::string& label);
void test_vector();
void test_list();
void test_deque();
/* ************************************************************************** */	
int main() {
	int choice;
	bool running = true;

	while (running) {
		printOutput(false, YELLOW_COLOR, "\n\n=== CPP08 Ex00: easyfind Test Menu ===");
		printOutput(false, NULL, "=== CPP08 演習00 テストメニュー ===");
		printOutput(false, NULL, "1: Test with std::vector                             std::vectorテスト");
		printOutput(false, NULL, "2: Test with std::list                               std::listテスト");
		printOutput(false, NULL, "3: Test with std::deque                              std::dequeテスト");
		printOutput(false, NULL, "0: Exit                                              終了");
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
					test_vector();
					break;
				case 2:
					test_list();
					break;
				case 3:
					test_deque();
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
void test_vector() {
	printOutput(false, GREEN_COLOR, "\n=== Testing with std::vector ===");
	printOutput(false, NULL, "=== std::vectorテスト ===");

	try {
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		printContainerContents(vec, "Vector contains");

		// 成功ケース
		printOutput(false, NULL, "\n--- Test 1: Finding existing value (3) / 既存の値の検索（3） ---");
		printOutput(false, GREEN_COLOR, "Calling: easyfind(vec, 3)");
		try {
			std::vector<int>::iterator result_it = easyfind(vec, 3);
			long index = std::distance(vec.begin(), result_it);
			std::cout << "Found: " << *result_it << " at index: " << index << std::endl;
			printOutput(false, NULL, "✅ Passed: Value found successfully / 値が見つかりました");
		} catch (const NoOccurrenceFoundException& e) {
			printOutput(false, NULL, std::string("❌ Failed: ") + e.what());
		}

		// 失敗ケース
		printOutput(false, NULL, "\n--- Test 2: Finding non-existing value (42) / 存在しない値の検索（42） ---");
		printOutput(false, GREEN_COLOR, "Calling: easyfind(vec, 42) - Expected to throw exception");
		try {
			std::vector<int>::iterator result_it = easyfind(vec, 42);
			long index = std::distance(vec.begin(), result_it);
			std::cout << "Found: " << *result_it << " at index: " << index << std::endl;
			printOutput(false, NULL, "❌ Failed: Exception should have been thrown! / 例外が発生するはずです！");
		} catch (const NoOccurrenceFoundException& e) {
			std::cout << "✅ Passed: Expected exception caught: " << e.what() << std::endl;
		}
	} catch (const std::exception &e) {
		printOutput(false, NULL, std::string("❌ Failed: ") + e.what());
	}
}
/* ************************************************************************** */	
void test_list() {
	printOutput(false, GREEN_COLOR, "\n=== Testing with std::list ===");
	printOutput(false, NULL, "=== std::listテスト ===");

	try {
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);

		printContainerContents(lst, "List contains");

		// 成功ケース
		printOutput(false, NULL, "\n--- Test 1: Finding existing value (20) / 既存の値の検索（20） ---");
		printOutput(false, GREEN_COLOR, "Calling: easyfind(lst, 20)");
		try {
			std::list<int>::iterator result = easyfind(lst, 20);
			long index = std::distance(lst.begin(), result);
			std::cout << "Found: " << *result << " at index: " << index << std::endl;
			printOutput(false, NULL, "✅ Passed: Value found successfully / 値が見つかりました");
		} catch (const NoOccurrenceFoundException& e) {
			printOutput(false, NULL, std::string("❌ Failed: ") + e.what());
		}

		// 失敗ケース
		printOutput(false, NULL, "\n--- Test 2: Finding non-existing value (42) / 存在しない値の検索（42） ---");
		printOutput(false, GREEN_COLOR, "Calling: easyfind(lst, 42) - Expected to throw exception");
		try {
			std::list<int>::iterator result = easyfind(lst, 42);
			std::cout << "Found: " << *result << std::endl;
			printOutput(false, NULL, "❌ Failed: Exception should have been thrown! / 例外が発生するはずです！");
		} catch (const NoOccurrenceFoundException& e) {
			std::cout << "✅ Passed: Expected exception caught: " << e.what() << std::endl;
		}
	} catch (const std::exception &e) {
		printOutput(false, NULL, std::string("❌ Failed: ") + e.what());
	}
}
/* ************************************************************************** */	
void test_deque() {
	printOutput(false, GREEN_COLOR, "\n=== Testing with std::deque ===");
	printOutput(false, NULL, "=== std::dequeテスト ===");

	try {
		std::deque<int> deq;
		deq.push_back(100);
		deq.push_back(200);
		deq.push_back(300);

		printContainerContents(deq, "Deque contains");

		// 成功ケース
		printOutput(false, NULL, "\n--- Test 1: Finding existing value (200) / 既存の値の検索（200） ---");
		printOutput(false, GREEN_COLOR, "Calling: easyfind(deq, 200)");
		try {
			std::deque<int>::iterator result = easyfind(deq, 200);
			long index = std::distance(deq.begin(), result);
			std::cout << "Found: " << *result << " at index: " << index << std::endl;
			printOutput(false, NULL, "✅ Passed: Value found successfully / 値が見つかりました");
		} catch (const NoOccurrenceFoundException& e) {
			printOutput(false, NULL, std::string("❌ Failed: ") + e.what());
		}

		// 失敗ケース
		printOutput(false, NULL, "\n--- Test 2: Finding non-existing value (42) / 存在しない値の検索（42） ---");
		printOutput(false, GREEN_COLOR, "Calling: easyfind(deq, 42) - Expected to throw exception");
		try {
			std::deque<int>::iterator result = easyfind(deq, 42);
			std::cout << "Found: " << *result << std::endl;
			printOutput(false, NULL, "❌ Failed: Exception should have been thrown! / 例外が発生するはずです！");
		} catch (const NoOccurrenceFoundException& e) {
			std::cout << "✅ Passed: Expected exception caught: " << e.what() << std::endl;
		}
	} catch (const std::exception &e) {
		printOutput(false, NULL, std::string("❌ Failed: ") + e.what());
	}
}
/* ************************************************************************** */	
// テンプレート関数として実装: std::listは[]演算子（Random Access）をサポートしていないため、
// すべてのコンテナタイプ（vector, list, deque）で共通して使用できるイテレータベースの実装が必要
template <typename T>
void printContainerContents(const T& container, const std::string& label) {
	std::cout << label << ": ";
	typename T::const_iterator it = container.begin();
	typename T::const_iterator end = container.end();
	for (; it != end; ++it) {
		std::cout << *it;
		typename T::const_iterator next = it;
		++next;
		if (next != end)
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
