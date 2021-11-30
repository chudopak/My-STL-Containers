#ifndef STACK_HPP
# define STACK_HPP

# include "headers.hpp"
# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack {

	public:
		typedef T				value_type;
		typedef Container		container_type;
		typedef size_t			size_type;
	
	};
}

#endif