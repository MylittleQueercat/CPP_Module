#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T &min(const T &a, const T &b) {
	return (a < b) ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b) {
	return (a > b) ? a : b;
}

#endif

// template: mot-clé qui dit ce qui suit est un moule
// T: si on sais pas quel type de données, on utilise T pour l'instant
// une declaration de template n'eat valable que pour le
// bloc de code qui suit immediatement