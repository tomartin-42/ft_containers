#ifndef _TREE_HPP_
# define _TREE_HPP_

#include <memory>
#include "tree_iterator.hpp"

namespace ft
{

	template<class T, class compare, class alloc = std::allocator<T> >
	class tree
	{
		public:
			typedef T																value_type;
			typedef compare															value_comp;
			typedef alloc															alloc_type;
			typedef ft::node<T>														node;
			typedef typename alloc::template rebind<ft::node<value_type> >::other	alloc_node;
			typedef typename alloc_node::reference									reference;
			typedef typename alloc_node::const_reference							const_reference;
			typedef typename alloc_node::pointer									pointer;
			typedef typename alloc_node::const_pointer								const_pointer;
			typedef typename alloc_type::size_type									size_type;
			typedef typename alloc_type::difference_type							diference_type;
			typedef typename ft::iterator_tree<value_type>							iterator;
			typedef typename ft::iterator_tree<const value_type>					const iterator;

		private:
			pointer		_root;
			node		_nill;
			size_type	_size;
			value_comp	_comp;
		
		public:
			tree() {}
	};
}//end ft namespace

#endif
