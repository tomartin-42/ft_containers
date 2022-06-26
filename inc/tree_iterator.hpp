/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:56 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/26 15:55:15 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TREE_ITERATOR_HPP_
# define _TREE_ITERATOR_HPP_

#include "iterator_traits.hpp"
#include "nullptr.hpp"// to ft::nullptr
#include "node.hpp"// to ft::nullptr
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
			typedef	T*																	pointer;
			typedef T&																	reference;

		private:
			pointer	_ptr;

		public:
			tree_iterator() : _ptr(ft::nullptr_t){}

			explicit tree_iterator(pointer ptr) : _ptr(ptr) {}

			tree_iterator(const tree_iterator& other) : _ptr(other.base()) {}

			pointer	base() const {return this->_ptr;}

			tree_iterator& operator = (const tree_iterator& other)
			{
				if(this != &other)
					this->_ptr = other.base();
				return *this;
			}

			pointer get_ptr() const {return this->_ptr;}
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
			reference	operator * () const {return (this->_ptr->data);}
			pointer		operator -> () const {return &(this->_ptr->data);}

			tree_iterator& operator ++ ()
			{
				if (this->_ptr->right->get_nill() != true)
				{
					this->_ptr = minimum(this->_ptr);
					return *this;
				}
				while(this->_ptr == this->_ptr->prev->left)
					this->_ptr = this->_ptr->prev;
				return *this;
			}

			tree_iterator operator ++ (int)
			{
				tree_iterator	tmp = *this;

				++(this->_ptr);
				return tmp;
			}

			tree_iterator& operator -- ()
			{
				if (this->_ptr->right->get_nill() != true)
				{
					this->_ptr = maximum(this->_ptr);
					return *this;
				}
				while(this->_ptr == this->_ptr->prev->left)
					this->_ptr = this->_ptr->prev;
				return *this;
			}

			tree_iterator operator -- (int)
			{
				tree_iterator	tmp = *this;

				--(this->_ptr);
				return tmp;
			}

			bool	operator == (const tree_iterator &b) const 
			{
				return this->get_ptr() == b.get_ptr();
			}

			bool	operator != (const tree_iterator &b) const 
			{
				return this->get_ptr() != b.get_ptr();
			}
	};//end tree_iterator class

//===================================
//No member functions
//===================================
//
	template <typename T, typename V>
	bool	operator == (const tree_iterator<T>& itf, const tree_iterator<V>& itl)
	{
		return itf.base() == itl.base();
	}

	template <typename T, typename V>
	bool	operator != (const tree_iterator<T>& itf, const tree_iterator<V>& itl)
	{
		return !(itf.base() == itl.base());
	}

} //end namespace ft

#endif
