/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramdom_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:04:37 by tomartin          #+#    #+#             */
/*   Updated: 2022/04/01 13:03:31 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_trails.hpp" 
#include "nullptr.hpp"// to ft::nullptr
#include <cstddef> // to ptrdiff_t

namespace ft
{
	template <class T>
	class random_access_iterator
	{
		public:
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::Iter<ft::random_access_iterator_tag, T>::reference				reference;

		private:
			pointer	_ptr;
	
		public:
//==========================
//constructors
//==========================
			random_access_iterator() : _ptr(ft::nullptr_t) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			
			random_access_iterator& operator = (const random_access_iterator& other)
			{
				if (this == &other)
					return *this;
				this->_ptr = other.get_ptr();
				return *this;
			}

			~random_access_iterator() {}

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

			random_access_iterator	operator ++ (int)
			{
				random_access_iterator	tmp;
				tmp = *this;
				++(this->_ptr);
				return tmp;
			}

			random_access_iterator&	operator ++ ()
			{
				++(this->_ptr);
				return *this;
			}

			random_access_iterator	operator -- (int)
			{
				random_access_iterator	tmp;
				tmp = *this;
				--(this->_ptr);
				return tmp;
			}

			random_access_iterator&	operator -- ()
			{
				--(this->_ptr);
				return *this;
			}

			random_access_iterator	operator + (difference_type i) const
			{
				random_access_iterator	aux(this->_ptr + i);
				return aux;
			}

			random_access_iterator	operator - (difference_type i) const
			{
				random_access_iterator	aux(this->_ptr - i);
				return aux;
			}

			random_access_iterator&	operator += (difference_type i)
			{
				this->_ptr += i;
				return (*this);
			}

			random_access_iterator&	operator -= (difference_type i)
			{
				this->_ptr -= i;
				return (*this);
			}
	}; //end random_access_iterator class

//===================================
//No member functions
//===================================

	template <typename T, typename V>
	bool	operator == (random_access_iterator<T>& left, random_access_iterator<V>& rigth) 
	{
		return left.get_ptr() == rigth.get_ptr();
	}

	template <typename T, typename V>
	bool	operator != (random_access_iterator<T>& left, random_access_iterator<V>& rigth) 
	{
		return !(left.get_ptr() == rigth.get_ptr());
	}

	template <typename T, typename V>
	bool	operator < (random_access_iterator<T>& left, random_access_iterator<V>& rigth) 
	{
		return left.get_ptr() < rigth.get_ptr();
	}

	template <typename T, typename V>
	bool	operator > (random_access_iterator<T>& left, random_access_iterator<V>& rigth)
	{
		return left.get_ptr() > rigth.get_ptr();
	}

	template <typename T, typename V>
	bool	operator <= (random_access_iterator<T>& left, random_access_iterator<V>& rigth) 
	{
		return !(left.get_ptr() > rigth.get_ptr());
	}

	template <typename T, typename V>
	bool	operator >= (random_access_iterator<T>& left, random_access_iterator<V>& rigth)
	{
		return !(left.get_ptr() < rigth.get_ptr());
	}

//====================================
//Overload n + it and n - it because can not implement as member function
//====================================
	template <typename T>
	random_access_iterator<T> operator + (typename ft::random_access_iterator<T>::difference_type i, random_access_iterator<T> it)
	{
		random_access_iterator<T>	aux;
		aux = it + i;
		return aux;
	}

	template <typename T>
	random_access_iterator<T> operator - (typename ft::random_access_iterator<T>::difference_type i, random_access_iterator<T> it)
	{
		random_access_iterator<T>	aux;
		aux = it - i;
		return aux;
	}
}

#endif
