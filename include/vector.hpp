/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:54:52 by oabdelha          #+#    #+#             */
/*   Updated: 2023/01/17 17:29:45 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <memory>
#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <iterator>

namespace ft {
    template < class T, class Alloc = std::allocator<T> > 
        class vector {
        public:
            typedef  T                                          value_type;
            typedef  Alloc                                      allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::difference_type    difference_type;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef ft::IterVector<pointer>                     iterator;
            typedef ft::IterVector<const_pointer>               const_iterator;
            typedef ft::ReverseIterVector<pointer>              reverse_iterator;
            typedef ft::ReverseIterVector<const_pointer>        const_reverse_iterator;
            
            //methods
            explicit vector(const allocator_type& alloc = allocator_type()): alloc(alloc), __begin(NULL), __end(NULL), __end_cap(NULL) {
                
            }

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): alloc(alloc), __begin(NULL), __end(NULL), __end_cap(NULL) {
                if (n > 0)
                {
                    __vallocate__(n);
                    __construct_at_end__(n, val);
                }
            }

            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): alloc(alloc), __begin(NULL), __end(NULL), __end_cap(NULL) {
                    size_type n = static_cast<size_type>(std::distance(first, last));
                    if (n > 0)
                    {
                        __vallocate__(n);
                        __construct_at_end__(n, first, last);
                    }
            }

            vector (const vector &x) {
                size_type n = x.size();
                if (n > 0)
                {
                    __vallocate__(n);
                    __construct_at_end__(n, x.__begin, x.__end);
                }
            }

            // vector& operator= (const vector& x) {
            //     if (this != &x)
            //     {
                    
            //     }
            //     return (*this);
            // }

            // template <class InputIterator>
            // void assign (InputIterator first, InputIterator last) {
            //     size_type __new_size = static_cast<size_type>(std::distance(first, last));
            //     if (__new_size <= capacity())
			// 	{
			// 		if (__new_size > size())
            //         {
                        
            //         }
			// 	}
			// 	else {
			// 		__vdeallocate__();
            // 		__vallocate__(__recommend__(__new_size));
            //     	__construct_at_end__(first, last, __new_size);
			// 	}
            // }
            
            //iteartors
            iterator begin() {
                return (__make_iterator__(__begin));
            }
            
            const_iterator cbegin() const {
                return (__make_iterator__(__begin));
            }
            
            iterator end() {
                return (__make_iterator__(__end));
            }

            const_iterator cend() const {
                return (__make_iterator__(__end));
            }

            reverse_iterator rbegin() {
                return (__make_reverse_iterator__(__end - 1));
            }
            
            const_reverse_iterator crbegin() const {
                return (__make_reverse_iterator__(__end - 1));
            }

            reverse_iterator rend() {
                return (__make_reverse_iterator__(__begin - 1));
            }

            const_reverse_iterator crend() const {
                return (__make_reverse_iterator__(__begin - 1));
            }
            //end_iterators

            //capacity
            size_type size() const {
                return (static_cast<size_type>(__end - __begin));
            }

            size_type capacity() const {
                return (static_cast<size_type>(__end_cap - __begin));
            }

            size_type max_size() const {
                return (std::min<size_type>(alloc.max_size(), std::numeric_limits<difference_type>::max()));               
            }

            bool empty() const
            {
                return (__begin == __end);
            }
            
                        
            //end_capacity
            
            //element access
            reference operator[] (size_type n) {
                return (__begin[n]);
            }
            
            const_reference operator[] (size_type n) const {
                return (__begin[n]);
            }

            reference at (size_type n) {
                if (n >= size())
                    throw std::out_of_range("vector");
                return (__begin[n]);
            }

            const_reference at (size_type n) const {
                if (n >= size())
                    throw std::out_of_range("vector");
                return (__begin[n]);
            }
            
            reference front() {
                return (*__begin);
            }
            
            const_reference front() const {
                return (*__begin);
            }

            reference back() {
                return (*(__end - 1));
            }
            
            const_reference back() const {
                return (*(__end - 1));
            }
            
            value_type* data() {
                return (__begin);
            }

            const value_type* data() const {
                return (__begin);
            }

            //end_element access
            void clear() {
                __destruct_at_end__(__begin);
            }

            ~vector() {
                if (__begin != NULL)
                {
                    clear();
                    std::allocator_traits<Alloc>::deallocate(alloc, __begin, capacity());
                }
            }

        private:
            allocator_type                                      alloc;
            pointer                                             __begin;
            pointer                                             __end;
            pointer                                             __end_cap;

            //methods 
            void                                                __vallocate__(size_type);
            void                                                __construct_at_end__(size_type, value_type);
            template <class InputIterator>
                void                                            __construct_at_end__(size_type, InputIterator, InputIterator);
            size_type                                           __recommend__(size_type) const;
            void                                                __destruct_at_end__(pointer);
			void												__vdeallocate__();
            inline iterator                                     __make_iterator__(pointer);
            inline const_iterator                               __make_iterator__(const_pointer) const;
            inline reverse_iterator                             __make_reverse_iterator__(pointer);
            inline const_reverse_iterator                       __make_reverse_iterator__(const_pointer) const;
            
    };

    template <class T, class Alloc>
        void
        vector<T, Alloc>::__vallocate__(size_type n) {
            const size_type __new_size = __recommend__(n);
            if (__new_size > max_size())
                throw (std::length_error("can't allocate region"));
            __begin = __end =  alloc.allocate(__new_size);
            __end_cap = __begin + __new_size;
        }

    template <class T, class Alloc>
        void
        vector<T, Alloc>::__construct_at_end__(size_type n, value_type val) {
            while (n > 0)
            {
                alloc.construct(__end, val);
                ++__end;
                --n;
            }
        }

    template <class T, class Alloc>
    template <class InputIterator>
        void
        vector<T, Alloc>::__construct_at_end__(size_type n, InputIterator first, InputIterator last) {
                for (size_type i = 0; first != last; first++, i++)
                    alloc.construct(__begin  + i, *first);
                __end_cap = __end = __begin + n;
        }

    template <class T, class Alloc>
        typename vector<T, Alloc>::size_type
        vector<T, Alloc>::__recommend__(size_type __new_size) const {
            const size_type __ms = max_size();
            if (__new_size > __ms)
                throw (std::length_error("can't allocate region"));
            const size_type __cap = capacity();
            if (__cap >= __ms / 2)
                return (__ms);
            return (std::max<size_type>(2 * __cap, __new_size));
        }

    template <class T, class Alloc>
        void
        vector<T, Alloc>::__destruct_at_end__(pointer __new_last) {
            while (__new_last != __end)
                alloc.destroy(--__end);
        }

	template <class T, class Alloc>
        void
        vector<T, Alloc>::__vdeallocate__()
        {
            if (this->__begin_ != NULL)
            {
                clear();
                alloc.deallocate(__begin, capacity());
                __begin = __end = __end_cap = NULL;
            }
        }

    template <class T, class Alloc>
        inline
            typename vector<T, Alloc>::const_iterator
            vector<T, Alloc>::__make_iterator__(const_pointer __p) const {
            return const_iterator(__p);
        }

     template <class T, class Alloc>
        inline
            typename vector<T, Alloc>::iterator
            vector<T, Alloc>::__make_iterator__(pointer __p) {
            return iterator(__p);
        }
        
    template <class T, class Alloc>
        inline
            typename vector<T, Alloc>::const_reverse_iterator
            vector<T, Alloc>::__make_reverse_iterator__(const_pointer __p) const {
            return const_reverse_iterator(__p);
        }
    
    template <class T, class Alloc>
        inline
            typename vector<T, Alloc>::reverse_iterator
            vector<T, Alloc>::__make_reverse_iterator__(pointer __p) {
            return reverse_iterator(__p);
        }
}

#endif 