#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "headers.hpp"

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector {

	public:
		typedef T														value_type;
		typedef Allocator												allocator_type;

		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;

		typedef ft::random_access_iterator<value_type>					iterator;
		typedef ft::random_access_iterator<const value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef typename allocator_type::size_type						size_type;

		explicit	vector (const allocator_type& alloc = allocator_type()) :
			_start(NULL),
			_end(NULL),
			_capacity(NULL),
			_alloc(alloc)
		{ }

		explicit	vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_start(NULL),
			_end(NULL),
			_capacity(NULL),
			_alloc(alloc)
		{
			_start = _alloc.allocate(n);
			_capacity = _start + n;
			_end = _start;
			for (size_type i = 0; i < n; i++) {
				_alloc.construct(_end, val);
				_end++;
			}
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) :
			_alloc(alloc) 
		{
			difference_type n = ft::distance(first, last);
			_start = _alloc.allocate( n );
			_capacity = _start + n;
			_end = _start;
			for (int i = 0; i < n; i++) {
				_alloc.construct(_end, *first++);
				_end++;
			}
		}

		vector (const vector& x) :
			_start(NULL),
			_end(NULL),
			_capacity(NULL),
			_alloc(x._alloc)
		{
			*this = x;
		}

		~vector(void) {
			if (_start) {
				clear();
				_alloc.deallocate(_start, capacity());
			}
		}

		vector	&operator=(const vector& vec) {

			if (vec == *this)
				return (*this);
			this->clear();
			this->insert(this->begin(), vec.begin(), vec.end());
			return (*this);
		}
		/*
		**	Capacity
		*/
		size_type	size(void) const {
			return (_end - _start);
		}

		size_type	capacity (void) const {
			return (this->_capacity - this->_start);
		}

		size_type	max_size(void) const {
			return (allocator_type().max_size());
		}

		void		resize(size_type n, value_type val = value_type()) {
			if (n > this->max_size())
				throw (std::length_error("vector::resize"));
			else if (n >= this->size()){
				this->insert(this->end(), n - this->size(), val);
			}
			else {
				while (this->size() > n) {
					_alloc.destroy(_end);
					--_end;
				}
			}
		}

		bool		empty() const {
			return (_start == _end);
		}

		void		reserve(size_type n) {

			if (n <= this->capacity())
				return ;
			else if (n > this->max_size())
				throw (std::length_error("vector::reserve"));

			pointer		newStart = pointer();
			pointer		newEnd = pointer();
			pointer		newCapacity = pointer();

			newStart = _alloc.allocate(n);
			newEnd = newStart;
			newCapacity = newStart + n;

			for (size_type i = 0; _start + i < _end; i++) {
				_alloc.construct(newEnd, *(_start + i));
				newEnd++;
			}
			_alloc.deallocate(_start, this->capacity());
			_start = newStart;
			_end = newEnd;
			_capacity = newCapacity;
		}

		/*
		**	Iterators
		*/

		iterator				begin() { return (_start); }

		const_iterator			begin() const { return (_start); }

		iterator				end() { return (_end); }

		const_iterator			end() const { return (_end); }

		reverse_iterator		rbegin() { return (reverse_iterator(this->_end)); }

		const_reverse_iterator	rbegin() const { return(const_reverse_iterator(this->_end)); }

		reverse_iterator		rend() { return (reverse_iterator(this->_start)); }

		const_reverse_iterator	rend() const { return (const_reverse_iterator(this->_start)); }

		/*
		**	Element access
		*/

		reference		operator[](size_type n) { return(*(_start + n)); }

		const_reference	operator[](size_type n) const { return(*(_start + n)); }

		reference		at(size_type n) {
			_checkRange(n);
			return ((*this)[n]);
		}

		const_reference	at(size_type n) const {
			_checkRange(n);
			return ((*this)[n]);
		}

		reference		front() { return (*_start); }

		const_reference	front() const { return (*_start); }

		reference		back() { return (*(_end - 1)); }

		const_reference back() const { return (*(_end - 1)); }

		/*
		**	Modifiers
		*/

		void			assign(size_type n, const value_type& val) {
			resize(n);
			for (size_type i = 0; i < n; i++) {
				_start[i] = val;
			}
		}

		template <class InputIterator>
		void			assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

			resize(static_cast<size_type>(ft::distance(first, last)));
			for (size_type i = 0; first != last; first++, i++) {
				_start[i] = *first;
			}
		}

		void			push_back(const value_type& val) {
			if (_end == _capacity)
				reserve(static_cast<size_type>(this->size() + 1 + (this->size() + 1) / 3));
			_alloc.construct(_end, val);
			_end++;
		}

		void			pop_back(void) {
			if (size() > 0) {
				_alloc.destroy(_end);
				_end--;
			}
		}

		iterator		erase(iterator position) {

			size_type	size = this->size();
			for (size_type i = &(*position) - _start; i < size - 1; i++) {
				_start[i] = _start[i + 1];
			}
			_alloc.destroy(_end - 1);
			--_end;
			return (position);
		}

		iterator erase (iterator first, iterator last) {

			pointer first_pointer = &(*first);
			for (; first_pointer != &(*last); first_pointer++)
				_alloc.destroy(first_pointer);
			first_pointer = &(*first);
			for (int i = 0; i < _end - &(*last); i++) {
				_alloc.construct(first_pointer + i, *(&(*last) + i));
				_alloc.destroy(&(*last) + i);
			}
			_end -= (&(*last) - first_pointer);
			return (first);
		}

		iterator		insert(iterator position, const value_type& val) {

			size_type cell_index = &(*position) - _start;

			if (size() < capacity()) {
				for (pointer it = _end; it >= &(*position); it--)
					_alloc.construct(it + 1, *it);
				_end++;
				_alloc.construct(&(*position), val);
			}
			else {
				pointer		newStart = pointer();
				pointer		newEnd = pointer();
				pointer		newCapacity = pointer();
				size_type	newSize;
				int			constructedElements = 0;
				if (this->size() > 100000)
					newSize =  this->size() + 1 + static_cast<size_type>((this->size() / 100));
				else
					newSize = this->size() + 1 + static_cast<size_type>((this->size() + 1) / 3);

				newStart = _alloc.allocate(newSize);
				newEnd = newStart + this->size() + 1;
				newCapacity = newStart + newSize;

				try {
					for (int i = 0; i < &(*position) - _start; i++, constructedElements++)
						_alloc.construct(newStart + i, *(_start + i));
					_alloc.construct(newStart + cell_index, val);
					constructedElements++;
					for (size_type i = 0; i < this->size() - (&(*position) - _start); i++, constructedElements++)
						_alloc.construct(newStart + (&(*position) - _start) + 1 + i, *(&(*position) + i));
				} catch (...) {
					iterator it = newStart;
					for (int i = 0; i < constructedElements; i++, it++) {
						it->~value_type();
					}
					_alloc.deallocate(newStart, newCapacity - newStart);
					throw ;
				}
				if (_start != NULL)
					_alloc.deallocate(_start, this->capacity());
				_start = newStart;
				_end = newEnd;
				_capacity = newCapacity;
			}
			return (iterator(_start + cell_index));
		}

		void			insert(iterator position, size_type n, const value_type& val) {

			if (n > this->max_size())
				throw(std::length_error("vector: insert n > max_size"));
			if (n == 0)
				return ;

			size_type cell_index = &(*position) - _start;

			if (static_cast<size_type>(_capacity - _end) >= n) {
				for (pointer it = _end; it >= &(*position); it--)
					_alloc.construct(it + 1, *it);
				_end += n;
				while (n) {
					_alloc.construct(&(*position) + (n - 1), val);
					n--;
				}
			}
			else {
				pointer		newStart = pointer();
				pointer		newEnd = pointer();
				pointer		newCapacity = pointer();
				size_type	newSize;
				int			constructedElements = 0;

				if (this->size() > 100000)
					newSize = this->size() + n + static_cast<size_type>((this->size() / 100));
				else
					newSize = this->size() + n + static_cast<size_type>((this->size() + n) / 3);

				newStart = _alloc.allocate(newSize);
				newEnd = newStart + this->size() + n;
				newCapacity = newStart + newSize;

				try {
					for (int i = 0; i < &(*position) - _start; i++, constructedElements++)
						_alloc.construct(newStart + i, *(_start + i));
					for (size_type i = 0; i < n; i++, constructedElements++)
						_alloc.construct(newStart + cell_index + i, val);
					for (size_type i = 0; i < this->size() - cell_index; i++, constructedElements++)
						_alloc.construct(newStart + cell_index + n + i, *(&(*position) + i));
				} catch (...) {
					iterator it = newStart;
					for (int i = 0; i < constructedElements; i++, it++) {
						it->~value_type();
					}
					_alloc.deallocate(newStart, newCapacity - newStart);
					throw ;
				}
				if (_start != NULL)
					_alloc.deallocate(_start, this->capacity());
				_start = newStart;
				_end = newEnd;
				_capacity = newCapacity;
			}
		}

		template<class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

			size_type	dist = static_cast<size_type>(ft::distance(first, last));
			if (dist + size() < capacity()) {
				for (pointer it = _end; it >= &(*position) ; it--) {
					_alloc.construct(it + dist, *it);
				}
				_end += dist;
				for (; first != last; position++, first++)
					_alloc.construct(&(*position), *first);
			}
			else {
				pointer		newStart = pointer();
				pointer		newEnd = pointer();
				pointer		newCapacity = pointer();
				size_type	newSize;
				int			constructedElements = 0;
				if (this->size() > 100000)
					newSize = this->size() + dist + static_cast<size_type>((this->size() / 100));
				else
					newSize = this->size() + dist + static_cast<size_type>((this->size() + dist) / 3);

				newStart = _alloc.allocate(newSize);
				newEnd = newStart + this->size() + dist;
				newCapacity = newStart + newSize;

				try {
					for (int i = 0; i < &(*position) - _start; i++, constructedElements++) {
						_alloc.construct(newStart + i, *(_start + i));
					}
					for (int i = 0; &(*first) != &(*last); first++, i++, constructedElements++) {
						_alloc.construct(newStart + (&(*position) - _start) + i, *first);
					}
					for (size_type i = 0; i < this->size() - (&(*position) - _start); i++, constructedElements++) {
						_alloc.construct(newStart + (&(*position) - _start) + dist + i, *(&(*position) + i));
					}
				} catch (...) {
					iterator it = newStart;
					for (int i = 0; i < constructedElements; i++, it++) {
						it->~value_type();
					}
					_alloc.deallocate(newStart, newCapacity - newStart);
					throw ;
				}
				for (size_type i = 0; i < this->size(); i++)
					_alloc.destroy(_start + i);
				if (_start != NULL)
					_alloc.deallocate(_start, this->capacity());
				_start = newStart;
				_end = newEnd;
				_capacity = newCapacity;
			}
		}

		void	swap(vector& x) {

			if (x == *this)
				return ;

			pointer	tmp;
			tmp = _start;
			_start = x._start;
			x._start = tmp;

			tmp = _end;
			_end = x._end;
			x._end = tmp;

			tmp = _capacity;
			_capacity = x._capacity;
			x._capacity = tmp;

			allocator_type	tmpAlloc;
			tmpAlloc = _alloc;
			_alloc = x._alloc;
			x._alloc = tmpAlloc;
		}

		void	clear() {

			size_type save_size = this->size();
			for (size_type i = 0; i < save_size; i++) {
				_end--;
				_alloc.destroy(_end);
			}
		}

	private:
		pointer			_start;
		pointer			_end;
		pointer			_capacity;
		allocator_type	_alloc;

		void			_checkRange(const size_type& n) const {
			if (n >= this->size())
				throw(std::out_of_range("vector: Passed number bigger or equal than size: "
							+ ft::to_string(n) + " >= "
							+ ft::to_string(this->size())));
		}
	};

	template <class T, class Alloc>
	bool operator== (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {

		typename ft::vector<T>::const_iterator vec1 = lhs.begin();
		typename ft::vector<T>::const_iterator vec2 = rhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (vec1 != lhs.end()) {
			if (*vec1 != *vec2 || vec2 == rhs.end())
				return (false);
			vec1++;
			vec2++;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(lhs < rhs));
	}
	
	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>&y) {
		x.swap(y);
	}
}

#endif