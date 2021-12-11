#ifndef MAP_HPP
# define MAP_HPP

# include "headers.hpp"

namespace ft {

	template <	class Key,
				class T,
				class Compare = ft::less<Key>,
				class Alloc = std::allocator<ft::pair<const Key, T> > 
			>
	class map {

	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair<const key_type, mapped_type>					value_type;
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

		typedef Alloc																		allocator_type;
		typedef typename allocator_type::reference											reference;
		typedef typename allocator_type::const_reference									const_reference;
		typedef typename allocator_type::pointer											pointer;
		typedef typename allocator_type::const_pointer										const_pointer;

		typedef typename ft::BST<value_type, key_compare, allocator_type>::node_type		node_type;
		typedef typename ft::BST<value_type, key_compare, allocator_type>::iterator			iterator;
		typedef typename ft::BST<value_type, key_compare, allocator_type>::const_iterator	const_iterator;
		typedef ft::reverse_iterator<iterator>												reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;

		typedef typename allocator_type::size_type											size_type;
		typedef typename allocator_type::difference_type									difference_type;

		/**
		 * Constructors
		 */
		explicit map(	const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) :
			_bst(comp),
			_compare(comp),
			_alloc(alloc)
		{ }

		/**
		 * @brief ft::enable_if is used for hide this constructor
		 * if InputIterator has standart type because Int cant be iteratable
		 * 
		 */
		template <class InputIterator>
		map (	InputIterator first,
				InputIterator last,
				const key_compare & comp = key_compare(),
				const allocator_type & alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) :
			_bst(comp),
			_compare(comp),
			_alloc(alloc)
		{
			this->insert(first, last);
		}

		map (const map& x) : 
			_bst(x._bst),
			_compare(x._compare),
			_alloc(x._alloc)
		{ }

		/**
		 * Iterators
		 */

		iterator		begin() {
			return (_bst.getBegin());
		}

		const_iterator	begin() const {
			return (_bst.getBeginConst());
		}

		iterator		end() {
			return (_bst.getEnd());
		}

		const_iterator	end() const {
			return (_bst.getEndConst());
		}

		/**
		 * Capacity
		 */

		size_type		size() const {
			return (_bst.getSize());
		}


		/**
		 * Modifiers
		 */

		pair<iterator,bool>			insert(const value_type& val) {
			pair<iterator,bool>		res = _bst.insert(val);
			return (res);
		}

		iterator					insert(iterator position, const value_type & val) {
			return (_bst.insertPos(position, val));
		}

		template <class InputIterator>
		void						insert(InputIterator first, InputIterator last) {
			for (; first != last; first++) {
				_bst.insert(*first);
			}
		}

		void						clear() {
			_bst.clear();
		}

		void						swap(map& x) {
			_bst.swap(x._bst);
			ft::swap(this->_compare, x._compare);
			ft::swap(this->_alloc, x._alloc);
		}


	private:
		ft::BST<value_type, key_compare, allocator_type>	_bst;
		key_compare											_compare;
		allocator_type										_alloc;
	};
}

#endif