/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:19:18 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/25 10:42:18 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "ft_containers.hpp"
#include "std_containers.hpp"
#include <sys/time.h>

//constructor
void   stack_constructor_test() {
 std::cout << "stack constructor test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_stack_constructor_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_stack_constructor_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mstack constructor test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_stack time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_stack time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_stack time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_stack time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mstack constructor test failed\033[0m" << std::endl;
    std::cout << "stack constructor test end" << std::endl << std::endl;
}
//size
void   stack_size_test() {
 std::cout << "stack size test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_stack_size_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_stack_size_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mstack size test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_stack time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_stack time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_stack time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_stack time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mstack size test failed\033[0m" << std::endl;
    std::cout << "stack size test end" << std::endl << std::endl;
}
//empty
void   stack_empty_test() {
 std::cout << "stack empty test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_stack_empty_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_stack_empty_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mstack empty test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_stack time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_stack time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_stack time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_stack time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mstack empty test failed\033[0m" << std::endl;
    std::cout << "stack empty test end" << std::endl << std::endl;
}
//swap
void   stack_swap_test() {
 std::cout << "stack swap test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_stack_swap_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_stack_swap_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mstack swap test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_stack time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_stack time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_stack time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_stack time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mstack swap test failed\033[0m" << std::endl;
    std::cout << "stack swap test end" << std::endl << std::endl;
}
//relational operators
void   stack_relational_operators_test() {
 std::cout << "stack relational operators test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_stack_relational_operators_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_stack_relational_operators_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mstack relational operators test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_stack time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_stack time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_stack time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_stack time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mstack relational operators test failed\033[0m" << std::endl;
    std::cout << "stack relational operators test end" << std::endl << std::endl;
}

void stack_tests(int time) {
    std::cout << "\x1B[2J\x1B[H";
    stack_constructor_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    stack_size_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    stack_empty_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    stack_swap_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    stack_relational_operators_test();
    sleep(time);
}