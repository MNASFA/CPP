NAME = Sed_is_for_losers
CC = cc 
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
HEADERS = 
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