#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <ctime>
# include <algorithm>
# include <iomanip>
# include <sstream>

class PmergeMe {
	private:  
		std::vector<int>	_vec;
		std::deque<int>		_deq;

	public:  
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void run(int ac, char** av);

		template <typename T>
		void fordJohnsonSort(T& container);

		template <typename T>
		void insertionSort(T& mainChain, T& pending);
};

#endif