/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:41:05 by tomartin          #+#    #+#             */
/*   Updated: 2022/04/17 20:44:17 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "nullptr.hpp" //to ft::nullptr
#include <cstddef> // to ptrdiff_t
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include <memory> //to allocate
#include <iostream>

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
			typedef ft::reverse_iterator<const iterator>						const_reverse_iterator;
			typedef typename ft::iterator_trails<iterator>::difference_type 	difference_type;
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
				this->_size = ft::distance(first, last);
                this->_start = _alloc.allocate(this->_size);
				this->_end_capacity	= this->_start + this->_size;
				this->_end = this->_end_capacity;
			//	for (unsigned long i = 0; first != last; i++)
				for (size_type i = 0; first != last; i++)
				{
					_alloc.construct((this->_start + i), *first);
					first++;
				}
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
				this->_alloc.deallocate(this->_start, ft::distance (this->_start, this->_end_capacity) + 1);
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
			void	pre_asig_memory(size_type	n)
			{
				size_type	aux;

				if (ft::distance(this->_start, this->_end_capacity) < n)
				{
					n = n * 0.2;
					_alloc.allocate(n, this->_end_capacity + 1);
					this->_end_capacity += n;
				}
			}

			//Return amount prereserve free space
			size_type	remained_space() {return (ft::distance(this->_end, this->_end_capacity));}

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
				return ft::distance(this->_start, this->_end_capacity);
			}

			bool	empty() const
			{
				if(this->_size == 0)
					return 1;
				return 0;
			}

			void	reserve(size_type n)
			{
					std::cout << "RESERVE\n";
				if (this->_start == ft::nullptr_t)
				{
					this->_start = _alloc.allocate(1, 0);
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
			void	assing(InputIterator first, InputIterator last)
			{
				size_type	long_needed;

				long_needed = ft::distance(first, last);
				this->_alloc.deallocate(this->_start, ft::distance (this->_start, this->_end_capacity));
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

			void	assing(size_type n, const value_type& val)
			{
				this->_alloc.deallocate(this->_start, ft::distance (this->_start, this->_end_capacity));
				this->_size = n;
                this->_start = _alloc.allocate(this->_size);
				this->_end_capacity	= this->_start + this->_size;
				this->_end = this->_end_capacity;
				for (size_type i = 0; i < this->_size; i++)
				{
					_alloc.construct((this->_start + i), val);
				}
				pre_asig_memory();
			}
			
			void push_back(const value_type& val)
			{
				std::cout << "Pre memory asignate= " << ft::distance(this->_start, this->_end_capacity) << std::endl;
				if (ft::distance(this->_start, this->_end_capacity) == 0)
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
			}
		
			//Single Element-------------------------------------
			iterator    insert(iterator it, const value_type& val)
			{
				iterator end_it;
				iterator insert_it;

				if(this->remained_space() == 0)
					reserve(this->_size);
				end_it = this->_back();
				insert_it = ++this->_back();
				while(end_it != it)
					*insert_it-- = *end_it--;
				*it = val;
				return it;
			}

	};// end vector class
} // end namespace ft

#endif
