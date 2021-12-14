#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>
# define UNDERLINE "\033[4m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_RED "\033[1;31m"
# define NORMAL "\033[0;37m"
# define STANDART "\033[0m"
# define YELLOW "\033[1;33m"

# include "../containers/vector.hpp"
# include "../containers/stack.hpp"
# include "../containers/map.hpp"

# include <vector>
# include <stack>
# include <map>
# include <memory>
# include <list>


void	VectorTests();
void	StackTest();
void	MapTest();

#endif