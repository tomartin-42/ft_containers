/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramdom_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:04:37 by tomartin          #+#    #+#             */
/*   Updated: 2022/04/04 10:09:08 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_trails.hpp" 
#include "random_access_iterator.hpp"
#include "nullptr.hpp"// to ft::nullptr
#include <cstddef> // to ptrdiff_t

namespace ft
{
	template <class T>
	class reverse_iterator
	{
		public:
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::reference			reference;

		private:
			pointer	_ptr;
	
		public:
//==========================
//constructors
//==========================
			reverse_iterator() : _ptr(ft::nullptr_t) {}
			reverse_iterator(pointer ptr) : _ptr(ptr) {}
			
			reverse_iterator& operator = (const reverse_iterator& other)
			{
				if (this == &other)
					return *this;
				this->_ptr = other.get_ptr();
				return *this;
			}

			~reverse_iterator() {}

			pointer get_ptr() const {return this->_ptr;}

//==========================
//operators
//==========================

			reference	operator * () const {return *(this->_ptr);}
			pointer		operator -> () const {return this->_ptr;}

			reference	operator [] (difference_type i)
			{
				return *(this->_ptr + i);
			}

			reverse_iterator	operator ++ (int)
			{
				reverse_iterator	tmp;
				tmp = *this;
				--(this->_ptr);
				return tmp;
			}

			reverse_iterator&	operator ++ ()
			{
				--(this->_ptr);
				return *this;
			}

			reverse_iterator	operator -- (int)
			{
				reverse_iterator	tmp;
				tmp = *this;
				++(this->_ptr);
				return tmp;
			}

			reverse_iterator&	operator -- ()
			{
				++(this->_ptr);
				return *this;
			}

			reverse_iterator	operator + (difference_type i) const
			{
				reverse_iterator	aux(this->_ptr - i);
				return aux;
			}

			reverse_iterator	operator - (difference_type i) const
			{
				reverse_iterator	aux(this->_ptr + i);
				return aux;
			}

			reverse_iterator&	operator += (difference_type i)
			{
				this->_ptr -= i;
				return (*this);
			}

			reverse_iterator&	operator -= (difference_type i)
			{
				this->_ptr += i;
				return (*this);
			}
	}; //end reverse_iterator class

//===================================
//No member functions (compair operators)
//===================================

	template <typename T, typename V>
	bool	operator == (reverse_iterator<T>& left, reverse_iterator<V>& rigth) 
	{
		return left.get_ptr() == rigth.get_ptr();
	}

	template <typename T, typename V>
	bool	operator != (reverse_iterator<T>& left, reverse_iterator<V>& rigth) 
	{
		return !(left.get_ptr() == rigth.get_ptr());
	}

	template <typename T, typename V>
	bool	operator < (reverse_iterator<T>& left, reverse_iterator<V>& rigth) 
	{
		return left.get_ptr() < rigth.get_ptr();
	}

	template <typename T, typename V>
	bool	operator > (reverse_iterator<T>& left, reverse_iterator<V>& rigth)
	{
		return left.get_ptr() > rigth.get_ptr();
	}

	template <typename T, typename V>
	bool	operator <= (reverse_iterator<T>& left, reverse_iterator<V>& rigth) 
	{
		return !(left.get_ptr() > rigth.get_ptr());
	}

	template <typename T, typename V>
	bool	operator >= (reverse_iterator<T>& left, reverse_iterator<V>& rigth)
	{
		return !(left.get_ptr() < rigth.get_ptr());
	}

//====================================
//Overload n + it and n - it because can not implement as member function
//====================================
	template <typename T>
	reverse_iterator<T> operator + (typename ft::reverse_iterator<T>::difference_type i, reverse_iterator<T> it)
	{
		reverse_iterator<T>	aux;
		aux = it - i;
		return aux;
	}

	template <typename T>
	reverse_iterator<T> operator - (typename ft::reverse_iterator<T>::difference_type i, reverse_iterator<T> it)
	{
		reverse_iterator<T>	aux;
		aux = it + i;
		return aux;
	}
} //end ft namespace

#endif
