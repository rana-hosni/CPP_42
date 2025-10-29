CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp\
	Zombie.cpp\
	randomChump.cpp\
	newZombie.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = BraiiiiiiinnnzzzZ

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