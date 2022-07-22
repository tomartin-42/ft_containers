/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:56 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/20 08:58:11 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONST_TREE_ITERATOR_HPP_
# define _CONST_TREE_ITERATOR_HPP_

#include "iterator_traits.hpp"
#include "tree_iterator.hpp"
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
			typedef const ft::node<T>																	node;
			typedef node*																		node_pointer;
			typedef node&																		node_reference;
			typedef	const value_type*																	pointer;
			typedef const value_type&																	reference;

		private:
			node_pointer	_ptr;

		public:
			const_tree_iterator() : _ptr(ft::nullptr_t){}

			explicit const_tree_iterator(node_pointer ptr) : _ptr(ptr) {}

			const_tree_iterator(const const_tree_iterator& other) : _ptr(other._ptr) {}
			
			template<class I>	
			const_tree_iterator(const tree_iterator<I>& other)
				: _ptr(other._ptr) {}

			template <class Iter>
			const_tree_iterator& operator = (const Iter other)
			{
				if(*this != other)
					this->_ptr = other.get_ptr();
				return *this;
			}

			node_pointer get_ptr() const {return this->_ptr;}

			//-----------------------------destructor
			~const_tree_iterator() {}
//==========================
//Aux fuctions			
//==========================
		private :
			node_pointer minimum(node_pointer n)
			{
				node_pointer aux = n;

				while(aux->right->get_nill() != true)
					aux = aux->right;
				return aux;
			}

			node_pointer maximum(node_pointer n)
			{
				node_pointer aux = n;

				while(aux->left->get_nill() != true)
					aux = aux->left;
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
				if(this->_ptr->get_nill() == true)
				{
					this->_ptr = this->_ptr->right;
					return *this;
				}
				if(this->_ptr->left->get_nill() != true)
				{
					this->_ptr = minimum(this->_ptr->left);
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

			const_tree_iterator operator ++ (int)
			{
				const_tree_iterator	tmp = *this;

				this->operator ++ ();
				return tmp;
			}

			const_tree_iterator& operator -- ()
			{
				if(this->_ptr->get_nill() == true)
				{
					this->_ptr = this->_ptr->left;
					return *this;
				}
				if(this->_ptr->right->get_nill() != true)
				{
					this->_ptr = maximum(this->_ptr->right);
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

			const_tree_iterator operator -- (int)
			{
				const_tree_iterator	tmp = *this;

				this->operator -- ();
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

} //end namespace ft

#endif
