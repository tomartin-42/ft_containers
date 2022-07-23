# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 19:11:19 by tomartin          #+#    #+#              #
#    Updated: 2022/07/23 18:56:38 by tomartin         ###   ########.fr        #
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

# Name of the program
NAME = ft_container 
NAME2 = ft_container_std

# Compiling and flags
#CXX = clang++ --std=c++98
CXX = g++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror -Iinc -MD -O3 -g3 #-fsanitize=address
LDFLAGS = #-fsanitize=address

# Folders
OBJ_DIR = obj/
SRC_DIR = src/

# Source files and includes
SRC_FILES = main.cpp

# Objs
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))	
OBJ = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.cpp=.o))
DEP = $(OBJ:.o=.d)

# all rule
all: obj $(NAME) 

std: obj $(NAME2)

-include $(DEP)

print:
	echo $(SRC)
	echo $(OBJ)
	echo $(DEP)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp 
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# Compiling
$(NAME): $(OBJ)
	@echo "By Tomartin in 42Madrid"
	@$(CXX) $(OBJ) $(LDFLAGS) -D NS=ft -o $(NAME)
	@echo "Compilation OK!!"
	@echo "$(NAME) ready!".

$(NAME2): $(OBJ)
	@echo "By Tomartin in 42Madrid"
	@$(CXX) $(OBJ) $(LDFLAGS) -D NS=std -o $(NAME2)
	@echo "Compilation OK!!"
	@echo "$(NAME2) ready!".

bonus: all

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@echo "Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@echo "$(NAME) removed!"
	@echo "$(NAME2) removed!"

# re rule
 re: fclean all

# phony
 .PHONY: all clean fclean re
