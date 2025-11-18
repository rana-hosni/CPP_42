CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

CXXFILES = main.cpp\
		PhoneBook.cpp\
		Contact.cpp

OBJFILES = $(CXXFILES:.cpp=.o)

NAME = PhoneBook

all: $(NAME)

$(NAME): $(OBJFILES)
	$(CXX) $(CXXFLAGS)  -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all