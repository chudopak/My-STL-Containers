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
			_start(my_nullptr),
			_end(my_nullptr),
			_capacity(my_nullptr),
			_alloc(alloc)
		{ }

		explicit	vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_start(my_nullptr),
			_end(my_nullptr),
			_capacity(my_nullptr),
			_alloc(alloc)
		{
			//https://www.cplusplus.com/reference/memory/allocator/allocate/
			_start = _alloc.allocate(n);
			_capacity = _start + n;
			_end = _start;
			for (size_type i = 0; i < n; i++) {
				//https://www.cplusplus.com/reference/memory/allocator/construct/
				_alloc.construct(_end, val);
				_end++;
			}
		}

		/*
		**	typename in arguments needet to pass iterators.
		*/
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = my_nullptr) :
			_alloc(alloc) 
		{
			// Checking is iterator match with those five iteratros tags in utils
			// if (!ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value)
			// 	throw (ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());
			difference_type n = ft::distance(first, last);
			_start = _alloc.allocate( n );
			_capacity = _start + n;
			_end = _start;
			for (size_type i = 0; i < n; i++) {
				_alloc.construct(_end, *first++);
				_end++;
			}
		}

		vector (const vector& x) :
			_alloc(x._alloc),
			_start(my_nullptr),
			_end(my_nullptr),
			_capacity(my_nullptr)
		{
			this->insert(this->begin(), x.begin(), x.end());
		}

		~vector(void) {
			clear();
			_alloc.deallocate(_start, capacity());
		}

		/*
		**	Capacity
		**	Need to realisation:
		**	- resize
		**	- reserve
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

		// void		resize(size_type n, value_type val = value_type()) {

		// }

		bool		empty() const {
			return (_start == _end);
		}

		/*
		**	Iterators
		*/

		iterator				begin() { return (_start); }

		const_iterator			begin() const { return (_start); }

		iterator				end() { return (_end); }

		const_iterator			end() const { return (_end); }

		reverse_iterator		rbegin() { return (reverse_iterator(this->_end)); }

		const_reverse_iterator	rbegin() const { return(reverse_iterator(this->_end)); }

		reverse_iterator		rend() { return (reverse_iterator(this->_start)); }

		const_reverse_iterator	rend() const { return (reverse_iterator(this->_start)); }

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


		template<class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = my_nullptr) {

			// if (!ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value)
			// 	throw (ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());

			size_type	dist = static_cast<size_type>(ft::distance(first, last));
			if (dist + size() <= capacity()) {
				for (pointer it = _end; it >= &(*position) ; it--)
					_alloc.construct(it + dist, *it);
				_end += dist;
				for (; first != last; position++, first++)
					_alloc.construct(&(*position), *first);
			}
			else {
				pointer		newStart = pointer();
				pointer		newEnd = pointer();
				pointer		newCapacity = pointer();
				size_type	newSize = this->size() + dist + static_cast<size_type>((this->size() + dist) / 3);

				newStart = _alloc.allocate(newSize);
				newEnd = newStart + this->size() + dist;
				newCapacity = newStart + newSize;

				for (int i = 0; i < &(*position) - _start; i++)
					_alloc.construct(newStart + i, *(_start + i));
				for (int i = 0; &(*first) != &(*last); first++, i++)
					_alloc.construct(newStart + (&(*position) - _start) + i, *first);
				for (size_type i = 0; i < this->size() - (&(*position) - _start); i++)
					_alloc.construct(newStart + (&(*position) - _start) + dist + i, *(_start + (&(*position) - _start) + i));
				for (size_type i = 0; i < this->size(); i++)
					_alloc.destroy(_start + i);
				
				_alloc.deallocate(_start, this->capacity());
				_start = newStart;
				_end = newEnd;
				_capacity = newCapacity;
			}
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

		void			_checkRange(const size_type& n) const throw(std::out_of_range()) {
			if (n >= this->size())
				throw(std::out_of_range("vector: Passed number bigger or equal than size: "
							+ ft::to_string(n) + " >= "
							+ ft::to_string(this->size())));
		}
	};
}

#endif