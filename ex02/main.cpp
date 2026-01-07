/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:00:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/07 23:41:22 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AnsiColor.hpp"
#include <limits>

void testBasicCreation();
void testExceptionHandling();
void testGradeIncrementDecrement();
void testOutputOperator();
void testCopyAndAssignment();
void testBoundaryValues();

int main() {
	int choice;
	bool running = true;

	while (running) {
		std::cout << YELLOW_COLOR << "\n\n=== CPP05 Ex00: Bureaucrat Test Menu ===" << RESET_COLOR << std::endl;
		std::cout << "=== CPP05 演習00 テストメニュー ===" << std::endl;
		std::cout << "1: Test Basic Creation                                   基本作成テスト" << std::endl;
		std::cout << "2: Test Exception Handling                               例外処理テスト" << std::endl;
		std::cout << "3: Test Grade Increment/Decrement                        等級増減テスト" << std::endl;
		std::cout << "4: Test Output Operator                                  出力演算子テスト" << std::endl;
		std::cout << "5: Test Copy and Assignment                              コピー・代入テスト" << std::endl;
		std::cout << "6: Test Boundary Values                                  境界値テスト" << std::endl;
		std::cout << "0: Exit                                                  終了" << std::endl;
		std::cout << "Choose an option / 選択してください: ";

		// Exception-safe input handling
		if (!(std::cin >> choice)) {
			std::cout << "⚠️ Invalid input! Please enter a number. / 無効な入力です！数字を入力してください。" << std::endl;
			std::cin.clear();  // Clear error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
			continue;
		}

		try {
			switch (choice) {
				case 1:
					testBasicCreation();
					break;
				case 2:
					testExceptionHandling();
					break;
				case 3:
					testGradeIncrementDecrement();
					break;
				case 4:
					testOutputOperator();
					break;
				case 5:
					testCopyAndAssignment();
					break;
				case 6:
					testBoundaryValues();
					break;
				case 0:
					running = false;
					break;
				default:
					std::cout << "Invalid selection. Please try again. / 無効な選択です。もう一度試してください。" << std::endl;
			}
		} catch (const std::exception &e) {
			std::cout << "⚠️ Exception caught: " << e.what() << std::endl;
			std::cout << "Test continued... / テストを継続します..." << std::endl;
		}
	}

	return 0;
}

