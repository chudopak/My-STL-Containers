#include "tests.hpp"

template <typename T>
void	print_std_vector_vec(std::vector<T>& std) {
	for (typename std::vector<T>::iterator it = std.begin() ; it != std.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template <typename T>
bool	cmp_containers_vec(std::vector<T>& stl, std::vector<T>& ft) {

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
void	print_data_of_compared_vec(std::vector<T>& stl, std::vector<T>& ft) {

	std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
	std::cout << "\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl.size() << "\t\t"<< ft.size() << STANDART<< std::endl;
	
	std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
	std::cout << "\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl.capacity() << "\t\t"<< ft.capacity() << STANDART<< std::endl;

	std::cout << BOLD_RED << UNDERLINE << "compare\t" << STANDART;
	if (cmp_containers_vec(stl, ft)) {
		std::cout << "\t\U0001F600\U00002705" << std::endl << std::endl;
	} else {
		std::cout << "\t\U0000274C" << std::endl << std::endl;
	}
}

template <typename T, class U>
void	print_ft_map(ft::map<T, U>& ft) {
	for (typename ft::map<T, U>::iterator it = ft.begin() ; it != ft.end(); ++it)
		std::cout << ' ' << it->first;
	std::cout << '\n';
}

template <typename T, class U>
void	print_std_map(std::map<T, U>& std) {
	for (typename std::map<T, U>::iterator it = std.begin() ; it != std.end(); ++it)
		std::cout << ' ' << it->first;
	std::cout << '\n';
}
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

template <typename T, class U>
bool	cmp_containers(ft::map<T, U>& stl, ft::map<T, U>& ft) {

	if (stl.size() == 0 && ft.size() == 0)
		return (true);
	if (stl.size() != ft.size())
		return (false);

	typename ft::map<T, U>::iterator it = stl.begin();
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
void	print_data_of_compared(ft::map<T, U>& stl, ft::map<T, U>& ft) {

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
		for (int i = 0; i < 20000; i += 4) {
			stdMap.insert(std::make_pair(i, i + 1));
			stdMap.insert(std::make_pair(i - 1, i + 1));
			stdMap.insert(std::make_pair(-i, -i + 1));
			stdMap.insert(std::make_pair(-i + 1, -i + 1));
		}
		

		ft::map<int, int> 										myMap;
		for (int i = 0; i < 20000; i += 4) {
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
		for (int i = 0; i < 50000; i += 4) {
			stdMap.insert(std::make_pair(i, i + 1));
			stdMap.insert(std::make_pair(i - 1, i + 1));
			stdMap.insert(std::make_pair(-i, -i + 1));
		}


		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;


		struct timeval		ftStart;
		struct timeval		ftEnd;
		gettimeofday(&ftStart, NULL);
		long	ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;


		ft::map<int, int> 										myMap;
		for (int i = 0; i < 50000; i += 4) {
			myMap.insert(ft::make_pair(i, i + 1));
			myMap.insert(ft::make_pair(i - 1, i + 1));
			myMap.insert(ft::make_pair(-i, -i + 1));
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

		for (int i = 0; i < 20000; i += 4) {
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
		for (int i = 0; i < 20000; i += 4) {
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
		for (int i = 0; i < 20000; i += 4) {
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
		for (int i = 0; i < 20000; i += 4) {
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

		for (int i = 0; i < 10000; i += 8) {
			myCopyMap.insert(ft::make_pair(i, i + 1));
			myCopyMap.insert(ft::make_pair(i - 1, i + 1));
			myCopyMap.insert(ft::make_pair(-i, -i + 1));
			myCopyMap.insert(ft::make_pair(-i + 1, -i + 1));
		}
		for (int i = 0; i < 10000; i += 8) {
			stdCopyMap.insert(std::make_pair(i, i + 1));
			stdCopyMap.insert(std::make_pair(i - 1, i + 1));
			stdCopyMap.insert(std::make_pair(-i, -i + 1));
			stdCopyMap.insert(std::make_pair(-i + 1, -i + 1));
		}
		myMap.swap(myCopyMap);
		stdMap.swap(stdCopyMap);
		print_data_of_compared(stdMap, myMap);
		print_time_map(stlDiff, ftDiff);
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

	{
		std::cout << std::endl << BOLD_GREEN << "\tTEST INSERT AGAIN" << STANDART << std::endl;
		{
			std::vector<int> ftv;
			ft::map<int, int>	ftmp;
			ft::pair<ft::map<int, int>::iterator , bool> pair = ftmp.insert(ft::make_pair(7, 7));
			ft::map<int, int>::iterator ftit = ftmp.begin();
			ftv.push_back(ftit->first);
			ftv.push_back(ftit->second);
			ftv.push_back(pair.first->first);
			ftv.push_back(pair.first->second);
			ftv.push_back(pair.second);
			ftmp.insert(ft::make_pair(9, 9));
			ft::pair<ft::map<int, int>::iterator , bool> pair2 = ftmp.insert(ft::make_pair(9, 9));
			ft::map<int, int>::iterator ftit2 = pair.first;
			ftv.push_back(ftit2->first);
			ftv.push_back(ftit2->second);
			ftv.push_back(pair2.first->first);
			ftv.push_back(pair2.first->second);
			ftv.push_back(pair2.second);
			for (int i = 0, j = 0; i < 17; ++i, ++j) {
				ftmp.insert(ft::make_pair(i, j));
			}
			ftv.push_back(ftmp.size());

			std::vector<int> stdv;
			std::map<int, int>	stdmp;
			std::pair<std::map<int, int>::iterator , bool> stdpair = stdmp.insert(std::make_pair(7, 7));
			std::map<int, int>::iterator stdit = stdmp.begin();
			stdv.push_back(stdit->first);
			stdv.push_back(stdit->second);
			stdv.push_back(stdpair.first->first);
			stdv.push_back(stdpair.first->second);
			stdv.push_back(stdpair.second);
			stdmp.insert(std::make_pair(9, 9));
			std::pair<std::map<int, int>::iterator , bool> stdpair2 = stdmp.insert(std::make_pair(9, 9));
			std::map<int, int>::iterator stdit2 = stdpair.first;
			stdv.push_back(stdit2->first);
			stdv.push_back(stdit2->second);
			stdv.push_back(stdpair2.first->first);
			stdv.push_back(stdpair2.first->second);
			stdv.push_back(stdpair2.second);
			for (int i = 0, j = 0; i < 17; ++i, ++j) {
				stdmp.insert(std::make_pair(i, j));
			}
			stdv.push_back(stdmp.size());

			print_data_of_compared_vec(stdv, ftv);
		}
	}
	{
		std::cout << std::endl << BOLD_GREEN << "\tTEST rbegin() rend()" << STANDART << std::endl;

		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int>	v;
		std::map<int, int>	mp;

		mp.insert(std::make_pair(5, 5));
		mp.insert(std::make_pair(3, 3));
		mp.insert(std::make_pair(7, 7));
		std::map<int, int>::reverse_iterator rit = mp.rbegin();
		std::map<int, int>::reverse_iterator rit2 = mp.rend();
		v.push_back(rit->first);
		rit++;
		rit2--;
		v.push_back(rit->first);
		v.push_back(rit2->first);
		rit++;
		v.push_back(*rit == *rit2);
		rit2--;
		v.push_back(rit->first);
		v.push_back(rit2->first);
		v.push_back(*rit2 > *rit);
		v.push_back(*rit2 < *rit);
		v.push_back((--rit)->first);
		v.push_back((++rit2)->first);
		v.push_back((rit--)->first);
		v.push_back((rit2++)->first);

		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;


		struct timeval		ftStart;
		struct timeval		ftEnd;
		gettimeofday(&ftStart, NULL);
		long	ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		std::vector<int> ftvec;
		ft::map<int, int>	ftmp;

		ftmp.insert(ft::make_pair(5, 5));
		ftmp.insert(ft::make_pair(3, 3));
		ftmp.insert(ft::make_pair(7, 7));
		ft::map<int, int>::reverse_iterator ftrit = ftmp.rbegin();
		ft::map<int, int>::reverse_iterator ftrit2 = ftmp.rend();
		ftvec.push_back(ftrit->first);
		ftrit++;
		ftrit2--;
		ftvec.push_back(ftrit->first);
		ftvec.push_back(ftrit2->first);
		ftrit++;
		ftvec.push_back(*ftrit == *ftrit2);
		ftrit2--;
		ftvec.push_back(ftrit->first);
		ftvec.push_back(ftrit2->first);
		ftvec.push_back(*ftrit2 > *ftrit);
		ftvec.push_back(*ftrit2 < *ftrit);
		ftvec.push_back((--ftrit)->first);
		ftvec.push_back((++ftrit2)->first);
		ftvec.push_back((ftrit--)->first);
		ftvec.push_back((ftrit2++)->first);

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared_vec(v, ftvec);
		print_time_map(stlDiff, ftDiff);
	}
}