/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:30:28 by npinto-g          #+#    #+#             */
/*   Updated: 2022/04/21 16:01:29 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "map.hpp"
#include <map>

template <typename MAP, typename T1>
void	ft_erase(MAP &mp, const T1 param)
{
	std::cout << "\t-- [" << param << "] --" << std::endl;
	mp.erase(param);
}

template <typename T, typename U>
void	tree_cmp(T &m, U &n) {
	typename T::iterator	mb = m.begin();
	typename T::iterator	me = m.end();
	typename U::iterator	nb = n.begin();
	typename U::iterator	ne = n.end();

	while (mb != me && nb != ne)
	{
		std::cout << "#[" << mb->first << ":" << mb->second << "] ";
		std::cout << "@[" << nb->first << ":" << nb->second << "]#\n";
		++mb;
		++nb;
	}
}

void test_map(std::string n)
{
	putline("███╗   ███╗ █████╗ ██████╗ ");
	putline("████╗ ████║██╔══██╗██╔══██╗");
	putline("██╔████╔██║███████║██████╔╝");
	putline("██║╚██╔╝██║██╔══██║██╔═══╝ ");
	putline("██║ ╚═╝ ██║██║  ██║██║     ");
	putline("╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ");
	struct timeval	timer;                               
                                                             
	std::cout << "TESTING : " << n << "::map" << std::endl;
				std::map<int, std::string> msys;
{
	putline("map basics");
	timer = set_timer();

	NAMESPACE::map<int,int>		m;
	putaction("\tmap->size()", m.size());
	putaction("\tmap->empty()", m.empty());
	putaction("\tmap->max_size()", m.max_size());
	putaction("\tmap->insert(5,5)", (m.insert(NAMESPACE::make_pair(5,5)).second));
	putaction("\tmap->insert(3,3)", (m.insert(NAMESPACE::make_pair(3,3)).second));
	putaction("\tmap->insert(6,6)", (m.insert(NAMESPACE::make_pair(6,6)).second));
	putaction("\tmap->insert(1,1)", (m.insert(NAMESPACE::make_pair(1,1)).second));
	putaction("\tmap->size()", m.size());
	putaction("\tmap->empty()", m.empty());
	putaction("\tmap->max_size()", m.max_size());
	NAMESPACE::map<int,int>		n(m);
	
	tree_cmp(m, n);
	putaction("\tmap[exists]", m[3]);
	putaction("\tmap[doesn't exist]", m[4]);
	tree_cmp(m, n);
	m.swap(n);
	tree_cmp(m, n);
	m.erase(1);
	if (n==m) std::cout << "\tn and m are equal\n";
 	if (n!=m) std::cout << "\tn and m are not equal\n";
	if (n< m) std::cout << "\tn is less than m\n";
 	if (n> m) std::cout << "\tn is greater than m\n";
  	if (n<=m) std::cout << "\tn is less than or equal to m\n";
  	if (n>=m) std::cout << "\tn is greater than or equal to m\n";
	
	m.clear();
	putaction("\tmap->size()", m.size());
	putaction("\tmap->empty()", m.empty());
	putaction("\tmap->max_size()", m.max_size());
	tree_cmp(m, m);
	m = n;
	tree_cmp(m, n);
	putaction("key_comp(1,2)",(m.key_comp())(1,2));
	putaction("key_comp(2,1)",(m.key_comp())(2,1));
	putaction("value_comp(beg, ++beg)",m.value_comp()(*m.begin(), *(++m.begin())));
	putaction("value_comp(beg,++(++beg))",m.value_comp()(*m.begin(), *++(++m.begin())));
	putaction("find(3)", m.find(3)->first);
	putaction("count(exists)", m.count(5));
	putaction("count(doesn't exist)", m.count(99));
	putaction("lower bound", m.lower_bound(5)->first);
	putaction("upper bound", m.upper_bound(5)->first);
	putaction("equal range", m.equal_range(5).first->first);
	put_elapsed_time(timer);
}
{
			timer = set_timer();	
			std::pair<int, std::string> psys(1, "1");
			std::pair<int, std::string> psys2(2, "2");
			msys.insert(psys);

			int i = 0;
			ft::putendl("single node");
			ft::putendl("incrementing");
			for (std::map<int, std::string>::iterator isys = msys.begin();  isys != msys.end() ; ++isys)
			{
				++i;
				std::cout << "\t" << i << ")" << " " << isys->first << ":" << isys->second << std::endl; 
			}
			i = 0;	
			ft::putendl("decrement");
			for (std::map<int, std::string>::iterator isys = --(msys.end());  isys != msys.begin() ; --isys)
			{
				++i;
				std::cout << "\t" << i << ")" << " " << isys->first << ":" << isys->second << std::endl; 
			}
			ft::putendl("two nodes (right favored)");
			i = 0;	
			msys.insert(psys2);
			ft::putendl("incrementing");
			for (std::map<int, std::string>::iterator isys = msys.begin();  isys != msys.end() ; ++isys)
			{
				++i;
				std::cout << "\t" << i << ")" << " " << isys->first << ":" << isys->second << std::endl; 
			}
			
			i = 0;	
			ft::putendl("decrement");
			for (std::map<int, std::string>::iterator isys = --(msys.end());  isys != msys.begin() ; --isys)
			{
				++i;
				std::cout << "\t" << i << ")" << " " << isys->first << ":" << isys->second << std::endl; 
			}

			
			ft::putendl("///MAP DELETIOn TESTS\\\\\\");
			NAMESPACE::map<int,int>	del;
			NAMESPACE::pair<int, int>	ds1(1,1);
			NAMESPACE::pair<int, int>	ds2(2,2);
			NAMESPACE::pair<int,int>	ds3(3,3);
			NAMESPACE::pair<int, int>	ds4(4,4);
			NAMESPACE::pair<int, int>	ds5(5,5);
			NAMESPACE::pair<int, int>	ds6(6,6);

			ft::putendl("contents pre erase:");
			del.insert(ds1);
			del.insert(ds2);
			del.insert(ds3);
			del.insert(ds4);
			del.insert(ds5);
			del.insert(ds6);
			for (NAMESPACE::map<int, int>::iterator isys = del.begin();  isys != del.end() ; ++isys)
			{
				std::cout << isys->first << ":" << isys->second << std::endl; 
			}
			del.erase(del.begin());
			ft::putendl("begin() erase:(no children)");
			for (NAMESPACE::map<int, int>::iterator isys = del.begin();  isys != del.end() ; ++isys)
			{
				std::cout << isys->first << ":" << isys->second << std::endl; 
			}
			del.erase(del.find(4));
			ft::putendl("find(4) erase:(root of tree, two children)");
			for (NAMESPACE::map<int, int>::iterator isys = del.begin();  isys != del.end() ; ++isys)
			{
				std::cout << isys->first << ":" << isys->second << std::endl; 
			}
			put_elapsed_time(timer);
		}
	{
				timer = set_timer();

				std::list<NAMESPACE::pair<const int, int> > lst;
				unsigned int lst_size = 7;
				
				for (unsigned int i = 0; i < 7; ++i)
				{
					lst.push_back(NAMESPACE::pair<const int, int> (lst_size - i, i));
				}

				NAMESPACE::map<int, int> mp(lst.begin(), lst.end());
				NAMESPACE::map<int, int>::iterator it = mp.begin();
				NAMESPACE::map<int, int>::iterator ite = mp.end();

				NAMESPACE::map<int,int> mrc(it, --(--ite));

				
				std::list<NAMESPACE::pair<const int, char> > lsterase;

				lst_size = 10;
				for (unsigned int i = 0; i < lst_size; ++i)
				{
					lsterase.push_back(NAMESPACE::make_pair((int)lst_size - i, (int)i + 65));
				}
				NAMESPACE::map<int, int> mpe(lsterase.begin(), lsterase.end());
				std::cout << "Deling " << (++mpe.begin())->first << std::endl;
				mpe.erase(++mpe.begin());

				std::cout << "Deling " << (mpe.begin())->first << std::endl;
				mpe.erase(mpe.begin());
				

				std::cout << "Deling " << (--mpe.end())->first << std::endl;
				mpe.erase(--mpe.end());
				
				std::cout << "Deling " << (--(--mpe.end()))->first << std::endl;
				mpe.erase(--(--mpe.end()));
				put_elapsed_time(timer);
	}
	{			
				timer = set_timer();
				std::list<NAMESPACE::pair<const int, std::string> > lst;
				unsigned int lst_size = 10;
				for (unsigned int i = 0; i < lst_size; ++i)
					lst.push_back(NAMESPACE::pair<const int, std::string >(i, std::string((lst_size - i), i + 65)));
				NAMESPACE::map<int, std::string> mp(lst.begin(), lst.end());

				std::cout << "erase " << (++mp.begin())->first << std::endl;
				mp.erase( ++mp.begin());

				std::cout << "erase " << mp.begin()->first << std::endl;
				mp.erase( mp.begin());

				std::cout << "erase " << (--mp.end())->first << std::endl;
				mp.erase( --mp.end());
			
				std::cout << std::endl;
				mp.erase(mp.begin(), ++(++(++mp.begin())));
				std::cout << "erasing range :\n";
				for (NAMESPACE::map<int, std::string>::iterator i = --(--(--mp.end())); i != --mp.end();  ++i)
				{
					std::cout << "(" << i->first << ")" << " ";
				}
				put_elapsed_time(timer);
	}

	{
	timer = set_timer();

	ft::putendl("TRICKY ERASURE");
	NAMESPACE::map<int, std::string> mp;
	mp[42] = "lol";
	mp[50] = "mdr";
	mp[25] = "funny";

	mp[46] = "bunny";
	mp[21] = "fizz";
	mp[30] = "buzz";
	mp[55] = "fuzzy";

	mp[18] = "bee";
	mp[23] = "coconut";
	mp[28] = "diary";
	mp[35] = "fiesta";
	mp[44] = "hello";
	mp[48] = "world";
	mp[53] = "this is a test";
	mp[80] = "hey";

	mp[12] = "no";
	mp[20] = "idea";
	mp[22] = "123";
	mp[24] = "345";
	mp[27] = "27";
	mp[29] = "29";
	mp[33] = "33";
	mp[38] = "38";

	mp[43] = "1";
	mp[45] = "2";
	mp[47] = "3";
	mp[49] = "4";
	mp[51] = "5";
	mp[54] = "6";
	mp[60] = "7";
	mp[90] = "8";

	ft_erase(mp, 25); // right != NULL; left != NULL
	ft_erase(mp, 55); // right != NULL; left != NULL
	ft_erase(mp, 24); // right != NULL; left != NULL
	ft_erase(mp, 54); // right != NULL; left != NULL
	ft_erase(mp, 22); // right == NULL; left == NULL
	ft_erase(mp, 51); // right == NULL; left == NULL
	ft_erase(mp, 21); // right == NULL; left != NULL
	ft_erase(mp, 53); // right != NULL; left == NULL
	ft_erase(mp, 20); // right == NULL; left != NULL
	ft_erase(mp, 23); // right != NULL; left != NULL
	ft_erase(mp, 42); // right != NULL; left != NULL; parent == NULL
	ft_erase(mp, 38); // right != NULL; left != NULL; parent == NULL
	ft_erase(mp, 35); // right != NULL; left != NULL; parent == NULL
	ft_erase(mp, 33); // right != NULL; left != NULL; parent == NULL
	put_elapsed_time(timer);
	}
	{
		putline("complex insertion 🤯, worst case scenario");
		timer = set_timer();
		NAMESPACE::map<int, int> m;
		
		for (size_t i = 0; i < 1e6;++i)
		{
			m.insert(NAMESPACE::make_pair(i, i % 99));
		}
		put_elapsed_time(timer);
		putline("in order");
		timer = set_timer();
		for (NAMESPACE::map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
		{ 
			std::cout << i->second << "\n";
		}
		putline("in reverse");
		for (NAMESPACE::map<int, int>::reverse_iterator i = m.rbegin(); i != m.rend(); ++i)
		{ 
			std::cout << i->second<< "\n";
		}
		put_elapsed_time(timer);
	}
	putline(".-------------------------------------------------------------------.");
	putline(".-------------------------------------------------------------------.");
	putline(".-------------------------------------------------------------------.");

}
 
 //0989796959493929190898887868584838281807978777675747372717069
 //0989796959493929190898887868584838281807978777675747372717069