#ifndef _TREE_HPP_
# define _TREE_HPP_

#include <memory>

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
			//_________ITERATORS______________________//////

		private:
			pointer		_root;
			pointer		_nill;
			size_type	_size;
			value_comp	_comp;



}//end ft namespace
