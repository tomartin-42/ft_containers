/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_trails.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:39:13 by tomartin          #+#    #+#             */
/*   Updated: 2022/03/26 18:59:23 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAILS_HPP
# define ITERATOR_TRAILS_HPP

#include <cstddef> //to ptrdiff_t

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<class Iter>
	struct iterator_trails
	{
		typedef typename Iter::difference_type		difference_type;
		typedef	typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};
	
	template<class T>
	struct iterator_trails<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template<class T>
	struct iterator_trails<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

}//end namespace ft

#endif
