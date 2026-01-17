#include "../includes/MutantStack.hpp"

//std::stackはイテレータを提供しない。
//stackの内容を確認するためには、要素を一つずつtop()で取得してpop()で削除するしかない。
//stackは「後入先出（LIFO: 本を積み重ねるイメージ）」というデータ構造の抽象概念を表現しており、中身を順番に見ていくためのイテレータが無いのよ。
//std::stackは実際には「コンテナアダプタ」と呼ばれる設計パターンの実装であり、内部的には他のコンテナ（デフォルトではstd::deque）を使用しています。この内部コンテナにアクセスできれば、そのイテレータを活用することが可能。
/* ************************************************************************** */
int subject_test()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

    std::cout << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
        std::cout << *it << std::endl;
        ++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

/* ************************************************************************** */
int my_test()
{
    std::cout << "Testing with std::string" << std::endl;
    {
        MutantStack<std::string> stringStack;
        stringStack.push("Hello");
        stringStack.push("World");
        stringStack.push("C++");
        stringStack.push("Templates  42Tokyo");
        std::cout << "String stack contents: ";
        for (MutantStack<std::string>::iterator it = stringStack.begin(); 
             it != stringStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << "Top element: " << stringStack.top() << std::endl;
        std::cout << "Stack size: " << stringStack.size() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Testing:std::list Output:" << std::endl;
    
    std::vector<int> testData;
    testData.push_back(5);
    testData.push_back(17);                             // push() → push_back()
    std::cout << testData.back() << std::endl;          // top() → back()
    testData.pop_back();                                // pop() → pop_back()
    std::cout << testData.size() << std::endl;          // size() → size()（同じ）
    testData.push_back(3);
    testData.push_back(5);
    testData.push_back(737);
    testData.push_back(0);

    std::cout << "\n--- std::list Output (for comparison) ---" << std::endl;
    {
        std::list<int> lst;
        for (size_t i = 0; i < testData.size(); ++i) {
            lst.push_back(testData[i]);
        }
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        
        std::cout << "std::list: ";
        while (it != ite) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }
    return(0);
}

/* ************************************************************************** */
int main()
{
	subject_test();
	my_test();
	return 0;
}