/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:24:31 by oabdelha          #+#    #+#             */
/*   Updated: 2023/01/21 18:20:49 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TYPE_TRAITS_H__
#define __TYPE_TRAITS_H__

namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if {
        
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
    
    // is_integral
    template <class T>
    struct is_integral
    {
        static const bool value = false;
    };
    
    template <>
    struct is_integral<bool>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<signed char>
    {
        static const bool value = true;  
    };

    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<short>
    {
        static const bool value = true;
    };
    
    template <>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };
    
    template <>
    struct is_integral<long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<long long>
    {
        static const bool value = true;  
    };

    template<>
    struct is_integral<wchar_t>
    {
        static const bool value = true;  
    };

    template<>
    struct is_integral<unsigned long>
    {
        static const bool value = true;  
    };
    
    template<>
    struct is_integral<unsigned long long>
    {
        static const bool value = true;  
    };

    //is input iterator
    template <typename T>
    struct is_input_iterator {
    const static bool value = std::is_same<
        typename std::iterator_traits<T>::iterator_category,
        std::input_iterator_tag>::value;
    };

    // is forward iterator
    template <typename T>
    struct is_forward_iterator {
    const static bool value = std::is_same< typename std::iterator_traits<T>::iterator_category, std::forward_iterator_tag>::value || std::is_same< typename std::iterator_traits<T>::iterator_category,std::random_access_iterator_tag>::value || std::is_same<typename std::iterator_traits<T>::iterator_category, std::bidirectional_iterator_tag>::value;
    };
    
    
}
#endif // __TYPE_TRAITS_H__