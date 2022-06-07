/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/07 11:38:45 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
#include <string>

int	main (void)
{
	
	ft::vector<int> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (i + 65);

	vct.erase(vct.begin() + 2);
/*
	vct.erase(vct.begin());
	vct.erase(vct.end() - 1);

	vct.erase(vct.begin(), vct.begin() + 3);
	vct.erase(vct.end() - 3, vct.end() - 1);

	vct.push_back("Hello");
	vct.push_back("Hi there");
	vct.erase(vct.end() - 3, vct.end());

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	vct.erase(vct.begin(), vct.end());
*/
	return (0);
}
