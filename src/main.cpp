/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/23 19:17:40 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
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
#include <set>
#include <map>
#include <stack>
#include <string>

#define NS ft 

template<class T>
void	print_vector(T v)
{
	typename T::iterator	it = v.begin();

	std::cout << "===========================================" << std::endl;
	for(; it != v.end(); it++)
		std::cout << "vector = " << *it << std::endl;
	std::cout << "Size= " << v.size() << std::endl;

	std::cout << "===========================================" << std::endl;
}

int		main(void)
{

//------------------------VECTOR--------------------------//
	NS::vector<int>	per;
	for(int i = 0; i < 10000; i++)
	{
		per.push_back(i * 10);
	}
	for(int i = 0; i < 9999; i++)
		per.pop_back();
	per.clear();
	

//------------------------MAP--------------------------//
//	NS::map<int, int>	mapa;

//	mapa[1] = 100;
//	mapa[2] = 200;
//	mapa[3] = 300;

//	system("leaks ft_container");

}

