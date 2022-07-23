/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:09:37 by npinto-g          #+#    #+#             */
/*   Updated: 2022/04/20 12:51:53 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"


int main(int argc, char **argv)
{
	argc ^= argc;

	std::string _namespace = NS_STRING;
	std::cout << _namespace << std::endl;
	test_vector(_namespace);
	test_stack(_namespace);
	test_map(_namespace);
	
	std::string leaks("leaks " + std::string(argv[0] + 2));
	std::cerr << leaks << std::endl;
	system(leaks.c_str());
	return 0;
}
