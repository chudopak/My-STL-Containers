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

		virtual ~map() { }

		/**
		 * Iterators
		 */

		iterator				begin() {
			return (_bst.getBegin());
		}

		const_iterator			begin() const {
			return (_bst.getBeginConst());
		}

		iterator				end() {
			return (_bst.getEnd());
		}

		const_iterator			end() const {
			return (_bst.getEndConst());
		}

		reverse_iterator		rbegin() {
			return (reverse_iterator(end()));
		}

		const_reverse_iterator		rbegin() const {
			return (const_reverse_iterator(end()));
		}

		reverse_iterator		rend() {
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator	rend() const {
			return (const_reverse_iterator(begin()));
		}

		/**
		 * Capacity
		 */

		size_type		size() const {
			return (_bst.getSize());
		}

		size_type		max_size() const {
			return (_alloc.max_size());
		}

		bool empty() const {
			return (_bst.getSize() == 0);
		}

		/**
		 * Modifiers
		 */

		mapped_type& operator[] (const key_type& k)
		{
			iterator it = find(k);
			if (it == end())
				it = insert(ft::make_pair(k, mapped_type())).first;
			return (it->second);
		}

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

		size_type					erase(const key_type & k) {
			return (_bst.erase(k));
		}

		void						erase(iterator position) {
			_bst.eraseIt(position);
		}

		void						erase(iterator first, iterator last) {

			iterator	tmp;

			while (first != last) {
				tmp = first;
				first++;
				_bst.eraseIt(tmp);
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

		/**
		 * Observers
		 * 
		 */
		key_compare					key_comp() const {
			return (_compare);
		}

		value_compare				value_comp() const {
			return (value_compare(_compare));
		}

		/**
		 * Operations
		 * 
		 */

		iterator			find(const key_type & k) {
			return (_bst.find(k));
		}

		const_iterator		find(const key_type & k) const {
			return (_bst.find(k));
		}

		size_type			count(const key_type & k) const {
			return (_bst.count(k));
		}

		iterator			lower_bound (const key_type& k) {
			return (iterator(_bst.lower_bound(k)));
		}

		const_iterator		lower_bound (const key_type& k) const {
			return (const_iterator(_bst.lower_bound(k)));
		}

		iterator			upper_bound (const key_type& k) {
			return (iterator(_bst.upper_bound(k)));
		}

		const_iterator		upper_bound (const key_type& k) const {
			return (const_iterator(_bst.upper_bound(k)));
		}

		pair<iterator, iterator>				equal_range (const key_type& k) {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		pair<const_iterator, const_iterator>	equal_range (const key_type& k) const {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		allocator_type get_allocator() const {
			return (_alloc);
		}

	private:
		ft::BST<value_type, key_compare, allocator_type>	_bst;
		key_compare											_compare;
		allocator_type										_alloc;
	};

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator==(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {

		typename map<Key, T, Compare, Allocator>::const_iterator	it = lhs.begin();
		typename map<Key, T, Compare, Allocator>::const_iterator	ite = lhs.end();
		typename map<Key, T, Compare, Allocator>::const_iterator	it2 = rhs.begin();

		while (it != ite && it2 != rhs.end())
		{
			if (it->first != it2->first || it->second != it2->second)
				return (false);
			it++;
			it2++;
		}
		return (it == ite && it2 == rhs.end());
	}
	
	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator!=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		return (!(lhs == rhs));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator<(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		typename map<Key, T, Compare, Allocator>::const_iterator	it = lhs.begin();
		typename map<Key, T, Compare, Allocator>::const_iterator	ite = lhs.end();
		typename map<Key, T, Compare, Allocator>::const_iterator	it2 = rhs.begin();

		while (it != ite && it2 != rhs.end())
		{
			if (it->first != it2->first)
				return (it->first < it2->first);
			else if (it->second != it2->second)
				return (it->second < it2->second);
			it++;
			it2++;
		}
		return (it == ite && it2 != rhs.end());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator>(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		return (rhs < lhs);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator<=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		return (!(rhs < lhs));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator>=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		return (!(lhs < rhs));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	void swap(map<Key, T, Compare, Allocator> &lhs, map<Key, T, Compare, Allocator> &rhs) {
		lhs.swap(rhs);
	}
}

#endif