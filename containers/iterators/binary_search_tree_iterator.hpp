#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
# define BINARY_SEARCH_TREE_ITERATOR_HPP

# include "utils.hpp"
# include "binary_search_tree_node.hpp"

namespace ft {

	template <class Node>
	class BST_iterator : ft::iterator<ft::bidirectional_iterator_tag, Node> {

	public:
		typedef Node *																					node_pointer;

		typedef typename Node::value_type																value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

		BST_iterator() :
			_node(NULL)
		{ }

		BST_iterator(node_pointer node) :
			_node(node)
		{ }

		BST_iterator(const BST_iterator &it) {
			*this = it;
		}

		virtual ~BST_iterator() { }

		BST_iterator&	operator=(const BST_iterator &it) {

			if (*this == it)
				return (*this);
			this->_node = it._node;
			// std::cout << "WE In assingment" << std::endl;
			return (*this);
		}

		bool			operator==(BST_iterator const & it) const { return (_node == it._node); }
		node_pointer	getNode() const { return (_node); }
		bool			operator!=(BST_iterator const & it) const { return (_node != it._node); }

		reference		operator*() const {
			return (this->_node->value);
		}

		pointer			operator->() const {
			return (&(operator*()));
		}

		BST_iterator&	operator++() {

			if (_node) {
				if (_node->right) {
					_node = _node->right;
					while (_node->left)
						_node = _node->left;
				}
				else {
					while (_node->parent && _node->parent->right == _node)
						_node = _node->parent;
					_node = _node->parent;
				}
			}
			return (*this);
		}

		BST_iterator	operator++(int) {

			BST_iterator	tmp = *this;
			operator++();
			return (tmp);
		}

		BST_iterator&	operator--() {

			if (_node) {
				if (_node->left) {
					_node = _node->left;
					while (_node->right) {
						_node = _node->right;
					}
				}
				else {
					while (_node->parent && _node->parent->left == _node)
						_node = _node->parent;
					_node = _node->parent;
				}
			}
			return (*this);
		}

		BST_iterator	operator--(int) {

			BST_iterator	tmp = *this;
			operator--();
			return (tmp);
		}

	private:
		node_pointer	_node;
	};

	template <class Node>
	class BST_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, Node> {

	public:
		typedef Node *																					node_pointer;

		typedef typename Node::value_type const															value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

		BST_const_iterator() :
			_node(NULL)
		{ }

		BST_const_iterator(node_pointer node) :
			_node(node)
		{ }

		BST_const_iterator(const BST_const_iterator & it) {
			*this = it;
		}

		BST_const_iterator(const BST_iterator<Node> & it) :
			_node(it.getNode())
		{ }

		virtual ~BST_const_iterator() { }

		BST_const_iterator&	operator=(const BST_const_iterator &it) {

			if (*this == it)
				return (*this);
			this->_node = it._node;
			return (*this);
		}

		bool			operator==(BST_const_iterator const & it) const { return (_node == it._node);}
		node_pointer	getNode() const { return (_node); }
		bool			operator!=(BST_const_iterator const & it) const { return (_node != it._node);}

		reference		operator*() const {
			return (this->_node->value);
		}

		pointer			operator->() const {
			return (&(operator*()));
		}

		BST_const_iterator&	operator++() {

			if (_node) {
				if (_node->right) {
					_node = _node->right;
					while (_node->left)
						_node = _node->left;
				}
				else {
					while (_node->parent && _node->parent->right == _node)
						_node = _node->parent;
					_node = _node->parent;
				}
			}
			return (*this);
		}

		BST_const_iterator	operator++(int) {

			BST_const_iterator	tmp = *this;
			operator++();
			return (tmp);
		}

		BST_const_iterator&	operator--() {

			if (_node) {
				if (_node->left) {
					_node = _node->left;
					while (_node->right) {
						_node = _node->right;
					}
				}
				else {
					while (_node->parent && _node->parent->left == _node)
						_node = _node->parent;
					_node = _node->parent;
				}
			}
			return (*this);
		}

		BST_const_iterator	operator--(int) {

			BST_const_iterator	tmp = *this;
			operator--();
			return (tmp);
		}

	private:
		node_pointer	_node;
	};
}

#endif