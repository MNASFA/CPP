NAME = horde
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = zombieHorde.cpp Zombie.cpp main.cpp
HEADERS = Zombie.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
 
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all