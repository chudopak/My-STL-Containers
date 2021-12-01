#include "tests.hpp"


template <typename T>
void	print_ft_vector(ft::vector<T>& ft) {
	for (typename ft::vector<T>::iterator it = ft.begin() ; it != ft.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template <typename T>
void	print_std_vector(std::vector<T>& std) {
	for (typename std::vector<T>::iterator it = std.begin() ; it != std.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template <typename T>
bool	cmp_containers(std::vector<T>& stl, ft::vector<T>& ft) {

	if (stl.size() == 0 && ft.size() == 0)
		return (true);
	if (stl.size() != ft.size())
		return (false);

	typename std::vector<T>::iterator it = stl.begin();
	typename ft::vector<T>::iterator ite = ft.begin();

	while (it < stl.end()) {
		if (*it != *ite)
			return (false);
		it++;
		ite++;
	}
	return (true);
}

template <typename T>
void	print_data_of_compared(std::vector<T>& stl, ft::vector<T>& ft) {

	std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
	std::cout << "\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl.size() << "\t\t"<< ft.size() << STANDART<< std::endl;
	
	std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
	std::cout << "\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl.capacity() << "\t\t"<< ft.capacity() << STANDART<< std::endl;

	std::cout << BOLD_RED << UNDERLINE << "compare\t" << STANDART;
	if (cmp_containers(stl, ft)) {
		std::cout << "\t\U0001F600\U00002705" << std::endl << std::endl;
	} else {
		std::cout << "\t\U0000274C" << std::endl << std::endl;
	}
}

void	print_time(long stl, long ft) {
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

	std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
	std::cout << "\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl.size() << "\t\t"<< ft.size() << STANDART<< std::endl;
	
	std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
	std::cout << "\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl.capacity() << "\t\t"<< ft.capacity() << STANDART<< std::endl;

	std::cout << BOLD_RED << UNDERLINE << "compare\t" << STANDART;
	if (cmp_containers(stl, ft)) {
		std::cout << "\t\U0001F600\U00002705" << std::endl << std::endl;
	} else {
		std::cout << "\t\U0000274C" << std::endl << std::endl;
	}
}



void	VectorTests(void) {
 
	std::cout << YELLOW << " \\    /  |---  |/  -----  .oo.  |®®" << std::endl;
	std::cout << YELLOW << "  \\  /   |--   |\\    |    o  o  |®®" << std::endl;
	std::cout << YELLOW << "   \\/    |---  | \\   |    .oo.  |\\" << std::endl;

	std::cout << BOLD_GREEN << "\t____Testing empty container____" << STANDART << std::endl;
	{
		std::vector<int>	stl;
		ft::vector<int>		ft;

		print_data_of_compared(stl, ft);
	}


	{
		std::cout << BOLD_GREEN << "\t____Testing Default Constructor Pointer____" << STANDART << std::endl;
		std::vector<int>	*stl = new std::vector<int>;
		ft::vector<int>		*ft = new ft::vector<int>;

		print_data_of_compared(*stl, *ft);
		delete stl;
		delete ft;
	}

	{
		std::cout << BOLD_GREEN << "\t____Testing Constructor With 0 Size____" << STANDART << std::endl;
		std::vector<int>	stl(0);
		ft::vector<int>		ft(0);

		print_data_of_compared(stl, ft);

	}

	std::cout << BOLD_GREEN << "\t____Testing Constructor With 9 Size____" << STANDART << std::endl;
	{
		std::vector<int>	stl_with_size(9);
		ft::vector<int>		ft_with_size(9);

		print_data_of_compared(stl_with_size, ft_with_size);
	}

	std::cout << BOLD_GREEN << "\t____Testing First Constructor With 30000000 Size____" << STANDART << std::endl;
	{
		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stdBig2(30000000);

		gettimeofday(&stlEnd, NULL);

		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;
		ft::vector<int> ftBig2(30000000);

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stdBig2, ftBig2);
		print_time(stlDiff, ftDiff);
	}

	std::cout << BOLD_GREEN << "\t____Testing Second Constructor With 30000000 Size____" << STANDART << std::endl;
	{
		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stdBig2(30000000, 1);

		gettimeofday(&stlEnd, NULL);

		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;
		ft::vector<int> ftBig2(30000000, 1);

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stdBig2, ftBig2);
		print_time(stlDiff, ftDiff);
	}

	std::cout << BOLD_GREEN << "\t____Testing Third Constructor With 30000000 Size____" << STANDART << std::endl;
	{
		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		std::vector<int> stdBig2(30000000, 1);
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stdBig(stdBig2.begin(), stdBig2.end());

		gettimeofday(&stlEnd, NULL);

		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;

		ft::vector<int> ftBig2(30000000, 1);
		gettimeofday(&ftStart, NULL);
		long	ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		ft::vector<int> ftBig(ftBig2.begin(), ftBig2.end());

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stdBig2, ftBig2);
		print_time(stlDiff, ftDiff);
	}

	std::cout << BOLD_GREEN << "\t____Testing Copy Constructor With 30000000 Size____" << STANDART << std::endl;
	{
		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		std::vector<int> stdBig2(30000000, 1);
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stdBig(stdBig2);

		gettimeofday(&stlEnd, NULL);

		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;

		ft::vector<int> ftBig2(30000000, 1);
		gettimeofday(&ftStart, NULL);
		long	ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		ft::vector<int> ftBig(ftBig2);

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stdBig2, ftBig2);
		print_time(stlDiff, ftDiff);
	}

	std::cout << BOLD_GREEN << "\t____Testing Capacity____" << STANDART << std::endl;
	{
		std::vector<int>	stl_with_size(9);
		ft::vector<int>		ft_with_size(9);

		ft::vector<int>::iterator iter = ft_with_size.begin();
		std::vector<int>::iterator iters = stl_with_size.begin();

		for (int i = 0 ; iter != ft_with_size.end(); ++iter) {
			int& tmp = ft_with_size.at(i);
			tmp = i;
			i++;
		}

		for (int i = 0 ; iters != stl_with_size.end(); ++iters) {
			int& tmp = stl_with_size.at(i);
			tmp = i;
			i++;
		}

		
		print_ft_vector(ft_with_size);
		print_std_vector(stl_with_size);

		ft_with_size.clear();
		stl_with_size.clear();

		print_data_of_compared(stl_with_size, ft_with_size);
	}

	
	std::cout << BOLD_GREEN << "\t____Testing reserve()____" << STANDART << std::endl;
	{
		std::vector<int>	stl(10);
		ft::vector<int>		ft(10);

		std::cout << YELLOW << "Before reserve()" << STANDART<< std::endl;
		print_data_of_compared(stl, ft);

		ft.reserve(15);
		stl.reserve(15);
		print_ft_vector(ft);
		print_std_vector(stl);
		
		std::cout << YELLOW << "After reserve(15)" << STANDART <<std::endl;
		print_data_of_compared(stl, ft);
	}

	{
		std::cout << BOLD_GREEN << "\t____Testing insert1()____" << STANDART << std::endl;
		ft::vector<int> ft(10);
		ft::vector<int> ft2;
		std::vector<int> stl(10);
		std::vector<int> stl2;

		for (unsigned long int i = 0; i < ft.size(); ++i)
			ft[i] = (ft.size() - i) * 3;
		for (unsigned long int i = 0; i < stl.size(); ++i)
			stl[i] = (stl.size() - i) * 3;
		
		std::cout << YELLOW << "CMP - adding one variable to empry containers:" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.insert(vec.end(), 1);" << STANDART<< std::endl;
		ft2.insert(ft2.end(), 1);
		stl2.insert(stl2.end(), 1);
		print_data_of_compared(stl2, ft2);

		std::cout << YELLOW << "CMP - adding 2 variables previos containers:" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.insert(vec.begin(), 2, 2);" << STANDART<< std::endl;
		ft2.insert(ft2.begin(), 2, 2);
		stl2.insert(stl2.begin(), 2, 2);
		print_data_of_compared(stl2, ft2);

		std::cout << YELLOW << "CMP - adding one variable in front:" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.insert(vec.end() - 2, 3);" << STANDART<< std::endl;
		ft2.insert(ft2.end() - 2, 3);
		stl2.insert(stl2.end() - 2, 3);
		print_data_of_compared(stl2, ft2);


		std::cout << YELLOW << "CMP - adding 2 variables at the end:" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.insert(vec.end(), 2, 4);" << STANDART<< std::endl;
		ft2.insert(ft2.end(), 2, 4);
		stl2.insert(stl2.end(), 2, 4);
		print_data_of_compared(stl2, ft2);


		std::cout << YELLOW << "CMP - huge size" << STANDART<< std::endl;
		std::cout << YELLOW << "stdBig2.insert(stdBig2.end(), 100000000, 1);" << STANDART<< std::endl;
		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stdBig(10000000, 3);
		std::vector<int> stdBig2(300000);

		stdBig2.insert(stdBig2.end(), 10000000, 1);

		gettimeofday(&stlEnd, NULL);

		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;
		ft::vector<int> ftBig(10000000, 3);
		ft::vector<int> ftBig2(300000);

		ftBig2.insert(ftBig2.end(), 10000000, 1);

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stdBig2, ftBig2);
		print_time(stlDiff, ftDiff);
	}

	std::cout << BOLD_GREEN << "\t____Testing insert2()____" << STANDART << std::endl;
	{
		ft::vector<int> ft(5);
		ft::vector<int> ft2;
		std::vector<int> std(5);
		std::vector<int> std2;
		const int cut = 3;

		for (unsigned long int i = 0; i < ft.size(); ++i)
			ft[i] = (ft.size() - i) * 7;
		for (unsigned long int i = 0; i < std.size(); ++i)
			std[i] = (std.size() - i) * 7;

		std::cout << YELLOW << "CMP - (cut = 3); add range of variables:" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.insert(vec.begin(), ft.begin(), ft.end() + cut);" << STANDART<< std::endl;
		ft2.insert(ft2.begin(), ft.begin(), ft.begin() + cut);
		std2.insert(std2.begin(), std.begin(), std.begin() + cut);
		print_data_of_compared(std2, ft2);

		std::cout << YELLOW << "CMP - (cut = 3); add range of variables:" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.insert(vec.begin(), ft.begin() + cut, ft.end());" << STANDART<< std::endl;
		ft2.insert(ft2.begin(), ft.begin() + cut, ft.end());
		std2.insert(std2.begin(), std.begin() + cut, std.end());
		print_data_of_compared(std2, ft2);

		std::cout << YELLOW << "CMP - (cut = 3); add range of variables:" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.insert(vec.begin(), ft.begin(), ft.begin() + cut);" << STANDART<< std::endl;
		ft2.insert(ft2.end(), ft.begin(), ft.begin() + cut);
		std2.insert(std2.end(), std.begin(), std.begin() + cut);
		print_data_of_compared(std2, ft2);


		std::cout << YELLOW << "CMP - huge size" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.insert(vec.begin(), ft.begin(), ft.begin());" << STANDART<< std::endl;
		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stdBig(10000000, 3);
		std::vector<int> stdBig2(30000000);

		stdBig2.insert(stdBig2.end(), stdBig.begin(), stdBig.begin());

		gettimeofday(&stlEnd, NULL);

		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;
		ft::vector<int> ftBig(10000000, 3);
		ft::vector<int> ftBig2(30000000);

		ftBig2.insert(ftBig2.end(), ftBig.begin(), ftBig.begin());

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(stdBig2, ftBig2);
		print_time(stlDiff, ftDiff);
	}

	std::cout << BOLD_GREEN << "\t____Testing resize() and resirve()____" << STANDART << std::endl;
	{
		const int start_size = 7;
		ft::vector<int> ft(start_size, 20);
		ft::vector<int> ft2;
		ft::vector<int>::iterator it = ft.begin();

		std::vector<int> std(start_size, 20);
		std::vector<int> std2;
		std::vector<int>::iterator ite = std.begin();

		for (int i = 2; i < start_size; ++i)
			it[i] = (start_size - i);

		for (int i = 2; i < start_size; ++i)
			ite[i] = (start_size - i);

		std::cout << YELLOW << "CMP - resizing vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.resize(10, 89);" << STANDART<< std::endl;
		ft.resize(10, 89);
		std.resize(10, 89);
		print_data_of_compared(std, ft);

		std::cout << YELLOW << "CMP - resizing vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.resize(5);" << STANDART<< std::endl;
		ft.resize(5);
		std.resize(5);
		print_data_of_compared(std, ft);

		std::cout << YELLOW << "CMP - resizing vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.resize(31, 11);" << STANDART<< std::endl;
		ft.resize(31, 11);
		std.resize(31, 11);
		print_data_of_compared(std, ft);


		std::cout << YELLOW << "CMP - resizing vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.resize(23, 44);" << STANDART<< std::endl;
		ft.resize(23, 44);
		std.resize(23, 44);
		print_data_of_compared(std, ft);


		std::cout << YELLOW << "CMP - resizing vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.resize(5);" << STANDART<< std::endl;
		ft.resize(5);
		std.resize(5);
		print_data_of_compared(std, ft);


		std::cout << YELLOW << "CMP - reserving space vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.reserve(5);" << STANDART<< std::endl;
		ft.reserve(5);
		std.reserve(5);
		print_data_of_compared(std, ft);

		std::cout << YELLOW << "CMP - reserving space vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.reserve(3);" << STANDART<< std::endl;
		ft.reserve(3);
		std.reserve(3);
		print_data_of_compared(std, ft);

		std::cout << YELLOW << "CMP - resizing vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.resize(87);" << STANDART<< std::endl;
		ft.resize(87);
		std.resize(87);
		print_data_of_compared(std, ft);

		std::cout << YELLOW << "CMP - resizing vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.resize(87);" << STANDART<< std::endl;
		ft.resize(5);
		std.resize(5);
		print_data_of_compared(std, ft);


		std::cout << YELLOW << "CMP - assigning vectors" << STANDART<< std::endl;
		std::cout << YELLOW << "vec2 = vec " << STANDART<< std::endl;
		ft2 = ft;
		std2 = std;
		print_data_of_compared(std2, ft2);

		std::cout << YELLOW << "CMP - reserving space vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.reserve(vec.capacity() + 1);" << STANDART<< std::endl;
		ft.reserve(ft.capacity() + 1);
		std.reserve(std.capacity() + 1);
		print_data_of_compared(std, ft);

		std::cout << YELLOW << "CMP - resizing vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.resize(0);" << STANDART<< std::endl;
		ft2.resize(0);
		std2.resize(0);
		print_data_of_compared(std, ft);


		std::cout << YELLOW << "CMP - time reserving vector" << STANDART<< std::endl;
		std::cout << YELLOW << "vec.reserve(100000000);" << STANDART<< std::endl;
		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std.reserve(100000000);

		gettimeofday(&stlEnd, NULL);

		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		ft.reserve(100000000);

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;
		print_data_of_compared(std, ft);
		print_time(stlDiff, ftDiff);
	}

	std::cout << BOLD_GREEN << "\t____Testing assign()____" << STANDART << std::endl;
	{
		ft::vector<int> ft_v;
		ft::vector<int> ft, ft2;

		std::vector<int> stl_v;
		std::vector<int> stl, stl2;

		std::vector<int>	stl_vector;
		ft::vector<int>		ft_vector;

		struct timeval		stlStart;
		struct timeval		stlEnd;
		
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		stl_vector.assign(3, 3);
		stl.assign(40000000, 1);
		stl2.assign(4000, 1);
		stl_vector.assign(stl.begin(), stl.end());
		stl_v.push_back(stl_vector[1]);
		stl_v.push_back(stl_vector.size());
		stl_vector.assign(stl2.begin(), stl2.end());
		stl_v.push_back(stl_vector[444]);
		stl_v.push_back(stl_vector.size());

		gettimeofday(&stlEnd, NULL);

		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;

		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		ft_vector.assign(3, 3);
		ft.assign(40000000, 1);
		ft2.assign(4000, 1);
		ft_vector.assign(ft.begin(), ft.end());
		ft_v.push_back(ft_vector[1]);
		ft_v.push_back(ft_vector.size());
		ft_vector.assign(ft2.begin(), ft2.end());
		ft_v.push_back(ft_vector[444]);
		ft_v.push_back(ft_vector.size());

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;

		print_data_of_compared(stl_v, ft_v);
		print_time(stlDiff, ftDiff);
	}

	std::cout << BOLD_GREEN << "\t____Testing erase() range____" << STANDART << std::endl;
	{

		struct timeval		stlStart;
		struct timeval		stlEnd;
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stl;
		std::vector<int> stl_v(10000, 6);
		for (int i = 0; i < 99000000; ++i)
			stl_v.push_back(i);
		stl.push_back(*(stl_v.erase(stl_v.begin() + 80000, stl_v.end() - 15000000)));
		stl.push_back(*(stl_v.begin() + 82000));
		stl.push_back(stl_v.size());

		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		ft::vector<int> ft;
		ft::vector<int> ft_v(10000, 6);
		for (int i = 0; i < 99000000; ++i)
			ft_v.push_back(i);
		ft.push_back(*(ft_v.erase(ft_v.begin() + 80000, ft_v.end() - 15000000)));
		ft.push_back(*(ft_v.begin() + 82000));
		ft.push_back(ft_v.size());

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;

		print_data_of_compared(stl, ft);
		print_time(stlDiff, ftDiff);
	}

	std::cout << BOLD_GREEN << "\t____Testing erase() value____" << STANDART << std::endl;
	{
		struct timeval		stlStart;
		struct timeval		stlEnd;
		gettimeofday(&stlStart, NULL);
		long	stlStartMil = stlStart.tv_sec * 1000 + stlStart.tv_usec / 1000;

		std::vector<int> stl;
		std::vector<int> stl_v;
		for (int i = 0; i < 99000000; ++i)
			stl_v.push_back(i);
		stl.push_back(*(stl_v.erase(stl_v.begin() + 80000)));
		stl.push_back(*(stl_v.begin() + 82000));
		stl.push_back(stl_v.size());

		gettimeofday(&stlEnd, NULL);
		long	stlEndMil = stlEnd.tv_sec * 1000 + stlEnd.tv_usec / 1000;
		long	stlDiff = stlEndMil - stlStartMil;

		struct timeval		ftStart;
		struct timeval		ftEnd;
		long				ftStartMil;
		gettimeofday(&ftStart, NULL);
		ftStartMil = ftStart.tv_sec * 1000 + ftStart.tv_usec / 1000;

		ft::vector<int> ft;
		ft::vector<int> ft_v;
		for (int i = 0; i < 99000000; ++i)
			ft_v.push_back(i);
		ft.push_back(*(ft_v.erase(ft_v.begin() + 80000)));
		ft.push_back(*(ft_v.begin() + 82000));
		ft.push_back(ft_v.size());

		gettimeofday(&ftEnd, NULL);
		long	ftEndMil = ftEnd.tv_sec * 1000 + ftEnd.tv_usec / 1000;
		long	ftDiff = ftEndMil - ftStartMil;

		print_data_of_compared(stl, ft);
		print_time(stlDiff, ftDiff);
	}
}