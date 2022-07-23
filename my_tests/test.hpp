/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:20:08 by npinto-g          #+#    #+#             */
/*   Updated: 2022/04/20 09:38:17 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP



# include <iostream>
# include <string>
# include <stdio.h>
# include <sys/time.h>
# include <ctime>
# include <list>
# include <unistd.h>

#ifdef STD
# define NAMESPACE std
# define NS_STRING "std"
#else
# define NAMESPACE ft
# define NS_STRING "ft"
#endif

/*
** common
*/
struct timeval	set_timer(void);
void			put_elapsed_time(const struct timeval & t);
template<typename T>
void	putaction(std::string action, T x)
{
	std::cout << action << " : " << x << std::endl;
}
template<typename T>
void	putvec( std::string title, T c)
{
	size_t	pos = 0;

	std::cout << title << std::endl; 
	for (typename T::iterator i = c.begin(); i != c.end(); ++i)
	{
		std::cout << "[" << pos << "]" << " " << *i << std::endl;
		//std::cout << "addr:" << &(*i)<<std::endl;
		++pos;
	}
}
void	putline(std::string s);

/*
** vector
*/
void	test_vector(std::string	n);
void	test_stack(std::string	n);
void	test_map(std::string	n);
/*
** stack
*/

/*
** map
*/

#endif
