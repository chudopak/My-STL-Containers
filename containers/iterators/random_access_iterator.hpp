#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include "utils.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <class Iterator>
	class random_access_iterator : ft::iterator<random_access_iterator_tag, Iterator> {

	public:
		typedef Iterator																			iterator_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::value_type			value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::difference_type	difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::pointer			pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::reference			reference;

		/*
		** Constructors
		*/
		random_access_iterator(void) : _elem(0) { }
		random_access_iterator(pointer elem) : _elem(elem) { }
		random_access_iterator(const random_access_iterator& src) : _elem(src._elem) { }
		virtual ~random_access_iterator(void) { }

		pointer					base(void) const { return (_elem); }

		reference				operator*(void) const { return (*_elem); }
		pointer					operator->(void) { return (&(this->operator*())); }

		random_access_iterator	&operator=(const random_access_iterator &src) {
			if (*this == src)
				return (*this);
			_elem = src._elem;
			return (*this);
		}
		operator random_access_iterator<const value_type>() const { return (random_access_iterator<const value_type>(_elem)); }

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

		reference						operator[](difference_type n) { return (*(_elem + n));}

		bool					operator==(random_access_iterator const &src) const { return (_elem == src._elem); }
		bool					operator!=(random_access_iterator const &src) const { return (_elem != src._elem); }
		bool					operator<=(random_access_iterator const &src) const { return (_elem <= src._elem); }
		bool					operator>=(random_access_iterator const &src) const { return (_elem >= src._elem); }
		bool					operator>(random_access_iterator const &src) const { return (_elem > src._elem); }
		bool					operator<(random_access_iterator const &src) const { return (_elem < src._elem); }
		difference_type operator-(const random_access_iterator& src) const { return (_elem - src._elem); }

	private:
		pointer	_elem;
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
	bool operator!= (const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) {
		return (lhs != rhs);
	}

	template <class Iterator1, class Iterator2>
	bool operator!= (const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) {
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