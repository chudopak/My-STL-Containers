#include "tests.hpp"


void	print_time_map(long stl, long ft) {
	std::cout << BOLD_RED << UNDERLINE << "time :" << STANDART;
	std::cout << "\t\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl << "\t\t"<< ft << STANDART<< std::endl;
}

template <typename T, class U>
bool	cmp_containers(std::map<T, U>& stl, ft::map<T, U>& ft) {

	if (stl.size() == 0 && ft.size() == 0)
		return (true);
	if (stl.size() != ft.size())
		return (false);

	typename std::map<T, U>::iterator it = stl.begin();
	typename ft::map<T, U>::iterator ite = ft.begin();

	while (it != stl.end()) {
		if (it->first != ite->first || it->second != ite->second || ite == ft.end())
			return (false);
		it++;
		ite++;
	}
	return (true);
}

template <typename T, class U>
void	print_data_of_compared(std::map<T, U>& stl, ft::map<T, U>& ft) {

	std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
	std::cout << "\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl.size() << "\t\t"<< ft.size() << STANDART<< std::endl;

	std::cout << BOLD_RED << UNDERLINE << "compare\t" << STANDART;
	if (cmp_containers(stl, ft)) {
		std::cout << "\t\U0001F600\U00002705" << std::endl << std::endl;
	} else {
		std::cout << "\t\U0000274C" << std::endl << std::endl;
	}
}


