/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:50:07 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/06 09:50:39 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UITILS_HPP
# define UITILS_HPP

#include "iterator_trails.hpp"
#include <iostream>

namespace ft
{
	template<class Iter>
	typename ft::iterator_trails<Iter>::difference_type	dist(Iter it1, Iter it2)
	{
		typename ft::iterator_trails<Iter>::difference_type	i = 0;
		while (it1 != it2)
		{
			it1++;
			i++;
		}
		return i;
	}
} //end namespace ft

#endif
