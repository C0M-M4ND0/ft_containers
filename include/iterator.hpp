/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:47:26 by oabdelha          #+#    #+#             */
/*   Updated: 2023/01/17 12:03:25 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <cstddef>
#include "iterator_traits.hpp"

namespace ft {

   template <class __Iter__>
    class IterVector : iterator<typename iterator_traits<__Iter__>::iterator_category, 
                                typename iterator_traits<__Iter__>::value_type,
                                typename iterator_traits<__Iter__>::difference_type,
                                typename iterator_traits<__Iter__>::pointer,
                                typename iterator_traits<__Iter__>::reference>
    {
        public:
            typedef typename ft::iterator_traits<__Iter__>::difference_type     difference_type;
            typedef typename ft::iterator_traits<__Iter__>::value_type          value_type;
            typedef typename ft::iterator_traits<__Iter__>::pointer             pointer;
            typedef typename ft::iterator_traits<__Iter__>::reference           reference;
            typedef typename ft::iterator_traits<__Iter__>::iterator_category   iterator_category;

            IterVector() : _ptr(NULL) {
                
            }

            explicit IterVector(__Iter__ ptr) : _ptr(ptr) {
                
            }
            
            template <class __Iter>
            IterVector(IterVector<__Iter> const & rhs) {
                *this = rhs;
            }

            ~IterVector() {
                
            }

            IterVector & operator=(IterVector const & rhs) {
                _ptr = rhs._ptr;
                return (*this);
            }

            reference operator*() const {
                return (*_ptr);
            }

            pointer operator->() const {
                return (_ptr);
            }

            IterVector & operator++() {
                ++_ptr;
                return (*this);
            }

            IterVector operator++(int) {
                IterVector tmp(*this);
                operator++();
                return (tmp);
            }

            IterVector & operator--() {
                --_ptr;
                return (*this);
            }

            IterVector operator--(int) {
                IterVector tmp(*this);
                operator--();
                return (tmp);
            }

            IterVector operator+(difference_type n) const {
                return (IterVector(_ptr + n));
            }

            IterVector operator-(difference_type n) const {
                return (IterVector(_ptr - n));
            }

            difference_type operator-(IterVector const & rhs) const {
                return (_ptr - rhs._ptr);
            }

            IterVector & operator+=(difference_type n) {
                _ptr += n;
                return (*this);
            }

            difference_type operator+=(IterVector const & rhs) {
                _ptr += rhs._ptr;
                return (*this);
            }

            IterVector & operator-=(difference_type n) {
                _ptr -= n;
                return (*this);
            }

            difference_type operator-=(IterVector const & rhs) {
                _ptr -= rhs._ptr;
                return (*this);
            }
            
            reference operator[](difference_type n) const {
                return (_ptr[n]);
            }

            bool operator==(IterVector const & rhs) const {
                return (_ptr == rhs._ptr);
            }

            bool operator!=(IterVector const & rhs) const {
                return (!(_ptr == rhs._ptr));
            }

            bool operator<(IterVector const & rhs) const {
                return (_ptr < rhs._ptr);
            }

            bool operator<=(IterVector const & rhs) const {
                return (_ptr <= rhs._ptr);
            }

            bool operator>(IterVector const & rhs) const {
                return (_ptr > rhs._ptr);
            }

            bool operator>=(IterVector const & rhs) const {
                return (_ptr >= rhs._ptr);
            }

        private:
            __Iter__ _ptr;
    };

}

#endif // __ITERATORS_H__