CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp\
	AForm.cpp\
	Bureaucrat.cpp\
	ShrubberyCreationForm.cpp\
	RobotomyRequestForm.cpp\
	PresidentialPardonForm.cpp

OBJ = $(CFILES:.cpp=.o) 
NAME = bureaucrat

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
