/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:04:34 by oabdelha          #+#    #+#             */
/*   Updated: 2023/01/17 13:26:03 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSE_ITERATOR_H__
#define __REVERSE_ITERATOR_H__

#include <cstddef>
#include "iterator_traits.hpp"

    //reverse_iterator
namespace ft {
    
    template <class __Iter__>
    class ReverseIterVector : Iterator<typename iterator_traits<__Iter__>::iterator_category, 
                                typename iterator_traits<__Iter__>::value_type,
                                typename iterator_traits<__Iter__>::difference_type,
                                typename iterator_traits<__Iter__>::pointer,
                                typename iterator_traits<__Iter__>::reference>
    {
        public:
            typedef typename iterator_traits<__Iter__>::difference_type     difference_type;
            typedef typename iterator_traits<__Iter__>::value_type          value_type;
            typedef typename iterator_traits<__Iter__>::pointer             pointer;
            typedef typename iterator_traits<__Iter__>::reference           reference;
            typedef typename iterator_traits<__Iter__>::iterator_category   iterator_category;
        
            ReverseIterVector() : _ptr(NULL) {
                
            }
            explicit ReverseIterVector(__Iter__ ptr) : _ptr(ptr) {
                
            }

            ~ReverseIterVector() {
                
            }

            ReverseIterVector & operator=(ReverseIterVector const & rhs) {
                _ptr = rhs._ptr;
                return (*this);
            }

            reference operator*() const {
                return (*_ptr);
            }

            pointer operator->() const {
                return (_ptr);
            }

            ReverseIterVector & operator++() {
                --_ptr;
                return (*this);
            }

            ReverseIterVector operator++(int) {
                ReverseIterVector tmp(*this);
                operator++();
                return (tmp);
            }

            ReverseIterVector & operator--() {
                ++_ptr;
                return (*this);
            }

            ReverseIterVector operator--(int) {
                ReverseIterVector tmp(*this);
                operator--();
                return (tmp);
            }

            ReverseIterVector operator+(difference_type n) const {
                return (ReverseIterVector(_ptr - n));
            }

            ReverseIterVector operator-(difference_type n) const {
                return (ReverseIterVector(_ptr + n));
            }

            ReverseIterVector & operator+=(difference_type n) {
                _ptr -= n;
                return (*this);
            }

            ReverseIterVector & operator-=(difference_type n) {
                _ptr += n;
                return (*this);
            }

            reference operator[](difference_type n) const {
                return (_ptr[- n - 1]);
            }

            bool operator==(ReverseIterVector const & rhs) const {
                return (_ptr == rhs._ptr);
            }

            bool operator!=(ReverseIterVector const & rhs) const {
                return (!(_ptr == rhs._ptr));
            }

            bool operator<(ReverseIterVector const & rhs) const {
                return (_ptr < rhs._ptr);
            }

            bool operator<=(ReverseIterVector const & rhs) const {
                return (_ptr <= rhs._ptr);
            }

            bool operator>(ReverseIterVector const & rhs) const {
                return (_ptr > rhs._ptr);
            }

            bool operator>=(ReverseIterVector const & rhs) const {
                return (_ptr >= rhs._ptr);
            }

        private:
            __Iter__ _ptr;
    };
}
#endif // __REVERSE_ITERATOR_H__