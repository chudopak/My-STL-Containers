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
	// int		iterations = 0;
	for (typename ft::map<T, U>::iterator it = ft.begin() ; it != ft.end(); ++it) {
		std::cout << ' ' << it->first;
	// std::cout << "LOOP" << std::endl;
		// if (iterations > 30)
			// break;
		// iterations++;
	}
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

	{
		std::cout << std::endl << BOLD_GREEN << "\tTEST find() count()" << STANDART << std::endl;

		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int>	stdvec;
		std::map<int, int>	stdmp;

		for (int i = 0, j = 0; i < 30000; i += 2, ++j) {
			stdmp.insert(std::make_pair(-i, j));
			stdmp.insert(std::make_pair(i, j));
			stdmp.insert(std::make_pair(i + 1, j));
		}
		std::map<int, int>::iterator it = stdmp.find(29000);
		stdvec.push_back(it->first);
		stdvec.push_back(it->second);
		it = stdmp.find(-29000);
		stdvec.push_back(it->first);
		stdvec.push_back(it->second);
		it = stdmp.find(-234523542);
		if (it == stdmp.end())
			stdvec.push_back(1);

		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		gettimeofday(&ftStart, NULL);
		long	ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		std::vector<int>	ftvec;
		ft::map<int, int>	mp;

		for (int i = 0, j = 0; i < 30000; i += 2, ++j) {
			mp.insert(ft::make_pair(-i, j));
			mp.insert(ft::make_pair(i, j));
			mp.insert(ft::make_pair(i + 1, j));
		}
		ft::map<int, int>::iterator ftit = mp.find(29000);
		ftvec.push_back(ftit->first);
		ftvec.push_back(ftit->second);
		ftit = mp.find(-29000);
		ftvec.push_back(ftit->first);
		ftvec.push_back(ftit->second);
		ftit = mp.find(-234523542);
		if (ftit == mp.end())
			ftvec.push_back(1);
			
		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared_vec(stdvec, ftvec);
		print_time_map(stlDiff, ftDiff);
	}
	{
		std::cout << std::endl << BOLD_GREEN << "\tTEST erase()" << STANDART << std::endl;
		std::cout << YELLOW << "\ttesting time erase()" << STANDART << std::endl;

		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int>	stdvec;
		std::map<int, int>	stdmp;
		stdvec.push_back(stdmp.erase(3));
		for (int i = 0, j = 0; i < 500000 ; ++i, ++j)
			stdmp.insert(std::make_pair(i, j));
		std::map<int, int>::iterator stdit = stdmp.begin();
		stdvec.push_back(stdmp.erase(0));
		stdvec.push_back(stdmp.size());
		stdvec.push_back(stdit->first);
		stdvec.push_back(stdmp.erase(-1));
		stdvec.push_back(stdmp.size());
		stdit = stdmp.begin();
		stdvec.push_back(stdit->first);
		std::map<int, int>::iterator stdit4 = stdmp.begin();
		for (; stdit4 != stdmp.end(); stdit4 = stdmp.begin())
				stdmp.erase(stdit4->first);
		std::map<int, int>::iterator stdit2 = stdmp.end();
		stdit2--;
		stdvec.push_back(stdmp.erase(400000));
		stdvec.push_back(stdmp.size());
		std::map<int, int> stdmp2;
		for (int i = 0, j = 0; i < 10 ; ++i, ++j)
				stdmp2.insert(std::make_pair(i, j));
		stdmp2.erase(2);
		stdmp2.erase(7);
		std::map<int, int>::iterator stdit3 = stdmp2.begin();
		for (; stdit3 != stdmp2.end(); ++stdit3) {
			stdvec.push_back(stdit3->first);
			stdvec.push_back(stdit3->second);
		}

		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		gettimeofday(&ftStart, NULL);
		long	ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		std::vector<int>	ftvec;
		ft::map<int, int>	ftmp;
		ftvec.push_back(ftmp.erase(3));
		for (int i = 0, j = 0; i < 500000 ; ++i, ++j)
			ftmp.insert(ft::make_pair(i, j));
		ft::map<int, int>::iterator ftit = ftmp.begin();
		ftvec.push_back(ftmp.erase(0));
		ftvec.push_back(ftmp.size());
		ftvec.push_back(ftit->first);
		ftvec.push_back(ftmp.erase(-1));
		ftvec.push_back(ftmp.size());
		ftit = ftmp.begin();
		ftvec.push_back(ftit->first);
		ft::map<int, int>::iterator ftit4 = ftmp.begin();
		for (; ftit4 != ftmp.end(); ftit4 = ftmp.begin())
				ftmp.erase(ftit4->first);
		ft::map<int, int>::iterator ftit2 = ftmp.end();
		ftit2--;
		ftvec.push_back(ftmp.erase(400000));
		ftvec.push_back(ftmp.size());
		ft::map<int, int> ftmp2;
		for (int i = 0, j = 0; i < 10 ; ++i, ++j)
				ftmp2.insert(ft::make_pair(i, j));
		ftmp2.erase(2);
		ftmp2.erase(7);
		ft::map<int, int>::iterator ftit3 = ftmp2.begin();
		for (; ftit3 != ftmp2.end(); ++ftit3) {
			ftvec.push_back(ftit3->first);
			ftvec.push_back(ftit3->second);
		}

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared_vec(stdvec, ftvec);
		print_time_map(stlDiff, ftDiff);

		std::cout << std::endl << YELLOW << "\ttesting triky erase()" << STANDART << std::endl;

		ft::map<int, int>	ftTree;
		ftTree.insert(ft::make_pair(15, 0));
		ftTree.insert(ft::make_pair(10, 0));
		ftTree.insert(ft::make_pair(1, 0));
		ftTree.insert(ft::make_pair(12, 0));
		ftTree.insert(ft::make_pair(30, 0));
		ftTree.insert(ft::make_pair(22, 0));
		ftTree.insert(ft::make_pair(25, 0));
		ftTree.insert(ft::make_pair(20, 0));
		ftTree.insert(ft::make_pair(40, 0));
		ftTree.insert(ft::make_pair(33, 0));
		ftTree.insert(ft::make_pair(31, 0));
		ftTree.insert(ft::make_pair(32, 0));
		ftTree.insert(ft::make_pair(39, 0));
		ftTree.insert(ft::make_pair(50, 0));
		ftTree.insert(ft::make_pair(60, 0));

		ftTree.erase(30);

		std::map<int, int>	stdTree;
		stdTree.insert(std::make_pair(15, 0));
		stdTree.insert(std::make_pair(10, 0));
		stdTree.insert(std::make_pair(1, 0));
		stdTree.insert(std::make_pair(12, 0));
		stdTree.insert(std::make_pair(30, 0));
		stdTree.insert(std::make_pair(22, 0));
		stdTree.insert(std::make_pair(25, 0));
		stdTree.insert(std::make_pair(20, 0));
		stdTree.insert(std::make_pair(40, 0));
		stdTree.insert(std::make_pair(33, 0));
		stdTree.insert(std::make_pair(31, 0));
		stdTree.insert(std::make_pair(32, 0));
		stdTree.insert(std::make_pair(39, 0));
		stdTree.insert(std::make_pair(50, 0));
		stdTree.insert(std::make_pair(60, 0));

		stdTree.erase(30);
		print_data_of_compared(stdTree, ftTree);
		ftTree.erase(1);
		stdTree.erase(1);
		print_data_of_compared(stdTree, ftTree);
		ftTree.erase(15);
		stdTree.erase(15);
		print_data_of_compared(stdTree, ftTree);
		stdTree.insert(std::make_pair(15, 0));
		ftTree.insert(ft::make_pair(15, 0));
		print_data_of_compared(stdTree, ftTree);
		ftTree.erase(10);
		stdTree.erase(10);
		print_data_of_compared(stdTree, ftTree);
	}
	{
		ft::map<int, int>	ftTree;
		ftTree.insert(ft::make_pair(10, 0));
		ftTree.insert(ft::make_pair(1, 0));

		std::map<int, int>	stdTree;
		stdTree.insert(std::make_pair(10, 0));
		stdTree.insert(std::make_pair(1, 0));
		ftTree.erase(10);
		stdTree.erase(10);
		print_data_of_compared(stdTree, ftTree);
		ftTree.erase(1);
		stdTree.erase(1);
		print_data_of_compared(stdTree, ftTree);
				ftTree.insert(ft::make_pair(10, 0));
		ftTree.insert(ft::make_pair(1, 0));

		stdTree.insert(std::make_pair(10, 0));
		stdTree.insert(std::make_pair(1, 0));
		ftTree.erase(10);
		stdTree.erase(10);
		print_data_of_compared(stdTree, ftTree);
		ftTree.erase(1);
		stdTree.erase(1);
		print_data_of_compared(stdTree, ftTree);
	}



	{
		std::vector<int>	v;
		ft::map<int, int>	mp;
		for (int i = 0, j = 0; i < 1000; ++i, ++j)
			mp.insert(ft::make_pair(i, j));
		mp.erase(mp.begin(), --mp.end());
		std::cout << "SEGA" << std::endl;
		print_ft_map(mp);
		v.push_back(mp.begin()->first);
	}
}