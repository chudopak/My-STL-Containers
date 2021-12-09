#include "tests.hpp"

void	MapTest() {

	{
		std::cout << "simple iterator test" << std::endl;

		ft::BST_node<int>										node_one;
		ft::BST_iterator<ft::BST_node<int> >		it_empty;


		ft::BST_iterator<ft::BST_node<int> >		it_one(&node_one);
		ft::BST_iterator<ft::BST_node<int> >		it_two(it_one);

/* 		it++;
		it++;
		if (myMap.begin() == it) {
			std::cout << "Iterator equal" << std::endl;
			// std::cout << myMap.end() << std::endl;
			std::cout << (*it).first << std::endl;
		} else {
			std::cout << "Iterator not equal" << std::endl;
			std::cout << it->first << std::endl;
		} */

	}

	{
		ft::BST_node<ft::pair<int, int> >										node_pair;
		ft::BST_iterator<ft::BST_node<ft::pair<int, int> > >		it_pair(&node_pair);

		node_pair.value.first = 45;
		std::cout << it_pair->first << std::endl;
		it_pair++;
		// ft::BST_node<ft::pair<int, int> >										*come_node = it_pair.getNode();
		// if (come_node == NULL) {
		// 	std::cout << "it's NULL" << std::endl;
		// }


	}

	{
		std::cout << "test insert" << std::endl;

		std::map<int, int> 										myMap;

		myMap.insert(std::make_pair(3, 2));
		myMap.insert(std::make_pair(4, 2));
		myMap.insert(std::make_pair(2, 2));
		myMap.insert(std::make_pair(1, 2));

		myMap.insert(std::make_pair(5, 2));
		// it = myMap.end();
		// it--;
		std::map<int, int>::iterator							it = myMap.begin();
		while (it != myMap.end()) {
			std::cout << it->first << std::endl;
			it++;
		}
		std::cout << "REVERSE" << std::endl;

		while (it != myMap.begin()) {
			std::cout << it->first << std::endl;
			it--;
		}
			// std::cout << it->first << std::endl;


	}

	{
		std::cout << std::endl << "test MY insert" << std::endl;
		ft::BST_node<ft::pair<int, int> >										node_pair;
		ft::BST_iterator<ft::BST_node<ft::pair<int, int> > >		it_pair;
		ft::BST<ft::pair<int, int> >											bst;

		ft::BST_iterator<ft::BST_node<ft::pair<int, int> > >	iter = bst.getBegin();
		ft::BST_node<ft::pair<int, int> >						*new_node = iter.getNode();
		ft::BST_node<ft::pair<int, int> >						*node1 = iter.getNode();


		bst.insert(ft::make_pair(14, 2));
		bst.insert(ft::make_pair(14, 2));
		bst.insert(ft::make_pair(14, 2));
		bst.insert(ft::make_pair(14, 2));


		// iter = bst.getBegin();
		// std::cout << iter->first << std::endl;

		// std::cout << "ADDED ONE NODE" << std::endl;
		// iter = bst.getEnd();
		// new_node = iter.getNode();
		// new_node = new_node->parent;

		// std::cout << new_node->value.first << new_node->value.second << std::endl;



		
		
		bst.insert(ft::make_pair(1, 45));
		iter = bst.getBegin();
		bst.insert(ft::make_pair(-1, 2));
		bst.insert(ft::make_pair(-8, 2));
		bst.insert(ft::make_pair(13, 2));
		bst.insert(ft::make_pair(15, 2));
		bst.insert(ft::make_pair(12, 2));

		bst.insert(ft::make_pair(5, 2));

		std::cout << "The Other Way" << std::endl;
		iter = bst.getEnd();
		new_node = iter.getNode();
		iter = bst.getBegin();
		node1 = iter.getNode();
		node1 = node1->right;
		if (node1 == new_node)
			std::cout << "They EQ" << std::endl;
		iter = bst.getBegin();
		while (iter != bst.getEnd()) {
			std::cout << iter->first << std::endl;
			iter++;
		}
		std::cout << std::endl << " NEW ERA" << std::endl;

		while (iter != bst.getBegin()) {
			std::cout << iter->first << " " << iter->second << std::endl;
			iter--;
		}
			// std::cout << iter->first << " " << iter->second << std::endl;



	}
}