NAME = harlFilter

SRC = Harl.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f 

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

