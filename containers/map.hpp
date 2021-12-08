#ifndef MAP_HPP
# define MAP_HPP

# include "headers.hpp"

namespace ft {

	template <	class Key,
				class T,
				class Compare = ft::less<Key>,
				class Alloc = std::allocator<pair<const Key, T> > 
			>
	class map {

	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef Compare											key_compare;

		class value_compare : ft::binary_function<value_type, value_type, bool>
		{
			friend class map<key_type, mapped_type, key_compare, Alloc>;
		protected:
			Compare comp;
			value_compare (Compare c)
				: comp(c)
			{ }
		public:
			bool operator()(const value_type& x, const value_type& y) const {
				return (comp(x.first, y.first));
			}
		};

		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;

		/*
		** Place for iterators
		*/

		typedef typename allocator_type::size_type				size_type;
		typedef typename allocator_type::difference_type		difference_type;


	};
}

#endif