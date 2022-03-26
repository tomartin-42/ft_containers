/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramdom_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:04:37 by tomartin          #+#    #+#             */
/*   Updated: 2022/03/26 19:40:34 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_trails.hpp" 
#include "nullptr.hpp"// to ft::nullptr
#include <cstddef> // to ptrdiff_t

namespace ft
{
	template <class T>
	class random_access_iterator
	{
		public:
			typedef typename ft::iterator_trails<T>::value_type			value_type;	
			typedef typename ft::iterator_trails<T>::difference_type	difference_type;	
			typedef typename ft::iterator_trails<T>::pointer			pointer;	
			typedef typename ft::iterator_trails<T>::reference			reference;	
			typedef typename ft::random_access_iterator_tag				iterator_category;	
	
		private:
			pointer	_ptr;
	
		public:
//==========================
//constructors
//==========================
			random_access_iterator() : _ptr(ft::nullptr_t) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}


	};
}//end namespace ft

#endif
