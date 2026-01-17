#include "../includes/Span.hpp"

//listは双方向リストであることから、任意の位置での挿入と削除に優れている、
//でも今回はその機能使わないっぴ！
//というわけでvector使用。
/* ************************************************************************** */
int test_subject()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return(0);
}

/* ************************************************************************** */
int test_Mine()
{
    std::cout << std::endl;
    std::cout << "3. Testing multipleAdd Function:" << std::endl;
    try {
        std::vector<int> sourceNumbers;
        sourceNumbers.push_back(1);
        sourceNumbers.push_back(5);
        sourceNumbers.push_back(3);
        sourceNumbers.push_back(9);
        sourceNumbers.push_back(2);
        
        Span bulkSpan(10);
        
        std::cout << "Source vector contains: ";
        for (size_t i = 0; i < sourceNumbers.size(); ++i) {
            std::cout << sourceNumbers[i] << " ";
        }
        std::cout << std::endl;
        
        // multipleAddを使用して一括追加!!!!!!!!!!!!!!!!!!!
        bulkSpan.multipleAdd(sourceNumbers.begin(), sourceNumbers.end());
        
        std::cout << "After multipleAdd: ";
        bulkSpan.printVector();
        
        std::cout << "Shortest span: " << bulkSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bulkSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "ERROR :in multipleAdd test: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout<< "Test vector large range" << std::endl;
	Span largeSpan = Span(999999);
	std::vector<int> largeVec;
	std::srand(time(NULL));
	for (unsigned int i = 0; i < 999999; i++)
	{
		int random_int = rand() % 100000000;
		largeVec.push_back(random_int);
	}
	try
	{
		largeSpan.multipleAdd(largeVec.begin(), largeVec.end());
		std::cout << "shortest span: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "longest span: " << largeSpan.longestSpan() << std::endl;
	}
    catch (std::exception &e)
	{
		std::cout << "ERROR :in LargeVector test: " << e.what() << std::endl;
	}
    
    std::cout << std::endl;
    std::cout << "4. Testing Capacity Overflow Exception:" << std::endl;
    try {
        Span smallSpan(2);  // 容量2のSpanを作成
        smallSpan.addNumber(1);
        smallSpan.addNumber(2);
        
        // 3つ目の要素を追加しようとする（例外が発生するはず）
        smallSpan.addNumber(3);
        std::cout << "Exception should have been thrown!" << std::endl;
        
    } catch (const std::out_of_range& e) {
        std::cout << "Expected overflow exception caught: " << e.what() << std::endl;
    }
    
    // multipleAddの容量オーバーフローテスト
    try {
        std::vector<int> tooManyNumbers;
        for (int i = 0; i < 5; ++i) {
            tooManyNumbers.push_back(i * 10);
        }
        
        Span tinySpan(3);
        tinySpan.multipleAdd(tooManyNumbers.begin(), tooManyNumbers.end());
        std::cout << "multipleAdd should have thrown exception!" << std::endl;
        
    } catch (const std::out_of_range& e) {
        std::cout << "Expected multipleAdd overflow exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "5. Testing Insufficient Elements Exception:" << std::endl;
    try {
        Span emptySpan(5);
        emptySpan.shortestSpan(); // 例外が発生するはず
        std::cout << " Empty span should throw exception!" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Empty span exception (shortest): " << e.what() << std::endl;
    }
    try {
        Span emptySpan(5);
        emptySpan.longestSpan(); // 例外が発生するはず
        std::cout << " Empty span should throw exception!" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Empty span exception (longest): " << e.what() << std::endl;
    }
    try {
        Span singleSpan(5);
        singleSpan.addNumber(42);
        singleSpan.shortestSpan(); // 例外が発生するはず
        std::cout << "Single element span should throw exception!" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Single element span exception: " << e.what() << std::endl;
    }
    return 0;
}

/* ************************************************************************** */
int main()
{
	std::cout << "Subject tests\n";
	test_subject();
	std::cout << "\nMy tests\n";
	test_Mine();
}