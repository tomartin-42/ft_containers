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
			void assig_nill_values()
			{
				this->_nill.prev = this->root; 
				this->_nill.left = this->minimun(this->_root);
				this->_nill.right = this->maximun(this->_root);
			}

			pointer get_nill() {return this->_nill;}

			//maybe implement with const_pointer too
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

			pointer	next_node(const pointer n) const
			{
				if (n->right != this->_nill)
					return minimun(n->right);
				while (n == n->prev->left)
					n = n->prev;
				return n->prev;
			}

			pointer	prev_node(const pointer n) const
			{
				if (n->left != this->_nill)
					return maximun(n->left);
				while (n == n->prev->left)
				//while (n == n->prev->rigth)
					n = n->prev;
				return n->prev;
			}
//==========================
//Iterators
//==========================

			iterator		begin() {return iterator(this->minimum(this->_root));}

			const_iterator	begin() const {return const_iterator(this->minmum(this->_root));}

			iterator		end() {return iterator(this->maximum(this->_root));}
			
			const_iterator	end() const {return const_iterator(this->maximum(this->_root));}

//==========================
//Capacity
//==========================

			bool	empty() const
			{
				if(this->_size == 0)
					return true;
				return false;
			}

	};//end tree class
}//end ft namespace

#endif
