/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:42:38 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/25 19:23:28 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TREE_HPP_
# define _TREE_HPP_

#include <memory>
#include "tree_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "utils.hpp"
#include "node.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "nullptr.hpp" //to ft::nullptr

namespace ft
{

	template<class T, class compare, class alloc = std::allocator<T> >
	class tree
	{
		public:
			typedef T																value_type;
			typedef compare															value_comp;
			typedef alloc															alloc_type;
			typedef ft::node<T>														node;
			typedef const node														const_node;
			typedef node*															node_pointer;
			typedef const node*														const_node_pointer;
			typedef typename alloc::template rebind<ft::node<value_type> >::other	alloc_node;
			typedef typename alloc_type::size_type									size_type;
			typedef typename alloc_type::difference_type							diference_type;
			typedef typename ft::tree_iterator<node>								iterator;
			typedef typename ft::tree_iterator<const_node>							const_iterator;

		private:
			alloc_node		_alloc;
			node_pointer	_root;
			node			_nill;
			size_type		_size;
			value_comp		_comp;
		
		public:
			tree(const alloc_type & alloc_t = alloc_type()) : 
			_alloc(alloc_t), _root(&_nill), _nill(), _size(0), _comp(compare()) 
			{
				this->_nill.prev = &this->_nill;
				this->_nill.left = &this->_nill;
				this->_nill.right = &this->_nill;
				this->_nill.black = true;
			}

//==========================
//Aux functions
//==========================

			node_pointer get_nill() {return &this->_nill;}

			//maybe implement with const_pointer too
			node_pointer minimum(const node_pointer n) const
			{
				node_pointer aux = n;

				while(aux->left != &this->_nill)
					aux = aux->left;
				return aux;
			}

			node_pointer minimum(node_pointer n) 
			{
				node_pointer aux = n;

				while(aux->left != &this->_nill)
					aux = aux->left;
				return aux;
			}

			node_pointer maximum(const node_pointer n) const
			{
				node_pointer aux = n;

				while(aux->right != &this->_nill)
					aux = aux->right;
				return aux;
			}

			node_pointer maximum(node_pointer n) 
			{
				node_pointer aux = n;

				while(aux->right != &this->_nill)
					aux = aux->right;
				return aux;
			}

			node_pointer	next_node(const node_pointer n) const
			{
				if (n->right != this->_nill)
					return minimun(n->right);
				while (n == n->prev->left)
					n = n->prev;
				return n->prev;
			}

			node_pointer	prev_node(const node_pointer n) const
			{
				if (n->left != this->_nill)
					return maximun(n->left);
				while (n == n->prev->rigth)
					n = n->prev;
				return n->prev;
			}

			void	left_rotate(node_pointer x)
			{
				node_pointer y = x->right;
  				
				x->right = y->left;
 				if(y->left != &this->_nill)
  					y->left->prev = x;
  				y->prev = x->prev;
 				if(x->prev == &this->_nill) 	//x is root
  					this->_root = y;
				else if(x == x->prev->left)		// x is left child
					x->prev->left = y;
				else							// x is right child
 					x->prev->right = y;
				y->left = x;
				x->prev = y;
				this->assig_nill_values();
			}

			void	right_rotate(node_pointer x)
			{
				node_pointer y = x->left;

  				x->left = y->right;
 				if(y->right != &this->_nill)
  					y->right->prev = x;
  				y->prev = x->prev;
 				if(x->prev == &this->_nill) 	//x is root
  					this->_root = y;
				else if(x == x->prev->right)	// x is left child
					x->prev->right = y;
				else							// x is right child
 					x->prev->left = y;
				y->right = x;
				x->prev = y;
				this->assig_nill_values();
			}

			void	assig_nill_values()
			{
				this->_nill.prev = this->_root; 
				this->_nill.left = this->minimum(this->_root);
				this->_nill.right = this->maximum(this->_root);
			}

			void	assig_to_nill(node_pointer& p_n)
			{
				p_n->prev = &this->_nill;
				p_n->left = &this->_nill;
				p_n->right = &this->_nill;
			}

