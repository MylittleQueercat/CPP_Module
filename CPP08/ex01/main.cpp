#include "Span.hpp"

int main() {
	Span sp = Span(10000);
	std::vector<int> bigData;
	for (int i = 0; i < 10000; i++)
		bigData.push_back(i * 2);

	sp.addNumbers(bigData.begin(), bigData.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}