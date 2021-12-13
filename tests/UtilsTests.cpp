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
void	print_time_time_map(long stl, long ft) {
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


bool	cmp_containers_map(std::map<int, int>& stl, ft::map<int, int>& ft) {

	if (stl.size() == 0 && ft.size() == 0)
		return (true);
	if (stl.size() != ft.size())
		return (false);

	std::map<int, int>::iterator it = stl.begin();
	ft::map<int, int>::iterator ite = ft.begin();

	while (it != stl.end()) {

		if (it->first != ite->first || it->second != ite->second || ite == ft.end())
			return (false);
		it++;
		ite++;
	}
	return (true);
}

void	print_data_of_compared_int(std::map<int, int>& stl, ft::map<int, int>& ft) {

	std::cout << BOLD_RED << UNDERLINE << "size() :" << STANDART;
	std::cout << "\tSTL\t" << "\tFT" << std::endl;
	std::cout << NORMAL << "\t\t" << stl.size() << "\t\t"<< ft.size() << STANDART<< std::endl;

	std::cout << BOLD_RED << UNDERLINE << "compare\t" << STANDART;

	if (cmp_containers_map(stl, ft)) {
		std::cout << "\t\U0001F600\U00002705" << std::endl << std::endl;
	} else {
		std::cout << "\t\U0000274C" << std::endl << std::endl;
	}
}

void	UtilsTest() {

	{
		std::vector<int>	v;
		ft::map<int, int>	mp;
		for (int i = 0, j = 0; i < 500000; ++i, ++j)
			mp.insert(ft::make_pair(i, j));
		mp.erase(mp.begin(), --mp.end());
		// print_ft_map(mp);
		v.push_back(mp.begin()->first);
		std::cout << "SEGA" << std::endl;
	}
}