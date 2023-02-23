/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:04:34 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/23 12:53:18 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSE_ITERATOR_H__
#define __REVERSE_ITERATOR_H__

#include <cstddef>
#include "iterator_traits.hpp"

//reverse_iterator
namespace ft {
    
    template <class __Iter__>
    class ReverseIterator 
    {
        public:
            typedef typename ft::iterator_traits<__Iter__>::difference_type     difference_type;
            typedef typename ft::iterator_traits<__Iter__>::value_type          value_type;
            typedef typename ft::iterator_traits<__Iter__>::pointer             pointer;
            typedef typename ft::iterator_traits<__Iter__>::reference           reference;
            typedef typename ft::iterator_traits<__Iter__>::iterator_category   iterator_category;
        
            ReverseIterator() : _ptr(NULL) {
                
            }
            explicit ReverseIterator(__Iter__ ptr) : _ptr(ptr) {
                
            }

            template <class __Iter>
            ReverseIterator(ReverseIterator<__Iter> const & rhs) {
                *this = rhs;
            }

            ~ReverseIterator() {
                
            }

            ReverseIterator & operator=(ReverseIterator const & rhs) {
                _ptr = rhs._ptr;
                return (*this);
            }

            reference operator*() const {
                __Iter__ tmp = _ptr;
                return (*--tmp);
            }

            pointer operator->() const {
                __Iter__ tmp = _ptr;
                return (&(*--tmp));
            }

            ReverseIterator & operator++() {
                --_ptr;
                return (*this);
            }

            ReverseIterator operator++(int) {
                ReverseIterator tmp(*this);
                operator++();
                return (tmp);
            }

            ReverseIterator & operator--() {
                ++_ptr;
                return (*this);
            }

            ReverseIterator operator--(int) {
                ReverseIterator tmp(*this);
                operator--();
                return (tmp);
            }

            ReverseIterator operator+(difference_type n) const {
                return (ReverseIterator(_ptr - n));
            }

            ReverseIterator operator-(difference_type n) const {
                return (ReverseIterator(_ptr + n));
            }

            ReverseIterator & operator+=(difference_type n) {
                _ptr -= n;
                return (*this);
            }

            ReverseIterator & operator-=(difference_type n) {
                _ptr += n;
                return (*this);
            }

            reference operator[](difference_type n) const {
                return (_ptr[- n - 1]);
            }

            bool operator==(ReverseIterator const & rhs) const {
                return (_ptr == rhs._ptr);
            }

            bool operator!=(ReverseIterator const & rhs) const {
                return (!(_ptr == rhs._ptr));
            }

            bool operator<(ReverseIterator const & rhs) const {
                return (_ptr < rhs._ptr);
            }

            bool operator<=(ReverseIterator const & rhs) const {
                return (_ptr <= rhs._ptr);
            }

            bool operator>(ReverseIterator const & rhs) const {
                return (_ptr > rhs._ptr);
            }

            bool operator>=(ReverseIterator const & rhs) const {
                return (_ptr >= rhs._ptr);
            }

        private:
            __Iter__ _ptr;
    };
}
#endif // __REVERSE_ITERATOR_H__