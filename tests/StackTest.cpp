#include <stack>
#include <vector>
#include <deque>
#include "tests.hpp"


template <typename T>
void	print_data_of_compared(std::stack<T>& stl, ft::stack<T>& ft) {

	std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
	std::cout << "\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl.size() << "\t\t"<< ft.size() << STANDART<< std::endl;
	
	std::cout << BOLD_RED << UNDERLINE << "empty() :" << STANDART;
	std::cout << "\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl.empty() << "\t\t"<< ft.empty() << STANDART<< std::endl;
}

void	print_stack_time(long stl, long ft) {
	std::cout << BOLD_RED << UNDERLINE << "time :" << STANDART;
	std::cout << "\t\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl << "\t\t"<< ft << STANDART<< std::endl;
}

template <typename T>
bool	cmp_containers(std::vector<T>& stl, std::vector<T>& ft) {

	if (stl.size() == 0 && ft.size() == 0)
		return (true);
	if (stl.size() != ft.size())
		return (false);

	typename std::vector<T>::iterator it = stl.begin();
	typename std::vector<T>::iterator ite = ft.begin();

	while (it < stl.end()) {
		if (*it != *ite)
			return (false);
		it++;
		ite++;
	}
	return (true);
}

template <typename T>
void	print_data_of_compared(std::vector<T>& stl, std::vector<T>& ft) {

	std::cout << BOLD_RED << UNDERLINE << "compare\t" << STANDART;
	if (cmp_containers(stl, ft)) {
		std::cout << "\t\U0001F600\U00002705" << std::endl << std::endl;
	} else {
		std::cout << "\t\U0000274C" << std::endl << std::endl;
	}
}

