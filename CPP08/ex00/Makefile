CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
NAME = ex00
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAG) -o $@ $^
%.o:%.cpp
	$(CC) $(CFLAG) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re