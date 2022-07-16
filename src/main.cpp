/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/16 15:11:25 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "tree.hpp"
#include "map.hpp"
#include "pair.hpp"
#include "tree_iterator.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>


#define TESTED_TYPE int
#define TEST ft

int		main(void)
{
	ft::map<int, int>	mapa;

	mapa[2] = 20;

	std::cout << mapa[2] << std::endl;
	mapa[2] = 22;
	std::cout << mapa[2] << std::endl;

/*
	for(int i = 0; i < 10; i++)
		mapa.insert(ft::make_pair(i, i * 10));

	ft::map<int, int>::iterator	itb, ite;
	itb = mapa.begin();
	ite = mapa.end();
	itb.get_ptr()->print_pointer();
	itb++;
	itb.get_ptr()->print_pointer();
	itb++;
	itb.get_ptr()->print_pointer();
	itb++;
	itb.get_ptr()->print_pointer();
	std::cout << "==========================================\n";
	ite.get_ptr()->print_pointer();


	itb = mapa.begin();
	ite = mapa.end();
	while(itb != mapa.end())
	{
		itb.get_ptr()->print_pointer();
		itb++;
	}

	itb = mapa.begin();
	ft::map<int, int>	mapb(mapa);
	mapb.clear();
	std::cout << mapb.empty();
*/
}

