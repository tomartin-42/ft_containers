/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:42:38 by tomartin          #+#    #+#             */
/*   Updated: 2022/07/31 20:04:19 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TREE_HPP_
# define _TREE_HPP_

#include <memory>
#include <algorithm> //for std::swap
#include "tree_iterator.hpp"
#include "const_tree_iterator.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "utils.hpp"
#include "node.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "nullptr.hpp" //to ft::nullptr
#include "pair.hpp"

namespace ft
{
	template<class T, class compare = std::less<T>, class alloc = std::allocator<T> >
	class tree
	{
		public:
			typedef T																value_type;
			typedef compare															value_comp;
			typedef alloc															alloc_type;
			typedef ft::node<T>														node;
			typedef typename alloc::template rebind<ft::node<value_type> >::other	alloc_node;
			typedef typename alloc_node::pointer									node_pointer;
			typedef typename alloc_type::reference									reference;
			typedef typename alloc_type::const_reference							const_reference;
			typedef typename alloc_type::pointer									pointer;
			typedef typename alloc_type::const_pointer								const_pointer;
			typedef typename alloc_type::size_type									size_type;
			typedef typename alloc_type::difference_type							diference_type;
			typedef typename ft::tree_iterator<value_type>							iterator;
			typedef typename ft::const_tree_iterator<value_type>					const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;

		private:
			alloc_node		_alloc_node;
			node_pointer	_root;
			node_pointer	_nill;
			size_type		_size;
			value_comp		_comp;
		
		public:
			//-------------default constructor---------------------------------//
			tree(const value_comp& comp_t = value_comp(), const alloc_type & alloc_t = alloc_type()) : 
			_alloc_node(alloc_t), _size(0), _comp(comp_t) 
			{
				this->_nill = alloc_node().allocate(1);
				this->_nill->prev = this->_nill;
				this->_nill->right = this->_nill;
				this->_nill->left = this->_nill;
				this->_nill->nill = true;
				this->_nill->black = true;
				this->_root = this->_nill;
			}

			//-----------------copy constructor---------------------------------//
			tree(const tree& other) : _alloc_node(other._alloc_node), _nill(other._nill),
				_size(other._size), _comp(other._comp)
			{
				*this = other;
			}

			virtual ~tree() 
			{
				this->clear();
				this->kill_nill();
			}

//==========================
//Aux functions
//==========================
		private:
			bool is_nill(node_pointer& check) const
			{
				return (check == this->_nill ? true : false);
			}

			bool is_no_nill(node_pointer& check) const
			{
				return (check == this->_nill ? false : true);
			}

			void	transplant(node_pointer& a, node_pointer& b)
			{
 				if(this->is_nill(a->prev))
				{
      				this->_root = b;
					this->_nill->prev = b;
				}
				else if(a == a->prev->left) 
					a->prev->left = b;
				else
					a->prev->right = b;
				b->prev = a->prev;
				this->assig_nill_values();
			}
				
		public:
			void	kill_nill()
			{
				this->_alloc_node.deallocate(this->_nill, 1);
			}

			node_pointer get_root() {return this->_root;}

			node_pointer minimum(const node_pointer n) const
			{
				node_pointer aux = n;

				while(aux->left != this->_nill)
				{
					aux = aux->left;
				}
				return aux;
			}
	
			node_pointer minimum(node_pointer n) 
			{
				while(n->left != this->_nill)
				{
					n = n->left;
				}
				return n;
			}

			node_pointer maximum(const node_pointer n) const
			{
				node_pointer aux = n;

				while(aux->right != this->_nill)
					aux = aux->right;
				return aux;
			}
	
			node_pointer maximum(node_pointer n) 
			{
				while(n->right != this->_nill)
				{
					n = n->right;
				}
				return n;
			}

			node_pointer	next_node(const node_pointer n) const
			{
				if (n->left != this->_nill)
					return minimun(n->left);
				while (n == n->prev->right)
					n = n->prev;
				return n->prev;
			}

			node_pointer	prev_node(const node_pointer n) const
			{
				if (n->right != this->_nill)
					return maximun(n->right);
				while (n == n->prev->rigth)
					n = n->prev;
				return n->prev;
			}

			void	right_rotate(node_pointer x)
			{
				node_pointer y = x->left;
				  				
				x->left = y->right;
 				if(y->right != this->_nill)
  					y->right->prev = x;
  				y->prev = x->prev;
 				if(x->prev == this->_nill)
  					this->_root = y;
				else if(x == x->prev->right)
					x->prev->right = y;
				else					
 					x->prev->left = y;
				y->right = x;
				x->prev = y;
				this->assig_nill_values();
			}

			void	left_rotate(node_pointer x)
			{
				node_pointer y = x->right;

  				x->right = y->left;
 				if(y->left != this->_nill)
  					y->left->prev = x;
  				y->prev = x->prev;
 				if(x->prev == this->_nill)
  					this->_root = y;
				else if(x == x->prev->left)
					x->prev->left = y;
				else					
 					x->prev->right = y;
				y->left = x;
				x->prev = y;
				this->assig_nill_values();
			}

			void	assig_nill_values()
			{
				if(this->_size != 0)
				{
					this->_nill->prev = this->_root; 
					this->_nill->left = this->minimum(this->_root);
					this->_nill->right = this->maximum(this->_root);
					this->_nill->black = true;
				}
				else 
				{
					this->assig_to_nill(this->_nill);
				}
			}

			void	assig_to_nill(node_pointer& p_n)
			{
				p_n->prev = this->_nill;
				p_n->right = this->_nill;
				p_n->left = this->_nill;
			}

			void	kill_node(node_pointer& node)
			{
				this->_alloc_node.destroy(node);
				this->_alloc_node.deallocate(node, 1);
				this->_size -= 1;
			}

			void	insert_fix(node_pointer p_node)
			{
				node_pointer u(ft::nullptr_t);
				
				while(p_node->prev->black == false)
				{
					if(p_node->prev == p_node->prev->prev->left)
					{
						u = p_node->prev->prev->right;
						if(u->black == false)
						{
							u->black = true;
							p_node->prev->black = true;
							p_node->prev->prev->black = false;
							p_node = p_node->prev->prev;
						}
						else
						{
							if(p_node == p_node->prev->right)
							{
								p_node = p_node->prev;
								left_rotate(p_node);
							}
							p_node->prev->black = true;
							p_node->prev->prev->black = false;
							right_rotate(p_node->prev->prev);
						}
					}
					else
					{
						u = p_node->prev->prev->left;
						if(u->black == false)
						{
							u->black = true;
							p_node->prev->black = true;
							p_node->prev->prev->black = false;
							p_node = p_node->prev->prev;
						}
						else
						{
							if(p_node == p_node->prev->left)
							{
								p_node = p_node->prev;
								right_rotate(p_node);
							}
							p_node->prev->black = true;
							p_node->prev->prev->black = false;
							left_rotate(p_node->prev->prev);
						}
					}
					if(p_node == this->_root)
						break;
				}
				this->_root->black = true;
			}

			void erase_fix(node_pointer x)
			{
				node_pointer	s;

				while(x != this->_root && x->black == true)
				{
					if(x == x->prev->left)
					{
						s = x->prev->right;
						if(s->black == false)
						{
							s->black = true;
							x->prev->black = false;
							left_rotate(x->prev);
							s = x->prev->right;
						}
						if(s->left->black == true && s->right->black == true)
						{
							s->black = false;
							x = x->prev;
						}
						else
						{
							if(s->right->black == true)
							{
								s->left->black = true;
								s->black = false;
								right_rotate(s);
								s = x->prev->right;
							}
							s->black = x->prev->black;
							x->prev->black = true;
							s->right->black = true;
							left_rotate(x->prev);
							x = this->_root;
						}
					}
					else
					{
						s = x->prev->left;
						if(s->black == false)
						{
							s->black = true;
							x->prev->black = false;
							right_rotate(x->prev);
							s = x->prev->left;
						}
						if(s->right->black == true && s->left->black == true)
						{
							s->black = false;
							x = x->prev;
						}
						else
						{
							if(s->left->black == true)
							{
								s->right->black = true;
								s->black = false;
								left_rotate(s);
								s = x->prev->left;
							}
							s->black = x->prev->black;
							x->prev->black = true;
							s->left->black = true;
							right_rotate(x->prev);
							x = this->_root;
						}
					}
				}
				x->black = true;
			}

//==========================
//Iterators
//==========================
			public:
			iterator		begin() {return iterator(this->minimum(this->_root));}

			const_iterator	begin() const {return const_iterator(this->minimum(this->_root));}

			iterator		end() {return iterator(this->_nill);}
			
			const_iterator	end() const {return const_iterator(this->_nill);}

			iterator		rbegin() {return this->end();}

			const_iterator	rbegin() const {return this->end();}

			iterator		rend() {return this->begin();}

			const_iterator	rend() const {return this->begin();}

//==========================
//Capacity
//==========================
			bool	empty() const
			{
				if(this->_size == 0)
					return true;
				return false;
			}

			size_type	size() const {return this->_size;}

			size_type	max_size() const {return this->_alloc.max.size();}

//===========================
//Observers
//===========================
		value_comp	get_v_comp() const
		{
			return this->_comp;
		}

//==========================
//Modifiers
//==========================
			value_type insert(const value_type& nod)
			{
				if(this->find(nod) != this->end())
					return nod;
				node_pointer p_node = this->_alloc_node.allocate(1);

				this->_alloc_node.construct(p_node, ft::node<T>(nod, _nill));
				if(this->_size == 0) //When the tree in empty new node is root
				{
					this->_root = p_node;
					this->assig_to_nill(this->_root);
					this->_nill->prev = p_node;
					this->_size += 1;
					p_node->black = true;
					return (p_node->get_data());
				}
				node_pointer y = this->_nill;
			    node_pointer x = this->_root;
				
				while (x != this->_nill)
				{
					y = x;
					if (this->_comp((p_node->get_data()), (x->get_data())))
						x = x->left;
					else 
						x = x->right;
			    }
			    p_node->prev = y;
				if (this->_comp((p_node->get_data()),(y->get_data())))
					y->left = p_node;
				else
					y->right = p_node;
				this->_root->black = true;
			    insert_fix(p_node);
				this->_size += 1;
				this->assig_nill_values();
				return (p_node->get_data());
			}

			node_pointer	brother(node_pointer& n)
			{
				if(n == n->prev->right)
					return n->prev->left;
				else
					return n->prev->right;
			}

			node_pointer	lower_brother(node_pointer& n)
			{
					return n->prev->left;
			}

			size_type	erase(const value_type& val)
			{
				if(this->find(val) == this->end())
				{
					return (0);
				}
				node_pointer	d_node(this->_find(val));
				node_pointer	aux = d_node;
				node_pointer	x;
				node_pointer	y;
				bool			save_color;
			
				y = aux;
				save_color = y->black;
				if(this->is_nill(aux->left))
				{
					x = aux->right;
					this->transplant(aux, aux->right);
					
				}
				else if(this->is_nill(aux->right))
				{
					x = aux->left;
					this->transplant(aux, aux->left);
				}
				else
				{
					y = minimum(aux->right);
					save_color = y->black;
					x = aux->right;
					if(y->prev == aux)
						x->prev = y;
					else
					{
						this->transplant(y, y->right);
						y->right = aux->right;
						y->right->prev = y;
					}
					transplant(aux, y);
					y->left = aux->left;
					y->left->prev = y;
					y->black = aux->black;
				}
				kill_node(aux);
				if(save_color == true)
				{
					erase_fix(x);
				}
				this->assig_nill_values();
				return (1);
			}

			void	swap(tree<T, compare, alloc>& other)
			{
				std::swap(this->_root, other._root);
				std::swap(this->_nill->prev, other._nill->prev);
				std::swap(this->_nill->left, other._nill->left);
				std::swap(this->_nill->right, other._nill->right);
				std::swap(this->_nill, other._nill);
				std::swap(this->_size, other._size);
				std::swap(this->_comp, other._comp);
			}

//==========================
//Operations
//==========================

			iterator	find(const value_type& val)
			{
				node_pointer	aux = this->_root;

				while(is_no_nill(aux))
				{
					if(this->_comp(val, (aux->get_data())))
						aux = aux->left;
					else if(this->_comp((aux->get_data()), val))
						aux = aux->right;
					else
						return iterator(aux);
				}
				return this->end();
			}

			const_iterator	find(const value_type& val) const
			{
				node_pointer	aux = this->_root;
				
				while(is_no_nill(aux))
				{
					if(this->_comp(val, aux->get_data()))
						aux = aux->left;
					else if(this->_comp(aux->get_data(), val))
						aux = aux->right;
					else
						return const_iterator(aux);
				}
				return this->end();
			}

			private:
			node_pointer	_find(const value_type& val)
			{
				node_pointer	aux = this->_root;

				while(is_no_nill(aux))
				{
					if(this->_comp(val, (aux->get_data())))
						aux = aux->left;
					else if(this->_comp((aux->get_data()), val))
						aux = aux->right;
					else
						return (aux);
				}
				return this->_nill;
			}

			const_pointer	_find(const value_type& val) const
			{
				node_pointer	aux = this->_root;
				
				while(is_no_nill(aux))
				{
					if(this->_comp(val, aux->get_data()))
						aux = aux->left;
					else if(this->_comp(aux->get_data(), val))
						aux = aux->right;
					else
						return (aux);
				}
				return this->_nill;
			}
			
			void	clear()
			{
				if(this->_size != 0)
				{
					this->destroy_tree(this->_root);
					this->_size = 0;
					assig_to_nill(this->_nill);
				}
			}
			
			void	destroy_tree(node_pointer node)
			{
				if (!node->nill)
				{
					if (node->left && !node->left->nill)
						destroy_tree(node->left);
					if (node->right && !node->right->nill)
						destroy_tree(node->right);
					this->kill_node(node);
				}
			}

//=============================
//To debug
//=============================
/*
			public:
			void printBT(const std::string& prefix, const node_pointer node, bool isright)
			{
    			if(node != this->_nill)
    			{
        			std::cout << prefix;
			        std::cout << (isright ? "├──" : "└──" );

        			// print the value of the node
        			std::cout << node->get_data().first << "-" << node->get_data().second << " " << node->black;
        			std::cout << " nill right= " << is_nill(node->right) << " - " << "nill left= " << is_nill(node->left) << std::endl;

        			// enter the next tree level - right and left branch
        			printBT( prefix + (isright ? "│   " : "    "), node->right, true);
        			printBT( prefix + (isright ? "│   " : "    "), node->left, false);
    			}
			}
			
			void printBT(const node_pointer node)
			{
    			printBT("", node, false);
			}

			void printBT()
			{
				printBT(this->_root);
			}
*/
	};//end tree class
}//end ft namespace

#endif
