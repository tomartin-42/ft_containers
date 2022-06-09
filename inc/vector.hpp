/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:41:05 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/09 12:38:21 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "nullptr.hpp" //to ft::nullptr
#include <cstddef> // to ptrdiff_t
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "utils.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include <memory> //to allocate
#include <iostream>

#pragma once

namespace ft
{
	template <class T, class alloc = std::allocator<T> > 
	class vector
	{
		public:
			typedef T															value_type;
			typedef	alloc														alloc_type;
			typedef typename alloc_type::reference								reference;
			typedef typename alloc_type::const_reference						const_reference;
			typedef typename alloc_type::pointer								pointer;
			typedef typename alloc_type::const_pointer							const_pointer;
			typedef typename ft::random_access_iterator<value_type>				iterator; 			//random_access_iterator
			typedef typename ft::random_access_iterator<const value_type>		const_iterator;		//const random_access_iterator
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type 	difference_type;
			typedef typename alloc_type::size_type								size_type;			//When we refer to numbers of elemente
	
		private:
			alloc_type							_alloc;			// data type //
			pointer     						_start;			// where init data //
			pointer     						_end;			// where init empty data //
			pointer								_end_capacity;	// where end the prealocate data //
			//difference_type					_size;			// number of alocate data //
			size_type							_size;			// number of alocate data //


//************************************************************************************************************	
//********************************************constructors****************************************************
			
		public:
//empty====================================
			explicit vector (const alloc_type& alloc_t = alloc_type()) 
				: _alloc(alloc_t), _start(ft::nullptr_t), _end(_start), _end_capacity(_end), _size(0)
			{}

//fill======================================
			explicit vector (size_type n, const value_type& val = value_type(), const alloc_type& alloc_t = alloc_type())
				: _alloc(alloc_t), _start(ft::nullptr_t), _end(_start + n), _size(n) 
			{
				this->_start = _alloc.allocate(n);
				this->_end_capacity = (this->_start + n);
                this->_end = this->_end_capacity;
				for(unsigned long i = 0; i < n; i++)
				{
					_alloc.construct((this->_start + i), val);
				}
				pre_asig_memory();
			}
	
//range=======================================
			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
				const alloc_type& alloc_t = alloc_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
				: _alloc(alloc_t)
			{
				this->_size = ft::dist(first, last);
                this->_start = _alloc.allocate(this->_size);
				this->_end_capacity	= this->_start + this->_size;
				this->_end = this->_end_capacity;
				for (size_type i = 0; first != last; i++)
				{
					_alloc.construct((this->_start + i), *first);
					first++;
				}
				pre_asig_memory();
			}
	
//copy========================================
			vector(const vector& other)
				: _alloc(other._alloc), _start(other._start), _end(other._end), _end_capacity(other._end_capacity), _size(other._size)
			{}

//= operator===================================
			vector& operator = (const vector& other)
			{
				this->_alloc = other._alloc;
				this->_start = other._start;
				this->_end = other._end;
				this->_end_capacity = other._end_capacity;
				this->_size = other._size;
				return *this;
			}

//destructor==================================
			virtual ~vector ()
			{
				this->_alloc.deallocate(this->_start, ft::dist (this->_start, this->_end_capacity) + 1);
			}

//************************************************************************************************************//	
//*****************************************member fuctions****************************************************//	
			
//==========================
//Aux functions
//==========================	
			//To preasignate memory to go fast
			void	pre_asig_memory() 
			{
				if (this->_end == this->_end_capacity)
				{
					size_type	i;
					i = this->_size * 0.2;
					_alloc.allocate(i, this->_end_capacity + 1); 
					this->_end_capacity += i;
				}
			}
			
			//Preasignate memory: Add n elements to asignate memory to the vector plus 20%	
			void	pre_asig_memory(size_type n)
			{
				size_type	aux;

				if (ft::dist(this->_start, this->_end_capacity) < n)
				{
					n = n * 0.2;
					_alloc.allocate(n, this->_end_capacity + 1);
					this->_end_capacity += n;
				}
			}

