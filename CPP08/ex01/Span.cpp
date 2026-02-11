/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:27:15 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:27:16 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long long Span::longestSpan() const {
	if (_v.size() < 2)
		throw NoSpanException();
	
	int	min = *std::min_element(_v.begin(), _v.end());
	int max = *std::max_element(_v.begin(), _v.end());
	return static_cast<long long>(max) - static_cast<long long>(min);
}

long long Span::shortestSpan() const {
	if (_v.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted = _v;
	std::sort(sorted.begin(), sorted.end());

	long long minSpan = static_cast<long long>(sorted[1]) - static_cast<long long>(sorted[0]);
	for (size_t i = 1; i < sorted.size() - 1; ++i) {
		long long span = static_cast<long long>(sorted[i + 1]) - static_cast<long long>(sorted[i]);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}