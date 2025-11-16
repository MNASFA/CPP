NAME = Polymorphism
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
HEADERS = Animal.hpp  DogCat.hpp  WrongAnimal.hpp  WrongCat.hpp Brain.hpp
SRCS = Animal.cpp DogCat.cpp main.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
