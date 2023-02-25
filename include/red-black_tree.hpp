/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red-black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:07:11 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/25 14:06:44 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RED_BLACK_TREE_H__
#define __RED_BLACK_TREE_H__

#include "red-black_tree_iterator.hpp"
#include "reverse_iterator.hpp"
#include <memory>
#include <__tree>
#include <map>
#include <iostream>
#include <cmath>
#include <string>

#define RED 0
#define BLACK 1

namespace ft{
    template <class T>
    struct Node {
        bool                color;
        T                   data;
        Node                *left;
        Node                *right;
        Node                *parent;
    };
    
    template <class T>
    Node<T>* _next(Node<T>* node) {
        if (node->right != NULL)
            return (minimum(node->right));
        while (node == node->parent->right)
            node = node->parent;
        return (node->parent);
    }

    template <class T>
    Node<T>* _prev(Node<T>* node) {
       if (node->left != NULL)
            return (maximum(node->left));
        while (node == node->parent->left)
            node = node->parent;
        return (node->parent);
    }

    template <class T>
    Node<T>* minimum(Node<T>* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return (node);
    }
    
    template <class T>
    Node<T>* maximum(Node<T>* node) {
        while (node->right != NULL)
            node = node->right;
        return (node);
    }

    template <class T, class Compare, class Allocator>
    class RedBlackTree {
    public:
        typedef T                                                                   value_type;
        typedef Compare                                                             value_compare;
        typedef Node<value_type>*                                                   NodePtr;
        typedef Allocator                                                           allocator_type;
        typedef typename allocator_type::pointer                                    pointer;
        typedef typename allocator_type::const_pointer                              const_pointer;
        typedef typename allocator_type::reference                                  reference;
        typedef typename allocator_type::const_reference                            const_reference;
        typedef typename allocator_type::size_type                                  size_type;
        typedef typename allocator_type::difference_type                            difference_type;
        typedef red_black_tree_iterator<value_type, NodePtr>                        iterator;
        typedef red_black_tree_const_iterator<value_type, NodePtr>                  const_iterator;
        typedef ft::ReverseIterator<iterator>                                       reverse_iterator;
        typedef ft::ReverseIterator<const_iterator>                                 const_reverse_iterator;

        NodePtr                                                                     begin_node;
        NodePtr                                                                     end_node;
    // private functions
    private:
        value_compare                                                               compare;
        allocator_type                                                              alloc;
        typedef typename allocator_type::template rebind<Node<value_type> >::other  node_allocator;
        node_allocator                                                              node_alloc;
        
    
    void construct_node(NodePtr& node, const value_type& val) {
        alloc.construct(&(node->data), val);
        node->color = RED;
        node->left = node->right  = NULL;
    }

    void add_node(NodePtr _root, NodePtr node) {
        while (_root != NULL) {
            if (compare(node->data, _root->data)) {
                if (left_child(_root) == NULL) {
                    _root->left = node;
                    node->parent = _root;
                    break;
                }
                _root = left_child(_root);
            }
            else {
                if (right_child(_root) == NULL) {
                    _root->right = node;
                    node->parent = _root;
                    break;
                }
                _root = right_child(_root);
            }
        }
    }
    
    bool is_left_child(NodePtr node) const{
        return (node->parent->left == node);
    }
    
    NodePtr right_uncle(NodePtr node) const{
        return (node->parent->parent->right);
    }
    
    NodePtr left_uncle(NodePtr node) const{
        return (node->parent->parent->left);
    }
    
    NodePtr grand_parent(NodePtr node) const{
        return (node->parent->parent);
    }
    
    NodePtr parent(NodePtr node) const{
        return (node->parent);
    }

    NodePtr right_child(NodePtr node) const{
        return (node->right);
    }

    NodePtr left_child(NodePtr node) const{
        return (node->left);
    }

    NodePtr sibling(NodePtr node) const{
        if (is_left_child(node))
            return (right_child(parent(node)));
        return (left_child(parent(node)));
    }