void	StackTest() {
	std::cout << std::endl << std::endl << std::endl;
	std::cout << YELLOW << "\t\t***************" << std::endl;
	std::cout << YELLOW << "\t\t**** Stack ****" << std::endl;
	std::cout << YELLOW << "\t\t***************" << std::endl;

	{
		std::cout << BOLD_GREEN << "\t____Testing constructor____" << STANDART << std::endl;
		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stlStack;
		std::deque<int> stdStorage;
		std::stack<int>	stdStack;
		for (int i = 0; i < 500000; ++i)
			stdStorage.push_back(i);
		for (int i = 500000; i < 1000000; ++i)
			stdStack.push(i);
		std::stack<int> test(stdStorage);
		std::stack<int> test1(stdStack);
		std::stack<int> test2;
		test2 = test1;
		while (test.size() > 0) {
			stlStack.push_back(test.top());
			test.pop();
		}

		gettimeofday(&stlEnd, NULL);

		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		std::vector<int> myStack;
		ft::vector<int> storage;
		ft::stack<int>	ftStack;
		for (int i = 0; i < 500000; ++i)
			storage.push_back(i);
		for (int i = 500000; i < 1000000; ++i)
			ftStack.push(i);
		ft::stack<int> stack(storage);
		ft::stack<int> stack2(ftStack);
		ft::stack<int> stack3;
		stack3 = stack2;
		while (stack.size() > 0) {
			myStack.push_back(stack.top());
			stack.pop();
		}

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stlStack, myStack);
		print_stack_time(stlDiff, ftDiff);
	}

	{
		std::cout << std::endl;
		std::cout << BOLD_GREEN << "\t____Testing empty()____" << STANDART << std::endl;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		std::vector<int> storage;
		ft::stack<int> ftStack;
		for (int i = 0; i < 4000000; ++i)
			ftStack.push(i);
		storage.push_back(ftStack.empty());
		while (ftStack.size() > 0)
			ftStack.pop();
		storage.push_back(ftStack.empty());

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;

		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stlStorage;
		std::stack<int> stlStack;
		for (int i = 0; i < 4000000; ++i)
			stlStack.push(i);
		stlStorage.push_back(stlStack.empty());
		while (stlStack.size() > 0)
			stlStack.pop();
		stlStorage.push_back(stlStack.empty());

		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;
		print_data_of_compared(stlStorage, storage);
		print_stack_time(stlDiff, ftDiff);
	}

	{
		std::cout << std::endl;
		std::cout << BOLD_GREEN << "\t____Testing top() && push()____" << STANDART << std::endl;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		std::vector<int> ftStorage;
		ft::stack<int>	ftStack;
		for (int i = 0; i < 900000; ++i)
			ftStack.push(i);
		ftStorage.push_back(ftStack.top());
		ftStack.pop();
		ftStorage.push_back(ftStack.top());
		ftStack.push(7);
		ftStorage.push_back(ftStack.top());
		ftStack.push(9);
		ftStorage.push_back(ftStack.top());
		ftStack.push(91);
		ftStorage.push_back(ftStack.top());
		ftStack.push(39);
		ftStorage.push_back(ftStack.top());

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;

		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stlStorage;
		std::stack<int>	stlStack;
		for (int i = 0; i < 900000; ++i)
			stlStack.push(i);
		stlStorage.push_back(stlStack.top());
		stlStack.pop();
		stlStorage.push_back(stlStack.top());
		stlStack.push(7);
		stlStorage.push_back(stlStack.top());
		stlStack.push(9);
		stlStorage.push_back(stlStack.top());
		stlStack.push(91);
		stlStorage.push_back(stlStack.top());
		stlStack.push(39);
		stlStorage.push_back(stlStack.top());

		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;
		print_data_of_compared(stlStorage, ftStorage);
		print_stack_time(stlDiff, ftDiff);
	}


	{
		std::cout << std::endl;
		std::cout << BOLD_GREEN << "\t____Testing pop()____" << STANDART << std::endl;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		std::vector<int> ftStorage;
		ft::stack<int>	ftStack;
		for (int i = 0; i < 900000; ++i)
			ftStack.push(i);
		ftStorage.push_back(ftStack.top());
		ftStack.pop();
		ftStorage.push_back(ftStack.top());
		ftStack.push(7);
		ftStorage.push_back(ftStack.top());
		ftStack.push(9);
		ftStorage.push_back(ftStack.top());
		ftStack.push(91);
		ftStorage.push_back(ftStack.top());
		ftStack.push(39);
		ftStorage.push_back(ftStack.top());
		while (ftStack.size() > 0)
			ftStack.pop();
		ftStorage.push_back(ftStack.size());
		

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;

		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stlStorage;
		std::stack<int>	stlStack;
		for (int i = 0; i < 900000; ++i)
			stlStack.push(i);
		stlStorage.push_back(stlStack.top());
		stlStack.pop();
		stlStorage.push_back(stlStack.top());
		stlStack.push(7);
		stlStorage.push_back(stlStack.top());
		stlStack.push(9);
		stlStorage.push_back(stlStack.top());
		stlStack.push(91);
		stlStorage.push_back(stlStack.top());
		stlStack.push(39);
		stlStorage.push_back(stlStack.top());
		while (stlStack.size() > 0)
			stlStack.pop();
		stlStorage.push_back(stlStack.size());

		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;
		print_data_of_compared(stlStorage, ftStorage);
		print_stack_time(stlDiff, ftDiff);
	}


	{
		std::cout << std::endl;
		std::cout << BOLD_GREEN << "\t____Some Extra tests____" << STANDART << std::endl;
		ft::stack<int>	ft;
		std::stack<int> stl;

		std::cout << YELLOW << "Empty stack" << STANDART<< std::endl;
		print_data_of_compared(stl, ft);


		ft.push(41);
		ft.push(29);
		ft.push(10);
		ft.push(42);


		stl.push(41);
		stl.push(29);
		stl.push(10);
		stl.push(42);

		std::cout << YELLOW << "Full of shit" << STANDART<< std::endl;
		print_data_of_compared(stl, ft);
	}
}