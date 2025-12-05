CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp ScalarConverter.cpp
OBJS = $(SRC:.cpp=.o)
NAME = Scalar_Converter

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all