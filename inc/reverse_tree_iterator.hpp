/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:56 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/05 13:11:15 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REVERSE_TREE_ITERATOR_HPP_
# define _REVERSE_TREE_ITERATOR_HPP_

#include "iterator_traits.hpp"
#include "tree_iterator.hpp"
#include "nullptr.hpp"// to ft::nullptr
#include "node.hpp"// to ft::nullptr
#include <iostream>

namespace ft
{
	template<class Iter>
	class reverse_tree_iterator
	{
		public:
			typedef typename Iter::iterator_category	iterator_category;
			typedef typename Iter::value_type		value_type;
			typedef typename Iter::difference_type	difference_type;
			typedef typename Iter::pointer	pointer;
			typedef typename Iter::reference	reference;
			//typedef typename Iter::value	pair;
			typedef typename Iter::value_reference	value_reference;
			typedef typename Iter::value_pointer	value_pointer;
			/*
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;
			typedef typename ft::iterator_traits<Iter>::value_reference		value_reference;
			typedef typename ft::iterator_traits<Iter>::value_pointer		value_pointer;
*/
		private:
			pointer	_ptr;

		public:
			reverse_tree_iterator() : _ptr(ft::nullptr_t){}
			
			template<class Iterator>
			explicit reverse_tree_iterator(const Iterator& I) : _ptr(I.get_ptr()) {}

			explicit reverse_tree_iterator(pointer ptr) : _ptr(ptr) {}

			reverse_tree_iterator(const reverse_tree_iterator& other) : _ptr(other.get_ptr()) {}

			reverse_tree_iterator& operator = (const reverse_tree_iterator& other)
			{
				if(this != &other)
					this->_ptr = other.get_ptr();
				return *this;
			}

			//value_type base() const {return this->_ptr->get_data();}
			value_pointer base() const {return &this->_ptr->get_data();}

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
			value_reference		operator * () const {return (this->_ptr->get_data());}
			value_pointer		operator -> () const {return &(this->_ptr->get_data());}

			reverse_tree_iterator& operator ++ ()
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

			reverse_tree_iterator operator ++ (int)
			{
				reverse_tree_iterator	tmp = *this;

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

			reverse_tree_iterator& operator -- ()
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

			reverse_tree_iterator operator -- (int)
			{
				reverse_tree_iterator	tmp = *this;

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

			bool	operator == (reverse_tree_iterator &b) 
			{
				return this->get_ptr() == b.get_ptr();
			}

			bool	operator != (reverse_tree_iterator &b) 
			{
				return this->get_ptr() != b.get_ptr();
			}

			bool	operator == (const reverse_tree_iterator &b) const 
			{
				return this->get_ptr() == b.get_ptr();
			}

			bool	operator != (const reverse_tree_iterator &b) const 
			{
				return this->get_ptr() != b.get_ptr();
			}

	};//end reverse_tree_iterator class

} //end namespace ft

#endif
