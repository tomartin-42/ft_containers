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
		bool							black;

		node() {}

		~node() {}

		node(const T & _data, node * _nill) 
		: data(_data), left(_nill), right(_nill), prev(_nill), black(false) {}

		node(node const & other)
		: data(other.data), left(other.left), right(other.right), prev(other.prev), black(other.black) {}

		void set_prev(node* _prev)
		{
			this->prev = _prev;
		}

		//Return true if is black and false if is red
		bool get_color()
		{
			return this->black;
		}

	}; //End node class

} //end namespace ft

#endif