			void	insert_fix(node_pointer p_node)
			{
				node_pointer u;

				while (p_node->prev->black == false)
				{
					if (p_node->prev == p_node->prev->prev->right)
					{
						if(p_node->prev != &this->_nill || p_node->prev->prev != &this->_nill)
							p_node->prev->prev->left == p_node->prev ? u = p_node->prev->prev->right 
								: u = p_node->prev->prev->left;
						if (u && u->black == false)
						{
							if(p_node->prev != &this->_nill || p_node->prev->prev != &this->_nill)
								p_node->prev->prev->left == p_node->prev ? p_node->prev->prev->right->black = true
									: p_node->prev->prev->left->black = true;
							p_node->prev->black = true;
							p_node->prev->prev->black = false;
							p_node = p_node->prev->prev;
						}
						else
						{
							if (p_node == p_node->prev->left)
							{
								p_node = p_node->prev;
								right_rotate(p_node);
							}
							p_node->prev->black = true;
							p_node->prev->prev->black = false;
							left_rotate(p_node->prev->prev);
						}
					}
					else
					{
						if(p_node->prev != &this->_nill || p_node->prev->prev != &this->_nill)
							p_node->prev->prev->left == p_node->prev ? u = p_node->prev->prev->right 
								: u = p_node->prev->prev->left;

						if (u && u->black == false)
						{
							if(p_node->prev != &this->_nill || p_node->prev->prev != &this->_nill)
								p_node->prev->prev->left == p_node->prev ? p_node->prev->prev->right->black = false
									: p_node->prev->prev->left->black = false;
							p_node->prev->black = true;
							p_node->prev->prev->black = false;
							p_node = p_node->prev->prev;
						}
						else
						{
							if (p_node == p_node->prev->right)
							{
								p_node = p_node->prev;
								left_rotate(p_node);
							}
							p_node->prev->black = true;
							p_node->prev->prev->black = false;
							right_rotate(p_node->prev->prev);
						}
					}
					if (p_node == this->_root)
						break ;
				}
				this->_root->black = true;
  			}
//==========================
//Iterators
//==========================
			iterator		begin() {return iterator(this->minimum(this->_root));}

			const_iterator	begin() const {return const_iterator(this->minmum(this->_root));}

			iterator		end() {return iterator(this->maximum(this->_root));}
			
			const_iterator	end() const {return const_iterator(this->maximum(this->_root));}


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

//==========================
//Operations
//==========================


//==========================
//Modifiers
//==========================
			value_type insert(const value_type& nod)
			{
				node_pointer p_node = this->_alloc.allocate(1);

				this->_alloc.construct(p_node, ft::node<T>(nod, &_nill));
				if(this->_size == 0)							//When new node is root
				{
					this->_root = p_node;
					this->assig_to_nill(this->_root);
					this->_nill.set_prev(p_node);
					this->_size += 1;
			    //	p_node->black = true;
			    	insert_fix(p_node);
					return (p_node->get_data());
				}
				node_pointer y = &this->_nill;
			    node_pointer x = this->_root;
				
				while (x != &_nill)
				{
					y = x;
					if (this->_comp(p_node->get_data(), x->get_data()))
						x = x->right;
					else 
						x = x->left;
			    }
			    p_node->prev = y;
				//std::cout << p_node->get_data() << "===" << y->get_data() << std::endl;
				if (this->_comp(p_node->get_data(), y->get_data()))
					y->right = p_node;
				else
					y->left = p_node;

				//if (p_node->prev->prev == &this->_nill)
				//	return (p_node->get_data());

				this->_root->black = true;
			    insert_fix(p_node);
				return (p_node->get_data());
			}

//==========================
//Operations
//==========================

			iterator	find(const value_type& val)
			{
				node_pointer	aux = this->_root;

				while(aux != &this->_nill)
				{
					if(this->_comp(val, aux->get_data()))
						aux = aux->left;
					if(this->_comp(aux->get_data(), val))
						aux = aux->right;
					else
						return iterator(aux);
				}
				return iterator(ft::nullptr_t);
			}

			const_iterator	find(const value_type& val) const
			{
				node_pointer	aux = this->_root;

				while(aux != &this->_nill)
				{
					if(this->_comp(val, aux->get_data()))
						aux = aux->left;
					if(this->_comp(aux->get_data(), val))
						aux = aux->right;
					else
						return iterator(aux);
				}
				return iterator(ft::nullptr_t);
			}

			//size_type	count(const value_type& val) const
			//{
			//}
			void printBT(const std::string& prefix, const node_pointer node, bool isLeft)
			{
    			if(node != &this->_nill)
    			{
        			std::cout << prefix;
			        std::cout << (isLeft ? "├──" : "└──" );

        			// print the value of the node
        			std::cout << node->get_data() << " " << node->black << std::endl;

        			// enter the next tree level - left and right branch
        			printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        			printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
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

	};//end tree class
}//end ft namespace

#endif
