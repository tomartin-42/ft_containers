#include <memory> // to allocate
#include <iostream>
#include <functional>
#include "tree.hpp"
#include "tree_iterator.hpp"
#include "pair.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > > 
	class map
	{
		public:
			typedef	Key														key_type;
			typedef T														data_type;
			typedef Compare													value_comp;
			typedef Alloc													alloc_type;
			typedef typename ft::pair<const key_type, data_type>			value_type;	
			typedef typename alloc_type::pointer							pointer;
			typedef typename alloc_type::const_pointer						const_pointer;
			typedef typename alloc_type::reference							reference;
			typedef typename alloc_type::const_reference					const_reference;
			typedef typename alloc_type::size_type							size_type;
			typedef typename alloc_type::difference_type					difference_type;
			typedef typename ft::tree_iterator<value_type>					iterator;
			typedef typename ft::tree_iterator<const value_type>			const_iterator;
			typedef typename alloc_type::template rebind<value_type>::other	pair_alloc_type;

					//**********************************************//	
			class	value_compare : public std::binary_function<value_type, value_type, bool>
			{
			protected:
				value_comp	comp_t;

			public:
				value_compare(value_comp c) : comp_t(c) {}

				bool	operator()(const value_type& x, const value_type& y) const
				{
					return comp_t(x.first, y.first);
				}
			};

				//***************************************************//
		private:
			alloc_type										_alloc;
			ft::tree<value_type, value_compare, alloc_type>	_btree;

//********************************************************************************************************//	
//********************************************constructors************************************************//
		public:
			explicit map(const value_comp& comp_t = value_comp(), const alloc_type& alloc_t = alloc_type()) 
				: _alloc(alloc_t), _btree(alloc_t, comp_t) {}

		/*	
			map(InputIterator first, InputIterator last, 
				const value_comp& comp_t = value_comp(), const allocator_type& alloc_t = alloc_type())
				: _alloc(alloc_t), _btree(alloc_t, comp_t)
				{
				}
		*/	
			map(const map& other) : _alloc(other._alloc), _btree(other._btree)
			{
				*this = other;
			}


//********************************************************************************************************//
//*************************************member fuctions****************************************************//

//==============================
//iterators
//==============================
			iterator	begin()
			{}

			const_iterator begin() const
			{}

			iterator	end()
			{}

			const_iterator end() const
			{}


//==============================
//capacity
//==============================
			bool	empty()
			{
				if(this->_btree.size() == 0)
					return true;
				return false;
			}

			size_type	size()
			{
				return this->btree.size();
			}

			size_type	max_size()
			{
			}


//=============================
//element access
//=============================
			data_type	&operator[](const key_type &i) 
			{
			}

//===============================
//modifiers
//===============================


//===============================
//observers
//===============================

//===============================
//operations
//===============================


//===============================
//allocator
//===============================


	}; //end map class
}//end namespace ft

	
