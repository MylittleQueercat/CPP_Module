#include "Point.hpp"

int main() {
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	Point inside(2, 2);
	Point outside(5, 5);
	Point edge(2.5, 0);
	Point vertex(0, 0);

	std::cout << std::boolalpha;
	std::cout << "Inside:  " << bsp(a, b, c, inside) << std::endl;  // true
	std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl; // false
	std::cout << "Edge:    " << bsp(a, b, c, edge) << std::endl;    // false
	std::cout << "Vertex:  " << bsp(a, b, c, vertex) << std::endl;  // false

	return 0;
}
