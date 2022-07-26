/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/26 13:38:34 by tomartin         ###   ########.fr       */
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

template<class T>
void	print_map(T m)
{
	typename T::iterator	it = m.begin();

	std::cout << "===========================================" << std::endl;
	for(; it != m.end(); it++)
		std::cout << "map = " << it->first << " - " << it->second << std::endl;
	std::cout << "Size= " << m.size() << std::endl;

	std::cout << "===========================================" << std::endl;
}
int		main(void)
{

//------------------------VECTOR--------------------------//
	NS::vector<int>				va(10, 100);
	NS::vector<int>				vb(va);
	NS::vector<int>				vc;
	NS::vector<int>::iterator	vita = vb.begin();

	vb[1] = 20;
	va[1] = 10;
	print_vector(va);
	print_vector(vb);
	vita = va.begin();
	vc.assign(8, 800);
	print_vector(vc);	
	NS::vector<int>::iterator	a, b, c;
	a = ++(++va.begin());
	b = ++(++(++(++(++va.begin()))));
	c = ++(++(++vc.begin()));
	vc.insert(c, a, b);
	print_vector(vc);	
	va.clear();
	va.push_back(*(vb.begin()));
	va.push_back(999);
	print_vector(va);	
	bool x = va[0] == vc[0];
	bool y = va[0] < vc[0];
	bool z = va[0] > vc[0];
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
	a = vc.begin();
	b = vc.end();
	b--;
	b--;
	b--;
	b--;
	va.clear();
	va.assign(a, b);
	b = va.begin();
	b++;
	b++;
	b++;
	va.insert(b, 555);
	print_vector(va);
	b = va.begin() + 3;
	va.erase(b);
	b = va.begin() + 3;
	va.erase(b);
	print_vector(va);
	NS::vector<int>	per;
	for(int i = 0; i < 10000; i++)
	{
		per.push_back(i * 10);
	}
	for(int i = 0; i < 9999; i++)
		per.pop_back();
	per.clear();
	
//------------------------STACK--------------------------//

	





//------------------------MAP--------------------------//
	NS::map<int, int>	mapa;

	for(int i = 0; i < 15; i++)
		mapa.insert(NS::make_pair(i, i * 5));
	mapa.print();
	mapa.erase(5);
	mapa.erase(4);
	mapa.erase(13);
	mapa.print();
	mapa.clear();
//	mapa[1] = 100;
//	mapa[2] = 200;
//	mapa[3] = 300;

//	system("leaks ft_container");

}

