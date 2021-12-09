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
			// this->_compare = it._compare;
			return (*this);
		}

		bool			operator==(BST_iterator const & it) const {
			return (_node == it._node);
		}

		bool			operator!=(BST_iterator const & it) const {
			return (_node != it._node);
		}

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

		/*
		 * Don't forget to delete
		 */
		node_pointer	getNode() const { return (_node); }

	private:
		node_pointer	_node;
		// key_compare		_compare;
	};
}

#endif