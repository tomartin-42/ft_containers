/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/04/03 13:34:55 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>

int	main (void)
{
	ft::vector<int>	i;
	ft::vector<int>	j(4, 100);
	ft::vector<int> l;

	l = i;

	ft::random_access_iterator<int> it;
	ft::random_access_iterator<int> at;

	it = j.begin();
	at = j.end();

    at--;
    at--;
    at--;
    
	ft::vector<int> x(it, at);
    ft::random_access_iterator<int> ax;
    ft::random_access_iterator<int> bx;
    ax = x.begin();
    bx = x.end();
    while (ax != bx)
    {
      std::cout << " ax(iterator) " << *ax << "\n";
      ax++;
    }
	bool a;

	a = (it == at);

	std::cout << "it == at ->" << a << std::endl;

	return 0;
}
