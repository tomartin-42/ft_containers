/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:56 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/29 10:03:08 by tomartin         ###   ########.fr       */
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
			typedef ft::node<T>																	node;
			typedef node*																		node_pointer;
			typedef node&																		node_reference;
			typedef	value_type*																	pointer;
			typedef value_type&																	reference;

		public:
			node_pointer	_ptr;

		public:
			tree_iterator() : _ptr(ft::nullptr_t){}

			explicit tree_iterator(node_pointer ptr) : _ptr(ptr) {}

			tree_iterator(const tree_iterator& other) : _ptr(other._ptr) {}

			tree_iterator& operator = (const tree_iterator& other)
			{
				if(this->_ptr != other.get_ptr())
					this->_ptr = other.get_ptr();
				return *this;
			}

			node_pointer get_ptr() const {return this->_ptr;}

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

			tree_iterator& operator ++ ()
			{

				if(this->_ptr->get_nill() == true)
				{
					this->_ptr = this->_ptr->left;
					return *this;
				}
				if(this->_ptr->right->get_nill() != true)
				{
					this->_ptr = minimum(this->_ptr->right);
					return *this;
				}

				node_pointer y = this->_ptr->prev;
				while(y->get_nill() != true && this->_ptr == y->right)
				{
					this->_ptr = y;
					y = y->prev;
				}
				this->_ptr = y;
				return *this;
			}

			tree_iterator operator ++ (int)
			{
				tree_iterator	tmp = *this;

				this->operator ++ ();
				return tmp;
			}

			tree_iterator& operator -- ()
			{
				if(this->_ptr->get_nill() == true)
				{
					this->_ptr = this->_ptr->right;
					return *this;
				}
				if(this->_ptr->left->get_nill() != true)
				{
					this->_ptr = maximum(this->_ptr->left);
					return *this;
				}

				node_pointer y = this->_ptr->prev;
				while(y->get_nill() != true && this->_ptr == y->left)
				{
					this->_ptr = y;
					y = y->prev;
				}
				this->_ptr = y;
				return *this;
			}

			tree_iterator operator -- (int)
			{
				tree_iterator	tmp = *this;

				this->operator -- ();
				return tmp;
			}

			bool	operator == (tree_iterator &b) 
			{
				return this->get_ptr() == b.get_ptr();
			}

			bool	operator != (tree_iterator &b) 
			{
				return this->get_ptr() != b.get_ptr();
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

} //end namespace ft

#endif
