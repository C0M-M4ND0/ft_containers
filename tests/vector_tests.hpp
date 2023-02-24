/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:54:22 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/24 22:27:46 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "ft_containers.hpp"
#include "std_containers.hpp"

//constructors
void vector_constructor() {
    std::cout << "vector constructors test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_constructors_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_constructors_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector constructors test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector constructors test failed\033[0m" << std::endl;
    std::cout << "vector constructors test end" << std::endl << std::endl;
}

//assiment operator
void vector_assiment_operator() {
    std::cout << "vector assiment operator test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_assiment_operator_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_assiment_operator_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector assiment operator test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector assiment operator test failed\033[0m" << std::endl;
    std::cout << "vector assiment operator test end" << std::endl << std::endl;
}

//size
void vector_size() {
    std::cout << "vector size test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_size_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_size_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector size test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector size test failed\033[0m" << std::endl;
    std::cout << "vector size test end" << std::endl << std::endl;
}

//resize
void vector_resize() {
    std::cout << "vector resize test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_resize_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_resize_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector resize test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector resize test failed\033[0m" << std::endl;
    std::cout << "vector resize test end" << std::endl << std::endl;
}

//capacity
void vector_capacity() {
    std::cout << "vector capacity test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_capacity_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_capacity_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector capacity test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector capacity test failed\033[0m" << std::endl;
    std::cout << "vector capacity test end" << std::endl << std::endl;
}
//reserve
void vector_reserve() {
    std::cout << "vector reserve test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_reserve_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_reserve_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector reserve test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector reserve test failed\033[0m" << std::endl;
    std::cout << "vector reserve test end" << std::endl << std::endl;
}
//assign
void vector_assign() {
    std::cout << "vector assign test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_assign_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_assign_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector assign test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector assign test failed\033[0m" << std::endl;
    std::cout << "vector assign test end" << std::endl << std::endl;
}
//insert
void vector_insert() {
    std::cout << "vector insert test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_insert_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_insert_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector insert test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector insert test failed\033[0m" << std::endl;
    std::cout << "vector insert test end" << std::endl << std::endl;
}
//erase
void vector_erase() {
    std::cout << "vector erase test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_erase_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_erase_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector erase test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector erase test failed\033[0m" << std::endl;
    std::cout << "vector erase test end" << std::endl << std::endl;
}
//swap
void vector_swap() {
    std::cout << "vector swap test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_swap_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_swap_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector swap test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector swap test failed\033[0m" << std::endl;
    std::cout << "vector swap test end" << std::endl << std::endl;
}
//clear
void vector_clear() {
    std::cout << "vector clear test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_clear_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_clear_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector clear test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector clear test failed\033[0m" << std::endl;
    std::cout << "vector clear test end" << std::endl << std::endl;
}
//relational operators
void vector_relational_operators() {
    std::cout << "vector relational operators test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    clock_t start, end;
    
    start = clock();
    std_vector = std_vector_relational_operators_test();
    end = clock();
    std_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    start = clock();
    ft_vector = ft_vector_relational_operators_test();
    end = clock();
    ft_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mvector relational operators test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_vector time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_vector time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_vector time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mvector relational operators test failed\033[0m" << std::endl;
    std::cout << "vector relational operators test end" << std::endl << std::endl;
}

void vector_tests(int time) {
    std::cout << "\x1B[2J\x1B[H";
    vector_constructor();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_assiment_operator();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_size();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_resize();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_capacity();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_reserve();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_assign();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_insert();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_erase();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_swap();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_clear();
    std::cout << "\x1B[2J\x1B[H";
    sleep (time);
    vector_relational_operators();
    
}