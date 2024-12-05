CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
SRCS = main.cpp PmergeMe.cpp
INCS = PmergeMe.hpp
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
NAME = PmergeMe

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

re :
	make fclean
	make all

.PHONY : all clean fclean re