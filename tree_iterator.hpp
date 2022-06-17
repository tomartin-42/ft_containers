#ifndef _TREE_ITERATOR_HPP_
# define _TREE_ITERATOR_HPP_

#include "iterator_traits.hpp"

namespace ft
{
	template<class T>
	class iterator_tree
	{
		public:
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::reference				reference;

		private:
			pointer _ptr;

	}; //end class iterator_tree
}//end namespace ft

#endif
