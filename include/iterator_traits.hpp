/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:16:15 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/25 11:46:33 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __ITERATOR_TRAITS_H__
#define __ITERATOR_TRAITS_H__

namespace ft {
   template<class Iterator>
    class iterator_traits
    {
    public:
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template<class T>
    class iterator_traits<T*>
    {
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    
    template<class T>
    class iterator_traits<const T*>
    {
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
}

#endif // __ITERATOR_TRAITS_H__