#include <iostream>
#include <iterator>
#include <list>

int main(){
	std::list<int> ls1;
	for (int i = 0; i < 5; i++){
		ls1.push_back(i);
	}

	std::list<int>::iterator it = ls1.begin();
	ls1.insert(std::next(it, 10), 100);

	for (std::list<int>::iterator it = ls1.begin(); it != ls1.end(); ++it)
		std::cout << *it << std::endl;
}