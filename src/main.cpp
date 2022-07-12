/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/11 11:46:55 by tomartin         ###   ########.fr       */
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
	ft::map<int, int>	mapb(mapa);
	ft::map<int, int>::iterator	it;
	mapa.insert(ft::make_pair(1, 10));
	it = mapa.begin();
	std::cout << it->first << " " << it->second << std::endl;
//	ft::map<int, int>::iterator it;
//	mapa.insert(ft::make_pair(1, 2));
//	ft::map<int, int>::iterator it = mapa.begin();
//	ft::cout << it.base().first << it.base().second << ft::endl;
//	ft::map<int, int>::reverse_iterator rit = mapa.rbegin();
//	if(it == rit.base())
//		ft::cout << "LO LOGRE\n";
//	ft::map<int, int>::iterator	vita, vitb;

/*
	mapa.insert(ft::make_pair(3, 8));
	mapa.insert(ft::make_pair(5, 8));
	mapa.insert(ft::make_pair(8, 8));
	mapa.insert(ft::make_pair(1, 8));
	mapa.insert(ft::make_pair(6, 8));
	mapa.insert(ft::make_pair(2, 8));
	mapa.insert(ft::make_pair(0, 7));
	mapa.insert(ft::make_pair(4, 8));
	mapa.insert(ft::make_pair(7, 8));

	mapa.insert(ft::make_pair(0, 8));
	mapa.insert(ft::make_pair(1, 8));
	mapa.insert(ft::make_pair(2, 8));
	mapa.insert(ft::make_pair(3, 8));
	mapa.insert(ft::make_pair(4, 8));
	mapa.insert(ft::make_pair(5, 8));
	mapa.insert(ft::make_pair(6, 7));
	mapa.insert(ft::make_pair(7, 8));
	mapa.insert(ft::make_pair(8, 8));
	mapa[9] = 9;
//	mapa.insert(ft::make_pair(2, 3));
	mapa.print();
//	ft::cout << it->first << "-" << it->second << ft::endl;
//	ft::cout << "SIZE= " << mapa.size() << ft::endl;
	vita = mapa.begin();
	vitb = mapa.end();
	ft::map<int, int>	mapb(vita, vitb);
	mapb.print();
	mapa.erase(9);
	mapa.print();
//	mapa.find(2);
//	mapa.find(3);

	ft::tree<int, ft::less<int> >	treea;
	ft::tree<int, ft::less<int> >::iterator	itt;
	ft::tree_iterator<ft::node<int> >	itb(itt);
	ft::tree_iterator<ft::node<int> >	itc = itb;

	itt = treea.begin();
	treea.insert(3);
	treea.insert(5);
	treea.insert(8);
	treea.insert(1);
	treea.insert(6);
	treea.insert(2);
	treea.insert(0);
	treea.insert(4);
	treea.insert(7);
	treea.printBT(); 
	treea.erase(7);
	treea.printBT(); 
	treea.erase(5);
	treea.printBT(); 
	*/
}