    void left_rotate(NodePtr node) {
        NodePtr tmp = right_child(node);
        node->right = left_child(tmp);
        if (left_child(tmp) != NULL)
            tmp->left->parent = node;
        tmp->parent = parent(node);
        if (parent(node) == end_node)
            end_node->left = tmp;
        else if (is_left_child(node))
            node->parent->left = tmp;
        else
            node->parent->right = tmp;
        tmp->left = node;
        node->parent = tmp;
    }

    void right_rotate(NodePtr node) {
        NodePtr tmp = left_child(node);
        node->left = right_child(tmp);
        if (right_child(tmp) != NULL)
            tmp->right->parent = node;
        tmp->parent = parent(node);
        if (parent(node) == end_node)
            end_node->left = tmp;
        else if (is_left_child(node))
            node->parent->left = tmp;
        else
            node->parent->right = tmp;
        tmp->right = node;
        node->parent = tmp;
    }

   void color_flip(NodePtr uncle, NodePtr node) {
        uncle->color = BLACK;
        parent(node)->color = BLACK;
        grand_parent(node)->color = RED;
    }

    void _balance_after_insert(NodePtr node) {
        NodePtr tmp;
        // while node is not root and parent is red
        while (node != left_child(end_node) && parent(node)->color == RED) {
            // parent is left child
            if (is_left_child(parent(node))) {
                tmp = right_uncle(node);
                // uncle is red
                if (tmp != NULL && tmp->color == RED) {
                    color_flip(tmp, node);
                    node = grand_parent(node);
                }
                // uncle is black
                else {
                    // node is right child
                    if (!is_left_child(node)) {
                        node = parent(node);
                        left_rotate(node);
                    }
                    parent(node)->color = BLACK;
                    grand_parent(node)->color = RED;
                    right_rotate(grand_parent(node));
                }
            }
            // parent is right child
            else {
                tmp = left_uncle(node);
                // uncle is red
                if (tmp != NULL && tmp->color == RED) {
                    color_flip(tmp, node);
                    node = grand_parent(node);
                }
                // uncle is black
                else {
                    if (is_left_child(node)) {
                        node = parent(node);
                        right_rotate(node);
                    }
                    parent(node)->color = BLACK;
                    grand_parent(node)->color = RED;
                    left_rotate(grand_parent(node));
                }
            }
        }
        left_child(end_node)->color = BLACK;
    }
    
    void _balance_after_erase(NodePtr node) {
        NodePtr tmp;
        while (node != left_child(end_node) && node->color == BLACK) {
            if (is_left_child(node)) {
                tmp = sibling(node);
                //if sibling is red : swap colors and rotate left 
                if (tmp->color == RED) {
                    tmp->color = BLACK;
                    parent(node)->color = RED;
                    left_rotate(parent(node));
                    tmp = sibling(node);
                }
                // if sibling is black and both children are black : recolor 
                if ((left_child(tmp) == NULL || left_child(tmp)->color == BLACK) && (right_child(tmp) == NULL || right_child(tmp)->color == BLACK)) {
                    tmp->color = RED;
                    node = parent(node);
                }
                else 
                {
                    // if sibling is black and left child is red and right child is black : swap colors and rotate right
                    if (right_child(tmp) == NULL || right_child(tmp)->color == BLACK) {
                        left_child(tmp)->color = BLACK;
                        tmp->color = RED;
                        right_rotate(tmp);
                        tmp = sibling(node);
                    }
                    // sibling is black and right child is red : swap colors and rotate left
                    tmp->color = parent(node)->color;
                    parent(node)->color = BLACK;
                    right_child(tmp)->color = BLACK;
                    left_rotate(parent(node));
                    node = left_child(end_node);        
                }
            }
            else {
                tmp = sibling(node);
                if (tmp->color == RED) {
                    tmp->color = BLACK;
                    parent(node)->color = RED;
                    right_rotate(parent(node));
                    tmp = sibling(node);
                }
                if ((right_child(tmp) == NULL || right_child(tmp)->color == BLACK) && ((left_child(tmp) == NULL || left_child(tmp)->color == BLACK))) {
                    tmp->color = RED;
                    node = parent(node);
                }
                else {
                    if (left_child(tmp) == NULL || left_child(tmp)->color == BLACK) {
                        right_child(tmp)->color = BLACK;
                        tmp->color = RED;
                        left_rotate(tmp);
                        tmp = sibling(node);
                    }
                    tmp->color = parent(node)->color;
                    parent(node)->color = BLACK;
                    left_child(tmp)->color = BLACK;
                    right_rotate(parent(node));
                    node = left_child(end_node);
                }
            }
        }
        node->color = BLACK;
    }
    

