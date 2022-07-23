/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:05:15 by npinto-g          #+#    #+#             */
/*   Updated: 2022/04/20 12:14:21 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <stack>
#include <vector>
#include <deque>
#include "stack.hpp"

void	test_stack(std::string n)
{
	putline("███████╗████████╗ █████╗  ██████╗██╗  ██╗");
	putline("██╔════╝╚══██╔══╝██╔══██╗██╔════╝██║ ██╔╝");
	putline("███████╗   ██║   ███████║██║     █████╔╝ ");
	putline("╚════██║   ██║   ██╔══██║██║     ██╔═██╗ ");
	putline("███████║   ██║   ██║  ██║╚██████╗██║  ██╗");
	putline("╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝");

	struct timeval	timer;                               
                                                             
	std::cout << "TESTING : " << n << "::stack" << std::endl;

	putline("#SIMPLE#");
	timer = set_timer();
	NAMESPACE::stack<int> simple;

	putaction("stack->empty()", simple.empty());
	putaction("stack->size()", simple.size());
	putline("pushing to stack");
	for (int i = 1; i < 5; ++i)
	{
		simple.push(i);
		std::cout << "pushed " << simple.top() << std::endl;
	}
	putaction("stack->empty()", simple.empty());
	putaction("stack->size()", simple.size());
	put_elapsed_time(timer);
	putline("-------------------------------------------------------------------");

	putline("#TRICKIER (push and pop, different inner container and relational operators)");

	timer = set_timer();
	NAMESPACE::stack<std::string, std::deque<std::string> > tricky;
	
	for (int i = 0; i < 1e5; ++i)
	{
		tricky.push(std::string(i % 13, (i % 26) + 'a'));
		std::cout << "pushed " << tricky.top() << std::endl;
	}
	while (!tricky.empty())
	{
   		std::cout << "popped " << tricky.top() << std::endl;;
    	tricky.pop();
	}
	
	NAMESPACE::stack<char>	foo;
	NAMESPACE::stack<char>	bar;

	for (size_t i = 0; i < 4; ++i)
	{
		foo.push('a' + (i % 3));
	}
	for (size_t i = 0; i < 6; ++i)
	{
		foo.push('A' + (i % 3));
	}
	if (foo==bar) std::cout << "\tfoo and bar are equal\n";
 	if (foo!=bar) std::cout << "\tfoo and bar are not equal\n";
	if (foo< bar) std::cout << "\tfoo is less than bar\n";
 	if (foo> bar) std::cout << "\tfoo is greater than bar\n";
  	if (foo<=bar) std::cout << "\tfoo is less than or equal to bar\n";
  	if (foo>=bar) std::cout << "\tfoo is greater than or equal to bar\n";
	put_elapsed_time(timer);
	
	putline(".-------------------------------------------------------------------.");
	putline(".-------------------------------------------------------------------.");
	putline(".-------------------------------------------------------------------.");
}