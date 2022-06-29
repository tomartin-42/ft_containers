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
			typedef typename ft::tree_iterator<value_type>		iterator;
			typedef typename ft::tree_iterator<const value_type>	const_iterator;
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
//aux functions
//==============================

			iterator	find_by_value_type(const value_type& f)
			{
				return (this->find(f.first));
			}

			const_iterator	find_by_value_type(const value_type& f) const
			{
				return (this->find(f.first));
			}
//==============================
//iterators
//==============================
			iterator	begin()
			{
				return this->_btree.begin();
			}


			const_iterator begin() const
			{
				return this->_btree.begin();
			}

			iterator	end()
			{
				return this->_btree.end();
			}

			const_iterator end() const
			{
				return this->_btree.end();
			}


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
			ft::pair<iterator, bool>	insert(const value_type& val)
			{
				if(this->find_by_value_type(val) != iterator(this->_btree.get_nill()))
					return (ft::make_pair(this->end(), false));
				this->_btree.insert(val);
				iterator it = this->find(val.first);
				return ft::make_pair(it, true);
			}

//===============================
//observers
//===============================

//===============================
//operations
//===============================

			iterator	find(const key_type& key)
			{
				return iterator(this->_btree.find(ft::make_pair(key, data_type())));
			}

			const_iterator	find(const key_type& key) const
			{
				return const_iterator(this->_btree.find(ft::make_pair(key, data_type())));
			}


//===============================
//allocator
//===============================

//===============================
//debug
//===============================

	/*		void print()
			{
				iterator it = this->begin();
				std::cout << it->first << std::endl;
				it++;
				std::cout << &it << std::endl;
			} */
	}; //end map class
}//end namespace ft

	
