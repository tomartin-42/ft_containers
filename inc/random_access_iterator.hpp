/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramdom_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:04:37 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/09 13:31:00 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp" 
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
			//typedef typename ft::Iter<ft::random_access_iterator_tag, T>::pointer				pointer;
			//typedef typename ft::Iter<ft::random_access_iterator_tag, T>::reference				reference;
			typedef T*		pointer;
			typedef T&		reference;

		private:
			pointer	_ptr;
	
		public:
//==========================
//constructors
//==========================
			random_access_iterator() : _ptr(ft::nullptr_t) {}

			random_access_iterator(pointer ptr) : _ptr(ptr) {}

			template <class U>
			random_access_iterator(const random_access_iterator<U> &other) : _ptr(other.base()) {}

			random_access_iterator& operator = (const random_access_iterator& other)
			{
				if (this == &other)
					return *this;
				_ptr = other.base();
				return *this;
			}

			~random_access_iterator() {}

			pointer base() const 
			{
				return this->_ptr;
			}

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
				return (this->_ptr + i);
			}

			random_access_iterator	operator - (difference_type i) const
			{
				return (this->_ptr - i);
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

			bool	operator == (const random_access_iterator &b) const {return this->_ptr == b._ptr;}
			bool	operator != (const random_access_iterator &b) const {return this->_ptr != b._ptr;}
	}; //end random_access_iterator class

//===================================
//No member functions
//===================================

	template <typename T, typename V>
	bool	operator == (random_access_iterator<T>& left, random_access_iterator<V>& rigth) 
	{
		return left.base() == rigth.base();
	}

	template <typename T, typename V>
	bool	operator != (random_access_iterator<T> & left, random_access_iterator<V> & rigth) 
	{
		return !(left.base() == rigth.base());
	}

	template <typename T, typename V>
	bool	operator < (random_access_iterator<T>& left, random_access_iterator<V>& rigth) 
	{
		return left.base() < rigth.base();
	}

	template <typename T, typename V>
	bool	operator > (random_access_iterator<T>& left, random_access_iterator<V>& rigth)
	{
		return left.base() > rigth.base();
	}

	template <typename T, typename V>
	bool	operator <= (random_access_iterator<T>& left, random_access_iterator<V>& rigth) 
	{
		return !(left.base() > rigth.base());
	}

	template <typename T, typename V>
	bool	operator >= (random_access_iterator<T>& left, random_access_iterator<V>& rigth)
	{
		return !(left.base() < rigth.base());
	}

//====================================
//Overload n + it and n - it because can not implement as member function
//====================================
	template <typename T>
	random_access_iterator<T> operator + (typename ft::random_access_iterator<T>::difference_type i, random_access_iterator<T> it)
	{
		random_access_iterator<T> aux;
		aux = *it + i;
		return (aux);
	}

	template <typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type operator + (const ft::random_access_iterator<T> itf, const ft::random_access_iterator<U> itl)
	{
		return (itf.base() + itl.base());
	}

	template <typename T>
	random_access_iterator<T> operator - (typename ft::random_access_iterator<T>::difference_type i, random_access_iterator<T> it)
	{
		return (it - i);
	}
	
	template <typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type operator - (const ft::random_access_iterator<T> itf, const ft::random_access_iterator<U> itl)
	{
		return (itf.base() - itl.base());
	}
}

#endif
