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
			if (!_root)
				return (NULL);
			node_pointer	deleteNode;
			node = _start_node;
			while (_size > 0) {

				deleteNode = _findNodeToDelete(node);
				if (!deleteNode) {
					node = _root;
					continue ;
				}
				node = deleteNode->parent;
				if (node->left == deleteNode) {
					node->left = NULL;
				} else {
					node->right = NULL;
				}
				_alloc.destroy(deleteNode);
				_alloc.deallocate(deleteNode, 1);
				_size--;
			}
			if (_root) {
				_alloc.destroy(_root);
				_alloc.deallocate(_root, 1);
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
			return (iterator(_start_node));
		}

		const_iterator	getBeginConst() const {
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

		iterator			lower_bound(const key_type &value) {

			iterator it = getBegin();
			iterator ite = getEnd();
			while (it != ite) {
				if (!_compare(it->first, value))
					break;
				it++;
			}
			return (it);
		}

		const_iterator		lower_bound(const key_type &value) const {

			const_iterator it = getBeginConst();
			const_iterator ite = getEndConst();
			while (it != ite) {
				if (!_compare(it->first, value))
					break;
				it++;
			}
			return (it);
		}

		iterator			upper_bound(const key_type &value) {

			iterator it = getBegin();
			iterator ite = getEnd();
			while (it != ite) {
				if (_compare(value, it->first))
					break;
				it++;
			}
			return (it);
		}

		const_iterator		upper_bound(const key_type &value) const {

			const_iterator it = getBeginConst();
			const_iterator ite = getEndConst();
			while (it != ite) {
				if (_compare(value, it->first))
					break;
				it++;
			}
			return (it);
		}

		/**
		 * Find() count() erase()
		 *
		 */

		iterator			find(const key_type & k) {
			return (iterator(_findNodeByKey(k)));
		}

		const_iterator		find(const key_type & k) const {
			return (const_iterator(_findNodeByKey(k)));
		}

		size_type			count(const key_type & k) const {
			return (_findNodeByKey(k) != _end_node);
		}

		size_type			erase(const key_type & k) {
			node_pointer	node = _findNodeByKey(k);
			if (node == _end_node)
				return (0);
			_eraseNode(node);
			_size--;
			return (1);
		}

		void				eraseIt(iterator position) {
			node_pointer	node = _findNodeByKey(position->first);
			// std::cout << node->value.first << std::endl;
			// std::cout << _size << std::endl;
			if (node == _end_node)
				return ;
			_eraseNode(node);
			_size--;
		}



	private:
		node_allocator	_alloc;
		key_compare		_compare;
		node_pointer	_root;
		node_pointer	_end_node;
		node_pointer	_start_node;
		size_type		_size;

		void						_setStartEnd() {
			_end_node = _alloc.allocate(1);
			_alloc.construct(_end_node, node_type());
			_start_node = _end_node;
		}

		void						_setStartNode(node_pointer node) {
			if (_start_node == NULL || _compare(node->value.first, _start_node->value.first)) {
				_start_node = node;
			}
		}

		ft::pair<iterator, bool>	_rootNullCase(const value_type & val) {
			_start_node = _alloc.allocate(1);
			_alloc.construct(_start_node, node_type(val, NULL, NULL, _end_node));
			_end_node->parent = _start_node;
			_root = _start_node;
			_size++;
			return (pair<iterator, bool>(iterator(_start_node), true));
		}

		node_pointer				_preSetNode(const value_type & val, node_pointer node) {
			if (_compare(val.first, _start_node->value.first)
				|| (!_compare(val.first, _start_node->value.first) && !_compare(_start_node->value.first, val.first))) {
				node = _start_node;
			}
			else if (_compare(_end_node->parent->value.first, val.first)
				|| (!_compare(val.first, _end_node->parent->value.first) && !_compare(_end_node->parent->value.first, val.first))) {
				node = _end_node->parent;

			} 
			else if (_root && !node) {
				node = _root;
			}
			return (node);
		}

		ft::pair<iterator, bool>	_insert(const value_type & val, node_pointer node) {

			node_pointer	parent = NULL;
			if (!_root)
				return (_rootNullCase(val));
			node = _preSetNode(val, node);
			while (node && node != _end_node) {
				parent = node;
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
				_alloc.construct(tmp, node_type(val, parent, NULL, _end_node));
				_end_node->parent = tmp;
				node = tmp;
			} else {
				node = _alloc.allocate(1);
				_alloc.construct(node, node_type(val, parent));
			}
			if (parent) {
				if (_compare(val.first, parent->value.first)) {
					parent->left = node;
				} else {
					parent->right = node;
				}
			}
			_setStartNode(node);
			_size++;
			return (pair<iterator, bool>(iterator(node), true));
		}

		node_pointer	_findNodeToDelete(node_pointer node) {
			if (!node) {
				return (NULL);
			}
			while (node->left || node->right) {
				// std::cout << _size << std::endl;
				if (node->left) {
					node = node->left;
				} else {
					node = node->right;
				}
			}
			return (node);
		}

		node_pointer	_cmpValueWithStartAndEndNodesValues(const key_type & k) const {
			node_pointer	node = NULL;
			if (!_compare(k, _start_node->value.first) && !_compare(_start_node->value.first, k)) {
				node = _start_node;
			}
			else if (!_compare(_end_node->parent->value.first, k) && !_compare(k, _end_node->parent->value.first)) {
				node = _end_node->parent;
			}
			return (node);
		}

		bool			_isNodeKeyEqualKeyToFind(const key_type & k, node_pointer node) const {
			if (!_compare(k, node->value.first) && !_compare(node->value.first, k)) {
				return (true);
			}
			return (false);
		}

		node_pointer	_findNodeByKey(const key_type & k) const {
			if (!_root || _compare(_end_node->parent->value.first, k) || _compare(k, _start_node->value.first))
				return (_end_node);

			node_pointer	node = _cmpValueWithStartAndEndNodesValues(k);
			if (node)
				return (node);
			node = _root;
			while (node && node != _end_node) {
				if (_isNodeKeyEqualKeyToFind(k, node)) {
					return (node);
				}
				if (_compare(k, node->value.first)) {
					node = node->left;
				}
				else if (_compare(node->value.first, k)) {
					node = node->right;
				}
			}
			return (_end_node);
		}

		void		_eraseIfNoNodesAfter(node_pointer node) {
			node_pointer	parent = node->parent;
			
			if (node == _start_node) {
				_start_node = parent;
			}
			if (parent->left == node) {
				parent->left = NULL;
			} else {
				parent->right = NULL;
			}
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}

		void		_setNewChildForParentNode(node_pointer parent,
											node_pointer child,
											bool sideWhichPointsToChildNode) {

			if (parent->left == child) {
				if (sideWhichPointsToChildNode) {
					parent->left = child->right;
					child->right->parent = parent;
				} else {
					parent->left = child->left;
					child->left->parent = parent;
				}
			} else {
				if (sideWhichPointsToChildNode) {
					parent->right = child->right;
					child->right->parent = parent;
				} else {
					parent->right = child->left;
					child->left->parent = parent;
				}
			}
		}

		void		_setPropertiesNodeEqualRootAndStart(node_pointer node) {

			if (node->right != _end_node) {
				_root = _start_node = node->right;
				node->right->parent = NULL;
			} else {
				_root = NULL;
				_start_node = _end_node;
				_end_node->parent = NULL;
			}
		}

		/**
		 * @brief 
		 * 
		 * @param node 
		 * @param sideWhichPointsToChildNode if node has right child then it true,
		 * otherwise it false
		 */
		void		_eraseIfOneNodeAfter(node_pointer node, bool sideWhichPointsToChildNode) {
			node_pointer	parent = node->parent;

			if (parent) {
				if (node == _start_node) {
					node_pointer	tmp = node->right;
					while (tmp->left)
						tmp = tmp->left;
					_start_node = tmp;
				}
				_setNewChildForParentNode(parent, node, sideWhichPointsToChildNode);
			} else {
				_setPropertiesNodeEqualRootAndStart(node);
			}
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}

		node_pointer	_findMinValue(node_pointer startNode) {
			if (!startNode)
				return (NULL);
			while (startNode->left)
				startNode = startNode->left;
			return (startNode);
		}

		node_pointer	_findMaxValue(node_pointer startNode) {
			if (!startNode)
				return (NULL);
			while (startNode->right)
				startNode = startNode->right;
			return (startNode);
		}

		void			_changeNodeConnections(node_pointer node, node_pointer newNode) {

			if (node->parent) {
				if (node->parent->left == node) {
					node->parent->left = newNode;
				} else {
					node->parent->right = newNode;
				}
			} else {
				_root = newNode;
			}
			newNode->parent = node->parent;
			if (node->left != newNode) {
				node->left->parent = newNode;
				newNode->left = node->left;
			}
			if (node->right != newNode) {
				node->right->parent = newNode;
				newNode->right = node->right;
			}
		}

		void			_eraseEndCase(node_pointer node) {
			node_pointer	newNode = _findMaxValue(node->left);
			node_pointer	newNodeOldParent = newNode->parent;
			node_pointer	newNodeOldRight = newNode->left;

			_changeNodeConnections(node, newNode);

			newNodeOldParent->right = newNodeOldRight;
			if (newNodeOldRight)
				newNodeOldRight->parent = newNodeOldParent;
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
		void			_eraseIfTwoNodesAfter(node_pointer node) {
			
			if (node->right == _end_node) {
				_eraseEndCase(node);
				return ;
			}
			node_pointer	newNode = _findMinValue(node->right);
			if (!newNode)
				return ;
			node_pointer	newNodeOldParent = newNode->parent;
			node_pointer	newNodeOldRight = newNode->right;

			_changeNodeConnections(node, newNode);
			newNodeOldParent->left = newNodeOldRight;
			if (newNodeOldRight)
				newNodeOldRight->parent = newNodeOldParent;
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}

		void		_eraseNode(node_pointer node) {
			if (!node)
				return ;
			if (!node->left && !node->right) {
				_eraseIfNoNodesAfter(node);
			}
			else if (!node->left && node->right) {
				// std::cout << "Right" << std::endl;
				_eraseIfOneNodeAfter(node, true);
			}
			else if (node->left && !node->right) {
				_eraseIfOneNodeAfter(node, false);
			}
			else {
				_eraseIfTwoNodesAfter(node);
			}
		}
	};
}

#endif