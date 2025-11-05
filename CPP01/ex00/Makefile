NAME = Zombie
CC = c++
CFLAGS = -Wall -Wextra -Werror
SRC = newZombie.cpp Zombie.cpp randomChump.cpp main.cpp
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