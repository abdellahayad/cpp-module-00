NAME = AForm

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AForm.cpp  Bureaucrat.cpp  main.cpp  PresidentialPardonForm.cpp  RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp

OBJ = $(SRC:.cpp=.o)
DEPS =  AForm.hpp  Bureaucrat.hpp PresidentialPardonForm.hpp  RobotomyRequestForm.hpp  ShrubberyCreationForm.hpp

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
