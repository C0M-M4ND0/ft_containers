/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red-black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:07:11 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/15 11:44:28 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RED_BLACK_TREE_H__
#define __RED_BLACK_TREE_H__

#include "red-black_tree_iterator.hpp"
#include <memory>
#include <__tree>
#include <iostream>

#include <map>
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
        void construct_node(Node *node, const T& val) {
            node->color = RED;
            node->data = val;
        }
    };
    
    template <class T>
    Node<T>* _next(Node<T>* node) {
        if (node->right != NULL)
            return (minimum(node->right));
        Node<T>* tmp = node->parent;
        while (tmp != NULL && node == tmp->right) {
            node = tmp;
            tmp = tmp->parent;
        }
        return (tmp);
    }

    template <class T>
    Node<T>* _prev(Node<T>* node) 
    {
        if (node->left != NULL)
            return (maximum(node->left));
        Node<T>* tmp = node->parent;
        while (tmp != NULL && node == tmp->left) {
            node = tmp;
            tmp = tmp->parent;
        }
        return (tmp);
    }

    template <class T>
    Node<T>* minimum(Node<T>* node) {
        while (node->left != NULL)
            node = node->left;
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

        NodePtr                                                                     root;
        NodePtr                                                                     end_node;
    // private functions
    private:
        allocator_type                                                              alloc;
        value_compare                                                               compare;
        typedef typename allocator_type::template rebind<Node<value_type> >::other  node_allocator;
        node_allocator                                                              node_alloc;
        
    
    void construct_node(NodePtr& node, const value_type& val) {
        node->color = RED;
        alloc.construct(&node->data, val);
        node->left = NULL;
        node->right = NULL;
    }

    void add_node(NodePtr parent, NodePtr node) {
        while (parent != NULL) {
            if (compare(parent->data, node->data)) {
                if (parent->right == NULL) {
                    parent->right = node;
                    node->parent = parent;
                    break;
                }
                parent = parent->right;
            }
            else {
                if (parent->left == NULL) {
                    parent->left = node;
                    node->parent = parent;
                    break;
                }
                parent = parent->left;
            }
        }
    }

    public:
        explicit RedBlackTree(const value_compare& comp, const allocator_type& alloc) : compare(comp), alloc(alloc)  {
            end_node = node_alloc.allocate(1);
            node_alloc.construct(end_node, Node<value_type>());
            end_node->color = BLACK;
            root = end_node->right = end_node->parent = NULL;
        }

        ~RedBlackTree() {
            // print_tree(root);
        }
            
        NodePtr find(const value_type& to_find) {
            NodePtr tmp = root;
            while (tmp != NULL) {
                if (compare(tmp->data, to_find) && compare(to_find, tmp->data))
                    return (tmp);
                else if (compare(to_find, tmp->data))
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
            return (NULL);
        }

        // iterator 
        iterator begin() { 
            return (iterator(minimum(root)));
        }
        
        const_iterator begin() const {
            return (const_iterator(minimum(root)));
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
            return (root == NULL);
        }

        size_type size() const {
            size_type size = 0;
            NodePtr tmp = minimum(root);
            while (tmp != NULL) {
                tmp = _next(tmp);
                size++;
            }
            return (size - 1);
        }

        size_type max_size() const {
            return (node_alloc.max_size());
        }
        // end capacity

        // modifiers
        void clear() {
            NodePtr tmp = root;
            while (tmp != NULL) {
                tmp = next(tmp);
                node_alloc.deallocate(tmp, 1);
            }
            root = NULL;
        }

        NodePtr insert(const value_type& val) {
            NodePtr node = node_alloc.allocate(1);
            construct_node(node, val);
            if (root == NULL) {
                root = node;
                root->color = BLACK;
                root->parent = end_node;
                end_node->left = root;
                return (root);
            }
            add_node(root, node);
            return (node);
        }

        void erase(iterator it) {
            NodePtr node = it.get_node();
            NodePtr tmp = NULL;
            NodePtr tmp2 = NULL;
            if (node->left == NULL || node->right == NULL)
                tmp = node;
            else
                tmp = _next(node);
            if (tmp->left != NULL)
                tmp2 = tmp->left;
            else
                tmp2 = tmp->right;
            tmp2->parent = tmp->parent;
            if (tmp->parent == NULL)
                root = tmp2;
            else if (tmp == tmp->parent->left)
                tmp->parent->left = tmp2;
            else
                tmp->parent->right = tmp2;
            if (tmp != node)
                node->data.second = tmp->data.second;
            // if (tmp->color == BLACK)
            //     delete_fix(tmp2);
            node_alloc.destroy(tmp);
            node_alloc.deallocate(tmp, 1);
        }
        
        //temporary function
        void print_tree(NodePtr node) {
            if (node == NULL)
                return ;
            std::cout << "key: " << node->data.first;
            std::cout << " value: " << node->data.second;
            std::cout << " color: " << node->color; 
            std::cout << std::endl;    
            print_tree(node->left);
            print_tree(node->right);
        }
    };
}
// compare returns true if the first argument is less than the second
#endif // __RED_BLACK_TREE_H__