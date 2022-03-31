/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/03/31 13:55:58 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>

int	main (void)
{
	ft::vector<int>	i;
	ft::vector<int>	j(4, 100);
	ft::vector<int> l(j);

	ft::random_access_iterator<int> it;
	ft::random_access_iterator<int> at;

	at = it;
	at++;
	++at;

//	it = 2 - at;
	it = at - 2;
	it = 2 + at;
	it += 2;
	it -= 3;

	bool a;
	a = it != at;
	std::cout << "it1 != it2 -> " << a << std::endl;
	
	return 0;
}
