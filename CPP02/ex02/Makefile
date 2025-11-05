NAME = operator_overload
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp Fixed.cpp
HEADERS = Fixed.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
