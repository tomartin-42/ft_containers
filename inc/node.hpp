#ifndef _NODE_HPP_
# define _NODE_HPP_

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
		typedef typename ft::nullptr_t	nul:

		node(const T & _data, node * nul) 
		: data(_data), left(nul), right(nul), prev(nul), black(false) {}

		node(node const & other)
		: data(other._data), left(other.left), right(other.right), prev(other.prev), black(other.black) {}

		set_prev(node* _prev)
		{
			this->prev = prev;
		}

		set_all_branches(node * _l, node * _r, node * _p)
		{
			if(_l != nul)
				this->left = _l;
			if(_r != nul)
				this->right = _r;
			if(_r != nul)
				this->prev = _p;
		}
	}
}; //end namespace ft

#endif
