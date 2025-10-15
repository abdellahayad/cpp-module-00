NAME = Materia

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AMateria.cpp Character.cpp cure.cpp ice.cpp main.cpp MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)
DEPS = AMateria.hpp Character.hpp cure.hpp ice.hpp ICharacter.hpp\
	IMateriaSource.hpp MateriaSource.hpp 

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
