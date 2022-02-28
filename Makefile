# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 19:11:19 by tomartin          #+#    #+#              #
#    Updated: 2022/02/28 09:39:56 by tomartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Collors
BLU = \033[0;34m
GRN = \033[0;32m
YEL = \033[0;33m
RED = \033[0;31m
WHT = \033[0;37m
ORG = \033[38;5;202m

RESET = \033[0m                        
# SO
UNAME := $(shell uname)

# Name of the program
NAME = ft_container 

# Compiling and flags
CXX = clang++ --std=c++98
FLAGS = -Wall -Wextra -Werror -O3 -g3 -fsanitize=address

# Folders
OBJ_DIR = ./obj/
SCR_DIR = ./
STACK_DIR = ./stak/ 
VECTOR_DIR = ./vector/

# Source files and includes
SRC_FILES = main.cpp
STACK_FILES = stack.hpp
VECTOR_FILES = 

# Objs
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Paths
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
STACK = $(addprefix $(STACK_DIR), $(STACK_FILES))
VECTOR = $(addprefix $(VECTOR_DIR), $(VECTOR_FILES))

# all rule
all: obj $(NAME) 

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp 
	@$(CXX) -o $@ -c $<
	#@$(CXX) -I $(INC_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(STACK_DIR)%.cpp 
	@$(CXX) -o $@ -c $<
$(OBJ_DIR)%.o: $(VECTOR_DIR)%.cpp 
	@$(CXX) -o $@ -c $<

# Compiling
$(NAME): $(OBJ)

	@echo "By Tomartin in 42Madrid"
	@$(CXX) $(OBJ) $(FLAGS) -lm -o $(NAME)
	@echo "Compilation OK!!"
	@echo "$(NAME) ready!".

bonus: all

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@echo "Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed!"

 # re rule
 re: fclean all

 # phony
 .PHONY: all clean fclean re
