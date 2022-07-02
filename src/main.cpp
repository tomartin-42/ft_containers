/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/01 11:19:47 by tomartin         ###   ########.fr       */
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
#include <string>


#define TESTED_TYPE int
#define TEST ft


template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)

{
	std::cout << "*************************\n";
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
	//	ft_eq_ope(second, first, 0);
	std::cout << "*************************\n";
}

int		main(void)
{
	ft::map<int, int>	mapa;
	ft::map<int, int>::iterator it;
	ft::map<int, int>::iterator	vita, vitb;


	mapa.insert(ft::make_pair(3, 8));
	mapa.insert(ft::make_pair(5, 8));
	mapa.insert(ft::make_pair(8, 8));
	mapa.insert(ft::make_pair(1, 8));
	vita = mapa.begin();
	mapa.insert(ft::make_pair(6, 8));
	mapa.insert(ft::make_pair(2, 8));
	mapa.insert(ft::make_pair(0, 7));
	mapa.insert(ft::make_pair(4, 8));
	mapa.insert(ft::make_pair(7, 8));
	mapa.insert(ft::make_pair(8, 8));
	mapa.insert(ft::make_pair(8, 8));
	mapa.insert(ft::make_pair(8, 8));
//	mapa.insert(ft::make_pair(2, 3));
	mapa.print();
//	std::cout << it->first << "-" << it->second << std::endl;
//	std::cout << "SIZE= " << mapa.size() << std::endl;
//	vita = mapa.begin();
	vitb = mapa.end();
	ft::map<int, int>	mapb(vita, vitb);
	mapb.print();
//	mapa.find(2);
//	mapa.find(3);
/*
	ft::tree<int, std::less<int> >	treea;
	ft::tree<int, std::less<int> >::iterator	itt;
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
