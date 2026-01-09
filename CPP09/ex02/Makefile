CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = PmergeMe
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re