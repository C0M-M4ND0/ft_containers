/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:02:44 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/15 11:30:30 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/map.hpp"
#include <unistd.h>
int main() {
    ft::map<int, int> map;
    map.insert(std::make_pair(10, 1));
    map.insert(std::make_pair(20, 2));
    map.insert(std::make_pair(30, 3));
    map.insert(std::make_pair(40, 4));
    map.insert(std::make_pair(5, 5));
    map.insert(std::make_pair(4, 5));
    map.insert(std::make_pair(3, 5));
    map.insert(std::make_pair(50, 45));
    map.insert(std::make_pair(60, 45));
    map.insert(std::make_pair(1, 45));
    map.insert(std::make_pair(6, 5));
    map.insert(std::make_pair(7, 5));
    map.insert(std::make_pair(454, 5));
    map.insert(std::make_pair(5045, 45));
    map.insert(std::make_pair(602, 45));
    map.insert(std::make_pair(11, 45));
    map.erase(++(map.begin()));
    std::cout << "size: " << map.size()<< std::endl;
    for (ft::map<int, int>::iterator it = map.end(); it != map.begin(); --it) {
        std::cout << it->first << std::endl;
    }
    // ft::map<int, int>::iterator it = map.end();
    // it--;
    // it--;
    // it--;
    // std::cout << it->first << std::endl;
    
    std::cout << "----------------" << std::endl;
    std::map<int, int> map2;
    map2.insert(std::make_pair(10, 1));
    map2.insert(std::make_pair(20, 2));
    map2.insert(std::make_pair(30, 3));
    map2.insert(std::make_pair(40, 4));
    map2.insert(std::make_pair(5, 5));
    map2.insert(std::make_pair(4, 5));
    map2.insert(std::make_pair(3, 5));
    map2.insert(std::make_pair(50, 45));
    map2.insert(std::make_pair(60, 45));
    map2.insert(std::make_pair(1, 45));
    map2.insert(std::make_pair(6, 5));
    map2.insert(std::make_pair(7, 5));
    map2.insert(std::make_pair(454, 5));
    map2.insert(std::make_pair(5045, 45));
    map2.insert(std::make_pair(602, 45));
    map2.insert(std::make_pair(11, 45));
    map2.erase(++(map2.begin()));
    std::cout << "size: " << map2.size()<< std::endl;
    // std::cout << "size: " << map2.size()<< std::endl;
    for (std::map<int, int>::iterator it = map2.end(); it != map2.begin(); --it) {
        std::cout << it->first << std::endl;
    }
  
    return 0;
}
