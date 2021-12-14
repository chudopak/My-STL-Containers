#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <iostream>
# include <memory>


class my_nullptr_t {
public:
	template<typename T>
	operator T*() const { return (0); }

	template<typename C, typename T>
	operator T C::*() const { return (0); }

private:
	void	operator&() const;
};

namespace ft
{

	template <typename T>
	std::string to_string(T n)
	{
		std::ostringstream ss;
		ss << n;
		return (ss.str());
	}

	template <bool is_valid, typename T>
	struct valid_iterator_tag_res {
		typedef T type;
		const static bool value = is_valid;
	};

	/*
	** Iterators tags https://www.cplusplus.com/reference/iterator/iterator/
	*/

	class random_access_iterator_tag { };
	class bidirectional_iterator_tag { };
	class forward_iterator_tag {};
	class output_iterator_tag {};
	class input_iterator_tag {};

	/*
	**	Used for checking for some conditions and if it's true
	**	only then choose that method.
	*/
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

	/*
	**	Checking if the value has integral type
	*/

	template <bool is_integral, typename T>
	struct is_integral_res {
		typedef T type;
		static const bool value = is_integral;
	};

	template <typename>
	struct is_integral_type : public is_integral_res<false, bool> {};

	template <>
	struct is_integral_type<bool> : public is_integral_res<true, bool> {};

	template <>
	struct is_integral_type<char> : public is_integral_res<true, char> {};

	template <>
	struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

	template <>
	struct is_integral_type<short int> : public is_integral_res<true, short int> {};
		
	template <>
	struct is_integral_type<int> : public is_integral_res<true, int> {};

	template <>
	struct is_integral_type<long int> : public is_integral_res<true, long int> {};

	template <>
	struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

	template <>
	struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

	template <>
	struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

	template <>
	struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

	template <>
	struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
		
	template <>
	struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

	/*
	**	This structure will be used for checking types
	*/

	template <typename T>
	struct is_integral : public is_integral_type<T> { };

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



	/**
	 * @brief Generically, function objects are instances of a class with member function operator() defined.
	 * This member function allows the object to be used with the same syntax as a regular function call,
	 * and therefore its type can be used as template parameter when a generic function type is expected.
	 * 
	 * binary_function is just a base class, from which specific binary function objects are derived.
	 * It has no operator() member defined (which derived classes are expected to define) - 
	 * it simply has three public data members that are typedefs of the template parameters.
	 * 
	 * @tparam Arg1 
	 * @tparam Arg2 
	 * @tparam Result 
	 */
	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	/**
	 * @brief Generically, function objects are instances of a class with member function operator() defined.
	 * This member function allows the object to be used with the same syntax as a function call.
	 * 
	 * @tparam T 
	 */

	template <class T> struct less : binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const { return x < y; }
	};

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

	/*
	** equal
	*/
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	/* Lexicographical comparison */

	template <class InputIterator, class InputIterator2>
	bool lexicographical_compare(InputIterator first1, InputIterator last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator first1, InputIterator last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template<typename T>
	void swap(T &a, T &b)
	{
		T c(a);
		a = b;
		b = c;
	}

	/*
	** Function to find difference btw the element of container
	*/

	template<typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
			distance(InputIterator first, InputIterator last) {

		typename ft::iterator_traits<InputIterator>::difference_type	dst = 0;

		while (first != last) {
			first++;
			dst++;
		}
		return (dst);
	}

	/**
	 * @brief Pair. This class couples together a pair of values, which may be of different types (T1 and T2).
	 * The individual values can be accessed through its public members first and second.
	 * 
	 */

	template <class T1, class T2>
	struct pair {

	public:
		typedef T1	first_type;
		typedef T2	second_type;
		first_type	first;
		second_type	second;

		pair() :
			first(),
			second()
		{ }

		template <class U, class V>
		pair(const pair<U,V>& pr) :
			first(pr.first),
			second(pr.second)
		{ }

		pair(const first_type& a, const second_type& b) :
			first(a),
			second(b)
		{ }

		pair& operator=(const pair& pr) {
			if (*this == pr)
				return (*this);
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(rhs<lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (rhs<lhs);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs<rhs);
	}

	template <class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 x, T2 y) {
		return (ft::pair<T1, T2>(x, y));
	}
}

#endif
