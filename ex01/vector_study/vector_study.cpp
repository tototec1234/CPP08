#include <iostream>
#include <vector>

int main(){
	std::vector<int> vec;

	std::cout << "size		:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;

	vec.push_back(1);
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.push_back(2);
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.push_back(3);
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.push_back(4);
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.push_back(5);
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.push_back(66);
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.push_back(7);
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.push_back(8);
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.push_back(9);
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.pop_back();
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.pop_back();
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.pop_back();
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.pop_back();
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.pop_back();
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	vec.push_back(10);
	std::cout << "size	:" << vec.size() << std::endl;
	std::cout << "capacity	:" << vec.capacity() << std::endl;
	std::cout << "vec[4]	:" << vec.at(4) << std::endl;
	std::cout << "vec[3]	:" << vec.at(3) << std::endl;
	std::cout << "vec[0]	:" << vec.at(0) << std::endl;
	int index = 0;
	// for (int *i_ptr = &vec[0]; i_ptr != &vec[17]; i_ptr++){
	for (int *i_ptra = &vec[0]; i_ptra != &vec[17]; i_ptra++){

		index++;
		std::cout <<  "[" << index << "]" << i_ptra << "(" << *i_ptra << ")" << vec.at(index) << std::endl;	
		// std::cout <<  "[" << index << "]" << i_ptra << "(" << *i_ptra << ")"  << std::endl;	
		std::cout << "capacity	:" << vec.capacity() << std::endl;
	
	}
	return 0;	
}