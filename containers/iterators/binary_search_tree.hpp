#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include "utils.hpp"

namespace ft {

	template < typename T>
	struct BST_node {

		typedef T	value_type;

		value_type	value;
		BST_node	*parent_node;
		BST_node	*left_node;
		BST_node	*right_node;

		BST_node() :
			value(),
			parent_node(NULL),
			left_node(NULL),
			right_node(NULL)
		{ }

		BST_node(BST_node const & node) :
			value(node.value),
			parent_node(node.parent_node),
			left_node(node.left_node),
			right_node(node.right_node)
		{ }

		virtual ~BST_node() { }

		BST_node	&operator=(BST_node const & node) {
			if (this != &node) {
				this->value = node.value;
				this->parent_node = node.parent_node;
				this->left_node = node.left_node;
				this->right_node = node.right_node;
			}
			return (*this);
		}

		bool		operator==(BST_node const & node) {
			return (this->value == node.value);
		}
	};

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
				class Compare = ft::less<T>,
				class Node = ft::BST_node<T>,
				class Alloc = std::allocator<T>,
				class Node_alloc = std::allocator<Node> 
				>
	class BST {

	public:
		typedef Compare									key_compare;
		typedef T										value_type;
		typedef typename T::first_type					key_type;
		typedef typename T::second_type					mapped_type;

		typedef Node									node_type;
		typedef node_type *								node_pointer;
		typedef const node_type *						node_const_pointer;
		typedef node_type &								node_reference;
		typedef const node_type &						node_const_reference;

		typedef Alloc									type_allocator;
		typedef Node_alloc								node_allocator;
		typedef typename type_allocator::size_type		size_type;



		BST(const key_compare compare = key_compare()) :
			_compare(compare)
		{
			_rootNode = _alloc.allocate(1);
			_lowestNode = _rootNode;
			_highestNode = _rootNode;
			_size = 1;
		}


	private:
		node_allocator	_alloc;
		key_compare		_compare;
		node_pointer	_rootNode;
		node_pointer	_lowestNode;
		node_pointer	_highestNode;
		size_type		_size;
	};
}

#endif