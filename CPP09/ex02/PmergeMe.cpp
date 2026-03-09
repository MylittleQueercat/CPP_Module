#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<size_t> generateJacobsthal(size_t n) {
	std::vector<size_t> j;
	if (n == 0)
		return j;
	j.push_back(1);
	if (n == 1)
		return j;
	j.push_back(3);
	while (j.back() < n) {
		j.push_back(j[j.size() - 1] + 2 * j[j.size() - 2]);
	}
	return j;
}

template <typename T>
void PmergeMe::fordJohnsonSort(T& container) {
    size_t size = container.size();
    if (size <= 1) return;

	// La gestion du Straggler
    bool hasStraggler = (size % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = container.back();
        container.pop_back();
    }

	// La formation des paires
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size(); i += 2) {
        if (container[i] < container[i + 1])
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
        else
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
    }

	// le tri récursif
    T largerChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        largerChain.push_back(pairs[i].first);
    
    fordJohnsonSort(largerChain);

    T mainChain = largerChain;
    T pending;
    
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pending.push_back(pairs[j].second);
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pending[0]);

    std::vector<size_t> jSep = generateJacobsthal(pending.size());
    size_t lastIdx = 0;

    for (size_t k = 1; k < jSep.size(); ++k) {
        size_t currJac = jSep[k];
        if (currJac >= pending.size())
            currJac = pending.size() - 1;

        for (size_t i = currJac; i > lastIdx; --i) {
            typename T::iterator pos = std::upper_bound(mainChain.begin(), mainChain.end(), pending[i]);
            mainChain.insert(pos, pending[i]);
        }
        lastIdx = currJac;
        if (lastIdx == pending.size() - 1) break;
    }

	// L'insertion finale et le Straggler
    if (hasStraggler) {
        typename T::iterator pos = std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    container = mainChain;
}

//Explicit Template Instantiation
template void PmergeMe::fordJohnsonSort<std::vector<int> >(std::vector<int>&);
template void PmergeMe::fordJohnsonSort<std::deque<int> >(std::deque<int>&);