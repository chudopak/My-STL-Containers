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

	template <class Iterator>
	class iterator_traits
	{
	public:
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
	public:
		typedef T										value_type;
		typedef ptrdiff_t								difference_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
	public:
		typedef T										value_type;
		typedef ptrdiff_t								difference_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

}

#endif
