/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/04/01 13:30:55 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>

int	main (void)
{
	ft::vector<int>	i;
	ft::vector<const int>	j(4, 100);
	ft::vector<int> l;

	l = i;

	ft::random_access_iterator<const int> it;
	ft::random_access_iterator<const int> at;

	it = j.begin();
	at = j.end();
	
	bool a;

	a = (it == at);

	std::cout << "it == at ->" << a << std::endl;

	return 0;
}
