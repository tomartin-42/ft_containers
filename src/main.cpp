/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/25 15:56:00 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "tree.hpp"
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

	ft::tree<int, std::less<int> >	treea;
	ft::tree<int, std::less<int> >::iterator	itt;
	ft::tree_iterator<ft::node<int> >	itb(itt);
//	ft::tree_iterator<ft::node<int> >	itc = itb;

	itt = treea.begin();
	treea.insert(3);
	treea.printBT(); 
	treea.insert(5);
	treea.printBT(); 
	treea.insert(8);
	treea.printBT(); 
	treea.insert(1);
	treea.printBT(); 
	treea.insert(6);
	treea.printBT(); 
	treea.insert(2);
	treea.printBT(); 
	treea.insert(0);
	treea.printBT(); 
	treea.insert(4);
	treea.printBT(); 
	treea.insert(7);
	treea.printBT(); 

}
