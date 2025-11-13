NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

COL_CYAN  := \033[36m
COL_RESET := \033[0m

all: $(NAME)

define SHOW_BANNER  
	@printf " \n"
	@printf " \n"
	@printf	"▄   ▄     ▗▄▖                                                              ▄   ▄          ▗▄▖     ▗▖\n"
	@printf "█   █     ▝▜▌                            ▐▌                                █   █          ▝▜▌     ▐▌\n"
	@printf "▜▖█▗▛ ▟█▙  ▐▌   ▟██▖ ▟█▙ ▐█▙█▖ ▟█▙      ▐███  ▟█▙       ▟██▖▐▙█▙ ▐▙█▙      ▜▖█▗▛ ▟█▙  █▟█▌ ▐▌   ▟█▟▌\n"
	@printf "▐▌█▐▌▐▙▄▟▌ ▐▌  ▐▛  ▘▐▛ ▜▌▐▌█▐▌▐▙▄▟▌      ▐▌  ▐▛ ▜▌     ▐▛  ▘▐▛ ▜▌▐▛ ▜▌     ▐▌█▐▌▐▛ ▜▌ █▘   ▐▌  ▐▛ ▜▌\n"
	@printf "▐█▀█▌▐▛▀▀▘ ▐▌  ▐▌   ▐▌ ▐▌▐▌█▐▌▐▛▀▀▘      ▐▌  ▐▌ ▐▌     ▐▌   ▐▌ ▐▌▐▌ ▐▌     ▐█▀█▌▐▌ ▐▌ █    ▐▌  ▐▌ ▐▌\n"
	@printf "▐█ █▌▝█▄▄▌ ▐▙▄ ▝█▄▄▌▝█▄█▘▐▌█▐▌▝█▄▄▌      ▐▙▄ ▝█▄█▘     ▝█▄▄▌▐█▄█▘▐█▄█▘     ▐█ █▌▝█▄█▘ █    ▐▙▄ ▝█▄█▌\n"
	@printf "▝▀ ▀▘ ▝▀▀   ▀▀  ▝▀▀  ▝▀▘ ▝▘▀▝▘ ▝▀▀        ▀▀  ▝▀▘       ▝▀▀ ▐▌▀▘ ▐▌▀▘      ▝▀ ▀▘ ▝▀▘  ▀     ▀▀  ▝▀▝▘\n"
	@printf "	 					   	    ▐▌   ▐▌                                 \n"
	@printf " \n"
	@printf " \n"
	@printf "▗▖               █                      ▗▖                         \n"                                 
	@printf "▐▌               ▀                      ▐▌                         \n"                                 
	@printf "▐▌    ▟█▙  ▟█▟▌ ██  ▐▙██▖       ▄       ▐▙██▖ ▟█▟▌▐▌ ▐▌ ▟█▙       \n"                                  
	@printf "▐▌   ▐▛ ▜▌▐▛ ▜▌  █  ▐▛ ▐▌       █       ▐▛ ▐▌▐▛ ▜▌▐▌ ▐▌▐▛ ▜▌       \n"                                 
	@printf "▐▌   ▐▌ ▐▌▐▌ ▐▌  █  ▐▌ ▐▌               ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌      \n"                                  
	@printf "▐▙▄▄▖▝█▄█▘▝█▄█▌▗▄█▄▖▐▌ ▐▌       █       ▐▌ ▐▌▝█▄█▌▐▙▄█▌▝█▄█▘     \n"                                   
	@printf "▝▀▀▀▘ ▝▀▘  ▞▀▐▌▝▀▀▀▘▝▘ ▝▘       ▀       ▝▘ ▝▘ ▞▀▐▌ ▀▀▝▘ ▝▀▘       \n"                                  
	@printf "	   ▜█▛▘                               ▜█▛▘                 \n" 
	@printf " \n"
	@printf " \n"                                
endef

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	$(SHOW_BANNER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re