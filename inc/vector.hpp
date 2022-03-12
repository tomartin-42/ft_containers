/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:41:05 by tomartin          #+#    #+#             */
/*   Updated: 2022/03/12 20:09:51 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "nullptr.hpp"

namespace ft
{
	template <class T, class alloc = allocator<T> > 
	class vector
	{
		public:
			typedef T															value_type;
			typedef	alloc														allocator_type;
			typedef typename alloc_type::reference								reference;
			typedef typename alloc_type::const_eference							const_reference;
			typedef typename alloc_type::pointer								pointer;
			typedef typename alloc_type::const_pointer							const_pointer;
			typedef std::random_access_iterator<value_type>						iterator;
			typedef std::random_access_iterator<const value_type>				const_iterator;
			typedef std::reverse_iterator<iterator>								reverse_iterator;
			typedef std::reverse_iterator<const iterator>						const_reverse_iterator;
			typedef typename std::iterator_traits<iterator>::difference_type 	difference_type;
			typedef typename allocator_type::size_type							size_type;
	
		private:
			allocator_type						_alloc;
			pointer     						_start;
			pointer     						_end;
			pointer								_end_capacity;
			
			//constructors==============================================================================

			//empty
			explicit vector (const allocator_type& alloc = allocator_type()) 
				: _begin(ft::nullptr_t), _end(_begin), _size(0)
			{
			}
	
			//fill 
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				: _start(ft::nullptr_t), _end(_start), _size(n)
			{
				this->_start = _alloc.allocate(n);
				this->_end_capacity = this->_start + n;
				for(int i = 0; i < n; i++)
				{
					_alloc.construct((this->_start + i), val);
					this->_end++;
				}
			}
	
			//range
	/*		template <class InputIterator>
	        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
	
	
			//copy
			vector (const vector& x)
	*/
	};
} // end namespace ft
#endif


