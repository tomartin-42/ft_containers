/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:50:07 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/18 11:25:25 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UITILS_HPP
# define UITILS_HPP

#include "iterator_traits.hpp"
#include <iostream>

namespace ft
{
	template<class Iter>
	typename ft::iterator_traits<Iter>::difference_type	dist(Iter it1, Iter it2)
	{
		typename ft::iterator_traits<Iter>::difference_type	i = 0;

		while (it1 != it2)
		{
			it1++;
			i++;
		}
		return i;
	}

	template< class InputIterator_1, class InputIterator_2 >
	bool	equal(InputIterator_1 first1, InputIterator_1 last1, InputIterator_2 first2)
	{
		for (;first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2))
				return false;
		}
		return true;
	}

	template< class InputIterator_1, class InputIterator_2 >
	bool	low(InputIterator_1 first1, InputIterator_1 last1, InputIterator_2 first2)
	{
		for (;first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 < *first2))
				return false;
		}
		return true;
	}

	template< class InputIterator_1, class InputIterator_2 >
	bool	low_eq(InputIterator_1 first1, InputIterator_1 last1, InputIterator_2 first2)
	{
		for (;first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 <= *first2))
				return false;
		}
		return true;
	}

	template<class S>
	void	_swap(S& a, S& b)
	{
		S	aux;
		
		aux = a;
		a = b;
		b = aux;
	}

} //end namespace ft

#endif
