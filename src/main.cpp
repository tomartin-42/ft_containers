/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/17 16:45:43 by tomartin         ###   ########.fr       */
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

	for(int i = 0; i < 42; i++) 
		mapa[i] = i*10;
	ft::map<int, int>::iterator it;

	it = --(mapa.end());
	--it;
	std::cout << it->first << " = " << it->second << std::endl;
	for(;it != mapa.begin(); --it)
		std::cout << it->first << " = " << it->second << std::endl;


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

