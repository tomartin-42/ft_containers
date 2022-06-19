#ifndef _TREE_ITERATOR_HPP_
# define _TREE_ITERATOR_HPP_

#include "iterator_traits.hpp"
#include "nullptr.hpp"// to ft::nullptr
#include <iostream>

namespace ft
{
	template<class T>
	class tree_iterator
	{
		public:
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
		//	typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::pointer				pointer;
		//	typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::reference				reference;
			//typedef typename ft::node<value_type> *												nod_pointer;
			typedef	T*																	pointer;
			typedef T&																	reference;

		private:
			pointer	_ptr;

		public:
			tree_iterator() : _ptr(ft::nullptr_t) {}
			explicit tree_iterator(pointer ptr) : _ptr(ptr) {}

			tree_iterator(const tree_iterator & other) : _ptr(other.base()) {}

			pointer	base() const {return this->_ptr;}

			tree_iterator & operator = (const tree_iterator& other)
			{
				if(this == &other)
					return *this;
				_ptr = other.base();
				return *this;
			}

			pointer get_ptr() {return this->_ptr;}
			//copy asignable constuctor+++++++++++++++++++++++++++++++++++
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//==========================
//Aux fuctions			
//==========================
		private :
			pointer maximum(pointer n)
			{
				pointer aux = n;

				while(aux->left->get_nill() != true)
					aux = aux->right;
				return aux;
			}

			pointer minimum(pointer n)
			{
				pointer aux = n;

				while(aux->left->get_nill() != true)
					aux = aux->left;
				return aux;
			}
//==========================
//operators
//==========================

		public:
			reference	operator * () const {return *(this->_ptr.data);}
			pointer		operator -> () const {return &(this->_ptr.data);}

			tree_iterator& operator ++ ()
			{
				if (this->_ptr->right->get_nill() != true)
					return tree_iterator(this->minimum(this->_ptr));
				while(this->_ptr == this->_ptr->prev->left)
					this->_ptr = this->_ptr->prev;
				return tree_iterator(this->_ptr);
			}

			tree_iterator operator -- ()
			{
				this->_ptr = this->_ptr->prev_node(this->ptr);
				return *this;
			}

			
	};

} //end namespace ft

#endif
