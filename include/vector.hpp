/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:54:52 by oabdelha          #+#    #+#             */
/*   Updated: 2023/01/12 15:56:36 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <memory>
#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>

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
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): alloc(alloc), __begin(NULL), __end(NULL), __end_cap(NULL)  {
                    size_type n = static_cast<size_type>(std::distance(first, last));
                    if (n > 0)
                    {
                        __vallocate__(n);
                        __construct_at_end__(n, first, last);
                    }
            }

            size_type size() const {
                return (static_cast<size_type>(__end - __begin));
            }

            size_type capacity() const {
                return (static_cast<size_type>(__end_cap - __begin));
            }

            size_type max_size() const {
                return (std::min<size_type>(alloc.max_size(), std::numeric_limits<difference_type>::max()));               
            }

            vector (const vector &x) {
                size_type n = x.size();
                if (n > 0)
                {
                    __vallocate__(n);
                    __construct_at_end__(n, x.__begin, x.__end);
                }
            }

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

    };

    template <class T, class Alloc>
        void
        vector<T, Alloc>::__vallocate__(size_type n) {
            const size_type __new_size = __recommend__(n);
            if (__new_size > max_size())
                throw (std::length_error("can't allocate region"));
            __begin = __end =  std::allocator_traits<Alloc>::allocate(alloc, __new_size);
            __end_cap = __begin + __new_size;
        }

    template <class T, class Alloc>
        void
        vector<T, Alloc>::__construct_at_end__(size_type n, value_type val) {
            while (n > 0)
            {
                std::allocator_traits<Alloc>::construct(alloc, __end, val);
                ++__end;
                --n;
            }
        }

    template <class T, class Alloc>
    template <class InputIterator>
        void
        vector<T, Alloc>::__construct_at_end__(size_type n, InputIterator first, InputIterator last) {
                for (size_type i = 0; first != last; first++, i++)
                    std::allocator_traits<Alloc>::construct(alloc, __begin  + i, *first);
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
                std::allocator_traits<Alloc>::destroy(alloc, --__end);
        }
}

#endif 