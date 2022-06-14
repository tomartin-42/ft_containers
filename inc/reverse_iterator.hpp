/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramdom_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:04:37 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/13 11:21:39 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp" 
#include "random_access_iterator.hpp"
#include "nullptr.hpp"// to ft::nullptr
#include <cstddef> // to ptrdiff_t

namespace ft
{
	template <class Iter>
	class reverse_iterator
	{
		public:
			typedef Iter													iterator;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;

		private:
			pointer	_ptr;
	
		public:
//==========================
//constructors
//==========================
			reverse_iterator() : _ptr(ft::nullptr_t) {}
			reverse_iterator(pointer ptr) : _ptr(ptr) {}
			reverse_iterator(iterator it) : _ptr(it.base()) {}

			template <class U>
			reverse_iterator(const reverse_iterator<U> &other) : _ptr(other.base()) {}
			
			reverse_iterator& operator = (const reverse_iterator& other)
			{
				if (this == &other)
					return *this;
				this->_ptr = other.base();
				return *this;
			}

			//~reverse_iterator() {}

			pointer base() const {return this->_ptr;}

//==========================
//operators
//==========================

			reference	operator * () const {return *(this->_ptr - 1);}
			
			pointer		operator -> () const {return this->_ptr - 1;}

			reference	operator [] (difference_type i)
			{
				return (this->base()[-i - 1]);
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
				return(this->_ptr - i);
				//reverse_iterator	aux(this->_ptr - i);
				//return aux;
			}

			reverse_iterator	operator - (difference_type i) const
			{
				return(this->_ptr + i);
				//reverse_iterator	aux(this->_ptr + i);
				//return aux;
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

			bool	operator == (const reverse_iterator &b) const {return this->_ptr == b._ptr;}
			bool	operator != (const reverse_iterator &b) const {return this->_ptr != b._ptr;}
	}; //end reverse_iterator class

//===================================
//No member functions (compair operators)
//===================================

	template <typename T, typename V>
	bool	operator == (const reverse_iterator<T>& left, const reverse_iterator<V>& rigth) 
	{
		return left.base() == rigth.base();
	}

	template <typename T, typename V>
	bool	operator != (const reverse_iterator<T>& left, const reverse_iterator<V>& rigth) 
	{
		return !(left.base() == rigth.base());
	}

	template <typename T, typename V>
	bool	operator < (const reverse_iterator<T>& left, const reverse_iterator<V>& rigth) 
	{
		return left.base() < rigth.base();
	}

	template <typename T, typename V>
	bool	operator > (const reverse_iterator<T>& left, const reverse_iterator<V>& rigth)
	{
		return left.base() > rigth.base();
	}

	template <typename T, typename V>
	bool	operator <= (const reverse_iterator<T>& left, const reverse_iterator<V>& rigth) 
	{
		return !(left.base() > rigth.base());
	}

	template <typename T, typename V>
	bool	operator >= (const reverse_iterator<T>& left, const reverse_iterator<V>& rigth)
	{
		return !(left.base() < rigth.base());
	}

//====================================
//Overload n + it and n - it because can not implement as member function
//====================================

	template <typename T, typename U>
	typename ft::reverse_iterator<T>::difference_type operator - (const ft::reverse_iterator<T> itf, const ft::reverse_iterator<U> itl)
	{
		return (itl.base() - itf.base());
	}

	template <typename T>
	reverse_iterator<T> operator - (typename ft::reverse_iterator<T>::difference_type i, reverse_iterator<T> it)
	{
		return (it - i);
	}

	template <typename T, typename U>
	typename ft::reverse_iterator<T>::difference_type operator + (const ft::reverse_iterator<T> itf, const ft::reverse_iterator<U> itl)
	{
		return (itf.base() + itl.base());
	}

	template <typename T>
	reverse_iterator<T> operator + (typename ft::reverse_iterator<T>::difference_type i, reverse_iterator<T> it)
	{
		return (it + i);
	}

	template <typename T>
	reverse_iterator<T> operator-(const reverse_iterator<T> &it, typename reverse_iterator<T>::difference_type &i)
	{
		return it.base() - i;
	}
} //end ft namespace

#endif
