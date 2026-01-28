NAME = bureaucrat

SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

BOLD = \033[1m
CYAN = \033[36m
GREEN = \033[32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo " "
	@echo "$(BOLD)$(GREEN)✔  Build completed $(RESET)"
	@echo " "

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re