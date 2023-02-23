/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:07:32 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/23 14:58:44 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_H__
#define __MAP_H__

#include <functional>
#include <memory>
#include "red-black_tree.hpp"
#include "utility.hpp"

namespace ft {
    template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map {
        
        public:
            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef ft::pair<const key_type, mapped_type>                   value_type;
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
                    value_compare(const key_compare& c) : comp(c) {
                            
                    }
                public:
                    bool operator()(const value_type& x, const value_type& y) const {
                        return comp(x.first, y.first);
                    }
            };
            
        private:
            typedef RedBlackTree<value_type, value_compare, allocator_type>     _base;
            _base                                                               _tree;
            size_type                                                           _size;
        
        public:
            typedef typename _base::iterator                                iterator;
            typedef typename _base::const_iterator                          const_iterator;
            typedef typename _base::reverse_iterator                        reverse_iterator;
            typedef typename _base::const_reverse_iterator                  const_reverse_iterator;     
       
            // Constructors
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _size(0) {
                
            }

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _size(0) {
                while (first != last) {
                    insert(*first);
                    first++;
                } 
            }

            map (const map& x) : _tree(x._tree), _size(x._size) {
                
            }
            
            //end Constructors

            // Destructor
            ~map() {
                
            }
            //end Destructor

            // Assignation operator
            map& operator= (const map& x) {
                _tree = x._tree;
                _size = x._size;
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
                return (_size);
            }
 
            size_type max_size() const {
                return (_tree.max_size());
            }
            //end Capacity

            // Element access
            mapped_type& operator[] (const key_type& k) {
                return (this->insert(value_type(k, mapped_type())).first->second);
            }
            //end Element access

            // Modifiers
            ft::pair<iterator,bool> insert (const value_type& val) {
                iterator it = iterator(_tree.find(val));
                if (it == end()) {
                    _size++;
                    return (ft::make_pair(iterator(_tree.insert(val)), true));   
                }
                return (ft::make_pair(it, false));
            }

            iterator insert (iterator position, const value_type& val) {
                iterator it = iterator(_tree.find(val));
                if (it == end()) {
                    _size++;
                    return (iterator(_tree.insert(position, val)));
                }
                return (it);
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
                _size--;
            }

            size_type erase (const key_type& k) {
                iterator it = iterator(_tree.find(value_type(k, mapped_type())));
                if (it == end())
                    return (0);
                return (erase(it), 1);            
            }

            void erase (iterator first, iterator last) {
                while (first != last)
                    erase(first++);
            }
            
            void swap (map& x) {
                _tree.swap(x._tree);
                std::swap(_size, x._size);
            }
            
            void clear() {
                _tree.clear();
                _size = 0;
            }
            //end Modifiers

            // Observers
            key_compare key_comp() const {
                key_compare comp;
                return (comp);
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
                const_iterator it = const_iterator(_tree.find(value_type(k, mapped_type())));
                if (it == end())
                    return (0);
                return (1);
            }
            
            iterator lower_bound(const key_type& k) {
                return (iterator(_tree.lower_bound(value_type(k, mapped_type()))));
            }
            
            const_iterator lower_bound(const key_type& k) const {
                return (const_iterator(_tree.lower_bound(value_type(k, mapped_type()))));
            }
            
            iterator upper_bound(const key_type& k) {
                return (iterator(_tree.upper_bound(value_type(k, mapped_type()))));
            }
            
            const_iterator upper_bound(const key_type& k) const {
                return (const_iterator(_tree.upper_bound(value_type(k, mapped_type()))));
            }
            
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            
            ft::pair<iterator,iterator> equal_range(const key_type& k) {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            //end Operations

            // Allocator
            allocator_type get_allocator() const {
                return (_tree.get_allocator());
            }
            //end Allocator

            //end Class
    };
    //Non-member function overloads
    template <class Key, class T>
    bool operator== (const map<Key,T>& lhs, const map<Key,T>& rhs) {
        return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class Key, class T>
    bool operator!= (const map<Key,T>& lhs, const map<Key,T>& rhs) {
        return !(lhs == rhs);
    }
    
    template <class Key, class T>
    bool operator<  (const map<Key,T>& lhs, const map<Key,T>& rhs) {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    
    template <class Key, class T>
    bool operator<= (const map<Key,T>& lhs, const map<Key,T>& rhs) {
        return !(rhs < lhs);
    }
    
    template <class Key, class T>
    bool operator>  (const map<Key,T>& lhs, const map<Key,T>& rhs) {
        return (rhs < lhs);
    }
    
    template <class Key, class T>
    bool operator>= (const map<Key,T>& lhs, const map<Key,T>& rhs) {
        return !(lhs < rhs);
    }
    
    template <class Key, class T, class Compare, class Alloc>
    void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) {
        x.swap(y);
    }
    //end Non-member function overloads
}

#endif // __MAP_H__