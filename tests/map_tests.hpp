/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:59:34 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/25 10:44:58 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "ft_containers.hpp"
#include "std_containers.hpp"
#include <sys/time.h>

//constructors
void map_constructors_test() {
    std::cout << "map constructors test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_map_constructors_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_map_constructors_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mmap constructors test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_map time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_map time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mmap constructors test failed\033[0m" << std::endl;
    std::cout << "map constructors test end" << std::endl << std::endl;
    
}
//operator =
void map_operator_equal_test() {
    std::cout << "map operator test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_map_operator_equal_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_map_operator_equal_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mmap operator test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_map time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_map time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mmap operator test failed\033[0m" << std::endl;
    std::cout << "map operator test end" << std::endl << std::endl;
    
}
//size
void map_size_test() {
    std::cout << "map size test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_map_size_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_map_size_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mmap size test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_map time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_map time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mmap size test failed\033[0m" << std::endl;
    std::cout << "map size test end" << std::endl << std::endl;
    
}
//insret
void map_insert_test() {
    std::cout << "map insert test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_map_insert_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_map_insert_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mmap insert test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_map time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_map time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mmap insert test failed\033[0m" << std::endl;
    std::cout << "map insert test end" << std::endl << std::endl;
}
//erase
void map_erase_test() {
    std::cout << "map erase test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_map_erase_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_map_erase_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mmap erase test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_map time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_map time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mmap erase test failed\033[0m" << std::endl;
    std::cout << "map erase test end" << std::endl << std::endl;
    
}
//swap
void map_swap_test() {
    std::cout << "map swap test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_map_swap_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_map_swap_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mmap swap test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_map time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_map time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mmap swap test failed\033[0m" << std::endl;
    std::cout << "map swap test end" << std::endl << std::endl;
    
}
//clear
void map_clear_test() {
    std::cout << "map clear test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_map_clear_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_map_clear_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mmap clear test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_map time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_map time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mmap clear test failed\033[0m" << std::endl;
    std::cout << "map clear test end" << std::endl << std::endl;
    
}
//find
void map_find_test() {
    std::cout << "map find test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_map_find_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_map_find_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mmap find test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_map time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_map time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mmap find test failed\033[0m" << std::endl;
    std::cout << "map find test end" << std::endl << std::endl;
    
}
//equal_range
void map_equal_range_test() {
    std::cout << "map equal_range test start" << std::endl;
    std::vector<int> std_vector;
    std::vector<int> ft_vector;
    
    double std_time, ft_time;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    std_vector = std_map_equal_range_test();
    gettimeofday(&end, NULL);
    std_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    gettimeofday(&start, NULL);
    ft_vector = ft_map_equal_range_test();
    gettimeofday(&end, NULL);
    ft_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (std_vector == ft_vector){
        std::cout << "\033[1;32mmap equal_range test passed\033[0m" << std::endl;
        if (std_time > ft_time)
            std::cout << std::fixed << "\033[1;32mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;31mstd_map time: " << std_time << "\033[0m" << std::endl;
        else
            std::cout << std::fixed << "\033[1;31mft_map time: " << ft_time << "\033[0m" << std::endl << "\033[1;32mstd_map time: " << std_time << "\033[0m" << std::endl;
    }
    else
        std::cout << "\033[1;31mmap equal_range test failed\033[0m" << std::endl;
    std::cout << "map equal_range test end" << std::endl << std::endl;
    
}

void map_tests(int time) {
    std::cout << "\x1B[2J\x1B[H";
    map_constructors_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    map_operator_equal_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    map_size_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    map_insert_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    map_erase_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    map_swap_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    map_clear_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    map_find_test();
    sleep(time);
    std::cout << "\x1B[2J\x1B[H";
    map_equal_range_test();
    sleep(time);
}