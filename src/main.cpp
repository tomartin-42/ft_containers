/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:23:12 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/11 19:04:58 by tomartin         ###   ########.fr       */
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
	ft::vector<TESTED_TYPE> vct(10);
	ft::vector<TESTED_TYPE> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);

	vct2.insert(vct2.end() - 2, 42);

	vct2.insert(vct2.end(), 2, 84);

	vct2.resize(4);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();

	return (0);
}
