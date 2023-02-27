/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:37:04 by oabdelha          #+#    #+#             */
/*   Updated: 2023/02/27 15:19:47 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/utility.hpp"
#include "include/map.hpp"
#include "include/vector.hpp"
#include "include/set.hpp"
#include "include/stack.hpp"
#include "tests/vector_tests.hpp"
#include "tests/map_tests.hpp"
#include "tests/set_tests.hpp"
#include "tests/stack_tests.hpp"
#include <map>

int main (int argc, char **argv) {
    int time = 3;
    if (argc >= 2)
    {
        if (argc > 2 && !strcmp(argv[2], "-fast")){
            time = 1;
        }
        if (!strcmp(argv[1], "-m"))
            map_tests(time);
        else if (!strcmp(argv[1], "-v"))
            vector_tests(time);
        else if (!strcmp(argv[1], "-s"))
            set_tests(time);
        else if (!strcmp(argv[1], "-st"))
            stack_tests(time);
        else
            std::cout << "Usage: ./ft_containers -m/-v/-s/-st [-fast]" << std::endl;
    }
    else
        std::cout << "Usage: ./ft_containers -m/-v/-s/-st [-fast]" << std::endl;
    return (1);
}
