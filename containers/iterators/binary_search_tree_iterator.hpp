#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
# define BINARY_SEARCH_TREE_ITERATOR_HPP

# include "utils.hpp"
# include "binary_search_tree.hpp"

namespace ft {

	template <class Node, class Compare>
	class BST_iterator : ft::iterator<ft::bidirectional_iterator_tag, Node> {

	public:
		typedef Node *																					node_pointer;
		typedef Compare																					key_compare;

		typedef typename Node::value_type																value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

		BST_iterator(const key_compare& cmp = key_compare()) :
			_compare(cmp),
			_node()
		{ }

		BST_iterator(node_pointer node, const key_compare& cmp = key_compare()) :
			_compare(cmp),
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
			this->_compare = it._compare;
			return (*this);
		}

		bool			operator==(const BST_iterator& it) {
			return (this->_node == it._node);
		}



	private:
		node_pointer	_node;
		key_compare		_compare;
	};
}

#endif