    void  change_childrens_parent(NodePtr a, NodePtr b) {
        if (left_child(a) != NULL && left_child(a) != b)
            left_child(a)->parent = b;
        if (right_child(a) != NULL && right_child(a) != b)
            right_child(a)->parent = b;

        if (left_child(b) != NULL)
            left_child(b)->parent = a;
        if (right_child(b) != NULL)
            right_child(b)->parent = a;
    }
    
    void change_parents(NodePtr a, NodePtr b) {
        if (parent(a) == end_node)
            end_node->left = b;
        else if (is_left_child(a))
            parent(a)->left = b;
        else
            parent(a)->right = b;
        if (parent(b) == end_node)
            end_node->left = a;
        else if (is_left_child(b))
            parent(b)->left = a;
        else
            parent(b)->right = a;
    }

    void swap_nodes(NodePtr a, NodePtr b) {
        change_childrens_parent(a, b);
        change_parents(a, b);

        std::swap(a->parent, b->parent);
        std::swap(a->left, b->left);
        std::swap(a->right, b->right);
        std::swap(a->color, b->color);
    }
    
    void swap_related_nodes(NodePtr a, NodePtr b) {
        change_childrens_parent(a, b);
        if (is_left_child(a))
            a->parent->left = b;
        else
            a->parent->right = b;
        if (is_left_child(b)) {
            std::swap(a->right, b->right);
            a->left = b->left;
            b->left = a;
        }
        else {
            std::swap(a->left, b->left);
            a->right = b->right;
            b->right = a;
        }
        b->parent = a->parent;
        a->parent = b;
        std::swap(a->color, b->color);
    }

    void make_node_leaf(NodePtr node) {
        NodePtr tmp;
        while (left_child(node) != NULL || right_child(node) != NULL) {
            if (right_child(node) != NULL)
                tmp = _next(node);
            else
                tmp = _prev(node);
            if (parent(tmp) == node)
                swap_related_nodes(node, tmp);
            else
                swap_nodes(node, tmp);
        }
    }
    
    void clear_tree(NodePtr &node) {
        if (node == NULL)
            return ;
        clear_tree(node->left);
        clear_tree(node->right);
        alloc.destroy(&node->data);
        node_alloc.deallocate(node, 1);
        node = NULL;
    }

    public:
    //constructors
        explicit RedBlackTree(const value_compare& comp, const allocator_type& alloc) : compare(comp), alloc(alloc)  {
            end_node = node_alloc.allocate(1);
            end_node->color = BLACK;
            end_node->right = end_node->left = end_node->parent = NULL;
            begin_node = end_node;
        }

        template <class InputIterator>
        RedBlackTree(InputIterator first, InputIterator last, const value_compare& comp, const allocator_type& alloc) : compare(comp), alloc(alloc) {
            end_node = node_alloc.allocate(1);
            end_node->color = BLACK;
            end_node->right = end_node->left = end_node->parent = NULL;
            begin_node = end_node;
            while (first != last) {
                insert(*first);
                ++first;
            }
        }
        
        RedBlackTree(const RedBlackTree& x) : compare(x.compare), alloc(x.alloc) {
            end_node = node_alloc.allocate(1);
            end_node->color = BLACK;
            end_node->right = end_node->left = end_node->parent = NULL;
            begin_node = end_node;
            *this = x;
        }
        
        //destructor
        ~RedBlackTree() {
            clear();
            alloc.destroy(&end_node->data);
            node_alloc.deallocate(end_node, 1);
        }
        
        //assignment
        RedBlackTree& operator=(const RedBlackTree& x) {
            if (this == &x)
                return (*this);
            clear();
            for (NodePtr tmp = x.begin_node; tmp != x.end_node; tmp = _next(tmp))
                insert(tmp->data);
            return (*this);
        }
        
