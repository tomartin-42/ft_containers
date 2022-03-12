/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:03:00 by tomartin          #+#    #+#             */
/*   Updated: 2022/03/12 17:46:40 by tomartin         ###   ########.fr       */
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

    /*
    **  - bool
    **  - char
    **  - char16_t
    **  - char32_t
    **  - wchar_t
    **  - signed char
    **  - short int
    **  - int
    **  - long int
    **  - long long int
    **  - unsigned char
    **  - unsigned short int
    **  - unsigned int
    **  - unsigned long int
    **  - unsigned long long int
    */
	
	template<>
	struct is_integral<bool> : struct is_integral_struct<true, bool> {};

	template<>
	struct is_integral<char> : struct is_integral_struct<true, char> {};

	template<>
	struct is_integral<char16_t> : struct is_integral_struct<true, char16_t> {};

	template<>
	struct is_integral<char32_t> : struct is_integral_struct<true, char32_t> {};

	template<>
	struct is_integral<wchar_t> : struct is_integral_struct<true, wchar_t> {};

	template<>
	struct is_integral<signed char> : struct is_integral_struct<true, signed char> {};

	template<>
	struct is_integral<short int> : struct is_integral_struct<true, short int> {};

	template<>
	struct is_integral<int> : struct is_integral_struct<true, int> {};

	template<>
	struct is_integral<long int> : struct is_integral_struct<true, long int> {};

	template<>
	struct is_integral<long long int> : struct is_integral_struct<true, long long int> {};

	template<>
	struct is_integral<unsigned char> : struct is_integral_struct<true, unsigned char> {};

	template<>
	struct is_integral<unsigned short int> : struct is_integral_struct<true, unsigned short int> {};

	template<>
	struct is_integral<unsigned int> : struct is_integral_struct<true, unsigned int> {};

	template<>
	struct is_integral<unsigned long int> : struct is_integral_struct<true, unsigned long int> {};

	template<>
	struct is_integral<unsigned long long int> : struct is_integral_struct<true, unsigned long long int> {};
	
	template<typename>
	struct in_integral : is_integr_struct<false, void>
} // end ft namespace

#endif
