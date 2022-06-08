/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:50:07 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/08 12:01:19 by tomartin         ###   ########.fr       */
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
			//std::cout << "X1\n" << *it1 << "-" << *it2 << std::endl;
			it1++;
			i++;
		}
		return i;
	}
} //end namespace ft

#endif
