#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "nullptr.hpp"

template <class T, class alloc = allocator<T>i > 
class vector
{
	public:
		typedef	alloc														allocator_type;
		typedef T															value_type;
		typedef typename alloc_type::reference								reference;
		typedef typename alloc_type::const_eference							const_reference;
		typedef typename alloc_type::pointer								pointer;
		typedef typename alloc_type::const_pointer							const_pointer;
		typedef std::random_access_iterator<value_type>						iterator;
		typedef std::random_access_iterator<const value_type>				const_iterator;
		typedef std::random_access_iterator<iterator>						reverse_iterator;
		typedef std::random_access_iterator<const iterator>					const_reverse_iterator;
		typedef typename std::iterator_traits<iterator>::difference_type 	difference_type;
		typedef typename allocator_type::size_type							size_type;

	private:
		pointer     						_begin;
		pointer     						_end;
		size_type   						_size;
		std::pair<pointer, allocator_type> 	_end_cap;
		
		//constructors
		//empty
		explicit vector (const allocator_type& alloc = allocator_type()) 
			: _begin(ft::nullptr_t), _end(_begin), _size(0)
		{
		}

/*		//fill 
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())

		//range
		vector (InputIterator first, InputIterator last, 
				const allocator_type& alloc = allocator_type())

		//copy
		vector (const vector& x)
*/

