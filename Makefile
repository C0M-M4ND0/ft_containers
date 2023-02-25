# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 13:50:20 by oabdelha          #+#    #+#              #
#    Updated: 2023/02/25 11:35:58 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -g  -std=c++98 -Wall -Werror -Wextra #-fsanitize=address  -fsanitize=undefined

OBJECT_PATH = ./object_files/
FOBJ_SRC = object_files
SRC = main.cpp

NAME = main

INCLUDE = $(addprefix include/, vector.hpp iterator.hpp reverse_iterator.hpp iterator_traits.hpp map.hpp red-black_tree.hpp red-black_tree_iterator.hpp set.hpp utility.hpp stack.hpp)
INCLUDE += $(addprefix tests/, map_tests.hpp set_tests.hpp vector_tests.hpp stack_tests.hpp ft_containers.hpp std_containers.hpp)
OBJECTS = $(addprefix $(OBJECT_PATH), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(FOBJ_SRC) $(OBJECTS) $(INCLUDE)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

$(OBJECT_PATH)%.o : %.cpp $(INCLUDE)
	@$(CXX) $(CXXFLAGS) -o $@  -c $<


$(FOBJ_SRC) :
	@mkdir $@

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(FOBJ_SRC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all