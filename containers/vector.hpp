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
		typedef ft::reverse_iterator<const iterator>					const_reverce_iterator;

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

		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last,
		// 	const allocator_type& alloc = allocator_type()) {

		// }

		~vector(void) {
			clear();
			_alloc.deallocate(_start, capacity());
		}

		size_type	size(void) const {
			return (_end - _start);
		}

		size_type	capacity (void) const {
			return (this->_capacity - this->_start);
		}

		void	clear() {
			size_type save_size = this->size();
			for (size_type i = 0; i < save_size; i++) {
				_end--;
				_alloc.destroy(_end);
			}
		}
	
	private:
			pointer         _start;
			pointer         _end;
			pointer         _capacity;
			allocator_type  _alloc;
	};
}

#endif