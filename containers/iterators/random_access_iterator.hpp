#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include "utils.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T> {

	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

		/*
		** Constructors
		*/
		random_access_iterator(void) : _elem(0) { }
		random_access_iterator(T* elem) : _elem(elem) { }
		random_access_iterator(random_access_iterator const &src) { *this = src; }


		random_access_iterator &operator=(random_access_iterator const &src) {
			if (this == &src)
				return (*this);
			_elem = src._elem;
			return (*this);
		}

		// T* getElem() const {
		// 	return (_elem);
		// }

	private:
		T*	_elem;
	};

}

#endif