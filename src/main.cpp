/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/10 10:27:23 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
#include <string>

#define TESTED_TYPE int

int		main(void)
{
	ft::vector<TESTED_TYPE> vct(5);
	ft::vector<TESTED_TYPE> vct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	
	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);

	std::cout << "insert return:" << std::endl;

	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	return (0);
}
