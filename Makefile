# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 13:50:20 by oabdelha          #+#    #+#              #
#    Updated: 2023/02/10 11:04:54 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -g #-fsanitize=address -fsanitize=undefined #-std=c++98 -Wall -Werror -Wextra

OBJECT_PATH = ./object_files/
FOBJ_SRC = object_files
SRC = main.cpp

NAME = main

INCLUDE = $(addprefix include/, vector.hpp iterator.hpp reverse_iterator.hpp type_traits.hpp iterator_traits.hpp map.hpp red-black_tree.hpp red-black_tree_iterator.hpp)
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