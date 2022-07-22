#ifndef _NODE_HPP_
# define _NODE_HPP_

#include "nullptr.hpp"

//This class represent each node in the tree.
//Have 3 pointers, left, rigth, and prev.
//I would like to do red an black tree because of this I create a
//bool black type, if black is thrue the node is black else is red.

namespace ft
{
	template<typename T>
	struct node
	{
		typedef	T						value_type;
		value_type						data;
		node*							left;
		node*							right;
		node*							prev;
		bool							nill;
		bool							black;

		node() : nill(true) {}

		node(const T val) : data(val), nill(false) {}

		node(const T& _data, node* _nill) 
		: data(_data), left(_nill), right(_nill), prev(_nill), nill(false), black(false) {}

		//-------------------------destructor
		~node() {}

		node(node const& other) : data(other.data)
		{
			left = other.left;
			right = other.right;
			prev = other.prev;
			nill = other.nill;
			black = other.black;
		}
		
		value_type& get_data() 
		{
			return data;
		}

		const value_type& get_data() const 
		{
			return data;
		}

		void	set_prev(node* _prev)
		{
			this->prev = _prev;
		}
		
		void	set_nill(bool set)
		{
			this->nill = set;
		}

		bool get_nill() const
		{
			return this->nill;
		}

		bool get_nill() 
		{
			return this->nill;
		}

		//Return true if is black and false if is red
		bool get_color()
		{
			return this->black;
		}
//==========================
//debug
//==========================
/*
		void	print_pointer()
		{
			std::cout << "NODE========================" << std::endl;
			if(this->get_nill())
				print_nill(this);
			else
				std::cout << "NODE= " << this << std::endl;
			
			std::cout << "PREV========================" << std::endl;
			if(this->prev->get_nill())
				print_nill(this->prev);
			else
				std::cout << "PREV= " << this->prev << std::endl;
			
			std::cout << "LEFT========================" << std::endl;
			if(this->left->get_nill())
				print_nill(this->left);
			else
				std::cout << "LEFT= " << this->left << std::endl;
			
			std::cout << "RIGHT========================" << std::endl;
			if(this->right->get_nill())
				print_nill(this->right);
			else
				std::cout << "RIGHT= " << this->right << std::endl;
			std::cout << "***************************************************\n";
			std::cout << "***************************************************\n";
		}

		void 	print_nill(node* p)
		{
			std::cout << "!!!NILL_NODE!!!" << std::endl;
			std::cout << "NODE= " << p << std::endl;
			std::cout << "PREV= " << p->prev << std::endl;
			std::cout << "LEFT= " << p->left << std::endl;
			std::cout << "RIGHT= " << p->right << std::endl;
		}
*/
	}; //End node class

} //end namespace ft

#endif
