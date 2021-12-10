#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include "utils.hpp"
# include "binary_search_tree_node.hpp"
# include "binary_search_tree_iterator.hpp"

namespace ft {

	/**
	 * @brief Binary search tree class that contains method to interact with it
	 * 
	 * @tparam T 
	 * @tparam Compare 
	 * @tparam Node 
	 * @tparam Alloc 
	 * @tparam Node_alloc 
	 */

	template <	class T,
				class Compare = ft::less<typename T::first_type>,
				class Alloc = std::allocator<T>,
				class Node = ft::BST_node<T>,
				class Node_alloc = std::allocator<Node> 
				>
	class BST {

	public:
		typedef Compare										key_compare;
		typedef T											value_type;
		typedef typename T::first_type						key_type;
		typedef typename T::second_type						mapped_type;

		typedef Node										node_type;
		typedef node_type *									node_pointer;
		typedef const node_type *							node_const_pointer;
		typedef node_type &									node_reference;
		typedef const node_type &							node_const_reference;

		typedef Alloc										type_allocator;
		typedef Node_alloc									node_allocator;
		typedef typename type_allocator::size_type			size_type;

		typedef	ft::BST_iterator<node_type>					iterator;
		typedef	ft::BST_const_iterator<node_type>			const_iterator;


		BST(const key_compare compare = key_compare()) :
			_compare(compare)
		{
			this->_root = NULL;
			_setStartEnd();
			this->_size = 0;
		}

		BST(BST const & bst) {
			this->_size = 0;
			this->_root = NULL;
			_setStartEnd();
			*this = bst;
		}

		virtual ~BST()
		{
			if (_root) {
				clearAll();
			} else {
				_alloc.destroy(_end_node);
				_alloc.deallocate(_end_node, 1);
				_alloc.destroy(_start_node);
				_alloc.deallocate(_start_node, 1);
			}
		}

		BST&		operator=(BST const & bst)
		{
			if (this != &bst) {
				this->clear();
				this->_alloc = bst._alloc;
				this->_compare = bst._compare;

				const_iterator	first = bst.getBeginConst();
				const_iterator	last = bst.getEndConst();

				for (; first != last; first++) {
					this->insert(*first);
				}
			}
			return (*this);
		}

		node_pointer	clear(node_pointer node)
		{
			if (node)
			{
				node->left = clear(node->left);
				node->right = clear(node->right);
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
			}
			return (NULL);
		}

		void			clearAll() {
			_root = clear(_root);
			_end_node = _root;
			_start_node = _root;
		}

		void			clear() {
			if (_size != 0) {
				clearAll();
				_setStartEnd();
				_size = 0;
			}
		}


		iterator		getBegin() {
			if (!_root) {
				return (iterator(_end_node));
			}
			return (iterator(_start_node));
		}

		const_iterator	getBeginConst() const {
			if (!_root) {
				return (const_iterator(_end_node));
			}
			return (const_iterator(_start_node));
		}

		iterator		getEnd() {
			return (iterator(_end_node));
		}

		const_iterator	getEndConst() const {
			return (const_iterator(_end_node));
		}

		size_type		getSize() const {
			return (_size);
		}

		ft::pair<iterator, bool>	insert(const value_type & val) {
			return (_insert(val, _root));
		}

		iterator					insertPos(iterator position, const value_type & val) {
			(void)position;
			return (_insert(val, _root).first);
		}

		void						swap(BST & bst) {
			ft::swap(this->_alloc, bst._alloc);
			ft::swap(this->_compare, bst._compare);
			ft::swap(this->_root, bst._root);
			ft::swap(this->_end_node, bst._end_node);
			ft::swap(this->_start_node, bst._start_node);
			ft::swap(this->_size, bst._size);
		}


		/*
		 * Don't forget to delete
		 */
		iterator	getRoot() {
			return (iterator(_root));
		}
	private:
		node_allocator	_alloc;
		key_compare		_compare;
		node_pointer	_root;
		node_pointer	_end_node;
		node_pointer	_start_node;
		size_type		_size;

		void						_setStartEnd() {
			_start_node = _alloc.allocate(1);
			_alloc.construct(_start_node, node_type());
			_end_node = _alloc.allocate(1);
			_alloc.construct(_end_node, node_type());
			_start_node->right = _end_node;
			_end_node->parent = _start_node;
		}

		void						_setStartNode(node_pointer node) {
			if (!_size)
				return ;
			if (_start_node == NULL || _compare(node->value.first, _start_node->value.first)) {
				_start_node = node;
			}
		}

		ft::pair<iterator, bool>	_rootNullCase(const value_type & val) {
			_start_node->value = val;
			_root = _start_node;
			_size++;
			return (pair<iterator, bool>(iterator(_start_node), false));
		}

		ft::pair<iterator, bool>	_insert(const value_type & val, node_pointer node) {

			node_pointer	start_node = NULL;
			if (!_root)
				return (_rootNullCase(val));
			if (_root && !node)
				node = _root;
			while (node && node != _end_node) {
				start_node = node;
				if (_compare(val.first, node->value.first)) {
					node = node->left;
				} else if (_compare(node->value.first, val.first)) {
					node = node->right;
				} else {
					return (pair<iterator, bool>(iterator(node), false));
				}
			}
			if (node == _end_node) {
				node_pointer	tmp = _alloc.allocate(1);
				_alloc.construct(tmp, node_type(val, start_node, NULL, _end_node));
				_end_node->parent = tmp;
				node = tmp;
			} else {
				node = _alloc.allocate(1);
				_alloc.construct(node, node_type(val, start_node));
			}
			if (start_node) {
				if (_compare(val.first, start_node->value.first)) {
					start_node->left = node;
				} else {
					start_node->right = node;
				}
			}
			_setStartNode(node);
			_size++;
			return (pair<iterator, bool>(iterator(node), true));
		}
	};
}

#endif