        //operations  
        NodePtr find(const value_type& to_find) const{
            NodePtr tmp = left_child(end_node);
            while (tmp != NULL) {
                if(!compare(to_find, tmp->data) && !compare(tmp->data, to_find))
                    return tmp;
                if (compare( to_find,tmp->data))
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
            return (end_node);
        }

        NodePtr lower_bound(const value_type& value) const {
            NodePtr tmp = left_child(end_node);
            NodePtr res = end_node;
            while (tmp != NULL) {
                if (!compare(tmp->data, value)) {
                    res = tmp;
                    tmp = tmp->left;
                }
                else
                    tmp = tmp->right;
            }
            return (res);
        }

        NodePtr upper_bound(const value_type& value) const {
            NodePtr tmp = left_child(end_node);
            NodePtr res = end_node;
            while (tmp != NULL) {
                if (compare(value, tmp->data)) {
                    res = tmp;
                    tmp = tmp->left;
                }
                else
                    tmp = tmp->right;
            }
            return (res);
        }
        
        // iterator 
        iterator begin() { 
            return (iterator(begin_node));
        }
        
        const_iterator begin() const {
            return (const_iterator(begin_node));
        }
        
        iterator end() {
            return (iterator(end_node));
        }
        
        const_iterator end() const {
            return (const_iterator(end_node));
        }
        //end iterator

        // capacity
        bool empty() const {
            return (left_child(end_node) == NULL);
        }

        size_type size() const {
            size_type res = 0;
            for (NodePtr tmp = begin_node; tmp != end_node; tmp = _next(tmp))
                ++res;
            return (res);
        }
        
        size_type max_size() const {
            return (node_alloc.max_size());
        }
        // end capacity

        // modifiers
        void clear() {
            clear_tree(end_node->left);
            end_node->left = NULL;
            begin_node = end_node;
        }

        NodePtr insert(const value_type& val) {
            NodePtr node = node_alloc.allocate(1);
            construct_node(node, val);
            if (left_child(end_node) == NULL) {
                node->color = BLACK;
                node->parent = end_node;
                end_node->left = node;
                begin_node = node;
                return (node);
            }
            add_node(left_child(end_node), node);
            if (compare(node->data, begin_node->data))
                begin_node = node;
            if (parent(node)->color == RED)
                _balance_after_insert(node);
            return (node);
        }
        //insert with hint
        NodePtr insert(iterator position, const value_type& val) {
            NodePtr node = node_alloc.allocate(1);
            construct_node(node, val);
            if (left_child(end_node) == NULL) {
                node->color = BLACK;
                node->parent = end_node;
                end_node->left = node;
                begin_node = node;
                return (node);
            }
            NodePtr tmp = position.get_node();
            if (compare(val, tmp->data))
                add_node(tmp, node);
            else 
                add_node(left_child(end_node), node);
            if (compare(node->data, begin_node->data))
                begin_node = node;
            if (parent(node)->color == RED)
                _balance_after_insert(node);
            return (node);
        }

        void erase(iterator position) {
            NodePtr node = position.get_node();
            if (!node)
                return;
            if (node == begin_node)
                begin_node = _next(node);
            make_node_leaf(node);
            if (node->color == BLACK && left_child(end_node) != node)
                _balance_after_erase(node);
            if (parent(node) == end_node){
                end_node->left = NULL;
                begin_node = end_node;
            }
            else if (is_left_child(node))
                parent(node)->left = NULL;
            else
                parent(node)->right = NULL;
            alloc.destroy(&node->data);
            node_alloc.deallocate(node, 1);
        }
        
        void swap(RedBlackTree& x) {
            std::swap(compare, x.compare);
            std::swap(alloc, x.alloc);
            std::swap(node_alloc, x.node_alloc);
            std::swap(begin_node, x.begin_node);
            std::swap(end_node, x.end_node);
        }
        // end modifiers
        
        // observers
        value_compare value_comp() const {
            return (compare);
        }
        // end observers
    };
}

#endif // __RED_BLACK_TREE_H__