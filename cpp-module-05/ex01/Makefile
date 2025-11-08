NAME = Form

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp main.cpp Form.cpp

OBJ = $(SRC:.cpp=.o)
DEPS =  Bureaucrat.hpp Form.hpp

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
