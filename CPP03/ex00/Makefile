NAME = ClapTrap

# Folders
SRC_DIR = src
INC_DIR = include
OBJ_DIR = objs

# Files
SRCS = $(SRC_DIR)/ClapTrap.cpp \
       $(SRC_DIR)/main.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Compiler
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -I $(INC_DIR)
RM = rm -f

# Colors
BOLD = \033[1m
GREEN = \033[32m
CYAN = \033[36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo " "
	@echo "$(BOLD)$(GREEN)✔ Build completed!$(RESET)"
	@echo " "

# Generate .o inside objs/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Create objs/ automatically
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJS)
	@rmdir $(OBJ_DIR) 2>/dev/null || true

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
