#include "random_access_iterator.hpp"

class Test {};
int main() {
	int*	i;
	int		x;

	x = 5;
	i = &x;
	ft::random_access_iterator<Test>		test;
	ft::random_access_iterator<int>		test1(i);
	ft::random_access_iterator<int>		test2(test1);
	std::cout << i << "     " << *i << std::endl;
	std::cout << i << "     " << *i << std::endl;

	return (0);
}