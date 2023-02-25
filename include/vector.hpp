/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:54:52 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/25 11:27:17 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <algorithm>
#include <exception>
#include <iostream>
#include <memory>

#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utility.hpp"
namespace ft {
    template <class T, class Alloc = std::allocator<T> >
    class vector {
    public:
        typedef T                                        value_type;
        typedef Alloc                                    allocator_type;
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::const_pointer   const_pointer;
        typedef ft::IterVector<pointer>                  iterator;
        typedef ft::IterVector<const_pointer>            const_iterator;
        typedef ft::ReverseIterator<pointer>             reverse_iterator;
        typedef ft::ReverseIterator<const_pointer>       const_reverse_iterator;

        // Constructors
        explicit vector(const allocator_type &alloc = allocator_type())
            : alloc(alloc)
            , __begin(NULL)
            , __end(NULL)
            , __end_cap(NULL) {
        }

        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type())
            : alloc(alloc)
            , __begin(NULL)
            , __end(NULL)
            , __end_cap(NULL) {
                if (n > 0) {
                    __vallocate__(n);
                    __construct_at_end__(n, val);
            }
        }

        template <class InputIterator>
        vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type  first, InputIterator last,
            const allocator_type &alloc = allocator_type())
            : alloc(alloc)
            , __begin(NULL)
            , __end(NULL)
            , __end_cap(NULL) {
            for (; first != last; ++first)
                push_back(*first);
        }

        vector(const vector &x) : alloc(x.alloc), __begin(NULL), __end(NULL), __end_cap(NULL){
            size_type n = x.size();
            if (n > 0) {
                __vallocate__(n);
                __construct_at_end__(n, x.__begin, x.__end);
            }
        }
        // end constructors
        
        // operator=
        vector& operator= (const vector& x) {
            if (this != &x)
            {
                size_type n = x.size();
                if (n > 0) {
                    __vdeallocate__();
                    __vallocate__(n);
                    __construct_at_end__(n, x.__begin, x.__end);
                }
            }
            return (*this);
        }
        // end operator=

        // iteartors
        iterator begin() {
            return (__make_iterator__(__begin));
        }

        const_iterator begin() const {
            return (__make_iterator__(__begin));
        }

        iterator end() {
            return (__make_iterator__(__end));
        }

        const_iterator end() const {
            return (__make_iterator__(__end));
        }

        reverse_iterator rbegin() {
            return (__make_reverse_iterator__(__end));
        }

        const_reverse_iterator rbegin() const {
            return (__make_reverse_iterator__(__end));
        }

        reverse_iterator rend() {
            return (__make_reverse_iterator__(__begin));
        }

        const_reverse_iterator rend() const {
            return (__make_reverse_iterator__(__begin));
        }
        // end iterators

        // capacity
        size_type size() const {
            return (static_cast<size_type>(__end - __begin));
        }

        size_type max_size() const {
            return (std::min<size_type>(alloc.max_size(),
                                        std::numeric_limits<difference_type>::max()));
        }

        void resize(size_type n, value_type val = value_type()) 
        {   
            if (n > capacity()) {
                __realloc__(n);
                __construct_at_end__(n - size(), val);
            }
            else if (n > size())
                __construct_at_end__(n - size(), val);
            else if (n < size())
                __destruct_at_end__(__begin + n);
        }

        size_type capacity() const {
            return (static_cast<size_type>(__end_cap - __begin));
        }

        bool empty() const {
            return (__begin == __end);
        }

        void reserve(size_type n) {
            if (n > capacity()) {
                __realloc__(n);
            }
        }
        // end capacity

        // element access
        reference operator[](size_type n) {
            return (__begin[n]);
        }

        const_reference operator[](size_type n) const {
            return (__begin[n]);
        }

        reference at(size_type n) {
            if (n >= size())
                throw std::out_of_range("vector");
            return (__begin[n]);
        }

        const_reference at(size_type n) const {
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

        value_type *data() {
            return (__begin);
        }

        const value_type *data() const {
            return (__begin);
        }

        // end element access

        // modifiers
        template <class InputIterator>
        void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
            InputIterator it = first;
            size_type n = 0;
            while (it != last) {
                ++it;
                ++n;
            }
            resize(n);
            __construct_at_end__(n, first, last);
        }

        void assign (size_type n, const value_type& val){
            __vdeallocate__();
            __vallocate__(n);
            __construct_at_end__(n, val);
        }

        void push_back (const value_type& val) {
            if (__end == __end_cap) {
                __realloc__(size() + 1);
                alloc.construct(__end, val);
                ++__end;
            }
            else {
                alloc.construct(__end, val);
                ++__end;
            }
        }

        void pop_back() {
                --__end;
                alloc.destroy(__end);
        }

        iterator insert(iterator position, const value_type& val) {
            pointer __pos = __begin + (position - begin());
            if (__end < __end_cap) {
                if (__pos == __end) {
                    alloc.construct(__end, val);
                    ++__end;
                }
                else {
                    for (pointer __i = __end; __i > __pos; --__i)
                        *(__i) = *(__i - 1);
                    *__pos = val;
                    ++__end;
                }
            }
            else {
                size_type __distance = __pos - __begin;
                __realloc__(size() + 1);
                for (size_type __i = size(); __i > __distance; __i--)
                    __begin[__i] = __begin[__i - 1];
                this->alloc.construct(__begin + __distance, val);
                ++__end;
                __pos =  __begin + __distance;
            }
            return (__make_iterator__(__pos));
        }

        void insert (iterator position, size_type n, const value_type& val) {
            if (n == 0)
                return ;
            pointer __pos = __begin + (position - begin());
            if (__end + n <= __end_cap) {
                if (__pos == __end) {
                    __construct_at_end__(n, val);
                }
                else {
                    for (pointer __i = __end + n - 1; __i >= __pos + n; --__i)
                        *__i = *(__i - n);
                    for (pointer __i = __pos; __i < __pos + n; ++__i)
                        *__i = val;
                    __end += n;
                }
            }
            else {
                size_type __position = __pos - __begin;
                size_type __new_size = size() + n;
                __realloc__(__new_size);
                __construct_at_end__(n, 0);
                for (size_type __i = __new_size - 1; __i >= __position + n; --__i)
                    __begin[__i] = __begin[__i - n];
                for (size_type __i = __position; __i < __position + n; __i++)
                    alloc.construct(__begin + __i, val);
            }
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last){
                vector  __tmp(first, last);
                size_type __n = __tmp.size();
                if (__n == 0)
                    return ;
                pointer __pos = __begin + (position - begin());
                if (__end + __n <= __end_cap) {
                    if (__pos == __end) {
                        __construct_at_end__(__n, __tmp.begin(), __tmp.end());
                    }
                    else {
                        for (pointer __i = __end + __n - 1; __i >= __pos + __n; --__i)
                            *__i = *(__i - __n);
                        for (pointer __i = __pos; __i < __pos + __n; ++__i)
                           alloc.construct(__i, *(__tmp.begin() + (__i - __pos)));
                        __end += __n;
                    }
                }
                else {
                    size_type __position = __pos - __begin;
                    size_type __new_size = size() + __n;
                    __realloc__(__new_size);
                    __construct_at_end__(__n, 0);
                    for (size_type __i = __new_size - 1; __i >= __position + __n; --__i)
                        __begin[__i] = __begin[__i - __n];
                    for (size_type __i = __position; __i < __position + __n; __i++)
                        alloc.construct(__begin + __i, *(__tmp.begin() + (__i - __position)));
                }
        }

        iterator erase(iterator position) {
            pointer __pos = __begin + (position - begin());
            for (pointer __i = __pos; __i < __end - 1; ++__i)
                *__i = *(__i + 1);
            --__end;
            alloc.destroy(__end);
            return (__make_iterator__(__pos));
        }

        iterator erase (iterator first, iterator last) {
            pointer __pos = __begin + (first - begin());
            pointer __last = __begin + (last - begin());
            for (pointer __i = __pos; __i < __end - (__last - __pos); ++__i)
                *__i = *(__i + (__last - __pos));
            for (pointer __i = __end - (__last - __pos); __i < __end; ++__i)
                alloc.destroy(__i);
            __end -= (__last - __pos);
            return (__make_iterator__(__pos));
        }

        void clear() {
            __destruct_at_end__(__begin);
        }

        void swap (vector& x) {
            std::swap(__begin, x.__begin);
            std::swap(__end, x.__end);
            std::swap(__end_cap, x.__end_cap);
            std::swap(alloc, x.alloc);
        }

        //end modifiers

        // allocator
        allocator_type get_allocator() const {
            return (alloc);
        }
        // end allocator
        
        // destructor
        ~vector() {
            if (__begin != NULL) {
                clear();
                alloc.deallocate(__begin, capacity());
            }
        // end destructor
        }

    private:
        allocator_type alloc;
        pointer        __begin;
        pointer        __end;
        pointer        __end_cap;

        // private methods
        void                          __vallocate__(size_type);
        void                          __construct_at_end__(size_type, value_type);
        template <class InputIterator>
        void                          __construct_at_end__(size_type, InputIterator, InputIterator);
        size_type                     __recommend__(size_type) const;
        void                          __destruct_at_end__(pointer);
        void                          __vdeallocate__();
        inline iterator               __make_iterator__(pointer);
        inline const_iterator         __make_iterator__(const_pointer) const;
        inline reverse_iterator       __make_reverse_iterator__(pointer);
        inline const_reverse_iterator __make_reverse_iterator__(const_pointer) const;
        inline void                   __realloc__(size_type);
        inline void                   __swap__(vector &);
        // end private methods
    };

    template <class T, class Alloc>
    void vector<T, Alloc>::__vallocate__(size_type __n) {
        size_type __cap = __recommend__(__n);
        if (__n > max_size())
            throw(std::length_error("can't allocate region"));
        __begin = __end = alloc.allocate(__cap);
        __end_cap = __begin + __cap;
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::__construct_at_end__(size_type n, value_type val) {
            while (n > 0) {
                alloc.construct(__end, val);
                ++__end;
                --n;
            }
    }

    template <class T, class Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::__construct_at_end__(size_type n, InputIterator first,
                                                InputIterator last) {
        for (size_type i = 0; first != last; first++, i++)
            alloc.construct(__begin + i, *first);
        __end = __begin + n;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::size_type
    vector<T, Alloc>::__recommend__(size_type __new_size) const {
        const size_type __ms = max_size();
        if (__new_size > __ms)
            throw(std::length_error("can't allocate region"));
        const size_type __cap = capacity();
        if (__cap >= __ms / 2)
            return (__ms);
        return (std::max<size_type>(2 * __cap, __new_size));
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::__destruct_at_end__(pointer __new_last) {    
        while (__end != __new_last)
            alloc.destroy(--__end);
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::__vdeallocate__() {
        if (this->__begin != NULL) {
            clear();
            alloc.deallocate(__begin, capacity());
            __begin = __end = __end_cap = NULL;
        }
    }

    template <class T, class Alloc>
    inline typename vector<T, Alloc>::const_iterator
    vector<T, Alloc>::__make_iterator__(const_pointer __p) const {
        return const_iterator(__p);
    }

    template <class T, class Alloc>
    inline typename vector<T, Alloc>::iterator
    vector<T, Alloc>::__make_iterator__(pointer __p) {
        return iterator(__p);
    }

    template <class T, class Alloc>
    inline typename vector<T, Alloc>::const_reverse_iterator
    vector<T, Alloc>::__make_reverse_iterator__(const_pointer __p) const {
        return const_reverse_iterator(__p);
    }

    template <class T, class Alloc>
    inline typename vector<T, Alloc>::reverse_iterator
    vector<T, Alloc>::__make_reverse_iterator__(pointer __p) {
        return reverse_iterator(__p);
    }
    
    template <class T, class Alloc>
    inline void vector<T, Alloc>::__realloc__(size_type __new_size) {
        if (__new_size > max_size())
            throw(std::length_error("can't allocate region"));
        size_type __cap = __recommend__(__new_size);
        pointer __new_begin = NULL;
        try {
            pointer __new_begin = alloc.allocate(__cap);
            pointer __new_end = __new_begin;
            __new_end = std::uninitialized_copy(__begin, __end, __new_begin);
            alloc.deallocate(__begin, capacity());
            __begin = __new_begin;
            __end = __new_end;
            __end_cap = __begin + __cap;
        } catch (...) {
            alloc.deallocate(__new_begin, __cap);
            throw;
        }
    }

    template <class T, class Alloc>
    inline void vector<T, Alloc>::__swap__(vector &__x) {
        std::swap(__begin, __x.__begin);
        std::swap(__end, __x.__end);
        std::swap(__end_cap, __x.__end_cap);
        std::swap(alloc, __x.alloc);
    }
    
    // non-member functions
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
        if (lhs.size() != rhs.size())
            return false;
        return (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    
    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
        return !(lhs == rhs);
    }
    
    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); 
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
        return !(rhs < lhs);
    }
    
    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
        return (rhs < lhs);
    }
    
    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
        return !(lhs < rhs);
    }
    
    template <class T, class Alloc>
    void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs) {
        lhs.swap(rhs);
    }

    //end non-member functions
    
} // namespace ft

#endif // VECTOR_HPP