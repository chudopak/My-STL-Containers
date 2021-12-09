#ifndef BINARY_SEARCH_TREE_NODE_HPP
# define BINARY_SEARCH_TREE_NODE_HPP

# include "utils.hpp"

namespace ft {

	template < typename T>
	struct BST_node {

		typedef T	value_type;

		value_type	value;
		BST_node	*parent;
		BST_node	*left;
		BST_node	*right;

		BST_node() :
			value(),
			parent(NULL),
			left(NULL),
			right(NULL)
		{ }

		BST_node(const value_type & val, BST_node * prt = NULL, BST_node * lft = NULL, BST_node * rght = NULL) :
			value(val),
			parent(prt),
			left(lft),
			right(rght)
		{ }

		BST_node(BST_node const & node) :
			value(node.value),
			parent(node.parent),
			left(node.left),
			right(node.right)
		{ }

		virtual ~BST_node() { }

		BST_node	&operator=(BST_node const & node) {
			if (this != &node) {
				this->value = node.value;
				this->parent = node.parent;
				this->left = node.left;
				this->right = node.right;
			}
			return (*this);
		}

		bool		operator==(BST_node const & node) {
			return (this->value == node.value);
		}
	};
}

#endif
