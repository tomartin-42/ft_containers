/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:41:05 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/13 11:45:34 by tomartin         ###   ########.fr       */
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
				: _alloc(other._alloc), _start(ft::nullptr_t), _end(_start), _end_capacity(_end), _size(0)
			{
					iterator it = other._start;
					
					while(it != other._end)
					{
						this->push_back(*it);
						it++;
					}
			}

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
			virtual	~vector () 
			{
		//		this->clear();
		//		this->_alloc.deallocate(this->_start, this->remained_space());
			}

//********************************************************************************************************//	
//*****************************************member fuctions************************************************//	
			
//==========================
//Aux functions
//==========================	
			//To preasignate memory to go fast
			void	pre_asig_memory() 
			{
				if (this->_end == this->_end_capacity)
				{
					size_type	i;
					i = this->_size * 2;
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
			
			reverse_iterator rbegin() {return reverse_iterator(this->end());}
			
			const_reverse_iterator rbegin() const {return const_reverse_iterator(this->end());}
			
			reverse_iterator rend() {return reverse_iterator(this->begin());}
			
			const_reverse_iterator rend() const {return const_reverse_iterator(this->begin());}

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
				if(static_cast<size_type>(this->capacity()) < n)
				{
					_alloc.allocate(n - this->capacity(), (this->_end_capacity + 1));
					this->_end_capacity += n - this->capacity();
				}
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
				pre_asig_memory();
				this->insert(this->end(), val);
			}

			void pop_back()
			{
				this->_end -= 1;
				this->_size -= 1;
			}
		
			//Single Element insert-------------------------------------
			iterator    insert(iterator position, const value_type& val)
			{
				size_type	i = 0;
				size_type	offset;
				vector		tmp(this->size() + 1);
				iterator	insert_it = this->begin();

				while(insert_it != position)
				{
					tmp[i] = *insert_it;
					i++;
					insert_it++;
				}
				offset = i;
				tmp[i] = val;
				i++;

				while(insert_it != this->end())
				{
					tmp[i] = *insert_it;
					i++;
					insert_it++;
				}
				this->swap(tmp);
				tmp.clear();
				return this->begin() + offset;
			}

			//Fill insert---------------------------------------------
			void insert(iterator position, size_type n, const value_type& val)
			{
				size_type	i = 0;
				vector		tmp(this->size() + n);
				iterator	insert_it = this->begin();

				while(insert_it != position)
				{
					tmp[i] = *insert_it;
					i++;
					insert_it++;
				}
				while(n > 0)
				{
					tmp[i] = val;
					i++;
					n--;
				}
				while(insert_it != this->end())
				{
					tmp[i] = *insert_it;
					i++;
					insert_it++;
				}
				this->swap(tmp);
				tmp.clear();
			}

			//Range insert-------------------------------------------
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_type	new_capacity = (ft::dist(first, last)) + this->_size;
				vector		temp(new_capacity);
				iterator	it = this->begin();
				size_type	pos = 0;

				while (it != position)
				{
					temp[pos] = *it;
					it++;
					pos++;
				}
				while (first != last)
				{
					temp[pos] = *first;
					first++;
					pos++;
				}
				while (pos < new_capacity)
				{
					temp[pos] = *it;
					it++;
					pos++;
				}
				this->swap(temp);
				temp.clear();
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
				iterator	ret_it = first;

				while (last != this->end())
					*first++ = *last++;
				this->_size -= ft::dist(first, last);
				this->_end -= ft::dist(first, last);
				return ret_it;
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
		return !(vf <= vl);
	}

	template <typename T, typename U, class alloc>
	bool operator >= (const vector<T, alloc> vf, const vector<U, alloc> vl)
	{
		return !(vf < vl);
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
