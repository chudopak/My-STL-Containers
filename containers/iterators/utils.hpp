#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <iostream>


class my_nullptr_t {
public:
	template<typename T>
	operator T*() const { return (0); }

	template<typename C, typename T>
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

	template <bool is_valid, typename T>
	struct valid_iterator_tag_res {
		typedef T type;
		const static bool value = is_valid;
	};

	class random_access_iterator_tag { };
	class bidirectional_iterator_tag { };
	class forward_iterator_tag {};
	class output_iterator_tag {};
	class input_iterator_tag {};


	/*
	**	Cheking if the parametr is input operator.
	**	If it's not then it set validation parametr to false.
	*/

	template <typename T>
	struct is_input_iterator_tagged : public valid_iterator_tag_res<false, T> { };
	
	template <>
	struct is_input_iterator_tagged<ft::random_access_iterator_tag>
		: public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

	template <>
	struct is_input_iterator_tagged<ft::bidirectional_iterator_tag>
		: public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

	template <>
	struct is_input_iterator_tagged<ft::forward_iterator_tag>
		: public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

	template <>
	struct is_input_iterator_tagged<ft::input_iterator_tag>
		: public valid_iterator_tag_res<true, ft::input_iterator_tag> { };

	/*
	**
	*/

	template <typename T>
	struct is_ft_iterator_tagged : public valid_iterator_tag_res<false, T> { };
		
	template <>
	struct is_ft_iterator_tagged<ft::random_access_iterator_tag>
		: public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

	template <>
	struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag>
		: public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

	template <>
	struct is_ft_iterator_tagged<ft::forward_iterator_tag>
		: public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

	template <>
	struct is_ft_iterator_tagged<ft::input_iterator_tag>
		: public valid_iterator_tag_res<true, ft::input_iterator_tag> { };

	template <>
	struct is_ft_iterator_tagged<ft::output_iterator_tag>
		: public valid_iterator_tag_res<true, ft::output_iterator_tag> { };


	/*
	**	EXCEPTION called when iteratror doesn't match with demanded.
	*/
	template <typename T>
	class InvalidIteratorException : public std::exception
	{
		private:
			std::string _msg;
		
		public :
			InvalidIteratorException () { _msg = "Is invalid iterator tag : " + std::string(typeid(T).name()); }
			InvalidIteratorException (const InvalidIteratorException&) {}
			InvalidIteratorException& operator= (const InvalidIteratorException&) {}
			virtual ~InvalidIteratorException() {}
			virtual const char* what() const throw() { return (_msg.c_str()); }
	};




	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
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

	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last) {
		
		typename ft::iterator_traits<InputIterator>::difference_type itr = 0;
		while (first != last) {
			first++;
			itr++;
		}
		return (itr);
	}
}

#endif
