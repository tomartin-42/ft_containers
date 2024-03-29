/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:18:34 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/09 14:52:01 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
		public:
			typedef T1	first_t;
			typedef T2	second_t;

			first_t		first;
			second_t	second;
	
			//default constructor
			pair() : first(), second() {}
	
			//copy constructor
			template<class U, class V> 
			pair (const pair<U,V>& other) : first(other.first), second(other.second) {} 
			
			//initialization constructor
			pair(const first_t& a, const second_t& b) : first(a), second(b) {}
	
			pair& operator = (const pair& other)
			{
				this->first = other.first;
				this->second = other.second;
				return *this;
			}

			pair& operator * ()
			{
				return *this;
			}
	};

	//creates a pair object of type, defined by the argument types
	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1,T2>(x,y));
	}
	
	//operators
	template <class T1, class T2>
	bool operator == (const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y) 
	{
		return x.first == y.first && x.second == y.second;
	}

	template <class T1, class T2>
	bool operator < (const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y) 
	{
		return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
	}

	template <class T1, class T2>
	bool operator > (const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y) 
	{
		return (x.first > y.first || (!(y.first > x.first) && x.second > y.second));
	}

	template <class T1, class T2>
	bool operator <= (const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y) 
	{
		return !(x > y); 
	}

	template <class T1, class T2>
	bool operator >= (const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y) 
	{
		return !(x < y); 
	}

} //end namespace ft
#endif
