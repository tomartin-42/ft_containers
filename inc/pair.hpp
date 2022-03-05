/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:18:34 by tomartin          #+#    #+#             */
/*   Updated: 2022/03/05 20:14:53 by tomartin         ###   ########.fr       */
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
			typedef T1	first;
			typedef T2	second;
	
			//default constructor
			pair() : first(), second() {}
	
			//copy constructor
			template<class U, class V> 
			pair (const pair<U,V>& other) : first(other.first), second(other.second) {} 
			
			//initialization constructor
			pair(const first& a, const second& b) : first(a), second(b) {}
	
			pair& operator = (const pair& other)
			{
				this->first = other.first;
				this->second = other.second;
				return *this;
			}
	};

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1,T2>(x,y));
	}


} //end namespace ft
#endif
