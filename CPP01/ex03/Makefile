NAME = attacks
CC = c++
CFLAGS = -Wall -Wextra -Werror
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp ${HEADERS}
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all