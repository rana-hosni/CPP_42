CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp \
Base.cpp \
A.cpp \
B.cpp \
C.cpp 
OBJ = $(SRC:.cpp=.o)
NAME = ex02

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re