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
	template<class Key, class Compare = std::less<Key>, 
		class Alloc = std::allocator<Key> >
	class set
	{
		public:
			typedef	Key														key_type;
			typedef Key														value_type;
			typedef Compare													v_compare;
			typedef Compare													key_compare;
			typedef Alloc													alloc_type;
			typedef typename alloc_type::pointer							pointer;
			typedef typename alloc_type::const_pointer						const_pointer;
			typedef typename alloc_type::reference							reference;
			typedef typename alloc_type::const_reference					const_reference;
			typedef typename alloc_type::size_type							size_type;
			typedef typename alloc_type::difference_type					difference_type;

					//**********************************************//	
		private:
			class	pair_compare 
			{
				v_compare	comp_t;

				public:
					pair_compare(const v_compare& c) : comp_t(c) {}

					bool	operator()(const value_type& x, const value_type& y) const
					{
						return comp_t(x, y);
					}
			};
		public:
			typedef pair_compare											val_comp;
			typedef typename ft::tree<value_type, pair_compare, alloc_type>	rb_tree;
			typedef typename rb_tree::const_iterator								iterator;
			typedef typename rb_tree::const_iterator						const_iterator;
			typedef typename rb_tree::const_reverse_iterator						reverse_iterator;
			typedef typename rb_tree::const_reverse_iterator				const_reverse_iterator;

				//***************************************************//
		private:
			alloc_type			_alloc;
			rb_tree				_btree;
			v_compare			_comp;

//********************************************************************************************************//	
//********************************************constructors************************************************//
		public:
			explicit set(const v_compare& comp_t = v_compare(), const alloc_type& alloc_t = alloc_type()) 
				: _alloc(alloc_t), _btree(rb_tree(comp_t, alloc_t)), _comp(comp_t) {}

			template<class InputIterator>			
			set(InputIterator first, InputIterator last, 
				const v_compare& comp_t = v_compare(), const alloc_type& alloc_t = alloc_type())
				: _alloc(alloc_t), _btree(comp_t, alloc_t), _comp(comp_t)
				{
					while(first != last)
					{
						this->_btree.insert(*first);
						first++;
					}
				}
				
			
			set(const set& other)
				: _alloc(other._alloc), _btree(other._comp, other._alloc), _comp(other._comp)
			{
				this->insert(other.begin(), other.end());
			}

			set& operator= (const set& x)
			{
				this->clear();
				this->insert(x.begin(), x.end());
				return *this;
			}

			//---------------destructor
			virtual	~set() 
			{
				this->clear();
				this->_btree.kill_nill();
			}

//********************************************************************************************************//
//*************************************member fuctions****************************************************//

//==============================
//iterators
//==============================
			const_iterator begin() const {return this->_btree.begin();}


			const_iterator end() const {return this->_btree.end();}


			const_reverse_iterator	rbegin() const {return (this->_btree.rbegin());}


			const_reverse_iterator	rend() const {return (this->_btree.rend());}

//==============================/
//capacity
//==============================
			bool	empty() const
			{
				return this->_btree.empty();
			}

			size_type	size() const
			{
				return this->_btree.size();
			}

			size_type	max_size() const
			{
				return this->_alloc.max_size();
			}

//===============================
//modifiers
//===============================
			ft::pair<iterator, bool>	insert(const value_type& val)
			{
				iterator it = this->find(val);

				if(it != this->end())
					return (ft::make_pair(it, false));
				this->_btree.insert(val);
				it = this->find(val);
				return ft::make_pair(it, true);
			}

			iterator	insert(iterator pos, const value_type& val)
			{
				this->insert(val);
				pos = this->find(val);
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
					this->_btree.erase(key);
					return 1;
				}
				return 0;
			}

			template<typename InputIterator>
			void	erase(InputIterator first, InputIterator last)
			{
				iterator	it;

				while(first != last)
				{
					it = first;
					first++;
					this->erase(it);
				}
			}

			void	clear()
			{
				this->erase(this->begin(), this->end());
			}

			template<typename value_type, typename pair_compare, typename alloc_type>
			void	swap(set<value_type, pair_compare, alloc_type>& other)
			{
				this->_btree.swap(other._btree);
			}
		