			//Return amount prereserve free space
			size_type	remained_space() {return (ft::dist(this->_end, this->_end_capacity));}

//==========================
//iterators
//==========================	
			iterator begin() {return iterator(this->_start);}

			const_iterator begin() const {return const_iterator(this->_start);}
			
			iterator end() {return iterator(this->_end);}
			
			const_iterator end() const {return const_iterator(this->_end);}
			
			reverse_iterator rbegin() {return reverse_iterator(this->_end);}
			
			const_reverse_iterator rbegin() const {return const_reverse_iterator(this->_end);}
			
			reverse_iterator rend() {return reverse_iterator(this->_start);}
			
			const_reverse_iterator rend() const {return const_reverse_iterator(this->_start);}

//==========================
//capacity
//==========================
			//difference_type	size() const {return this->_size;}
			size_type	size() const {return this->_size;}
			
			difference_type	max_size() const {return _alloc.max_size();}
			
			void	resize(size_type n, value_type val = value_type())
			{
				size_type	aux;

				if (n < this->_size)
				{
					aux = this->_size - n;
					this->_end -= aux;
					this->_size -= aux;
				}
				else if (n > this->_size)
				{
					aux = n - this->_size;
					while (aux-- > 0)
						this->push_back(val);
				}
			}

			difference_type capacity() const
			{
				return ft::dist(this->_start, this->_end_capacity);
			}

			bool	empty() const
			{
				if(this->_size == 0)
					return 1;
				return 0;
			}

			void	reserve(size_type n)
			{
				if (this->_start == ft::nullptr_t)
				{
					this->_start = _alloc.allocate(n, 0);
					this->_end = this->_start;
					this->_end_capacity = this->_end;
				}
				if(static_cast<unsigned long>(this->capacity()) < n)
				{
					_alloc.allocate(n - this->capacity(), (this->_end_capacity + 1));
				}
				this->_end_capacity += n - this->capacity();
			}

//==========================
//Element access
//==========================
			reference	operator[](size_type i)
			{
				return *(this->_start + i);
			}

			const_reference operator[](size_type i) const
			{
				return *(this->_start + i);
			}

			reference	at(size_type i)
			{
				if (i >= this->_size)
					throw std::out_of_range("vector");
				return *(this->_start + i);
			}

			const_reference	at(size_type i) const
			{
				if (i >= this->_size)
					throw std::out_of_range("vector");
				return *(this->_start + i);
			}

			reference	front() {return *(this->_start);}

			const_reference	front() const {return *(this->_start);}
			
			reference	back() {return *(this->_end - 1);}

			const_reference	back() const {return *(this->_end - 1);}

//==========================
//Modifiers
//==========================
			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_type	long_needed;

				long_needed = ft::dist(first, last);
				this->_alloc.deallocate(this->_start, ft::dist (this->_start, this->_end_capacity));
				this->_size = long_needed;
                this->_start = _alloc.allocate(this->_size);
				this->_end_capacity	= this->_start + this->_size;
				this->_end = this->_end_capacity;
				for (size_type i = 0; first != last; i++)
				{
					_alloc.construct((this->_start + i), *first);
					first++;
				}
				pre_asig_memory();
			}

			void	assign(size_type n, const value_type& val)
			{
				this->clear();
				for(size_type i = 0; i < n; i++)
				{
					this->push_back(val);
				}
			}
			
			void push_back(const value_type& val)
			{
				if (ft::dist(this->_start, this->_end_capacity) == 0)
				{
					this->reserve(1);
				}
				this->_alloc.construct((this->_end + 1), val);
				this->_end += 1;
				this->_size += 1;
				pre_asig_memory();
			}

			void pop_back()
			{
				this->_end -= 1;
				this->_size -= 1;
			}
		
			//Single Element insert-------------------------------------
			iterator    insert(iterator it, const value_type& val)
			{
				iterator	end_it;
				iterator	insert_it;

				this->_size += 1;
				if(this->remained_space() == 0)
					reserve(this->_size);
				end_it = this->end();
				insert_it = ++this->end();
				while(insert_it != it)
					*(insert_it--) = *(end_it--);
				*it = val;
				this->_end += 1;
				return it;
			}

