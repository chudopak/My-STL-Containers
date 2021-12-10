#ifndef STACK_HPP
# define STACK_HPP

# include "headers.hpp"
# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack {

	public:
		typedef T									value_type;
		typedef Container							container_type;
		typedef typename container_type::size_type	size_type;

		explicit			stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) { }

		bool				empty() const {
			return (this->_ctnr.empty());
		}

		size_type			size() const {
			return (this->_ctnr.size());
		}

		value_type&			top() {
			return (this->_ctnr.back());
		}

		const value_type&	top() const {
			return (this->_ctnr.back());
		}

		void				push(const value_type& val) {
			this->_ctnr.push_back(val);
		}

		void				pop() {
			this->_ctnr.pop_back();
		}

		template <class T2, class Container2>
		friend bool operator== (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

		template <class T2, class Container2>
		friend bool operator!= (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);
			
		template <class T2, class Container2>
		friend bool operator< (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

		template <class T2, class Container2>
		friend bool operator<= (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

		template <class T2, class Container2>
		friend bool operator> (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

		template <class T2, class Container2>
		friend bool operator>= (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

	protected:
		container_type	_ctnr;
	};

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr == rhs._ctnr);
	}

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr != rhs._ctnr);
	}

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr < rhs._ctnr);
	}

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr <= rhs._ctnr);
	}

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr > rhs._ctnr);
	}

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr >= rhs._ctnr);
	}
}

#endif