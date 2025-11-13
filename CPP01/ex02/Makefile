NAME = brainz

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re