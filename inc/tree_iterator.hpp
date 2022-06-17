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
			typedef typename ft::Iter<ft::tree_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::Iter<ft::tree_iterator_tag, T>::value_type			value_type;
			typedef typename ft::Iter<ft::tree_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::Iter<ft::tree_iterator_tag, T>::pointer				pointer;
			typedef typename ft::Iter<ft::tree_iterator_tag, T>::reference				reference;
		//	typedef	T*																	pointer;
		//	typedef T&																	reference;

		private:
			pointer	_ptr;

		public:
			tree_iterator() : _ptr(ft::nullptr_t) {}
			explicit tree_iterator(pointer ptr) : _ptr(ptr) {}

			tree_iterator(const tree_iterator & other) : _ptr(other.base()) {}

			pointer	base() const {return this->_ptr;}

			

	};

} //end namespace ft

#endif