# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 13:06:15 by seungryk          #+#    #+#              #
#    Updated: 2024/09/14 21:06:01 by seungryk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
NAME = ex04

all : $(NAME)

$(NAME) : $(OBJS) $(INCS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : 
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	rm -f *.replace

re : 
	make fclean
	make all

.PHONY : all clean fclean re