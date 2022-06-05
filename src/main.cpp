/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/05 20:43:12 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>

int	main (void)
{
	ft::vector<int>	i(4);
	ft::vector<int>	j(7);
	ft::vector<int>	k;
	ft::vector<int>	l;

	for(unsigned long int x = 0; x < i.size(); ++x)
		i[x] = (i.size() - x) * 3;
	std::cout << i[0] << std::endl;
	std::cout << i[1] << std::endl;
	std::cout << i[2] << std::endl;
	std::cout << i[3] << std::endl;

	k.assign(2, 42);

	return 0;
}
