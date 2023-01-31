/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:34 by oabdelha          #+#    #+#             */
/*   Updated: 2023/01/26 16:41:21 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_H__
#define __STACK_H__

#include "vector.hpp"

namespace ft {
    template <class T, class Container = ft::vector<T> > 
    class stack {
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;
        protected:
            container_type c;
        public:
            explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {
                
            }
            
            bool empty() const {
                return (c.empty());
            }

            size_type size() const {
                return (c.size());
            }

            value_type& top() {
                return (c.back());
            }
            
            const value_type& top() const {
                return (c.back());
            }
            
            void push (const value_type& val) {
                c.push_back(val);
            }
            
            void pop() {
                c.pop_back();
            }
            
            void swap (stack& x) {
                std::swap(c, x.c);
            }

            template <class _T, class _Container>
            friend
            bool
            operator== (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

            template <class _T, class _Container>
            friend
            bool
            operator<  (const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

            ~stack() {
                
            }
    };
    
    // Non-member function overloads
    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs.c == rhs.c);
    }
    
    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return !(lhs == rhs);
    }
    
    template <class T, class Container>
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs.c < rhs.c);
    }

    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return !(rhs < lhs);
    }
    
    template <class T, class Container>
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (rhs < lhs);
    }
    
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return !(lhs < rhs);
    }
    
    template <class T, class Container>
    void swap (stack<T,Container>& x, stack<T,Container>& y) {
        x.swap(y);
    }
    // End of non-member function overloads
}
#endif // __STACK_H__