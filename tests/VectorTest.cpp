#include "../containers/vector.hpp"
#include <vector>
#include <iostream>
#include "tests.hpp"


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

		for (ft::vector<int>::iterator it = ft_with_size.begin() ; it != ft_with_size.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		for (std::vector<int>::iterator it = stl_with_size.begin() ; it != stl_with_size.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_with_size.size() << "\t\t"<< ft_with_size.size() << STANDART<< std::endl;

		std::cout << BOLD_RED << UNDERLINE << "capacity() :" << STANDART;
		std::cout << "\tSTL\t" << "\tFT" << std::endl;
		std::cout << NORMAL << "\t\t" << stl_with_size.capacity() << "\t\t"<< ft_with_size.capacity() << STANDART<< std::endl;
		
	}
}