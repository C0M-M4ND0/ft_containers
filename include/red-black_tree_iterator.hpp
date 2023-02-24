/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red-black_tree_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:32:06 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/24 12:33:15 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR_HPP
#define RED_BLACK_TREE_ITERATOR_HPP

#include <iterator>
#include <__tree>
#include "red-black_tree.hpp"
#include <iostream>
namespace ft{
    template <class __T, class __NodePtr>
    class red_black_tree_const_iterator;
    
    template <class __T, class __NodePtr>
    class red_black_tree_iterator {
        friend class red_black_tree_const_iterator<__T, __NodePtr>;
        public:
            typedef __T                             value_type;
            typedef __NodePtr                       iterator_type;
            typedef value_type*                     pointer;
            typedef value_type&                     reference;
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef std::ptrdiff_t                  difference_type;
            red_black_tree_iterator() : _ptr(NULL) {
                
            }

            explicit red_black_tree_iterator(iterator_type ptr) : _ptr(ptr) {
                
            }
            
            template <class _T ,class _NodePtr>
            red_black_tree_iterator(red_black_tree_iterator<_T, _NodePtr> const & rhs): _ptr(rhs._ptr) {
                
            }

            ~red_black_tree_iterator() {
                
            }

            red_black_tree_iterator & operator=(red_black_tree_iterator const & rhs) {
                _ptr = rhs._ptr;
                return (*this);
            }

            reference operator*() const {
                return (_ptr->data);
            }

            pointer operator->() const {
                return (&(_ptr->data));
            }

            red_black_tree_iterator & operator++() {
                _ptr = _next(_ptr);
                return (*this);
            }

            red_black_tree_iterator operator++(int) {
                red_black_tree_iterator tmp(*this);
                ++(*this);
                return (tmp);
            }

            red_black_tree_iterator & operator--() 
            {
                _ptr = _prev(_ptr);
                return (*this);
            }

            red_black_tree_iterator operator--(int) {
                red_black_tree_iterator tmp(*this);
                --(*this);
                return (tmp);
            }

            bool operator==(red_black_tree_iterator const & rhs) const {
                return (_ptr == rhs._ptr);
            }

            bool operator!=(red_black_tree_iterator const & rhs) const {
                return (_ptr != rhs._ptr);
            }
            
            iterator_type &get_node(){
                return (_ptr);
            }
        private:
            iterator_type _ptr;
    };
    // const iterator
    template <class __T, class __NodePtr>
    class red_black_tree_const_iterator {
        friend class red_black_tree_iterator<__T, __NodePtr>;
        public:
            typedef __T                             value_type;
            typedef __NodePtr                       iterator_type;
            typedef value_type*                     pointer;
            typedef value_type&                     reference;
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef std::ptrdiff_t                  difference_type;
            
            red_black_tree_const_iterator() : _ptr(NULL) {
                
            }

            explicit red_black_tree_const_iterator(__NodePtr ptr) : _ptr(ptr) {
                
            }
            
            template <class _T ,class _NodePtr>
            red_black_tree_const_iterator(red_black_tree_iterator<_T, _NodePtr> const & rhs): _ptr(rhs._ptr) {

            }

            ~red_black_tree_const_iterator() {
                
            }

            red_black_tree_const_iterator & operator=(red_black_tree_const_iterator const & rhs) {
                _ptr = rhs._ptr;
                return (*this);
            }

            reference operator*() const {
                return (_ptr->data);
            }

            pointer operator->() const {
                return (&(_ptr->data));
            }

            red_black_tree_const_iterator & operator++() {
                _ptr = _next(_ptr);
                return (*this);
            }

            red_black_tree_const_iterator operator++(int) {
                red_black_tree_const_iterator tmp(*this);
                ++(*this);
                return (tmp);
            }

            red_black_tree_const_iterator & operator--() {
                _ptr = _prev(_ptr);
                return (*this);
            }

            red_black_tree_const_iterator operator--(int) {
                red_black_tree_const_iterator tmp(*this);
                --(*this);
                return (tmp);
            }

            bool operator==(red_black_tree_const_iterator const & rhs) const {
                return (_ptr == rhs._ptr);
            }

            bool operator!=(red_black_tree_const_iterator const & rhs) const {
                return (_ptr != rhs._ptr);
            }

        private:
            iterator_type _ptr;
    };
}
#endif /* !RED_BLACK_TREE_ITERATOR_HPP */