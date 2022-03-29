/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:41:05 by tomartin          #+#    #+#             */
/*   Updated: 2022/03/29 12:00:35 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "nullptr.hpp" //to ft::nullptr
#include "random_access_iterator.hpp"
#include <memory>

namespace ft
{
	template <class T, class alloc = std::allocator<T> > 
	class vector
	{
		public:
			typedef T															value_type;
			typedef	alloc														alloc_type;
			typedef typename alloc_type::reference								reference;
			typedef typename alloc_type::const_reference						const_reference;
			typedef typename alloc_type::pointer								pointer;
			typedef typename alloc_type::const_pointer							const_pointer;
		//	typedef std::iterator<std::random_access_iterator_tag, value_type>		iterator;
		//	typedef std::iterator<std::random_access_iterator_tag, const value_type>	const_iterator;
		//	typedef std::iterator<std::random_access_iterator_tag, pointer>		iterator;
		//	typedef std::iterator<std::random_access_iterator_tag, const_pointer>	const_iterator;
		//	typedef std::reverse_iterator<iterator>								reverse_iterator;
		//	typedef std::reverse_iterator<const iterator>						const_reverse_iterator;
		//	typedef ft::random_access_iterator<value_type>						iterator;
		//	typedef ft::random_access_iterator<const value_type>				const_iterator;
			typedef ft::random_access_iterator<pointer>						iterator;
			typedef ft::random_access_iterator<const_pointer>				const_iterator;
	//		typedef ft::reverse_iterator<iterator>							reverse_iterator;
	//		typedef ft::reverse_iterator<const iterator>						const_reverse_iterator;
			typedef typename ft::iterator_trails<iterator>::difference_type 	difference_type;
			typedef typename alloc_type::size_type								size_type;
	
		private:
			alloc_type							_alloc;			// data type //
			pointer     						_start;			// where init data //
			pointer     						_end;			// where init empty data //
			pointer								_end_capacity;	// where end the prealocate data //
			size_type							_size;			// number of alocate data //


//************************************************************************************************************	
//********************************************constructors****************************************************
			
		public:
//=========================
//empty
//=========================
			explicit vector (const alloc_type& alloc_t = alloc_type()) 
				: _alloc(alloc_t), _start(ft::nullptr_t), _end(_start), _end_capacity(_end), _size(0)
			{}

//=========================
//fill
//========================= 
			explicit vector (size_type n, const value_type& val = value_type(), const alloc_type& alloc_t = alloc_type())
				: _alloc(alloc_t), _start(ft::nullptr_t), _end(_start), _size(n) 
			{
				this->_start = _alloc.allocate(n);
				this->_end_capacity = this->_start + n;
				for(unsigned long i = 0; i < n; i++)
				{
					_alloc.construct((this->_start + i), val);
					this->_end++;
				}
			}
	
//=========================
//range
//=========================
	/*		template <class InputIterator>
	        vector (InputIterator first, InputIterator last, const alloc_type& alloc_t = alloc_type())
				: _alloc(alloc_t) 
			{
				this->_size(std::distance(first, last));
			}
	*/
//=========================
//copy
//=========================
			vector (const vector& other)
				: _alloc(other._alloc), _start(other._start), _end(other._end), _end_capacity(other._end_capacity), _size(other._size)
			{}

//=========================
//destructor
//=========================
			~vector ()
			{
				this->_alloc.deallocate(this->_start, this->_size);
			}

//************************************************************************************************************//	
//*****************************************member fuctions****************************************************//	
			
//==========================
//iterators
//==========================	
			iterator begin() {return iterator(this->_start);}

		//	const_iterator begin() const {return this->_start;}

		//	iterator end() {return this->_end;}

		//	const_iterator end() const {return this->_end;}


	};// end vector class
} // end namespace ft
#endif
