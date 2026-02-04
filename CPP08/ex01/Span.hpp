#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>
# include <iostream>

class Span {
	private:  
		unsigned int		_n;
		std::vector<int>	_v;
		Span();

	public:  
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span& other);
		~Span();

		void addNumber(int n);

		template <typename T>
		void addNumbers(T begin, T end) {
			if (_v.size() + std::distance(begin, end) > _n)
				throw std::out_of_range("Not enough space to add these numbers");
			_v.insert(_v.end(), begin, end);
		}

		int	shortestSpan();
		int longestSpan();

		class FullException : public std::exception {
			public: virtual const char* what() const throw() {
				return "Span is full";
			}
		};
		class NoSpanException : public std::exception {
			public: virtual const char* what() const throw() {
				return "not enough numbers to find a span";
			}
		};
};

#endif