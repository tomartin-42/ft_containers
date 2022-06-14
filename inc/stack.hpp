/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 08:24:43 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/08 08:15:17 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{

template <class T, class container = ft::vector<T> >
class stack
{
	public:
		typedef T											value_type;
		typedef container									container_type;
		typedef typename container_type::reference			reference;	
		typedef typename container_type::const_reference	const_reference;	
		typedef typename container_type::size_type			size_type;

	private:
		container_type	_s;
	
	public:
		//Constructors 

		explicit stack(const container_type &other = container_type())
		{
			this->_s = other;
		}
	
		//Member Functions
		bool			empty() const {return _s.empty();}
		size_type		size() const {return _s.size();}
		reference		top() {return _s.back();}
		const_reference	top() const {return _s.back();}
		void			push(const value_type &e) {_s.push_back(e);}
		void			pop() {_s.pop_back();}

		container_type get_stack() const {return this->_s;}
};
	
	template<class T, class container>
	bool operator == (const ft::stack<T, container> first, const ft::stack<T, container> last)
	{
		return (first.get_stack() == last.get_stack());
	}

	template<class T, class container>
	bool operator != (const ft::stack<T, container> first, const ft::stack<T, container> last)
	{
		return (first.get_stack() != last.get_stack());
	}

	template<class T, class container>
	bool operator < (const ft::stack<T, container> first, const ft::stack<T, container> last)
	{
		return (first.get_stack() < last.get_stack());
	}

	template<class T, class container>
	bool operator <= (const ft::stack<T, container> first, const ft::stack<T, container> last)
	{
		return (first.get_stack() <= last.get_stack());
	}

	template<class T, class container>
	bool operator > (const ft::stack<T, container> first, const ft::stack<T, container> last)
	{
		return (first.get_stack() > last.get_stack());
	}

	template<class T, class container>
	bool operator >= (const ft::stack<T, container> first, const ft::stack<T, container> last)
	{
		return (first.get_stack() >= last.get_stack());
	}

}//end namespace ft

#endif