//===============================
//observers
//===============================
			v_compare	key_comp() const {return this->_comp;}

			val_comp	value_comp() const
			{
				return (this->_btree.get_v_comp());
			}

//===============================
//operations
//===============================
			iterator	find(const key_type& key)
			{
				return iterator(this->_btree.find(key));
			}

			const_iterator	find(const key_type& key) const
			{
				return const_iterator(this->_btree.find(key));
			}

			iterator lower_bound (const key_type& k)
			{
				for(iterator it = this->begin(); it != this->end(); ++it)
				{
					if(!_comp(*it, k))
						return it;
				}
				return this->end();
			}

			const_iterator lower_bound (const key_type& k) const
			{
				for(const_iterator it = this->begin(); it != this->end(); ++it)
				{
					if(!_comp(*it, k))
						return it;
				}
				return this->end();
			}

			iterator upper_bound (const key_type& k)
			{
				for(iterator it = this->begin(); it != this->end(); ++it)
				{
					if(_comp(k, *it))
						return it;
				}
				return this->end();
			}

			const_iterator upper_bound (const key_type& k) const
			{
				for(const_iterator it = this->begin(); it != this->end(); ++it)
				{
					if(_comp(k, *it))
						return it;
				}
				return this->end();
			}

			size_type count(const key_type& key) const
			{
				if(this->find(key) != this->end())
				   return 1;
				return 0;
			}

			ft::pair<iterator, iterator>	equal_range(const key_type& k)
			{
				return	ft::make_pair(this->lower_bound(k), this->upper_bound(k));
			}

			ft::pair<const_iterator, const_iterator>	equal_range (const key_type& k) const
			{
				return	ft::make_pair(lower_bound(k), upper_bound(k));
			}
//===============================
//allocator
//===============================
			alloc_type	get_allocator() const {return this->_alloc;}

//===============================
//debug
//===============================
		//	void print() {this->_btree.printBT();}
	}; //end set class

//=======================================
//No member functions (vompair operators)
//=======================================

	template<class Key, class T, class Alloc>
	bool	operator == (const set<Key, T, Alloc> m_f,
			const set<Key, T, Alloc> m_l)
	{
		if(m_f.size() != m_l.size())
			return false;
		return ft::equal(m_f.begin(), m_f.end(), m_l.begin());
	}

	template<class Key, class T, class Alloc>
	bool	operator != (const set<Key, T, Alloc> m_f,
			const set<Key, T, Alloc> m_l)
	{
		return !(m_f == m_l);
	}

	template<class Key, class T, class Alloc>
	bool	operator < (const set<Key, T, Alloc> m_f,
			const set<Key, T,  Alloc> m_l)
	{
		return (ft::lexicographical_compare(m_f.begin(), m_f.end(), m_l.begin(), m_l.end()));
	}

	template<class Key, class T, class Alloc>
	bool	operator > (const set<Key, T, Alloc> m_f,
			const set<Key, T,  Alloc> m_l)
	{
		return !(m_f == m_l || m_f < m_l);
	}

	template<class Key, class T, class Alloc>
	bool	operator <= (const set<Key, T, Alloc> m_f,
			const set<Key, T,  Alloc> m_l)
	{
		return !(m_f > m_l);
	}

	template<class Key, class T, class Alloc>
	bool	operator >= (const set<Key, T, Alloc> m_f,
			const set<Key, T,  Alloc> m_l)
	{
		return !(m_f < m_l);
	}
	
	template<class Key, class T, class Alloc>
	void	swap(set<Key, T, Alloc> &m_f,
			set<Key, T, Alloc> &m_l)
	{
		set<Key, T, Alloc>	aux;

		aux = m_f;
		m_f = m_l;
		m_l = aux;
	}
}//end namespace ft

	
