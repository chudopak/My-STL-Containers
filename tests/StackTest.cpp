#include <stack>
#include <vector>
#include <map>
#include "tests.hpp"

void	StackTest() {

	{
		ft::stack<int>	ft;
		std::cout << "empty: " << ft.empty() << std::endl;
		std::cout << "size: " << ft.size() << std::endl;

		ft.push(41);
		ft.push(29);
		ft.push(10);
		ft.push(42);
		std::cout << "Added some elements" << std::endl;

		std::cout << "empty: " << ft.empty() << std::endl;

		std::stack<int> stl;

		std::cout << "empty: " << stl.empty() << std::endl;
		std::cout << "size: " << stl.size() << std::endl;

		stl.push(41);
		stl.push(29);
		stl.push(10);
		stl.push(42);
		std::cout << "Added some elements" << std::endl;

		std::cout << "empty: " << stl.empty() << std::endl;
	}
}