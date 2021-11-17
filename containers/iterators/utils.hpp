#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <iostream>


class my_nullptr_t {
public:
	template<class T>
	operator T*() const { return (0); }

	template<class C, class T>
	operator T C::*() const { return (0); }

private:
	void	operator&() const;
};

my_nullptr_t	my_nullptr;

namespace ft
{
	/*
	** Iterators tags https://www.cplusplus.com/reference/iterator/iterator/
	*/
	class random_access_iterator_tag { };
	class bidirectional_iterator_tag { };
	class forward_iterator_tag {};
	class output_iterator_tag {};
	class input_iterator_tag {};


	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator {
	public:
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};
}

#endif
