/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:07:32 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/15 12:11:15 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_H__
#define __MAP_H__

#include <functional>
#include <memory>
#include "red-black_tree.hpp"
#include "reverse_iterator.hpp"
#include <map>

namespace ft {
    template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, T> > >
    class map {
        
        public:
            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef std::pair<const key_type, mapped_type>                  value_type;
            typedef Compare                                                 key_compare;
            typedef Allocator                                               allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef typename allocator_type::size_type                      size_type;
            typedef typename allocator_type::difference_type                difference_type;
            
            class value_compare : public std::binary_function<value_type, value_type, bool> {
                friend class map;
                protected:
                    key_compare comp;
                    value_compare(key_compare c) : comp(c) {

                    }
                public:
                    bool operator()(const value_type& x, const value_type& y) const {
                        return comp(x.first, y.first);
                    }
            };
            
        private:
            typedef RedBlackTree<value_type, value_compare, allocator_type>     _base;
            _base                                                               _tree;
        
        public:
            typedef typename _base::iterator                                iterator;
            typedef typename _base::const_iterator                          const_iterator;
            typedef ft::ReverseIterator<iterator>                           reverse_iterator;
            typedef ft::ReverseIterator<const_iterator>                     const_reverse_iterator;        
       
            // Constructors
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {
                
            }

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {
                while (first != last) {
                    insert(*first);
                    first++;
                } 
            }

            map (const map& x) : _tree(x._tree) {
                
            }
            
            //end Constructors

            // Destructor
            ~map() {
                
            }
            //end Destructor

            // Assignation operator
            map& operator= (const map& x) {
                _tree = x._tree;
                return *this;
            }
            //end Assignation operator

            // Iterators
            iterator begin() {
                return (_tree.begin());
            }

            const_iterator begin() const {
                return (_tree.begin());
            }

            iterator end() {
                return (_tree.end());
            }

            const_iterator end() const {
                return (_tree.end());
            }
            
            reverse_iterator rbegin() {
                return (reverse_iterator(end()));
            }

            const_reverse_iterator rbegin() const {
                return (const_reverse_iterator(end()));
            }
            
            reverse_iterator rend() {
                return (reverse_iterator(begin()));
            }

            const_reverse_iterator rend() const {
                return (const_reverse_iterator(begin()));
            }
            //end Iterators

            // Capacity
            bool empty() const {
                return (_tree.empty());
            }

            size_type size() const {
                return (_tree.size());
            }
 
            size_type max_size() const {
                return (_tree.max_size());
            }
            //end Capacity

            // Element access
            mapped_type& operator[] (const key_type& k) {
                iterator it = find(k);
                if (it == end()) {
                    insert(std::make_pair(k, mapped_type()));
                    it = find(k);
                }
                return (it->second);
            }
            //end Element access

            // Modifiers
            std::pair<iterator,bool> insert (const value_type& val) {
                return (std::make_pair(iterator(_tree.insert(val)), true));
            }

            iterator insert (iterator position, const value_type& val) {
                return (_tree.insert(position, val));
            }

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last) {
                while (first != last) {
                    insert(*first);
                    first++;
                }
            }
            
            void erase (iterator position) {
                _tree.erase(position);
            }

            size_type erase (const key_type& k) {
                return (_tree.erase(iterator(std::make_pair(k, mapped_type()))));
            }

            void erase (iterator first, iterator last) {
                while (first != last) {
                    erase(first);
                    first++;
                }
            }
            
            void swap (map& x) {
                _tree.swap(x._tree);
            }
            
            void clear() {
                _tree.clear();
            }
            //end Modifiers

            // Observers
            key_compare key_comp() const {
                return (_tree.key_comp());
            }
            
            value_compare value_comp() const {
                return (value_compare(_tree.key_comp()));
            }
            //end Observers

            // Operations
            iterator find(const key_type& k) {
                return (iterator(_tree.find(value_type(k, mapped_type()))));
            }
            
            const_iterator find(const key_type& k) const {
                return (const_iterator(_tree.find(value_type(k, mapped_type()))));
            }

            size_type count(const key_type& k) const {
                return (_tree.count(value_type(k, mapped_type())));
            }
            
            iterator lower_bound(const key_type& k) {
                return (itarator(_tree.lower_bound(value_type(k, mapped_type()))));
            }
            
            const_iterator lower_bound(const key_type& k) const {
                return (conat_iterator(_tree.lower_bound(value_type(k, mapped_type()))));
            }
            
            iterator upper_bound(const key_type& k) {
                return (itarator(_tree.upper_bound(value_type(k, mapped_type()))));
            }
            
            const_iterator upper_bound(const key_type& k) const {
                return (conat_iterator(_tree.upper_bound(value_type(k, mapped_type()))));
            }
            
            std::pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
                return (_tree.equal_range(value_type(k, mapped_type())));
            }
            
            std::pair<iterator,iterator> equal_range(const key_type& k) {
                return (_tree.equal_range(value_type(k, mapped_type())));
            }
            //end Operations

            // Allocator
            allocator_type get_allocator() const {
                return (_tree.get_allocator());
            }
            //end Allocator

            //end Class
    };
}

#endif // __MAP_H__