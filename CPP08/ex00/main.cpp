#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {
	//Case vector
	std::vector<int> v;
	for (int i = 0; i < 7; i++)
		v.push_back(i * 10);

	try {
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Found: " << *it << " at vector." << std::endl;

		easyfind(v, 99);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "~~~~~~~" << std::endl;

	//Case list
	std::list<int> k;
	k.push_back(26);
	k.push_back(42);
	try {
		std::list<int>::iterator it = easyfind(k, 26);
		std::cout << "Found: " << *it << " at list." << std::endl;

		easyfind(k, 43);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}