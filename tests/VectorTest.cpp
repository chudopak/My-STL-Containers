#include "../containers/vector.hpp"
#include <vector>
#include <iostream>
#include "tests.hpp"

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

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



void	VectorTests(void) {

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
	}

	{
		 std::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);		
		std::cout << myvector.capacity() <<std::endl;
		// erase the 6th element
		myvector.erase (myvector.begin()+5);
		std::cout << myvector.capacity() <<std::endl;
		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);
		std::cout << myvector.capacity() <<std::endl;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
		  std::cout << ' ' << myvector[i];
		std::cout << std::endl << myvector.capacity() <<std::endl;

	}

	
	// std::cout << BOLD_GREEN << "\t____Testing reserv___" << STANDART << std::endl;
	// {
	// 	ft::vector<int> vct(7);

	// 	for (unsigned long int i = 0; i < vct.size(); ++i)
	// 	{
	// 		vct.at(i) = (vct.size() - i) * 3;
	// 		std::cout << "vct.at(): " << vct.at(i) << " | ";
	// 		std::cout << "vct[]: " << vct[i] << std::endl;
	// 	}

	// 	ft::vector<int> const vct_c(vct);

	// 	std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	// 	std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	// 	try {
	// 		vct.at(10) = 42;
	// 	}
	// 	catch (std::out_of_range &e) {
	// 		std::cout << "Catch out_of_range exception!" << std::endl;
	// 	}
	// 	catch (std::exception &e) {
	// 		std::cout << "Catch exception: " << e.what() << std::endl;
	// 	}
	// }
}