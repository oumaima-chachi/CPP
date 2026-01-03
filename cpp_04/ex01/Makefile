NAME = animals

SRC = main.cpp Cat.cpp Dog.cpp Animal.cpp Brain.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all