/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/20 13:04:31 by tomartin         ###   ########.fr       */
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

	ft::node<int>	alfa;
	ft::tree<ft::node<int>, std::less<int> >	treea;
	ft::tree<ft::node<int>, std::less<int> >::iterator	itt;
	ft::tree_iterator<ft::node<int> >	itb(itt);
	ft::tree_iterator<ft::node<int> >	itc = itb;

	std::cout << itt.get_ptr() << std::endl;
	std::cout << itb.get_ptr() << std::endl;

	if(itt != itb)
		std::cout << "!=\n";
	if(itt == itb)
		std::cout << "==\n";

	const int size = 5;
	TEST::vector<TESTED_TYPE> vct(size);
	TEST::vector<TESTED_TYPE>::reverse_iterator it_0(vct.rbegin());
	TEST::vector<TESTED_TYPE>::reverse_iterator it_1(vct.rend());
	TEST::vector<TESTED_TYPE>::reverse_iterator it_mid;

	TEST::vector<TESTED_TYPE>::const_reverse_iterator cit_0 = vct.rbegin();
	TEST::vector<TESTED_TYPE>::const_reverse_iterator cit_1;
	TEST::vector<TESTED_TYPE>::const_reverse_iterator cit_mid;

	for (int i = size; it_0 != it_1; --i)
	{
		*it_0++ = i;
		std::cout << "it_0 = " << *(it_0 - 1)<< std::endl;
	}

	//printSize(vct, 1);
	it_0 = vct.rbegin();
	cit_1 = vct.rend();
	it_mid = it_0 + 3;
	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

	std::cout << std::boolalpha;
	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	std::cout << "\t\tft_eq_ope:" << std::endl;
	std::cout << "*****regular it\n";
//	ft_eq_ope(it_0 + 3, it_mid);
	ft_eq_ope(it_0, it_1);
//	ft_eq_ope(it_1 - 3, it_mid);
//	std::cout << "*****const it\n";
//	ft_eq_ope(cit_0 + 3, cit_mid);
//	ft_eq_ope(cit_0, cit_1);
//	ft_eq_ope(cit_1 - 3, cit_mid);
//	std::cout << "*****both it\n";
//	ft_eq_ope(it_0 + 3, cit_mid);
//	ft_eq_ope(it_mid, cit_0 + 3);
//	ft_eq_ope(it_0, cit_1);
//	ft_eq_ope(it_1, cit_0);
//	ft_eq_ope(it_1 - 3, cit_mid);
//	ft_eq_ope(it_mid, cit_1 - 3);

	return (0);
}
