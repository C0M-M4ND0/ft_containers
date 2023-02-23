/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:26:31 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/23 13:30:53 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <functional>
#include <memory>
#include "red-black_tree.hpp"
#include "utility.hpp"

namespace ft {
    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set {
        public:
            typedef T                                                                           key_type;
            typedef T                                                                           value_type;
            typedef Compare                                                                     key_compare;
            typedef Compare                                                                     value_compare;
            typedef Alloc                                                                       allocator_type;
            typedef typename allocator_type::reference                                          reference;
            typedef typename allocator_type::const_reference                                    const_reference;
            typedef typename allocator_type::pointer                                            pointer;
            typedef typename allocator_type::const_pointer                                      const_pointer;
             typedef typename allocator_type::size_type                                         size_type;
            typedef typename allocator_type::difference_type                                    difference_type;
        private:
            typedef RedBlackTree<value_type, key_compare, allocator_type>                       _base;
            _base                                                                               _tree;
            size_type                                                                           _size;
        public:
            typedef typename _base::iterator                                                    iterator;
            typedef typename _base::const_iterator                                              const_iterator;
            typedef typename _base::reverse_iterator                                            reverse_iterator;
            typedef typename _base::const_reverse_iterator                                      const_reverse_iterator;     
       
            // Constructors
            explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _size(0) {
                
            }
            
            template <class InputIterator>
            set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc),  _size(0) {
                while (first != last) {
                    insert(*first);
                    first++;
                }
            }
            
            set(set const & rhs) : _tree(rhs._tree), _size(rhs._size) {
                
            }
            
            ~set() {
                
            }
            
            set & operator=(set const & rhs) {
                _tree = rhs._tree;
                _size = rhs._size;
                return (*this);
            }
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
            //end iterators

            //capacity
            bool empty() const {
                return (_tree.empty());
            }

            size_type size() const {
                return (_size);
            }

            size_type max_size() const {
                return (_tree.max_size());
            }
            //end capacity
            
            //modifiers
            ft::pair<iterator,bool> insert(const value_type& val) {
                iterator it = iterator(_tree.find(val));
                if (it == end()) {
                    _size++;
                    return (ft::make_pair(_tree.insert(val), true));
                }
                return (ft::make_pair(it, false));
            }

            iterator insert(iterator position, const value_type& val) {
                iterator it = iterator(_tree.find(val));
                if (it == end()) {
                    _size++;
                    return (iterator(_tree.insert(position, val)));
                }
                return (it);
            }
            
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last) {
                while (first != last) {
                    insert(*first);
                    first++;
                }
            }

            void erase(iterator position) {
                _tree.erase(position);
                _size--;
            }

            size_type erase(const key_type& k) {
                iterator it = iterator(_tree.find(k));
                if (it == end())
                    return (0);
                return (erase(it), 1);
            }

            void erase(iterator first, iterator last) {
                while (first != last)
                    erase(first++);
            }

            void swap(set& x) {
                _tree.swap(x._tree);
                std::swap(_size, x._size);
            }

            void clear() {
                _tree.clear();
                _size = 0;
            }
            //end modifiers

            //observers
            key_compare key_comp() const {
                key_compare comp;
                return (comp);
            }

            value_compare value_comp() const {
                return (_tree.key_comp());
            }
            //end observers

            //operations
            iterator find(const key_type& k) {
                return (iterator(_tree.find(k)));
            }
            
            const_iterator find(const key_type& k) const {
                return (const_iterator(_tree.find(k)));
            }

            size_type count(const key_type& k) const {
                const_iterator it = const_iterator(_tree.find(k));
                if (it == end())
                    return (0);
                return (1);
            }
            
            iterator lower_bound(const key_type& k) {
                return (iterator(_tree.lower_bound(k)));
            }
            
            const_iterator lower_bound(const key_type& k) const {
                return (const_iterator(_tree.lower_bound(k)));
            }
            
            iterator upper_bound(const key_type& k) {
                return (iterator(_tree.upper_bound(k)));
            }
            
            const_iterator upper_bound(const key_type& k) const {
                return (const_iterator(_tree.upper_bound(k)));
            }
            
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            
            ft::pair<iterator,iterator> equal_range(const key_type& k) {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            //end operations
};
// non-member functions
template <class T, class Compare, class Alloc>
bool operator==(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
    return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Compare, class Alloc>
bool operator!=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
    return !(lhs == rhs);
}

template <class T, class Compare, class Alloc>
bool operator<(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Compare, class Alloc>
bool operator<=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
    return !(rhs < lhs);
}

template <class T, class Compare, class Alloc>
bool operator>(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
    return (rhs < lhs);
}

template <class T, class Compare, class Alloc>
bool operator>=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
    return !(lhs < rhs);
}

template <class T, class Compare, class Alloc>
void swap(set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y) {
    x.swap(y);
}

}


#endif