void	MapTest() {

	{
		std::cout << BOLD_GREEN << std::endl << "\tTesting copy constructor" << STANDART << std::endl;

		std::map<int, int> 										stdMap;
		for (int i = 0; i < 2000; i += 4) {
			stdMap.insert(std::make_pair(i, i + 1));
			stdMap.insert(std::make_pair(i - 1, i + 1));
			stdMap.insert(std::make_pair(-i, -i + 1));
			stdMap.insert(std::make_pair(-i + 1, -i + 1));
		}
		ft::map<int, int> 										myMap;
		for (int i = 0; i < 2000; i += 4) {
			myMap.insert(ft::make_pair(i, i + 1));
			myMap.insert(ft::make_pair(i - 1, i + 1));
			myMap.insert(ft::make_pair(-i, -i + 1));
			myMap.insert(ft::make_pair(-i + 1, -i + 1));
		}
		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;


		std::map<int, int> 										stdCopyMap(stdMap);


		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;


		struct timeval		ftStart;
		struct timeval		ftEnd;
		gettimeofday(&ftStart, NULL);
		long	ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		ft::map<int, int> 										myCopyMap(myMap);
		
		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stdCopyMap, myCopyMap);
		print_time_map(stlDiff, ftDiff);
	}

	{
		std::cout << BOLD_GREEN << std::endl << "\tTesting insert(val)" << STANDART << std::endl;


		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;


		std::map<int, int> 										stdMap;
		for (int i = 0; i < 10000; i += 4) {
			stdMap.insert(std::make_pair(i, i + 1));
			stdMap.insert(std::make_pair(i - 1, i + 1));
			stdMap.insert(std::make_pair(-i, -i + 1));
			stdMap.insert(std::make_pair(-i + 1, -i + 1));
		}


		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;


		struct timeval		ftStart;
		struct timeval		ftEnd;
		gettimeofday(&ftStart, NULL);
		long	ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;


		ft::map<int, int> 										myMap;
		for (int i = 0; i < 10000; i += 4) {
			myMap.insert(ft::make_pair(i, i + 1));
			myMap.insert(ft::make_pair(i - 1, i + 1));
			myMap.insert(ft::make_pair(-i, -i + 1));
			myMap.insert(ft::make_pair(-i + 1, -i + 1));
		}
		
		
		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stdMap, myMap);
		print_time_map(stlDiff, ftDiff);
	}

	{
		std::cout << BOLD_GREEN << std::endl << "\tTesting insert(pointer, val)" << STANDART << std::endl;


		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;


		std::map<int, int> 										stdMap;
		std::map<int, int>::iterator							ite = stdMap.begin();

		for (int i = 0; i < 5000; i += 4) {
			stdMap.insert(ite, std::make_pair(i, i + 1));
			stdMap.insert(ite, std::make_pair(i - 1, i + 1));
			stdMap.insert(ite, std::make_pair(-i, -i + 1));
			stdMap.insert(ite, std::make_pair(-i + 1, -i + 1));
		}


		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		gettimeofday(&ftStart, NULL);
		long	ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;


		ft::map<int, int> 										myMap;
		ft::map<int, int>::iterator								it = myMap.begin();
		for (int i = 0; i < 5000; i += 4) {
			myMap.insert(it, ft::make_pair(i, i + 1));
			myMap.insert(it, ft::make_pair(i - 1, i + 1));
			myMap.insert(it, ft::make_pair(-i, -i + 1));
			myMap.insert(it, ft::make_pair(-i + 1, -i + 1));
		}

		
		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stdMap, myMap);
		print_time_map(stlDiff, ftDiff);
	}

	{
		std::cout << std::endl << BOLD_GREEN << "\tTesting insert(InputIterator, InputItator)" << STANDART << std::endl;

		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;


		std::map<int, int> 										stdCopyMap;
		for (int i = 0; i < 5000; i += 4) {
			stdCopyMap.insert(std::make_pair(i, i + 1));
			stdCopyMap.insert(std::make_pair(i - 1, i + 1));
			stdCopyMap.insert(std::make_pair(-i, -i + 1));
			stdCopyMap.insert(std::make_pair(-i + 1, -i + 1));
		}
		std::map<int, int>::iterator							ite_start = stdCopyMap.begin();
		std::map<int, int>::iterator							ite_end = stdCopyMap.end();
		std::map<int, int> 										stdMap;
		stdMap.insert(ite_start, ite_end);


		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;


		struct timeval		ftStart;
		struct timeval		ftEnd;
		gettimeofday(&ftStart, NULL);
		long	ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;


		ft::map<int, int> 										myCopyMap;
		for (int i = 0; i < 5000; i += 4) {
			myCopyMap.insert(ft::make_pair(i, i + 1));
			myCopyMap.insert(ft::make_pair(i - 1, i + 1));
			myCopyMap.insert(ft::make_pair(-i, -i + 1));
			myCopyMap.insert(ft::make_pair(-i + 1, -i + 1));
		}
		ft::map<int, int>::iterator							it_start = myCopyMap.begin();
		ft::map<int, int>::iterator							it_end = myCopyMap.end();
		ft::map<int, int> 									myMap;
		myMap.insert(it_start, it_end);
		
		
		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stdMap, myMap);
		print_time_map(stlDiff, ftDiff);



		std::cout << std::endl << BOLD_GREEN << "\tTesting swap(x)" << STANDART << std::endl;

		myCopyMap.clear();
		stdCopyMap.clear();

		for (int i = 0; i < 300; i += 8) {
			myCopyMap.insert(ft::make_pair(i, i + 1));
			myCopyMap.insert(ft::make_pair(i - 1, i + 1));
			myCopyMap.insert(ft::make_pair(-i, -i + 1));
			myCopyMap.insert(ft::make_pair(-i + 1, -i + 1));
		}
		for (int i = 0; i < 300; i += 8) {
			stdCopyMap.insert(std::make_pair(i, i + 1));
			stdCopyMap.insert(std::make_pair(i - 1, i + 1));
			stdCopyMap.insert(std::make_pair(-i, -i + 1));
			stdCopyMap.insert(std::make_pair(-i + 1, -i + 1));
		}
		myMap.swap(myCopyMap);
		stdMap.swap(stdCopyMap);
		print_data_of_compared(stdMap, myMap);
	}

	{
		std::cout << std::endl << BOLD_GREEN << "\tTesting clear()" << STANDART << std::endl;

		std::map<int, int> 										stdMap;
		for (int i = 0; i < 10000; i += 4) {
			stdMap.insert(std::make_pair(i, i + 1));
			stdMap.insert(std::make_pair(i - 1, i + 1));
			stdMap.insert(std::make_pair(-i, -i + 1));
			stdMap.insert(std::make_pair(-i + 1, -i + 1));
		}
		ft::map<int, int> 										myMap;
		for (int i = 0; i < 10000; i += 4) {
			myMap.insert(ft::make_pair(i, i + 1));
			myMap.insert(ft::make_pair(i - 1, i + 1));
			myMap.insert(ft::make_pair(-i, -i + 1));
			myMap.insert(ft::make_pair(-i + 1, -i + 1));
		}
		ft::map<int, int> 										myMapsi;

		stdMap.clear();
		myMap.clear();

		for (int i = 0; i < 10000; i += 4) {
			myMap.insert(ft::make_pair(i, i + 1));
			myMap.insert(ft::make_pair(i - 1, i + 1));
			myMap.insert(ft::make_pair(-i, -i + 1));
			myMap.insert(ft::make_pair(-i + 1, -i + 1));
		}
		for (int i = 0; i < 10000; i += 4) {
			stdMap.insert(std::make_pair(i, i + 1));
			stdMap.insert(std::make_pair(i - 1, i + 1));
			stdMap.insert(std::make_pair(-i, -i + 1));
			stdMap.insert(std::make_pair(-i + 1, -i + 1));
		}
		stdMap.clear();
		myMap.clear();
		print_data_of_compared(stdMap, myMap);
	}
}