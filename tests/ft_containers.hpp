/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:31:25 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/24 23:00:49 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.hpp"
#include "../include/set.hpp"
#include "../include/map.hpp"
#include "../include/stack.hpp"
#include <vector>
#include <deque>

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

//constructors
std::vector<int> ft_vector_constructors_test() {
    std::vector<int> res;
    ft::vector<int> first;
    ft::vector<int> second (4,100); 
    ft::vector<int> third (second.begin(),second.end());
    ft::vector<int> fourth (third);

    int myints[] = {16,2,77,29};
    ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        res.push_back(*it);
    return res;
}

//assiment operator
std::vector<int> ft_vector_assiment_operator_test() {
    std::vector<int> res;
    ft::vector<int> foo (3,0);
    ft::vector<int> bar (5,0);

    bar = foo;
    foo = ft::vector<int>();

    for (ft::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
        res.push_back(*it);
    return res;
}

//size
std::vector<int> ft_vector_size_test() {
    std::vector<int> res;
    ft::vector<int> myints;
    res.push_back(myints.size());

    for (int i=0; i<10; i++) myints.push_back(i);
    res.push_back(myints.size());

    myints.insert (myints.end(),10,100);
    res.push_back(myints.size());

    myints.pop_back();
    res.push_back(myints.size());
    return res;
}

//resize
std::vector<int> ft_vector_resize_test() {
    std::vector<int> res;
    ft::vector<int> myvector;
    for (int i=1;i<10;i++) myvector.push_back(i);

    myvector.resize(5);
    myvector.resize(8,100);
    myvector.resize(12);

    for (size_t i=0;i<myvector.size();i++)
        res.push_back(myvector[i]);
    return res;
}

//capacity
std::vector<int> ft_vector_capacity_test() {
    std::vector<int> res;
    ft::vector<int> myvector;

    for (int i=0; i<100; i++) myvector.push_back(i);

    res.push_back(myvector.size());
    res.push_back(myvector.capacity());
    res.push_back(myvector.max_size());
    return res;
}
//reserve
std::vector<int> ft_vector_reserve_test() {
    std::vector<int> res;
    ft::vector<int>::size_type sz;

    ft::vector<int> foo;
    sz = foo.capacity();
    for (int i=0; i<100; ++i) {
        foo.push_back(i);
        if (sz!=foo.capacity()) {
        sz = foo.capacity();
        res.push_back(sz);
        }
    }

    ft::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);
    for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
        sz = bar.capacity();
        res.push_back(sz);
        }
    }
    return res;
}
//assign
std::vector<int> ft_vector_assign_test() {
    std::vector<int>    res;
    ft::vector<int> first;
    ft::vector<int> second;
    ft::vector<int> third;

    first.assign (7,100);
    ft::vector<int>::iterator it;
    it=first.begin()+1;

    second.assign (it,first.end()-1);

    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);

    res.push_back(first.size());
    res.push_back(second.size());
    res.push_back(third.size());
    return res;
}
//insert
std::vector<int> ft_vector_insert_test() {
    std::vector<int> res;
    ft::vector<int> myvector (3,100);
    ft::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );

    myvector.insert (it,2,300);

    it = myvector.begin();

    ft::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    for (it=myvector.begin(); it<myvector.end(); it++)
        res.push_back(*it);
    return res;
}
//erase
std::vector<int> ft_vector_erase_test() {
    std::vector<int> res;
    ft::vector<int> myvector;

    for (int i=1; i<=10; i++) myvector.push_back(i);

    myvector.erase (myvector.begin()+5);

    myvector.erase (myvector.begin(),myvector.begin()+3);

    for (unsigned i=0; i<myvector.size(); ++i)
        res.push_back(myvector[i]);
    return res;
}
//swap
std::vector<int> ft_vector_swap_test() {
    std::vector<int> res;
    ft::vector<int> foo (3,100);
    ft::vector<int> bar (5,200);

    foo.swap(bar);

    for (unsigned i=0; i<foo.size(); i++)
        res.push_back(foo[i]);

    for (unsigned i=0; i<bar.size(); i++)
        res.push_back(bar[i]);
    return res;
}
//clear
std::vector<int> ft_vector_clear_test() {
    std::vector<int> res;
    ft::vector<int> myvector;
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);

    for (unsigned i=0; i<myvector.size(); i++)
        res.push_back(myvector[i]);

    myvector.clear();
    myvector.push_back (1101);
    myvector.push_back (2202);

    for (unsigned i=0; i<myvector.size(); i++)
        res.push_back(myvector[i]);
    return res;
}
//relational operators
std::vector<int> ft_vector_relational_operators_test() {
    std::vector<int> res;
    ft::vector<int> foo (3,100);
    ft::vector<int> bar (2,200);

    if (foo==bar) res.push_back(1);
    if (foo!=bar) res.push_back(2);
    if (foo< bar) res.push_back(3);
    if (foo> bar) res.push_back(4);
    if (foo<=bar) res.push_back(5);
    if (foo>=bar) res.push_back(6);
    return res;
}
//map test
//constructors
#ifndef _CLASSCOMP
#define _CLASSCOMP
struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};
#endif
std::vector<int> ft_map_constructors_test() {
    std::vector<int> res;
    ft::map<char,int> first;

    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;

    ft::map<char,int> second (first.begin(),first.end());
    for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); it++)
        res.push_back(it->second);

    ft::map<char,int> third (second);
    for (ft::map<char, int>::iterator it = third.begin(); it != third.end(); it++)
        res.push_back(it->second);

    ft::map<char,int,classcomp> fourth;
    for (ft::map<char, int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        res.push_back(it->first);    
    
    return res;
}
//operator=
std::vector<int> ft_map_operator_equal_test() {
    std::vector<int> res;
    ft::map<char,int> foo,bar;
    foo['x']=100;
    foo['y']=200;

    bar=foo;
    for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); it++)
        res.push_back(it->second);
    foo=ft::map<char,int>();

    res.push_back(foo.size());
    res.push_back(bar.size());
    return res;
}
//size 
std::vector<int> ft_map_size_test() {
    std::vector<int> res;
    ft::map<char,int> mymap;
    mymap['a']=101;
    mymap['b']=202;
    mymap['c']=302;

    res.push_back(mymap.size());
    return res;
}
//insert
std::vector<int> ft_map_insert_test() {
    std::vector<int> res;
    ft::map<char,int> mymap;

    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('z',200) );

    ft::pair<ft::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( ft::pair<char,int>('z',500));
    if (ret.second==false)
        res.push_back(ret.first->second);

    ft::map<char,int>::iterator it = mymap.begin();
    mymap.insert (it, ft::pair<char,int>('b',300));
    mymap.insert (it, ft::pair<char,int>('c',400));  



    ft::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));

    for (it=mymap.begin(); it!=mymap.end(); ++it)
        res.push_back(it->second);

    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        res.push_back(it->second);
    return res;
}
//erase
std::vector<int> ft_map_erase_test() {
    std::vector<int> res;
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    it=mymap.find('b');
    mymap.erase (it);

    mymap.erase ('c');

    it=mymap.find ('e');
    mymap.erase ( it, mymap.end() );

    for (it=mymap.begin(); it!=mymap.end(); ++it)
        res.push_back(it->second);
    return res;
}
//swap
std::vector<int> ft_map_swap_test() {
    std::vector<int> res;
    ft::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    foo.swap(bar);

    for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        res.push_back(it->second);

    for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        res.push_back(it->second);
    return res;
}
//clear
std::vector<int> ft_map_clear_test() {
    std::vector<int> res;
    ft::map<char,int> mymap;
    mymap['x']=100;
    mymap['y']=200;
    mymap['z']=300;

    mymap.clear();
    mymap['a']=1101;
    mymap['b']=2202;

    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        res.push_back(it->second);
    return res;
}
//find
std::vector<int> ft_map_find_test() {
    std::vector<int> res;
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase (it);

    res.push_back(mymap.find('a')->second);
    res.push_back(mymap.find('c')->second);
    res.push_back(mymap.find('d')->second);
    return res;
}
//equal_range
std::vector<int> ft_map_equal_range_test() {
    std::vector<int> res;
    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    res.push_back(ret.first->second);
    res.push_back(ret.second->second);
    return res;
}
//stack
//constructor
std::vector<int> ft_stack_constructor_test() {
    std::vector<int> res;
    ft::vector<int> myvector1 (3,100);
    std::vector<int> myvector (2,200);

    ft::stack<int> first;
    ft::stack<int> second (myvector1);

    ft::stack<int,std::vector<int> > third;
    ft::stack<int,std::vector<int> > fourth (myvector);

    res.push_back(first.size());
    res.push_back(second.size());
    res.push_back(third.size());
    res.push_back(fourth.size());
    return res;
}
//size
std::vector<int> ft_stack_size_test() {
    std::vector<int> res;
    ft::stack<int> mystack;
    for (int i=0; i<5; ++i) mystack.push(i);

    res.push_back(mystack.size());
    mystack.pop();
    res.push_back(mystack.size());
    return res;
}
//empty
std::vector<int> ft_stack_empty_test() {
    std::vector<int> res;
    ft::stack<int> mystack;
    int sum (0);
    for (int i=1;i<=10;i++) mystack.push(i);

    while (!mystack.empty())
    {
        sum += mystack.top();
        mystack.pop();
    }

    res.push_back(sum);
    return res;
}
//swap
std::vector<int> ft_stack_swap_test() {
    std::vector<int> res;
    ft::stack<int> foo,bar;
    foo.push (10); foo.push(20); foo.push(30);
    bar.push (111); bar.push(222);

    foo.swap(bar);

    res.push_back(foo.top());
    res.push_back(bar.top());
    return res;
}
//relational operators
std::vector<int> ft_stack_relational_operators_test() {
    std::vector<int> res;
    ft::stack<int> foo,bar;
    foo.push (10); foo.push(20); foo.push(30);
    bar.push (111); bar.push(222);

    res.push_back(foo==bar);
    res.push_back(foo!=bar);
    res.push_back(foo<bar);
    res.push_back(foo<=bar);
    res.push_back(foo>bar);
    res.push_back(foo>=bar);
    return res;
}
//set
//constructor
std::vector<int> ft_set_constructor_test() {
    std::vector<int> res;
    int myints[]= {10,20,30,40,50};
    ft::set<int> first (myints,myints+5);
    ft::set<int> second (first);
    ft::set<int> third (second.begin(), second.end());
    ft::set<int> fourth (third);

    res.push_back(first.size());
    res.push_back(second.size());
    res.push_back(third.size());
    res.push_back(fourth.size());
    return res;
}
//size
std::vector<int> ft_set_size_test() {
    std::vector<int> res;
    ft::set<int> myints;
    res.push_back(myints.size());

    for (int i=0; i<10; ++i) myints.insert(i);
    res.push_back(myints.size());

    myints.insert (100);
    res.push_back(myints.size());

    myints.erase(5);
    res.push_back(myints.size());
    return res;
}
//operator=
std::vector<int> ft_set_operator_equal_test() {
    std::vector<int> res;
    ft::set<int> foo,bar;
    foo=ft::set<int>();
    bar=ft::set<int>();

    foo.insert(10);
    bar.insert(20);
    bar.insert(30);
    bar.insert(40);

    foo=bar;
    bar=ft::set<int>();

    res.push_back(foo.size());
    res.push_back(bar.size());
    return res;
}
//empty
std::vector<int> ft_set_empty_test() {
    std::vector<int> res;
    ft::set<int> myset;
    int sum (0);

    for (int i=1;i<=10;i++) myset.insert(i);

    while (!myset.empty())
    {
        sum += *(myset.begin());
        myset.erase (myset.begin());
    }

    res.push_back(sum);
    return res;
}
//swap
std::vector<int> ft_set_swap_test() {
    std::vector<int> res;
    ft::set<int> foo,bar;
    foo.insert(10);
    foo.insert(20);
    foo.insert(30);

    bar.insert(111);
    bar.insert(222);

    foo.swap(bar);

    res.push_back(*foo.begin());
    res.push_back(*bar.begin());
    return res;
}
//relational operators
std::vector<int> ft_set_relational_operators_test() {
    std::vector<int> res;
    ft::set<int> foo,bar;
    foo.insert(10);
    foo.insert(20);
    foo.insert(30);

    bar.insert(111);
    bar.insert(222);

    res.push_back(foo==bar);
    res.push_back(foo!=bar);
    res.push_back(foo<bar);
    res.push_back(foo<=bar);
    res.push_back(foo>bar);
    res.push_back(foo>=bar);
    return res;
}
//insert
std::vector<int> ft_set_insert_test() {
    std::vector<int> res;
    ft::set<int> myset;
    ft::set<int>::iterator it;
    ft::pair<ft::set<int>::iterator,bool> ret;

    for (int i=1; i<=5; ++i) myset.insert(i*10);

    ret = myset.insert(20);

    if (ret.second==false) it=ret.first;

    myset.insert (it,25);
    myset.insert (it,24);
    myset.insert (it,26);

    int myints[]= {5,10,15};
    myset.insert (myints,myints+3);

    for (it=myset.begin(); it!=myset.end(); ++it)
        res.push_back(*it);
    return res;
}   

//erase
std::vector<int> ft_set_erase_test() {
    std::vector<int> res;
    ft::set<int> myset;
    ft::set<int>::iterator it;

    for (int i=1; i<10; i++) myset.insert(i*10);

    it = myset.begin();
    ++it;

    myset.erase (it);

    myset.erase (40);

    it = myset.find (60);
    myset.erase (it, myset.end());

    for (it=myset.begin(); it!=myset.end(); ++it)
        res.push_back(*it);
    return res;
}
//clear
std::vector<int> ft_set_clear_test() {
    std::vector<int> res;
    ft::set<int> myset;
    ft::set<int>::iterator it;

    myset.clear();
    myset.insert(100);
    myset.insert(200);
    myset.insert(300);

    res.push_back(myset.size());
    myset.clear();
    res.push_back(myset.size());
    return res;
}
#endif