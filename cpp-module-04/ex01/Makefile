NAME = Animal

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJ = $(SRC:.cpp=.o)
DEPS = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
