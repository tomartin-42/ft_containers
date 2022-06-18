#ifndef _TREE_HPP_
# define _TREE_HPP_

#include <memory>
#include "tree_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "utils.hpp"
#include "node.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "nullptr.hpp" //to ft::nullptr

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
			typedef typename ft::tree_iterator<value_type>							iterator;
			typedef typename ft::tree_iterator<const value_type>					const_iterator;

		private:
			alloc_type	_alloc;
			pointer		_root;
			node		_nill;
			size_type	_size;
			value_comp	_comp;
		
		public:
			tree(const alloc_type & alloc_t = alloc_type()) : 
			_alloc(alloc_t), _root(&_nill), _nill(), _size(0), _comp(compare()) {}

			//tree() : _nill.left(ft::nullptr_t), _nill.right(ft::nullptr_t), _nill.prev(ft::nullptr_t), _root(ft::nullptr_t), _size(0) {}

//==========================
//Aux functions
//==========================

			//maybe implement with const_pointer
			pointer minimum(const pointer n) const
			{
				pointer aux = n;

				while(aux->left != &this->_nill)
					aux = aux->left;
				return aux;
			}

			pointer maximun(const pointer n) const
			{
				pointer aux = n;

				while(aux->left != &this->_nill)
					aux = aux->right;
				return aux;
			}

			void assig_nill_values()
			{
				this->_nill.prev = this->root; 
				this->_nill.left = this->minimun(this->_root);
				this->_nill.right = this->maximun(this->_root);
			}
	};
}//end ft namespace

#endif
