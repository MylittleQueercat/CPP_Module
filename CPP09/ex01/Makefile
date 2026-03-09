# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leticiabi <leticiabi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 16:33:23 by hguo              #+#    #+#              #
#    Updated: 2026/02/23 15:38:01 by leticiabi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

BOLD = \033[1m
GREEN = \033[32m
CYAN = \033[36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo " "
	@echo "$(BOLD)$(GREEN)✔  Build completed $(RESET)$(CYAN)"
	@echo " "

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re