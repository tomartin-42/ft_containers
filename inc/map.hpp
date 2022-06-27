#include <memory> // to allocate
#include <iostream>
#include "tree.hpp"
#include "pair.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > > 
	class map
	{
		public:
			typedef	Key													key_type;
			typedef T													data_type;
			typedef Compare												comp;
			typedef Alloc												alloc_type;
			typedef typename ft::pair<const key_type, data_type>		value_type;	
			typedef typename alloc_type::pointer						pointer;
			typedef typename alloc_type::const_pointer					const_pointer;
			typedef typename alloc_type::reference						reference;
			typedef typename alloc_type::const_reference				const_reference;
			typedef typename alloc_type::size_type						size_type;
			typedef typename alloc_type::difference_type				difference_type;
			typedef typename ft::tree_iterator<value_type>					iterator;
			typedef typename ft::tree_iterator<const value_type>			const_iterator;
	}; //end map class
}//end namespace ft

	