void testBasicCreation() {
	std::cout << GREEN_COLOR << "\n=== 1: Testing Basic Creation ===" << RESET_COLOR << std::endl;
	std::cout << "=== 基本作成テスト ===" << std::endl;
	
	std::cout << "\n----- Test 1-1: Default constructor / デフォルトコンストラクタ -----" << std::endl;
	try {
		Bureaucrat b0;
		std::cout << "✅ Created: " << b0.getName() << " with grade " << b0.getGrade() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- Test 1-2: Normal creation (grade 50) / 通常作成（等級50） -----" << std::endl;
	try {
		Bureaucrat b1("John", 50);
		std::cout << "✅ Created: " << b1.getName() << " with grade " << b1.getGrade() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- Test 1-3: Highest grade (grade 1) / 最高等級（等級1） -----" << std::endl;
	try {
		Bureaucrat b2("Alice", 1);
		std::cout << "✅ Created: " << b2.getName() << " with grade " << b2.getGrade() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- Test 1-4: Lowest grade (grade 150) / 最低等級（等級150） -----" << std::endl;
	try {
		Bureaucrat b3("Bob", 150);
		std::cout << "✅ Created: " << b3.getName() << " with grade " << b3.getGrade() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
}

void testExceptionHandling() {
	std::cout << GREEN_COLOR << "\n=== 2: Testing Exception Handling ===" << RESET_COLOR << std::endl;
	std::cout << "=== 例外処理テスト ===" << std::endl;
	
	std::cout << "\n----- Test 2-1: Grade 0 (too high) / 等級0（高すぎる） -----" << std::endl;
	try {
		Bureaucrat b("Invalid", 0);
		std::cout << "❌ Failed: Should have thrown exception / 例外がスローされるべきでした" << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "✅ Passed: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: Wrong exception type: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 2-2: Grade 151 (too low) / 等級151（低すぎる） -----" << std::endl;
	try {
		Bureaucrat b("Invalid", 151);
		std::cout << "❌ Failed: Should have thrown exception / 例外がスローされるべきでした" << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "✅ Passed: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: Wrong exception type: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 2-3: Boundary values (1 and 150) / 境界値テスト（1と150） -----" << std::endl;
	try {
		Bureaucrat b1("Boundary1", 1);
		std::cout << "✅ Passed: Grade 1 is valid / 等級1は有効です" << std::endl;
		Bureaucrat b2("Boundary2", 150);
		std::cout << "✅ Passed: Grade 150 is valid / 等級150は有効です" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
}

void testGradeIncrementDecrement() {
	std::cout << GREEN_COLOR << "\n=== 3: Testing Grade Increment/Decrement ===" << RESET_COLOR << std::endl;
	std::cout << "=== 等級増減テスト ===" << std::endl;
	
	std::cout << "\n----- Test 3-1: Normal increment/decrement / 通常の増減 -----" << std::endl;
	try {
		Bureaucrat b("Test", 50);
		std::cout << "Initial grade / 初期等級: " << b.getGrade() << std::endl;
		b.incrementGrade();
		std::cout << "After increment / 増加後: " << b.getGrade() << std::endl;
		b.decrementGrade();
		std::cout << "After decrement / 減少後: " << b.getGrade() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 3-2: Increment at grade 1 (should fail) / 等級1での増加（失敗すべき） -----" << std::endl;
	try {
		Bureaucrat b("Top", 1);
		b.incrementGrade();
		std::cout << "❌ Failed: Should have thrown exception / 例外がスローされるべきでした" << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "✅ Passed: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: Wrong exception type: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 3-3: Decrement at grade 150 (should fail) / 等級150での減少（失敗すべき） -----" << std::endl;
	try {
		Bureaucrat b("Bottom", 150);
		b.decrementGrade();
		std::cout << "❌ Failed: Should have thrown exception / 例外がスローされるべきでした" << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "✅ Passed: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: Wrong exception type: " << e.what() << std::endl;
	}
}

void testOutputOperator() {
	std::cout << GREEN_COLOR << "\n=== 4: Testing Output Operator ===" << RESET_COLOR << std::endl;
	std::cout << "=== 出力演算子テスト ===" << std::endl;
	
	std::cout << "\n----- Test 4-1: Output operator / 出力演算子 -----" << std::endl;
	try {
		Bureaucrat b("John", 42);
		std::cout << "Output / 出力: " << b << std::endl;
		std::cout << "✅ Passed: Output operator works correctly / 出力演算子が正しく動作しています" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
}

void testCopyAndAssignment() {
	std::cout << GREEN_COLOR << "\n=== 5: Testing Copy and Assignment ===" << RESET_COLOR << std::endl;
	std::cout << "=== コピー・代入テスト ===" << std::endl;
	
	std::cout << "\n----- Test 5-1: Copy Constructor / コピーコンストラクタ -----" << std::endl;
	try {
		Bureaucrat original("Original", 50);
		Bureaucrat copy(original);
		std::cout << "Original / 元: " << original << std::endl;
		std::cout << "Copy / コピー: " << copy << std::endl;
		std::cout << "✅ Passed: Copy constructor works correctly / コピーコンストラクタが正しく動作しています" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 5-2: Assignment Operator / 代入演算子 -----" << std::endl;
	try {
		Bureaucrat b1("First", 50);
		Bureaucrat b2("Second", 100);
		std::cout << "Before assignment / 代入前:" << std::endl;
		std::cout << "b1: " << b1 << std::endl;
		std::cout << "b2: " << b2 << std::endl;
		b2 = b1;
		std::cout << "After assignment / 代入後:" << std::endl;
		std::cout << "b1: " << b1 << std::endl;
		std::cout << "b2: " << b2 << std::endl;
		std::cout << "✅ Passed: Assignment operator works correctly / 代入演算子が正しく動作しています" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 5-3: Self Assignment / 自己代入 -----" << std::endl;
	try {
		Bureaucrat b("Self", 50);
		Bureaucrat& ref = b;
		b = ref;
		std::cout << "✅ Passed: Self assignment handled correctly / 自己代入が正しく処理されました" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
}

void testBoundaryValues() {
	std::cout << GREEN_COLOR << "\n=== 6: Testing Boundary Values ===" << RESET_COLOR << std::endl;
	std::cout << "=== 境界値テスト ===" << std::endl;
	
	std::cout << "\n----- Test 6-1: Bureaucrat grade = 1 (最高等級) -----" << std::endl;
	try {
		Bureaucrat b1("Highest", 1);
		std::cout << "✅ Created: " << b1 << std::endl;
		std::cout << "Attempting incrementGrade()..." << std::endl;
		b1.incrementGrade();
		std::cout << "❌ Failed: Should have thrown exception / 例外がスローされるべきでした" << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "✅ Passed: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: Wrong exception type: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- Test 6-2: Bureaucrat grade = 150 (最低等級) -----" << std::endl;
	try {
		Bureaucrat b2("Lowest", 150);
		std::cout << "✅ Created: " << b2 << std::endl;
		std::cout << "Attempting decrementGrade()..." << std::endl;
		b2.decrementGrade();
		std::cout << "❌ Failed: Should have thrown exception / 例外がスローされるべきでした" << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "✅ Passed: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: Wrong exception type: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- Test 6-3: Bureaucrat grade = 2 で incrementGrade() (境界値 - 成功すべき) -----" << std::endl;
	try {
		Bureaucrat b3("Test3", 2);
		std::cout << "Before increment: " << b3 << std::endl;
		b3.incrementGrade();
		std::cout << "After increment: " << b3 << std::endl;
		if (b3.getGrade() == 1) {
			std::cout << "✅ Passed: incrementGrade() succeeded / incrementGrade()が成功しました" << std::endl;
		} else {
			std::cout << "❌ Failed: Grade should be 1, but got " << b3.getGrade() << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- Test 6-4: Bureaucrat grade = 149 で decrementGrade() (境界値 - 成功すべき) -----" << std::endl;
	try {
		Bureaucrat b4("Test4", 149);
		std::cout << "Before decrement: " << b4 << std::endl;
		b4.decrementGrade();
		std::cout << "After decrement: " << b4 << std::endl;
		if (b4.getGrade() == 150) {
			std::cout << "✅ Passed: decrementGrade() succeeded / decrementGrade()が成功しました" << std::endl;
		} else {
			std::cout << "❌ Failed: Grade should be 150, but got " << b4.getGrade() << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- Test 6-5: Bureaucrat grade = 0 (無効値 - 高すぎる) -----" << std::endl;
	try {
		Bureaucrat b5("Invalid1", 0);
		std::cout << "❌ Failed: Should have thrown exception / 例外がスローされるべきでした" << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "✅ Passed: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: Wrong exception type: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- Test 6-6: Bureaucrat grade = 151 (無効値 - 低すぎる) -----" << std::endl;
	try {
		Bureaucrat b6("Invalid2", 151);
		std::cout << "❌ Failed: Should have thrown exception / 例外がスローされるべきでした" << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "✅ Passed: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: Wrong exception type: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- Test 6-7: 連続したincrement/decrementの境界値テスト -----" << std::endl;
	try {
		Bureaucrat b7("Test7", 3);
		std::cout << "Initial grade: " << b7 << std::endl;
		
		// 2回incrementして1に到達
		b7.incrementGrade();
		std::cout << "After first increment: " << b7 << std::endl;
		b7.incrementGrade();
		std::cout << "After second increment: " << b7 << std::endl;
		
		// 3回目のincrementは例外を投げるべき
		std::cout << "Attempting third increment (should fail)..." << std::endl;
		b7.incrementGrade();
		std::cout << "❌ Failed: Should have thrown exception / 例外がスローされるべきでした" << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "✅ Passed: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: Wrong exception type: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- Test 6-8: 連続したdecrementの境界値テスト -----" << std::endl;
	try {
		Bureaucrat b8("Test8", 148);
		std::cout << "Initial grade: " << b8 << std::endl;
		
		// 2回decrementして150に到達
		b8.decrementGrade();
		std::cout << "After first decrement: " << b8 << std::endl;
		b8.decrementGrade();
		std::cout << "After second decrement: " << b8 << std::endl;
		
		// 3回目のdecrementは例外を投げるべき
		std::cout << "Attempting third decrement (should fail)..." << std::endl;
		b8.decrementGrade();
		std::cout << "❌ Failed: Should have thrown exception / 例外がスローされるべきでした" << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "✅ Passed: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ Failed: Wrong exception type: " << e.what() << std::endl;
	}
}
