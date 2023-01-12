# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 13:50:20 by oabdelha          #+#    #+#              #
#    Updated: 2023/01/12 13:52:33 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -g -std=c++98 -Wall -Werror -Wextra

OBJECT_PATH = ./object_files/
FOBJ_SRC = object_files
SRC = main.cpp

NAME = main

INCLUDE = $(addprefix include/, vector.hpp)
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