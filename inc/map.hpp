#include <memory> // to allocate
#include <iostream>
#include <functional>
#include "tree.hpp"
#include "tree_iterator.hpp"
#include "tree_iterator.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "utils.hpp"

namespace ft
{
/*	template<class Pair>
	struct	key

	{
		typename Pair::first_t&	get_first(Pair& pair) const
		{
			return pair.first;
		}

		const typename Pair::first_t&	get_first(const Pair& pair) const
		{
			return pair.first;
		}

		typename Pair::second_t&	get_second(Pair& pair) const
		{
			return pair.second;
		}

		const typename Pair::second_t&	get_second(const Pair& pair) const
		{
			return pair.second;
		}
	};*/

	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef	Key														key_type;
			typedef T														data_type;
			typedef Compare													v_compare;
			typedef Alloc													alloc_type;
			typedef typename ft::pair<const key_type, data_type>			value_type;
			typedef typename ft::tree<value_type, v_compare, alloc_type> rb_tree;
			typedef typename alloc_type::pointer							pointer;
			typedef typename alloc_type::const_pointer						const_pointer;
			typedef typename alloc_type::reference							reference;
			typedef typename alloc_type::const_reference					const_reference;
			typedef typename alloc_type::size_type							size_type;
			typedef typename alloc_type::difference_type					difference_type;
			typedef typename rb_tree::iterator								iterator;
		//	typedef typename rb_tree::const_iterator						const_iterator;
			typedef typename rb_tree::reverse_iterator								reverse_iterator;
		//	typedef typename rb_tree::const_reverse_iterator							const_reverse_iterator;
			typedef typename alloc_type::template rebind<value_type>::other	pair_alloc_type;

					//**********************************************//	
			class	value_compare : public std::binary_function<value_type, value_type, bool>
			{
			protected:
				value_compare	comp_t;

			public:
				value_compare(v_compare c) : comp_t(c) {}

				bool	operator()(const value_type& x, const value_type& y) const
				{
					return comp_t(x.first, y.first);
				}
			};

				//***************************************************//
		private:
			alloc_type										_alloc;
			rb_tree											_btree;

//********************************************************************************************************//	
//********************************************constructors************************************************//
		public:
			explicit map(const v_compare& comp_t = v_compare(), const alloc_type& alloc_t = alloc_type()) 
				: _alloc(alloc_t), _btree(comp_t, alloc_t) {}

			template<class InputIterator>			
			map(InputIterator first, InputIterator last, 
				const v_compare& comp_t = v_compare(), const alloc_type& alloc_t = alloc_type())
				: _alloc(alloc_t), _btree(comp_t, alloc_t)
				{
					while(first != last)
					{
						this->_btree.insert(*first);
						first++;
					}
				}
			
			map(const map& other) : _alloc(other._alloc), _btree(other._btree)
			{
				*this = other;
			}

			map& operator= (const map& x)
			{
				this->clear();
				this->insert(x.begin(), x.end());
				return *this;
			}


//********************************************************************************************************//
//*************************************member fuctions****************************************************//

//==============================
//iterators
//==============================
			iterator	begin() {return this->_btree.begin();}

		//	const_iterator begin() const {return this->_btree.begin();}

			iterator	end() {return this->_btree.end();}

		//	const_iterator end() const {return this->_btree.end();}

			reverse_iterator	rbegin() {return this->_btree.rbegin();}

		//	const_reverse_iterator	rbegin() const {return this->_btree.rbegin();}

			reverse_iterator	rend() {return this->_btree.rend();}

		//	const_reverse_iterator	rend() const {return this->_btree.rend();}


//==============================
//capacity
//==============================
			bool	empty() const
			{
				if(this->_btree.empty() == 0)
					return true;
				return false;
			}

			size_type	size() const
			{
				return this->_btree.size();
			}

			size_type	max_size() const
			{
				return this->_alloc.max_size();
			}


//=============================
//element access
//=============================
			data_type	&operator[](const key_type& i) 
			{
				iterator it = this->find(i);

				if(it == this->end())
					this->insert(ft::make_pair(i, data_type()));
				return it->second;
			}

//===============================
//modifiers
//===============================
			ft::pair<iterator, bool>	insert(const value_type& val)
			{
				if(this->find(val.first) != this->end())
					return (ft::make_pair(this->end(), false));
				this->_btree.insert(val);
				iterator it = this->find(val.first);
				return ft::make_pair(it, true);
			}

			iterator	insert(iterator pos, const value_type& val)
			{
				this->insert(val);
				pos = this->find(val.first);
				return (pos);
			}

