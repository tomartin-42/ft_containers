/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:03:00 by tomartin          #+#    #+#             */
/*   Updated: 2022/03/04 10:29:31 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRALL_HPP
# define IS_INTEGRALL_HPP

namespace ft
{
	template<bool is_integral, typename T>
	struct is_integral_struct
	{
		const bool	value = is_integral;
		typedef T	type;
	};

