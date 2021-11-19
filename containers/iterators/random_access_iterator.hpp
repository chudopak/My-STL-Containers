#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include "utils.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {

	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;

		/*
		** Constructors
		*/
		random_access_iterator(void) : _elem(my_nullptr) { }
		random_access_iterator(T* elem) : _elem(elem) { }
		random_access_iterator(random_access_iterator const &src) { *this = src; }
		virtual ~random_access_iterator(void) { }

		T*						base(void) const { return (_elem); }
		random_access_iterator &operator=(random_access_iterator const &src) {
			if (this == &src)
				return (*this);
			_elem = src._elem;
			return (*this);
		}

		T&						operator*(void) const { return (*_elem); }
		T*						operator->(void) { return (_elem); }
		random_access_iterator&	operator++(void) {
			_elem++;
			return (*this);
		}
		random_access_iterator	operator++(int) {
			random_access_iterator	temp(*this);
			++(*this);
			return (temp);
		}

		random_access_iterator& operator--(void)
		{
			_elem--;
			return (*this);
		}
		random_access_iterator operator--(int)
		{
			random_access_iterator temp(*this);
			--(*this);
			return (temp);
		}

		random_access_iterator operator+(difference_type n) const { return random_access_iterator(_elem + n); }
		random_access_iterator operator-(difference_type n) const { return random_access_iterator(_elem - n); }

		random_access_iterator& operator+=(difference_type n) {
			_elem += n;
			return (*this);
		}
		random_access_iterator& operator-=(difference_type n) {
			_elem -= n;
			return (*this);
		}

		T&						operator[](difference_type n) { return (*(_elem + n));}

		bool					operator==(random_access_iterator const &src) { return  (_elem == src._elem); }
		bool					operator!=(random_access_iterator const &src) { return  (_elem != src._elem); }
		bool					operator<=(random_access_iterator const &src) { return  (_elem <= src._elem); }
		bool					operator>=(random_access_iterator const &src) { return  (_elem >= src._elem); }
		bool					operator>(random_access_iterator const &src) { return  (_elem > src._elem); }
		bool					operator<(random_access_iterator const &src) { return  (_elem < src._elem); }

	private:
		T*	_elem;
	};

	template <class Iterator>
	bool operator<(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) {
		return (lhs < rhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator<(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) {
		return (lhs.base() < rhs.base());
	}
	
	template <class Iterator>
	bool operator>(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) {
		return (lhs > rhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator>(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) {
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator>=(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) {
		return (lhs >= rhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator>=(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator<=(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) {
		return (lhs <= rhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator<=(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	bool operator==(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) {
		return (lhs == rhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator==(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!=(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) {
		return (lhs != rhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator!=(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	typename ft::random_access_iterator<Iterator>::difference_type operator-(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) {
		return (lhs - rhs);
	}
	template <class Iterator1, class Iterator2>
	typename ft::random_access_iterator<Iterator1>::difference_type operator-(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) {
		return (lhs.base() - rhs.base());
	}
	template <typename Iterator>
	ft::random_access_iterator<Iterator> operator-(typename random_access_iterator<Iterator>::difference_type n, const ft::random_access_iterator<Iterator>& lhs) {
		return (lhs - n);
	}

	template <class Iterator>
	typename ft::random_access_iterator<Iterator>::difference_type operator+(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) {
		return (lhs + rhs);
	}
	template <class Iterator1, class Iterator2>
	typename ft::random_access_iterator<Iterator1>::difference_type operator+(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) {
		return (lhs.base() + rhs.base());
	}
	template <typename Iterator>
	ft::random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, const ft::random_access_iterator<Iterator>& lhs) {
		return (lhs + n);
	}
}

#endif