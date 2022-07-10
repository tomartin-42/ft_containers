/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:56 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/10 19:50:53 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TREE_CONST_ITERATOR_HPP_
# define _TREE_CONST_ITERATOR_HPP_

#include "iterator_traits.hpp"
#include "nullptr.hpp"// to ft::nullptr
#include "node.hpp"// to ft::nullptr
#include <iostream>

namespace ft
{
	template<class T>
	class tree_const_iterator
	{
		public:
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef	const T																		node;	
			typedef	const T*																			pointer;
			typedef const T&																			reference;

		private:
			pointer	_ptr;

		public:
			tree_const_iterator() : _ptr(ft::nullptr_t){}

			explicit tree_const_iterator(pointer ptr) : _ptr(ptr) {}

			tree_const_iterator(const tree_const_iterator& other) : _ptr(other._ptr) {}

			tree_const_iterator& operator = (const tree_const_iterator& other)
			{
				if(this != &other)
					this->_ptr = other.get_ptr();
				return *this;
			}

			tree_const_iterator	base() const {return this->_ptr;}

			pointer get_ptr() const {return this->_ptr;}
			//copy asignable constuctor+++++++++++++++++++++++++++++++++++
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//==========================
//Aux fuctions			
//==========================
		private :
			pointer minimum(pointer n)
			{
				pointer aux = n;

				while(aux->left->get_nill() != true)
					aux = aux->left;
				return aux;
			}

			pointer maximum(pointer n)
			{
				pointer aux = n;

				while(aux->right->get_nill() != true)
					aux = aux->right;
				return aux;
			}
//==========================
//operators
//==========================

		public:
			reference			operator * () const {return (this->_ptr->get_data());}
			pointer		operator -> () const {return &(this->_ptr->get_data());}

			tree_const_iterator& operator ++ ()
			{
    			if (this->_ptr->left->get_nill() != true)
      			{
       				this->_ptr = this->_ptr->left;

       				while (this->_ptr->right->get_nill() != true)
       					this->_ptr = this->_ptr->right;
   				}
   				else
   				{
       				pointer p = this->_ptr->prev;
       				while (p->get_nill() != true && this->_ptr == p->left)
       				{
          				this->_ptr = p;
           				p = p->prev;
       				}
       				this->_ptr = p;
				}
  				return *this;
			}

			tree_const_iterator operator ++ (int)
			{
				tree_const_iterator	tmp = *this;

    			if (this->_ptr->left->get_nill() != true)
      			{
       				this->_ptr = this->_ptr->left;

       				while (this->_ptr->right->get_nill() != true)
       					this->_ptr = this->_ptr->right;
   				}
   				else
   				{
       				pointer p = this->_ptr->prev;
       				while (p->get_nill() != true && this->_ptr == p->left)
       				{
          				this->_ptr = p;
           				p = p->prev;
       				}
       				this->_ptr = p;
				}
				return tmp;
			}

			tree_const_iterator& operator -- ()
			{
    			if (this->_ptr->right->get_nill() != true)
      			{
       				this->_ptr = this->_ptr->right;

       				while (this->_ptr->left->get_nill() != true)
       					this->_ptr = this->_ptr->left;
   				}
   				else
   				{
       				pointer p = this->_ptr->prev;
       				while (p->get_nill() != true && this->_ptr == p->right)
       				{
          				this->_ptr = p;
           				p = p->prev;
       				}
       				this->_ptr = p;
				}
  				return *this;
			}

			tree_const_iterator operator -- (int)
			{
				tree_const_iterator	tmp = *this;

    			if (this->_ptr->right->get_nill() != true)
      			{
       				this->_ptr = this->_ptr->right;

       				while (this->_ptr->left->get_nill() != true)
       					this->_ptr = this->_ptr->left;
   				}
   				else
   				{
       				pointer p = this->_ptr->prev;
       				while (p->get_nill() != true && this->_ptr == p->right)
       				{
          				this->_ptr = p;
           				p = p->prev;
       				}
       				this->_ptr = p;
				}
				return tmp;
			}

			bool	operator == (tree_const_iterator &b) 
			{
				return this->get_ptr() == b.get_ptr();
			}

			bool	operator != (tree_const_iterator &b) 
			{
				return this->get_ptr() != b.get_ptr();
			}

			bool	operator == (const tree_const_iterator &b) const 
			{
				return this->get_ptr() == b.get_ptr();
			}

			bool	operator != (const tree_const_iterator &b) const 
			{
				return this->get_ptr() != b.get_ptr();
			}

	};//end tree_iterator class

//===================================
//No member functions
//===================================

} //end namespace ft

#endif
