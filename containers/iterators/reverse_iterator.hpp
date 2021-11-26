#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "utils.hpp"
# include "random_access_iterator.hpp"


namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		reverse_iterator() : _elem() {}

		explicit reverse_iterator(iterator_type elem) : _elem(elem) {}

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) : _elem(rev_it.base()) {}
		/* template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) {
			_elem = rev_it.base();
		} */

		virtual ~reverse_iterator() {}

		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& src ) {
			if (*this == src)
				return (*this);
			_elem = src.base();
			return *this;
		}

		iterator_type base() const { return (_elem); }

		reference operator*() const {
			iterator_type tmp = _elem;
			return (*--tmp);
		}

		pointer operator->() const { return &(operator*()); }

		reference operator[] (const difference_type n) const { return *(_elem - n - 1); }

		reverse_iterator operator+ (difference_type n) const { return (reverse_iterator(_elem - n)); }

		reverse_iterator& operator++() {
			--_elem;
			return (*this);
		}

		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}

		reverse_iterator& operator+= (const difference_type n) {
			_elem -= n;
			return (*this);
		}

		reverse_iterator operator- (difference_type n) const { return (reverse_iterator(_elem + n)); }

		reverse_iterator& operator--() {
			++_elem;
			return (*this);
		}

		reverse_iterator operator--(int) {
			reverse_iterator temp = *this;
			--(*this);
			return (temp);
		}

		reverse_iterator& operator-= (const difference_type n) {
			_elem += n;
			return (*this);
		}

		bool operator==(const reverse_iterator& src) const { return (_elem == src._elem); }
		bool operator!=(const reverse_iterator& src) const { return (_elem != src._elem); }
		bool operator<(const reverse_iterator& src) const { return (_elem > src._elem); }
		bool operator<=(const reverse_iterator& src) const { return (_elem >= src._elem); }
		bool operator>(const reverse_iterator& src) const { return (_elem < src._elem); }
		bool operator>=(const reverse_iterator& src) const { return (_elem <= src._elem); }

	private:
		iterator_type	_elem;
	};

	template <class Iterator>
	bool operator==(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
		return (lhs.base() == rhs.base());
	}
	template <class Iterator1, class Iterator2>
	bool operator==(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
		return (lhs != rhs);
	}
	template <class Iterator1, class Iterator2>
	bool operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
		return (rhs.base() < lhs.base());
	}
	template <class Iterator1, class Iterator2>
	bool operator<(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return (rhs.base() < lhs.base());
	}

	template <class Iterator>
	bool operator<=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
		return (rhs.base() <= lhs.base());
	}
	template <class Iterator1, class Iterator2>
	bool operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return (rhs.base() <= lhs.base());
	}

	template <class Iterator>
	bool operator>(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
		return (rhs.base() > lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return (rhs.base() > lhs.base());
	}

	template <class Iterator>
	bool operator>=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
		return (rhs.base() >= lhs.base());
	}
	template <class Iterator1, class Iterator2>
	bool operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {
		return (rhs.base() >= lhs.base());
	}

	template <class Iterator>
	ft::reverse_iterator<Iterator> operator+(const typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it) {
		return (rev_it + n);
	}

	template <class Iterator>
	ft::reverse_iterator<Iterator> operator-(const typename ft::reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& lhs) {
		return (lhs - n);
	}
	template <class Iterator1, class Iterator2>
	typename ft::reverse_iterator<Iterator1>::difference_type operator-(const ft::reverse_iterator<Iterator1> lhs, const reverse_iterator<Iterator2> rhs) {
		return (rhs.base() - lhs.base());
	}
}

#endif