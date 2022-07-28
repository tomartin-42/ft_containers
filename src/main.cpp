/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/28 12:40:43 by tomartin         ###   ########.fr       */
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
void	print_vector(T v, std::string name)
{
	typename T::iterator	it = v.begin();

	std::cout << "==================" << name << "===================" << std::endl;
	for(; it != v.end(); it++)
		std::cout << "vector = " << *it << std::endl;
	std::cout << "Size= " << v.size() << std::endl;
	std::cout << "Max Size= " << v.max_size() << std::endl;
	std::cout << "Capacity= " << v.capacity() << std::endl;
	std::cout << "Empty= " << v.empty() << std::endl;

	std::cout << "===========================================" << std::endl;
	std::cout << "\n\n\n";

}

template<class T>
void	print_stack(T st, std::string name)
{
	std::cout << "==================" << name << "===================" << std::endl;
	std::cout << "Size= " << st.size() << std::endl;
	std::cout << "Empty= " << st.empty() << std::endl;
	while(!st.empty())
	{
		std::cout << "stack = " << st.top() << std::endl;
		st.pop();
	}
	std::cout << "===========================================" << std::endl;
	std::cout << "\n\n\n";

}
template<class T>
void	print_map(T m, std::string name)
{
	typename T::iterator	it = m.begin();

	std::cout << "=================" << name << "=====================" << std::endl;
	for(; it != m.end(); it++)
		std::cout << "map = " << it->first << " - " << it->second << std::endl;
	std::cout << "Size= " << m.size() << std::endl;
	std::cout << "Max Size= " << m.max_size() << std::endl;
	std::cout << "Empty= " << m.empty() << std::endl;
	std::cout << "===========================================" << std::endl;
	std::cout << "\n\n\n";
}
int		main(void)
{
/*
//------------------------VECTOR--------------------------//
	std::cout << "=====================================================================================" << std::endl;
	std::cout << "VECTOR" << std::endl;
	std::cout << "=====================================================================================" << std::endl;
	NS::vector<int>						va(10, 100);
	NS::vector<int>						vb(va);
	NS::vector<int>						vc;
	NS::vector<int>						vd(++va.begin(), --(--va.end()));
	NS::vector<int>::iterator			vita = vb.begin();
	NS::vector<int>::reverse_iterator	rvita = vb.rbegin();

	std::cout << "Constructors-----------------------------------------------------" << std::endl;
	print_vector(va, "va");
	print_vector(vb, "vb");
	print_vector(vc, "vc");
	print_vector(vd, "vd");
	std::cout << "Reverse Iterator------------------------------------------------" << std::endl;
	rvita = va.rbegin();
	va[9] = 99;
	va[8] = 88;
	va[7] = 77;
	std::cout << "reverse va begin= " << *rvita << std::endl;
	rvita++;
	std::cout << "reverse va begin= " << *rvita << std::endl;
	rvita++;
	std::cout << "reverse va begin= " << *rvita << std::endl;
	rvita--;
	std::cout << "reverse va begin= " << *rvita << std::endl;
	std::cout << "\n\n\n";

	std::cout << "Assign-------------------------------------------------------" << std::endl;
	vita = va.begin();
	vc.assign(8, 800);
	print_vector(vc, "vc");	
	vb.assign(vd.begin(), vd.end());
	print_vector(vb, "vb");	

	std::cout << "Iterator----------------------------------------------------" << std::endl;
	NS::vector<int>::iterator	a, b, c;
	a = ++(++va.begin());
	b = ++(++(++(++(++va.begin()))));
	c = ++(++(++vc.begin()));
	vc.insert(c, a, b);
	print_vector(vc, "vc");	
	va.clear();

	std::cout << "Comparation-------------------------------------------------" << std::endl;
	va.push_back(*(vb.begin()));
	va.push_back(999);
	print_vector(va, "va");	
	bool x = va[0] == vc[0];
	bool y = va[0] < vc[0];
	bool z = va[0] > vc[0];
	std::cout << "va[0] == vc[0] " << x << std::endl;
	std::cout << "va[0] < vc[0] " << y << std::endl;
	std::cout << "va[0] > vc[0] " << z << std::endl;

	std::cout << "At, Fron and Back----------------------------------------------------" << std::endl;
	std::cout << "va.at(0) " << va.at(0) << std::endl;
	std::cout << "va.at(1) " << va.at(1) << std::endl;
	std::cout << "va.front " << va.front() << std::endl;
	std::cout << "va.back " << va.back() << std::endl;
	std::cout << "vb.front " << vb.front() << std::endl;
	std::cout << "vb.back " << vb.back() << std::endl;
	std::cout << "\n\n\n";
	print_vector(vb, "vb");
	vb.assign(9, 99);
	print_vector(vb, "vb");
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

	std::cout << "Insert--------------------------------------------------------" << std::endl;
	va.insert(b, 555);
	print_vector(va, "va");
	va.insert(va.begin(), 3, 666);
	print_vector(va, "va");
	b = vc.begin() + 3;
	va.insert(va.end(), a, b);
	print_vector(va, "va");
	b = va.begin() + 3;
	va.erase(b);
	print_vector(va, "va");
	va.erase(++b, va.end());
	print_vector(va, "va");

	std::cout << "Reserve, Swap and Clear---------------------------------------------------" << std::endl;
	vd.reserve(2);
	print_vector(vd, "vd");
	va.swap(vd);
	print_vector(va, "va");
	print_vector(vd, "vd");
	va.clear();
	print_vector(va, "va");

	//performance test--------------------------------------
	NS::vector<int>	per;
	for(int i = 0; i < 10000; i++)
	{
		per.push_back(i * 10);
	}
	for(int i = 0; i < 9999; i++)
		per.pop_back();
	per.clear();
	
//------------------------STACK--------------------------//

	std::cout << "=====================================================================================" << std::endl;
	std::cout << "STACK" << std::endl;
	std::cout << "=====================================================================================" << std::endl;
	NS::stack<char>	sta;

	std::cout << "Constructor--------------------------------------------------------" << std::endl;
	for(int i = 0; i < 20; i++)
		sta.push('A');
	print_stack(sta, "sta");
	sta.push('B');

	std::cout << "Top--------------------------------------------------------------" << std::endl;
	std::cout << "top " << sta.top() << std::endl;
	print_stack(sta, "sta");

	std::cout << "Pop and Top----------------------------------------------------------" << std::endl;
	while(!sta.empty())
	{
		std::cout << "top " << sta.top() << std::endl;
		sta.pop();
	}
	print_stack(sta, "sta");
	//performance test--------------------------------------
	for(int i = 0; i < 10000; i++)
		sta.push('X');
	while(!sta.empty())
		sta.pop();
//------------------------MAP--------------------------//

	std::cout << "=====================================================================================" << std::endl;
	std::cout << "MAP" << std::endl;
	std::cout << "=====================================================================================" << std::endl;

*/
	NS::map<int, int>	mapa;

	for(int i = 0; i < 3; i++)
		mapa.insert(NS::make_pair(i, (i * 10) + 1));
	mapa.print();
	mapa.clear();	
	mapa.print();
//	mapa.print();
/*	
	
	
	NS::map<int, int>	mapa;
	for(int i = 0; i < 15; i++)
		mapa.insert(NS::make_pair(i, i * 5));
	NS::map<int, int>	mapb(++mapa.begin(), --mapa.end());
	NS::map<int, int>	mapc(mapb);
	NS::map<int, int>	mapd;
	mapd = mapa;

	std::cout << "Constructors--------------------------------------------------------" << std::endl;
	print_map(mapa, "mapa");
	print_map(mapb, "mapb");
	print_map(mapc, "mapc");
	print_map(mapd, "mapc");

	std::cout << "Iterators--------------------------------------------------------" << std::endl;
	NS::map<int, int>::iterator mapit;
	NS::map<int, int>::reverse_iterator maprit;
	mapit = mapa.begin();
	std::cout << "mapa it " << mapit->first << " - " << mapit->second << std::endl;
	mapit++;
	std::cout << "mapa it " << mapit->first << " - " << mapit->second << std::endl;
	mapit++;
	std::cout << "mapa it " << mapit->first << " - " << mapit->second << std::endl;
	mapit++;
	std::cout << "mapa it " << mapit->first << " - " << mapit->second << std::endl;
	mapit++;
	std::cout << "mapa it " << mapit->first << " - " << mapit->second << std::endl;
	mapit++;
	std::cout << "mapa it " << mapit->first << " - " << mapit->second << std::endl;
	mapit--;
	std::cout << "mapa it " << mapit->first << " - " << mapit->second << std::endl;
	mapit--;
	std::cout << "mapa it " << mapit->first << " - " << mapit->second << std::endl;
	maprit = mapa.rbegin();

	std::cout << "Reverse Iterators--------------------------------------------------------" << std::endl;
	std::cout << "mapa it " << maprit->first << " - " << maprit->second << std::endl;
	maprit++;
	std::cout << "mapa it " << maprit->first << " - " << maprit->second << std::endl;
	maprit++;
	std::cout << "mapa it " << maprit->first << " - " << maprit->second << std::endl;
	maprit++;
	std::cout << "mapa it " << maprit->first << " - " << maprit->second << std::endl;
	maprit++;
	std::cout << "mapa it " << maprit->first << " - " << maprit->second << std::endl;
	maprit--;
	std::cout << "mapa it " << maprit->first << " - " << maprit->second << std::endl;
	maprit--;

	std::cout << "Operator []--------------------------------------------------------" << std::endl;
	mapa[0] = 555;
	print_map(mapa, "mapa");
	mapa[100] = 999;
	print_map(mapa, "mapa");

	std::cout << "Insert and Pair--------------------------------------------------------" << std::endl;
	mapb.insert(ft::make_pair(55, 555));
	mapb.insert(ft::make_pair(66, 666));
	mapb.insert(ft::make_pair(77, 777));
	print_map(mapb, "mapb");
	mapit = mapb.find(66);
	mapb.insert(mapit, ft::make_pair(88, 888));
	print_map(mapb, "mapb");
	//mapa.clear();
	for(int i = 100; i < 110; i++)
		mapa.insert(NS::make_pair(i, i * 10));
	mapb.insert(mapa.begin(), mapa.end());
	print_map(mapb, "mapb");
*/
//	system("leaks ft_container");

}

