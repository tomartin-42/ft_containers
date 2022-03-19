/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:19:06 by tomartin          #+#    #+#             */
/*   Updated: 2022/02/28 11:46:17 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <iostream>

int main(void)
{
	stack<int>	num;

	std::cout << "empy = " << num.empty() << std::endl;

	for(int i = 0; i < 10; i++)
	{
		num.push(i);
		std::cout << "top = " << num.top() << std::endl;
	}
	std::cout << "size = " << num.size() << std::endl;
	std::cout << "top = " << num.top() << std::endl;
	num.pop();
	std::cout << "POP" << std::endl;
	std::cout << "size = " << num.size() << std::endl;
	std::cout << "top = " << num.top() << std::endl;
	stack<int> other(num);
	for (; !other.empty(); )
	{
		std::cout << "other.top = " << other.top() << std::endl;
		other.pop();
	}
}
