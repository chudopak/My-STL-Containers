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

void	VectorTests(void) {

	std::cout << BOLD_GREEN << "\t____Testing empty container____" << STANDART << std::endl;
	{
		std::vector<int>	stl_vector;
		ft::vector<int>		ft_vector;

		std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_vector.size() << "\t\t"<< ft_vector.size() << STANDART<< std::endl;

		std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_vector.capacity() << "\t\t"<< ft_vector.capacity() << STANDART<< std::endl;
	}


	std::cout << BOLD_GREEN << "\t____Testing Default Constructor Pointer____" << STANDART << std::endl;
	{
		std::vector<int>	*stl_pointer_vector = new std::vector<int>;
		ft::vector<int>		*ft_pointer_vector = new ft::vector<int>;

		std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_pointer_vector->size() << "\t\t"<< ft_pointer_vector->size() << STANDART<< std::endl;

		std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_pointer_vector->capacity() << "\t\t"<< ft_pointer_vector->capacity() << STANDART<< std::endl;
		delete stl_pointer_vector;
		delete ft_pointer_vector;
	}

	std::cout << BOLD_GREEN << "\t____Testing Constructor With 0 Size____" << STANDART << std::endl;
	{
		std::vector<int>	stl_fill_vector(0);
		ft::vector<int>		ft_fill_vector(0);

		std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_fill_vector.size() << "\t\t"<< ft_fill_vector.size() << STANDART<< std::endl;

		std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_fill_vector.capacity() << "\t\t"<< ft_fill_vector.capacity() << STANDART<< std::endl;
		
	}

	std::cout << BOLD_GREEN << "\t____Testing Constructor With 9 Size____" << STANDART << std::endl;
	{
		std::vector<int>	stl_with_size(9);
		ft::vector<int>		ft_with_size(9);

		std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_with_size.size() << "\t\t"<< ft_with_size.size() << STANDART<< std::endl;

		std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_with_size.capacity() << "\t\t"<< ft_with_size.capacity() << STANDART<< std::endl;
		
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

		std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_with_size.size() << "\t\t"<< ft_with_size.size() << STANDART<< std::endl;

		std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_with_size.capacity() << "\t\t"<< ft_with_size.capacity() << STANDART<< std::endl;
		
	}

	std::cout << BOLD_GREEN << "\t____Testing insert()____" << STANDART << std::endl;
	{
		std::vector<int>	stl_with_size(10);
		ft::vector<int>		ft_with_size(10);
		ft::vector<int>		ft_insert(3);
		std::vector<int>	stl_insert(3);


		// for (int i = 0 ; i < 7; ++i) {
		// 	int& tmp = ft_with_size.at(i);
		// 	tmp = i;
		// }

		// for (int i = 0 ; i < 7; ++i) {
		// 	int& tmp = stl_with_size.at(i);
		// 	tmp = i;
		// }

		for (int i = 10 ; i < 13; ++i) {
			int& tmp = ft_insert.at(i - 10);
			tmp = i;
		}

		for (int i = 10 ; i < 13; ++i) {
			int& tmp = stl_insert.at(i - 10);
			tmp = i;
		}

		print_ft_vector(ft_insert);
		print_std_vector(stl_insert);

		ft_with_size.reserve(20);
		stl_with_size.reserve(20);
		ft_with_size.insert(ft_with_size.begin() + 6, ft_insert.begin(), ft_insert.end());
		stl_with_size.insert(stl_with_size.begin() + 6, stl_insert.begin(), stl_insert.end());

		print_ft_vector(ft_with_size);
		print_std_vector(stl_with_size);


		std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_with_size.size() << "\t\t"<< ft_with_size.size() << STANDART<< std::endl;

		std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_with_size.capacity() << "\t\t"<< ft_with_size.capacity() << STANDART<< std::endl;
	}

	std::cout << BOLD_GREEN << "\t____Testing reserve()____" << STANDART << std::endl;
	{
		std::vector<int>	stl(10);
		ft::vector<int>		ft(10);

		std::cout << BOLD_GREEN << "Before reserve()" << STANDART<< std::endl;
		std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl.size() << "\t\t"<< ft.size() << STANDART<< std::endl;

		std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl.capacity() << "\t\t"<< ft.capacity() << STANDART<< std::endl;


		ft.reserve(11);
		stl.reserve(11);
		print_ft_vector(ft);
		print_std_vector(stl);
		
		std::cout << BOLD_GREEN << "After reserve()" << STANDART <<std::endl;
		std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl.size() << "\t\t"<< ft.size() << STANDART<< std::endl;

		std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl.capacity() << "\t\t"<< ft.capacity() << STANDART<< std::endl;




	}
	{
		std::cout << BOLD_GREEN << "\t____Testing insert1()____" << STANDART << std::endl;
	ft::vector<int> ft(10);
	ft::vector<int> ft2;
	std::vector<int> stl(10);
	std::vector<int> stl2;

	for (unsigned long int i = 0; i < ft.size(); ++i)
		ft[i] = (ft.size() - i) * 3;
	ft2.insert(ft2.end(), 42);
	print_ft_vector(ft);
	ft2.insert(ft2.begin(), 2, 21);

	ft2.insert(ft2.end() - 2, 42);

	ft2.insert(ft2.end(), 2, 84);

	ft2.resize(4);

	ft2.insert(ft2.begin() + 2, ft.begin(), ft.end());
	ft.clear();
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