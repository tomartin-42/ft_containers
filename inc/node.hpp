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

		~node() {}

		node(const T & _data, node * _nill) 
		: data(_data), left(_nill), right(_nill), prev(_nill), nill(false), black(false) {}

		node(node const & other)
		: data(other.data), left(other.left), right(other.right), prev(other.prev), black(other.black) {}

		void	set_prev(node* _prev)
		{
			this->prev = _prev;
		}
		
		void	set_nill(bool set)
		{
			this->nill = set;
		}

		bool get_nill()
		{
			std::cout << "QUEEEEEE!!!!\n";
			return this->nill;
		}

		//Return true if is black and false if is red
		bool get_color()
		{
			return this->black;
		}

	}; //End node class

} //end namespace ft

#endif
