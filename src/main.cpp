/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/11 19:43:43 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
#include <string>

#define TESTED_TYPE std::string
int		main(void)
{
	ft::vector<TESTED_TYPE> vct(8);
	ft::vector<TESTED_TYPE> vct2;
	ft::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (unsigned long int i = 0; i < vct.size(); ++i)
		it[i] = std::string((vct.size() - i), i + 65);

	std::cout << "push_back():\n" << std::endl;

	std::cout << "HOLA1\n";
	vct.push_back("One long string");
	std::cout << "HOLA2\n";
	vct2.push_back("Another long string");
	std::cout << "HOLA3\n";

	vct.pop_back();
	std::cout << "HOLA4\n";
	vct2.pop_back();
	std::cout << "HOLA5\n";

	return (0);
}
