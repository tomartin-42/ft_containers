#ifndef _TREE_ITERATOR_HPP_
# define _TREE_ITERATOR_HPP_

#include "iterator_traits.hpp"
#include "nullptr.hpp"// to ft::nullptr

namespace ft
{
	template<class T>
	class tree_iterator
	{
		public:
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::reference				reference;
			typedef typename ft::node<value_type> *												nod_pointer;
		//	typedef	T*																	pointer;
		//	typedef T&																	reference;

		private:
			nod_pointer	_ptr;

		public:
			tree_iterator() : _ptr(ft::nullptr_t) {}
			explicit tree_iterator(pointer ptr) : _ptr(ptr) {}

			tree_iterator(const tree_iterator & other) : _ptr(other.base()) {}

			nod_pointer	base() const {return this->_ptr;}

			tree_iterator & operator = (const tree_iterator& other)
			{
				if(this == &other)
					return *this;
				_ptr = other.base();
				return *this;
			}

			nod_pointer get_ptr() {return this->_ptr;}
			//copy asignable constuctor+++++++++++++++++++++++++++++++++++
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//==========================
//operators
//==========================

			reference	operator * () const {return *(this->_ptr.data);}
			pointer		operator -> () const {return &(this->_ptr.data);}

		//	tree_iterator operator ++ ()
		//	{
		//		if(this->_ptr.rigth != _


			
	};

} //end namespace ft

#endif
