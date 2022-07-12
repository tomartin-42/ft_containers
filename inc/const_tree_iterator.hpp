/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:56 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/11 12:20:39 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONST_TREE_ITERATOR_HPP_
# define _CONST_TREE_ITERATOR_HPP_

#include "iterator_traits.hpp"
#include "nullptr.hpp"// to ft::nullptr
#include "node.hpp"// to ft::nullptr
#include <iostream>

namespace ft
{
	template<class T>
	class const_tree_iterator
	{
		public:
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::Iter<ft::bidirectional_iterator_tag,T>::value_type			value_type;
			typedef typename ft::Iter<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef ft::node<T>																	node;
			typedef node*																		node_pointer;
			typedef node&																		node_reference;
			typedef	value_type*																	pointer;
			typedef value_type&																	reference;

		private:
			node_pointer	_ptr;

		public:
			const_tree_iterator() : _ptr(ft::nullptr_t){}

			explicit const_tree_iterator(node_pointer ptr) : _ptr(ptr) {}

			const_tree_iterator(const const_tree_iterator& other) : _ptr(other._ptr) 
			{
			}

			template <class Iter>
			const_tree_iterator& operator = (const Iter other)
			{
				//if(*this != other)
					this->_ptr = other.get_ptr();
				return *this;
			}

			const_tree_iterator	base() const {return this->_ptr->data;}

			node_pointer get_ptr() const {return this->_ptr;}
			//copy asignable constuctor+++++++++++++++++++++++++++++++++++
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//==========================
//Aux fuctions			
//==========================
		private :
			node_pointer minimum(node_pointer n)
			{
				node_pointer aux = n;

				while(aux->left->get_nill() != true)
					aux = aux->left;
				return aux;
			}

			node_pointer maximum(node_pointer n)
			{
				node_pointer aux = n;

				while(aux->right->get_nill() != true)
					aux = aux->right;
				return aux;
			}
//==========================
//operators
//==========================

		public:
			reference			operator * () const {return (this->_ptr->get_data());}
			pointer				operator -> () const {return &(this->_ptr->get_data());}

			const_tree_iterator& operator ++ ()
			{
    			if (this->_ptr->left->get_nill() != true)
      			{
       				this->_ptr = this->_ptr->left;

       				while (this->_ptr->right->get_nill() != true)
       					this->_ptr = this->_ptr->right;
   				}
   				else
   				{
       				node_pointer p = this->_ptr->prev;
       				while (p->get_nill() != true && this->_ptr == p->left)
       				{
          				this->_ptr = p;
           				p = p->prev;
       				}
       				this->_ptr = p;
				}
  				return *this;
			}

			const_tree_iterator operator ++ (int)
			{
				const_tree_iterator	tmp = *this;

    			if (this->_ptr->left->get_nill() != true)
      			{
       				this->_ptr = this->_ptr->left;

       				while (this->_ptr->right->get_nill() != true)
       					this->_ptr = this->_ptr->right;
   				}
   				else
   				{
       				node_pointer p = this->_ptr->prev;
       				while (p->get_nill() != true && this->_ptr == p->left)
       				{
          				this->_ptr = p;
           				p = p->prev;
       				}
       				this->_ptr = p;
				}
				return tmp;
			}

			const_tree_iterator& operator -- ()
			{
    			if (this->_ptr->right->get_nill() != true)
      			{
       				this->_ptr = this->_ptr->right;

       				while (this->_ptr->left->get_nill() != true)
       					this->_ptr = this->_ptr->left;
   				}
   				else
   				{
       				node_pointer p = this->_ptr->prev;
       				while (p->get_nill() != true && this->_ptr == p->right)
       				{
          				this->_ptr = p;
           				p = p->prev;
       				}
       				this->_ptr = p;
				}
  				return *this;
			}

			const_tree_iterator operator -- (int)
			{
				const_tree_iterator	tmp = *this;

    			if (this->_ptr->right->get_nill() != true)
      			{
       				this->_ptr = this->_ptr->right;

       				while (this->_ptr->left->get_nill() != true)
       					this->_ptr = this->_ptr->left;
   				}
   				else
   				{
       				node_pointer p = this->_ptr->prev;
       				while (p->get_nill() != true && this->_ptr == p->right)
       				{
          				this->_ptr = p;
           				p = p->prev;
       				}
       				this->_ptr = p;
				}
				return tmp;
			}

			bool	operator == (const_tree_iterator &b) 
			{
				return this->get_ptr() == b.get_ptr();
			}

			bool	operator != (const_tree_iterator &b) 
			{
				return this->get_ptr() != b.get_ptr();
			}

			bool	operator == (const const_tree_iterator &b) const 
			{
				return this->get_ptr() == b.get_ptr();
			}

			bool	operator != (const const_tree_iterator &b) const 
			{
				return this->get_ptr() != b.get_ptr();
			}

	};//end const_tree_iterator class

//===================================
//No member functions
//===================================

} //end namespace ft

#endif