			template<typename InputIterator>
			void	insert(InputIterator first, InputIterator last)
			{
				while(first != last)
				{
					this->_btree.insert(*first);
					first++;
				}
			}

			void erase(iterator pos)
			{
				this->_btree.erase(*pos);
			}

			size_type	erase(const key_type& key)
			{
				if(this->find(key) != this->end())
				{
					this->_btree.erase(ft::make_pair(key, data_type()));
					return 1;
				}
				return 0;
			}

			template<typename InputIterator>
			void	erase(InputIterator first, InputIterator last)
			{
				while(first != last)
				{
					this->erase(first);
					first++;
				}
			}

			void swap(map& other)
			{
				(void)other;
			}

			void	clear()
			{
				iterator	it = this->begin();

				while(it != this->end())
				{
					this->_btree.erase(*it);
					it++;
				}
			}


//===============================
//observers
//===============================
			v_compare	key_comp() const {return v_compare();}

			value_compare	value_comp() const
			{
				return value_compare(this->_btree.get_v_comp());
			}

//===============================
//operations
//===============================
			iterator	find(const key_type& key)
			{
				return iterator(this->_btree.find(ft::make_pair(key, data_type())));
			}

		/*	const_iterator	find(const key_type& key) const
			{
				return const_iterator(this->_btree.find(ft::make_pair(key, data_type())));
			}
*/
			iterator lower_bound (const key_type& k)
			{
				iterator it = this->find(k);

				if(it != this->end())
					return --it;
				return it;

			}

/*			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = this->find(k);

				if(it != this->end())
					return --it;
				return it;
			}
*/
			iterator upper_bound (const key_type& k)
			{
				iterator it = this->find(k);

				if(it != this->end())
					return ++it;
				return it;
			}

/*			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator it = this->find(k);

				if(it != this->end())
					return ++it;
				return it;
			}
*/
			size_type count(const key_type& key) const
			{
				if(this->find(key) != this->end())
				   return 1;
				return 0;
			}

			ft::pair<iterator, iterator>	equal_range (const key_type& k)
			{
				iterator itf, itl;

				itf = this->find(k);
				itl = itf;
				return	ft::make_pair<iterator, iterator>(itf, itl);
			}

	/*		ft::pair<const_iterator, const_iterator>	equal_range (const key_type& k) const
			{
				const_iterator itf, itl;

				itf = this->find(k);
				itl = itf;
				return	ft::make_pair<const_iterator, const_iterator>(itf, itl);
			}
			*/
//===============================
//allocator
//===============================

			alloc_type	get_allocator() const {return this->_alloc;}

//===============================
//debug
//===============================

			void print() {this->_btree.printBT();}
	}; //end map class

//=======================================
//No member functions (vompair operators)
//=======================================

	template<class Key, class T, class Key_of_Value, class Alloc>
	bool	operator == (const map<Key, T, Key_of_Value, Alloc> mf,
			const map<Key, T, Key_of_Value, Alloc> ml)
	{
		return ft::equal(mf.begin(), mf.end(), ml.begin());
	}

	template<class Key, class T, class Key_of_Value, class Alloc>
	bool	operator != (const map<Key, T, Key_of_Value, Alloc> mf,
			const map<Key, T, Key_of_Value, Alloc> ml)
	{
		return !(ft::equal(mf.begin(), mf.end(), ml.begin()));
	}

	template<class Key, class T, class Key_of_Value, class Alloc>
	bool	operator < (const map<Key, T, Key_of_Value, Alloc> mf,
			const map<Key, T, Key_of_Value, Alloc> ml)
	{
		return !(ft::equal(mf.begin(), mf.end(), ml.begin()));
	}

	template<class Key, class T, class Key_of_Value, class Alloc>
	bool	operator > (const map<Key, T, Key_of_Value, Alloc> mf,
			const map<Key, T, Key_of_Value, Alloc> ml)
	{
		return !(ft::equal(mf.begin(), mf.end(), ml.begin()));
	}

	template<class Key, class T, class Key_of_Value, class Alloc>
	bool	operator <= (const map<Key, T, Key_of_Value, Alloc> mf,
			const map<Key, T, Key_of_Value, Alloc> ml)
	{
		return !(ft::equal(mf.begin(), mf.end(), ml.begin()));
	}

	template<class Key, class T, class Key_of_Value, class Alloc>
	bool	operator >= (const map<Key, T, Key_of_Value, Alloc> mf,
			const map<Key, T, Key_of_Value, Alloc> ml)
	{
		return !(ft::equal(mf.begin(), mf.end(), ml.begin()));
	}
	
}//end namespace ft

	
