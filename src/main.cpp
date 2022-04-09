/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/04/09 20:27:55 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>

int	main (void)
{
	ft::vector<int>	i;
	ft::vector<int>	j(80, 100);
	ft::vector<int> l;

	l = i;

	ft::random_access_iterator<int> it;
	ft::random_access_iterator<int> at;
	ft::vector<int>::reverse_iterator xx;

	it = j.begin();
	at = j.end();

	std::cout << "Size = " << j.size() << std::endl;
	std::cout << "Capacity = " << j.capacity() << std::endl;
	j.reserve(100);
	std::cout << "Capacity post= " << j.capacity() << std::endl;

    at--;
    
	//ft::vector<int> x(it, at);
	//x.resize(2); 
    ft::random_access_iterator<int> ax;
    ft::random_access_iterator<int> bx;
    //ax = x.begin();
    //bx = x.end();
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
