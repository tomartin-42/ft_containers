/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:25:32 by npinto-g          #+#    #+#             */
/*   Updated: 2022/04/20 15:23:52 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <vector>
#include "vector.hpp"

void	test_vector(std::string n)
{
	struct timeval	timer;                                   
	putline("██╗   ██╗███████╗ ██████╗████████╗ ██████╗ ██████╗");
	putline("██║   ██║██╔════╝██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗");
	putline("██║   ██║█████╗  ██║        ██║   ██║   ██║██████╔╝");
	putline("╚██╗ ██╔╝██╔══╝  ██║        ██║   ██║   ██║██╔══██╗");
	putline(" ╚████╔╝ ███████╗╚██████╗   ██║   ╚██████╔╝██║  ██║");
	putline("  ╚═══╝  ╚══════╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝");

	std::cout << "TESTING : " << n << "::vector" << std::endl;

	NAMESPACE::vector<int>	simple;
	putline("#SIMPLE(capacity member functions)#");
	timer = set_timer();
	putaction("\tvector->size()", simple.size());
	putaction("\tvector->empty()", simple.empty());
	putaction("\tvector->max_size()", simple.max_size());
	putaction("\tvector->capacity()", simple.capacity());
	putaction("\tvector->reserve(0)", "done..");
	simple.reserve(0);
	putaction("\tvector->capacity()", simple.capacity());
	putaction("\tvector->size()", simple.size());
	try
	{
		putline("\t[expected exception]");
		putaction("\t\tvector->reserve(-1)", "done..");
		simple.reserve(-1);
	}
	catch (std::exception &e)
	{
		std::cout << "\t\t" <<  e.what() << std::endl;
	}
	putaction("\tvector->capacity()", simple.capacity());
	putaction("\tvector->size()", simple.size());
	putaction("\tvector->reserve(4)", "done..");
	simple.reserve(4);
	putaction("\tvector->capacity()", simple.capacity());
	putaction("\tvector->size()", simple.size());
	putaction("\tvector->resize(5)","done..");
	simple.resize(0);
	putaction("\tvector->size()", simple.size());
	putaction("\tvector->resize(5)","done..");
	simple.resize(5);
	putaction("\tvector->size()", simple.size());
	putvec("simple vector", simple);
	put_elapsed_time(timer);
	putline("-------------------------------------------------------------------");

	putline("#TRICKIER (iterators, constructors, copy, assignment, swap, clear  and relational operators)");
	putline("\tparametric constructor..");
	timer = set_timer();
	NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
	NAMESPACE::vector<int> bar (2,200);   // two ints with a value of 200
	putline("\t\t0K..");

	putline("\trange constructor..");
	std::list<std::string>	l;
	for( size_t i = 0; i < 9 ; i++)
	{
		l.push_back(std::string(i + 1,i + 'a'));
	}
	putline("inputted content:");
	for (std::list<std::string>::iterator i = l.begin(); i != l.end(); i++)
	{
		std::cout << "-" << *i << std::endl;
	}
	NAMESPACE::vector<std::string> iv(l.begin(), l.end());
	putvec("corresponding vector", iv);
	for(NAMESPACE::vector<std::string>::reverse_iterator it = iv.rbegin(); it != iv.rend(); ++it)
	{
		putaction("rev", *it);
	}
	NAMESPACE::vector<std::string> ivcopy(iv);
	putline("\tcopy constructor..");
	putvec("copied vector", ivcopy);
	putline("\trelational operators:");
	putvec("foo", foo);
	putvec("bar", bar);
 	if (foo==bar) std::cout << "\tfoo and bar are equal\n";
 	if (foo!=bar) std::cout << "\tfoo and bar are not equal\n";
	if (foo< bar) std::cout << "\tfoo is less than bar\n";
 	if (foo> bar) std::cout << "\tfoo is greater than bar\n";
  	if (foo<=bar) std::cout << "\tfoo is less than or equal to bar\n";
  	if (foo>=bar) std::cout << "\tfoo is greater than or equal to bar\n";
	putline("\tassignment and swap");
	NAMESPACE::vector<int> assigned(4, 999);
	putvec("pre-assigned v", assigned);
	assigned = foo;
	putvec("post-assigned v", assigned);
	foo.swap(bar);
	putvec("swapped foo bar", foo);
	putvec("swapped bar foo", bar);
	foo.clear();
	bar.clear();
	putvec("'clear()'ed foo", foo);
	putvec("'clear()'ed bar", bar);
	putaction("vector.at(2)", iv.at(2));
	try
	{
		putline("\t[expected exception]");
		iv.at(-1);	
		simple.reserve(-1);
	}
	catch (std::exception &e)
	{
		std::cout << "\t\t" <<  e.what() << std::endl;
	}

	putaction("vector.front()", iv.front());
	putaction("vector.back()", iv.back());
	putaction("vector[4]", iv[4]);
	putaction("vector[-1]", iv[-1]);
	put_elapsed_time(timer);
	putline("-------------------------------------------------------------------");
	putline("#TRICKIEST !!111 (hard modifiers, dire time complexity, inserting and erasing)");
	
	NAMESPACE::vector<int>vct_two(4);
	NAMESPACE::vector<int>vct_four;
	
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;

	vct_two.assign(2, 42);
	vct_four.assign(4,21);
	
	timer = set_timer();
	std::list<std::string>	abc;
	for( size_t i = 0; i < 1e5; i++)
	{
		abc.push_back(std::string((i % 3) + 1,((i + 1) % 26) + 'a'));
	}
	NAMESPACE::vector<std::string>	u;
	putline("\tdire push_back 🙀");
	for(std::list<std::string>::iterator i = abc.begin(); i != abc.end(); ++i)
	{
		u.push_back(*i);
	}
	putvec("tricky vector's content 🙀", u);
	putline("dire single insert 🙀");
	u.insert(u.end(), "D I R E D I R E D I R E");
	putline("dire fill insert 🙀");
	u.insert(u.end(), 3 ,"👽D I R E D I R E D I R E👽");
	putline("dire range insert 🙀");
	u.insert(u.end(), abc.begin(), ++(++(++(abc.begin())))); //		
	putvec("deadly vector's content 🙀", u);
	putline("dire single erase 🙀");
	u.erase(u.end() - 4);
	putvec("tricky single erase ☠️", u);

	putline("dire range  erase 🙀");
	u.erase(u.begin() + 5, u.begin() + 10);//		

	putvec("tricky erase ☠️", u);
	putline("range vector.assign()");
	u.assign(abc.begin(), ++(++(++(abc.begin()))));//		
	putvec("", u);
	putline("fill vector.assign()");
	u.assign(10, "ITS OVER!");
	putvec("", u);
	put_elapsed_time(timer);
	putline(".-------------------------------------------------------------------.");
	putline(".-------------------------------------------------------------------.");
	putline(".-------------------------------------------------------------------.");
}
