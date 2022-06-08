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

#include <vector>

template <class _T, class _container = std::vector<_T> >
class stack
{
	public:
		typedef _container									container_type;
		typedef typename container_type::value_type			value_type;	
		typedef typename container_type::reference			reference;	
		typedef typename container_type::const_reference	const_reference;	
		typedef typename container_type::size_type			size_type;

	private:
		container_type	_c;
	
	public:
		//Constructors 
		stack() {}
		stack(const stack &other) : _c(other._c) {}	
	
		//Member Functions
		bool			empty() const {return _c.empty();}
		size_type		size() const {return _c.size();}
		reference		top() {return _c.back();}
		const_reference	top() const {return _c.back();}
		void			push(const value_type &e) {_c.push_back(e);}
		void			pop() {_c.pop_back();}
};

#endif

