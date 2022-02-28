#ifndef VECTOR_HPP
# define VECTOR_HPP

template <class T, class alloc = allocator<T>i > 
class vector
{
	public:
		typedef	alloc											allocator_type;
		typedef T												value_type;
		typedef typename alloc_type::reference					reference;
		typedef typename alloc_type::const_eference				const_reference;
		typedef typename alloc_type::pointer					pointer;
		typedef typename alloc_type::const_pointer				const_pointer;
		typedef std::random_access_iterator<value_type>			iterator;
		typedef std::random_access_iterator<const value_type>	const_iterator;
		typedef std::random_access_iterator<iterator>			reverse_iterator;
		typedef std::random_access_iterator<const iterator>		const_reverse_iterator;
		
/*		//constructors
		//empty
		explicit vector (const allocator_type& alloc = allocator_type()) 

		//fill
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())

		//range
		vector (InputIterator first, InputIterator last, 
				const allocator_type& alloc = allocator_type())

		//copy
		vector (const vector& x)
*/

		
