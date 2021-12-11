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


void	UtilsTest() {
		{
		std::cout << "New consept" << std::endl;
		std::map<int, int> 										stdMap;
		for (int i = 0; i < 3; i += 1) {
			stdMap.insert(std::make_pair(i, i + 1));
			stdMap.insert(std::make_pair(-i, -i + 1));
		}
		ft::map<int, int> 										myMap;
		for (int i = 0; i < 3; i += 1) {
			myMap.insert(ft::make_pair(i, i + 1));
			myMap.insert(ft::make_pair(-i, -i + 1));
		}
		print_ft_map(myMap);
		print_std_map(stdMap);
		print_data_of_compared(stdMap, myMap);

	}

	// // std::vector<int> result, result2;
	// // std::vector<char> v1, v2;
	// // ft::vector<char> b1, b2;
	// // v1.assign(50000000, 'f');
	// // v1.push_back('e');
	// // v2.assign(50000000, 'f');
	// // v2.push_back('e');
	// // b1.assign(50000000, 'f');
	// // b1.push_back('e');
	// // b2.assign(50000000, 'f');
	// // b2.push_back('e');
	// // result.push_back(std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
	// // result2.push_back(ft::lexicographical_compare(b1.begin(), b1.end(), b2.begin(), b2.end()));
	// // std::vector<int> v;
	// // bool res = 1;
	// // (std::is_integral<float>() == std::is_integral<float>()) ? 0 : res = 0;
	// // (std::is_integral<int>() == std::is_integral<int>()) ? 0 : res = 0;
	// // (std::is_integral<bool>() == std::is_integral<bool>()) ? 0 : res = 0;
	// // (std::is_integral<char>() == std::is_integral<char>()) ? 0 : res = 0;
	// // (std::is_integral<signed char>() == std::is_integral<signed char>()) ? 0 : res = 0;
	// // (std::is_integral<unsigned char>() == std::is_integral<unsigned char>()) ? 0 : res = 0;
	// // (std::is_integral<wchar_t>() == std::is_integral<wchar_t>()) ? 0 : res = 0;
	// // (std::is_integral<char16_t>() == std::is_integral<char16_t>()) ? 0 : res = 0;
	// // (std::is_integral<short>() == std::is_integral<short>()) ? 0 : res = 0;
	// // (std::is_integral<unsigned short>() == std::is_integral<unsigned short>()) ? 0 : res = 0;
	// // (std::is_integral<unsigned int>() == std::is_integral<unsigned int>()) ? 0 : res = 0;
	// // (std::is_integral<long>() == std::is_integral<long>()) ? 0 : res = 0;
	// // (std::is_integral<unsigned long>() == std::is_integral<unsigned long>()) ? 0 : res = 0;
	// // (std::is_integral<long long>() == std::is_integral<long long>()) ? 0 : res = 0;
	// // (std::is_integral<unsigned long long>() == std::is_integral<unsigned long long>()) ? 0 : res = 0;

	// std::vector<std::string> res;
	// ft::vector<std::string> res2;
	// res.push_back(typeid(std::vector<int>::iterator::iterator_category).name());
	// res.push_back("\n");
	// res.push_back(typeid(std::vector<int>::iterator::value_type).name());
	// res.push_back("\n");
	// res.push_back(typeid(std::vector<int>::iterator::difference_type).name());
	// res.push_back("\n");
	// res.push_back(typeid(std::vector<int>::iterator::iterator_type).name());
	// res.push_back("\n");
	// res.push_back(typeid(std::vector<int>::iterator::pointer).name());
	// res.push_back("\n");

	// res.push_back(typeid(std::vector<int>::iterator::reference).name());
	// res.push_back("\n");

	// res.push_back(typeid(std::vector<int>::reverse_iterator::iterator_category).name());
	// res.push_back("\n");

	// res.push_back(typeid(std::vector<int>::reverse_iterator::value_type).name());
	// res.push_back("\n");

	// res.push_back(typeid(std::vector<int>::reverse_iterator::difference_type).name());
	// res.push_back("\n");

	// res.push_back(typeid(std::vector<int>::reverse_iterator::pointer).name());
	// res.push_back("\n");

	// res.push_back(typeid(std::vector<int>::reverse_iterator::reference).name());
	// res.push_back("\n");
	// res.push_back("\n");
	// res.push_back("\n");



	// res2.push_back(typeid(ft::vector<int>::iterator::iterator_category).name());
	// res2.push_back("\n");

	// res2.push_back(typeid(ft::vector<int>::iterator::value_type).name());
	// res2.push_back("\n");

	// res2.push_back(typeid(ft::vector<int>::iterator::difference_type).name());
	// res2.push_back("\n");

	// res2.push_back(typeid(ft::vector<int>::iterator::iterator_type).name());
	// res2.push_back("\n");

	// res2.push_back(typeid(ft::vector<int>::iterator::pointer).name());
	// res2.push_back("\n");

	// res2.push_back(typeid(ft::vector<int>::iterator::reference).name());
	// res2.push_back("\n");

	// res2.push_back(typeid(ft::vector<int>::reverse_iterator::iterator_category).name());
	// res2.push_back("\n");

	// res2.push_back(typeid(ft::vector<int>::reverse_iterator::value_type).name());
	// res2.push_back("\n");

	// res2.push_back(typeid(ft::vector<int>::reverse_iterator::difference_type).name());
	// res2.push_back("\n");

	// res2.push_back(typeid(ft::vector<int>::reverse_iterator::pointer).name());
	// res2.push_back("\n");

	// res2.push_back(typeid(ft::vector<int>::reverse_iterator::reference).name());
	// res2.push_back("\n");


	// print_std_vector(res);
	// print_ft_vector(res2);
}