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

int		main(void)
{

	NS::vector<int>				va(10, 100);
	NS::vector<int>				vb(va);
	NS::vector<int>::iterator	vita = vb.begin();
	NS::vector<int>::iterator	vitb (vita);

	std::cout << *vita << " - " << *vitb << std::endl;
	vb[1] = 20;
	va[1] = 10;
	vita = va.begin();
	vita++;
	vitb++;
	std::cout << *vita << " - " << *vitb << std::endl;
	va.clear();
	vb.clear();
}

