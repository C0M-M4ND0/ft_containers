/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:15:26 by oabdelha          #+#    #+#             */
/*   Updated: 2023/01/26 16:35:00 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILITY_HPP__
#define __UTILITY_HPP__

#include "iterator.hpp"
#include "type_traits.hpp"


namespace ft{
    //lexicographical_compare
    //Compares the elements in the range [first1,last1) with those in the range [first2,last2) and returns true if the first range is lexicographically less than the second.
    //default (1)
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
        while (first1 != last1) {
            if (first2 == last2 || *first2 < *first1)
                return (false);
            else if (*first1 < *first2)
                return (true);
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
    
    //costum (2)
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
        while (first1 != last1) {
            if (first2 == last2 || comp(*first2, *first1))
                return (false);
            else if (comp(*first1, *first2))
                return (true);
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
    //end lexicographical_compare
    
    //pair
    template <class T1, class T2> 
    struct pair {
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair() : first(T1()), second(T2()) {

        }

        template<class U, class V>
        pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {

        }

        pair (const T1& a, const T2& b) : first(a), second(b) {

        }

        pair& operator= (const pair& pr) {
            first = pr.first;
            second = pr.second;
            return *this;
        }
};

// Non-member functions
template <class T1, class T2>
inline bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return (lhs.first==rhs.first && lhs.second==rhs.second);
}

template <class T1, class T2>
inline bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(lhs==rhs);
}

template <class T1, class T2>
inline bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return (lhs.first>rhs.first || (!(rhs.first<lhs.first) && lhs.second>rhs.second));
}

template <class T1, class T2>
inline bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return (rhs>lhs);
}

template <class T1, class T2>
inline bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(lhs<rhs);
}

template <class T1, class T2>
inline bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(lhs>rhs);
}

template <class T1, class T2>
inline pair<T1,T2> make_pair (T1 x, T2 y) {
    return pair<T1,T2>(x,y);
}
// End of non-member functions
// End of pair


}
#endif // __UTILITY_HPP__