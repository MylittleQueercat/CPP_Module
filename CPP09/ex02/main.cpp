#include "PmergeMe.hpp"

void PmergeMe::run(int ac, char** av) {
	for (int i = 1; i < ac; ++i) {
		char *endPtr;
		long val = std::strtol(av[i], &endPtr, 10);
		if (val < 0 || *endPtr != '\0' || val > INT_MAX) {
			std::cerr << "Error" << std::endl;
			return;
		}
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	clock_t start = clock();
	fordJohnsonSort(_vec);
	clock_t end = clock();
	double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	start = clock();
	fordJohnsonSort(_deq);
	end = clock();
	double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << deqTime << " us" << std::endl;
}

int main(int argc, char** argv) {
	if (argc < 2)
		return 1;
	PmergeMe g;
	g.run(argc, argv);
	return 0;
}