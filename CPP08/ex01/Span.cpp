#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_n = other._n;
		this->_v = other._v;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_v.size() >= _n) 
		throw FullException();
	_v.push_back(n);
}

int	Span::longestSpan() {
	if (_v.size() < 2)
		throw NoSpanException();
	
	int	min = *std::min_element(_v.begin(), _v.end());
	int max = *std::max_element(_v.begin(), _v.end());
	return max - min;
}

int Span::shortestSpan() {
	if (_v.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted = _v;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i) {
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}