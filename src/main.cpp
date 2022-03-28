/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/03/28 13:52:10 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "random_access_iterator.hpp"

int	main (void)
{
	ft::vector<int>	i;
	ft::vector<int>	j(4, 100);
	ft::vector<int> l(j);

	ft::random_access_iterator<int*> it;
	ft::random_access_iterator<int*> at;
	it = at;
	return 0;
}

