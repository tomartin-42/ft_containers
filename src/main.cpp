/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/14 11:05:08 by tomartin         ###   ########.fr       */
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

	for(int i = 0; i < 10; i++)
		mapa.insert(ft::make_pair(i, (i * 5)));

	ft::map<int, int>::iterator	it = mapa.begin();

	std::cout << it->first << " - " << it->second << " - " << &(*it) <<std::endl; 
	it++;
	std::cout << it->first << " - " << it->second << std::endl; 
	it++;
	std::cout << it->first << " - " << it->second << std::endl; 
	it++;
	std::cout << it->first << " - " << it->second << std::endl; 
	it++;
	std::cout << it->first << " - " << it->second << std::endl; 
	it++;
	std::cout << it->first << " - " << it->second << " - " << &(*it) <<std::endl; 
	it++;
	std::cout << it->first << " - " << it->second << std::endl; 
	it++;
	std::cout << it->first << " - " << it->second << std::endl; 
	it++;
	std::cout << it->first << " - " << it->second << std::endl; 
	it++;
	std::cout << it->first << " - " << it->second << " - " << &(*it) <<std::endl; 

	it = mapa.begin();
	while(it != mapa.end())
	{
		std::cout << it->first << " - " << it->second << std::endl; 
		it++;
	}
//	ft::map<int,int>	mapb(mapa);
//	it = mapb.begin();
//	while(it != mapb.end())
//	{
//		std::cout << it->first << " - " << it->second << std::endl; 
//		it++;
//	}


}
