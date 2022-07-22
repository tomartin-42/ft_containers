/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/22 08:24:13 by tomartin         ###   ########.fr       */
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
#include "set.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>


#define TESTED_TYPE int
#define TEST ft

int		main(void)
{
	ft::set<int>					mapa;
	ft::set<int>::iterator			it, it2;


	for(int i = 0; i < 10; i++)
		mapa.insert(i);
	it = mapa.begin();
	it2 = mapa.end();
	ft::set<int> mapb(it, it2);
	it = mapb.begin();
	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;
//	it++;
//	std::cout << it->first << std::endl;


/*
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

