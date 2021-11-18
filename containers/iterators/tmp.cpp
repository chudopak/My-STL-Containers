#include "random_access_iterator.hpp"

class Test {};
int main() {
	int*	i;
	int		x;

	x = 5;
	i = &x;
	ft::random_access_iterator<const int>		test;
	ft::random_access_iterator<const int>		test1(i);
	ft::random_access_iterator<const int>		test2(test1);
	test = test2;
	
	std::cout << test2[0] << std::endl;
	std::cout << (test2 +  1)[0] << std::endl;

	return (0);
}