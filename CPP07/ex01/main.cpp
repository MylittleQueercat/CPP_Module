#include "iter.hpp"

template <typename T>
void printElement(T &e) {
	std::cout << e << " ";
}

int main(void) {
	int arr[] = {0, 1, 2, 3, 4};
	std::cout << "Int array: ";
	::iter(arr, 5, printElement<int>);
	std::cout << std::endl;

	std::string strArr[] = {"cat", "rabbit", "dog"};
	std::cout << "String array: ";
	::iter(strArr, 3, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}