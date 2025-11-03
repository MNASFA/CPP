NAME = Harl_2_0
CC = c++
CFLAGS = -Wall -Wextra -Werror
SRC = main.cpp Harl.cpp
HEADERS = Harl.hpp
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