/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:41:14 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/24 22:57:35 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "ft_containers.hpp"
#include "std_containers.hpp"

//constructor
void   set_constructor_test() {
 std::cout << "set constructor test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_set_constructor_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_set_constructor_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mset constructor test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_set time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_set time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mset constructor test failed\033[0m" << std::endl;
    std::cout << "set constructor test end" << std::endl << std::endl;
}
//size
void   set_size_test() {
 std::cout << "set size test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_set_size_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_set_size_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mset size test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_set time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_set time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mset size test failed\033[0m" << std::endl;
    std::cout << "set size test end" << std::endl << std::endl;
}
//operator=
void   set_operator_equal_test() {
 std::cout << "set operator test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_set_operator_equal_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_set_operator_equal_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mset operator test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_set time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_set time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mset operator test failed\033[0m" << std::endl;
    std::cout << "set operator test end" << std::endl << std::endl;
}
//empty
void   set_empty_test() {
 std::cout << "set empty test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_set_empty_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_set_empty_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mset empty test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_set time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_set time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mset empty test failed\033[0m" << std::endl;
    std::cout << "set empty test end" << std::endl << std::endl;
}
//insert
void   set_insert_test() {
 std::cout << "set insert test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_set_insert_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_set_insert_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mset insert test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_set time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_set time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mset insert test failed\033[0m" << std::endl;
    std::cout << "set insert test end" << std::endl << std::endl;
}
//erase
void   set_erase_test() {
 std::cout << "set erase test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_set_erase_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_set_erase_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mset erase test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_set time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_set time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mset erase test failed\033[0m" << std::endl;
    std::cout << "set erase test end" << std::endl << std::endl;
}
//swap
void   set_swap_test() {
 std::cout << "set swap test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_set_swap_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_set_swap_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mset swap test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_set time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_set time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mset swap test failed\033[0m" << std::endl;
    std::cout << "set swap test end" << std::endl << std::endl;
}
//clear
void   set_clear_test() {
 std::cout << "set clear test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_set_clear_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_set_clear_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mset clear test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_set time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_set time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mset clear test failed\033[0m" << std::endl;
    std::cout << "set clear test end" << std::endl << std::endl;
}
//relational operators
void   set_relational_operators_test() {
 std::cout << "set relational operators test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_set_relational_operators_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_set_relational_operators_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mset relational operators test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_set time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_set time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_set time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mset relational operators test failed\033[0m" << std::endl;
    std::cout << "set relational operators test end" << std::endl << std::endl;
}

void set_tests(int time) {
    std::cout << "\x1B[2J\x1B[H";
    set_constructor_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    set_size_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    set_empty_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    set_clear_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    set_insert_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    set_erase_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    set_swap_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    set_operator_equal_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    set_relational_operators_test();
    sleep(time);
}