			//Fill insert---------------------------------------------
			void insert(iterator position, size_type n, const value_type& val)
			{
				iterator	end_it;
				iterator	insert_it;

				this->_size += n;
				this->_end += n; 
				if (remained_space() < n)
					this->reserve(n - remained_space());
				end_it = this->end();
				insert_it = this->end() + n;
				for (size_type aux = n; aux > 0; aux--)
					*(insert_it--) = *(end_it--);
				while(n-- > 0)
				{
					*position = val;
					position++;
				}
			}

			//Range insert-------------------------------------------
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_type	add;
				iterator	aux_it;
				iterator	end_it;
				iterator	insert_it;

				add = ft::dist(first, last);
				this->_size += add;
				if(this->remained_space() < add)
				{
					this->reserve(add - remained_space());
				}
				this->_end += add;
				aux_it = position;
				end_it = this->end();
				insert_it = this->end() + add;
				for (size_type aux = add; aux > 0; aux--)
					*(insert_it--) = *(end_it--);
				while(add-- > 0)
				{
					*position = *first;
					position++;
					first++;
				}
			}

			//One erase---------------------------------------------
			iterator erase(iterator position)
			{
				iterator	next_it;
				iterator	ret_it;

				next_it = position + 1;
				ret_it = position;
				while (next_it != this->end())
					*position++ = *next_it++;
				this->_size--;
				this->_end--;
				return ret_it;
			}

			//Fill erase-----------------------------------------
			iterator erase(iterator first, iterator last)
			{
				while (last != this->end())
					*first++ = *last++;
				return first;
			}

			void	swap(vector& x)
			{
				pointer   	aux_start(x._start);
				pointer   	aux_end(x._end);
				pointer		aux_end_capacity(x._end_capacity);
				size_type	aux_size(x.size());	

				x._start = this->_start;
				x._end = this->_end;
				x._end_capacity = this->_end_capacity;
				x._size = this->size();
				this->_start = aux_start;
				this->_end = aux_end;
				this->_end_capacity = aux_end_capacity;
				this->_size = aux_size;
			}

			void	clear(void)
			{
				while (this->_size != 0)
					this->pop_back();
			}

	};// end vector class
	
//=======================================
//No member functions (vompair operators)
//=======================================

	template <typename T, typename U, class alloc>
	bool operator == (const vector<T, alloc> vf, const vector<U, alloc> vl)
	{
		if(vf.size() != vl.size())
			return false;
		for(typename ft::vector<T>::size_type i = 0; i < vf.size(); i++)
		{
			if(vf[i] != vl[i])
				return false;
		}
		return true;
	}

	template <typename T, typename U, class alloc>
	bool operator != (const vector<T, alloc> vf, const vector<U, alloc> vl)
	{
		return !(vf == vl);
	}

	template <typename T, typename U, class alloc>
	bool operator < (const vector<T, alloc> vf, const vector<U, alloc> vl)
	{
		return (ft::lexicographical_compare(vf.begin(), vf.end(), vl.begin(), vl.end()));
	}

	template <typename T, typename U, class alloc>
	bool operator <= (const vector<T, alloc> vf, const vector<U, alloc> vl)
	{
		return (vf < vl || vf == vl);
	}

	template <typename T, typename U, class alloc>
	bool operator > (const vector<T, alloc> vf, const vector<U, alloc> vl)
	{
		return !(vf < vl);
	}

	template <typename T, typename U, class alloc>
	bool operator >= (const vector<T, alloc> vf, const vector<U, alloc> vl)
	{
		return !(vf <= vl);
	}

	template <typename T, class alloc>
	void	swap(vector<T, alloc> & x, vector<T, alloc> & y)
	{
		vector<T, alloc>	aux;

		aux = x;
		x = y;
		y = aux;
	}	
} // end namespace ft
#endif
