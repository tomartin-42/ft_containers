/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:13:30 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/08 08:14:40 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __NULLPTR__HPP
# define __NULLPTR__HPP

namespace ft
{

	static class nullptr_t
	{
		public:
			template<class T>
			operator T * () const 
			{
				return (0);
			}
	
			template<class C, class T>
			operator T C::* () const 
			{
				return (0);
			}

		private:
			void operator & () const;
	
	} nullptr_t = {};

} //end ft
#endif
