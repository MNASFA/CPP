NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror
SRC = contact.cpp main.cpp phoneBook.cpp
HEADERS = PhoneBook.hpp Contact.hpp
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