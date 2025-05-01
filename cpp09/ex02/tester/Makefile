# --- # Colors # --- #
RESET = \033[0m
WHITE_BOLD = \033[1;39m
BLACK_BOLD = \033[1;30m
RED_BOLD = \033[1;31m
GREEN_BOLD = \033[1;32m
YELLOW_BOLD = \033[1;33m
BLUE_BOLD = \033[1;34m
PINK_BOLD = \033[1;35m
CYAN_BOLD = \033[1;36m

WHITE = \033[0;39m
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PINK = \033[0;35m
CYAN = \033[0;36m
# ------------------ #



# ---- # Vars # ---- #
NAME = tester

C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -O3 -DSEQUENCE_TESTS_AMOUNT=10#-g -fsanitize=address

SRC = src/
PROGRAM_SRC = ../src/
BIN_DIR = bin/
INC = -I$(SRC) -I$(PROGRAM_SRC)

FILES = tester.cpp \
		PmergeMe.cpp \
		TestResult.cpp
OBJS = $(FILES:%.cpp=$(BIN_DIR)%.o)
DEPS = $(OBJS:%.o=%.d)
# ------------------ #

# --- # vpath # ---- #
vpath %.cpp $(SRC):\
			$(PROGRAM_SRC)/PmergeMe:\
			$(SRC)/TestResult
# ------------------ #



# --- # Rules # ---- #
all:
	@$(MAKE) --no-print-directory $(NAME)

$(NAME): $(OBJS) Makefile
	@printf "$(PINK)Linking $(YELLOW)objects$(PINK)...$(RESET)\n"
	@$(C++) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)Program compiled and ready to use.$(RESET)\n"

$(BIN_DIR)%.o: %.cpp Makefile
	@printf "$(PINK)Compiling $(CYAN)$(notdir $<)$(PINK)...$(RESET)\n"
	@mkdir -p $(BIN_DIR)
	@$(C++) $(FLAGS) $(INC) -MMD -c $< -o $@

clean:
	@rm -rf $(BIN_DIR)
	@printf "$(RED)Objects and dependencies removed.$(RESET)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED)Executable $(WHITE)$(NAME)$(RED) removed.$(RESET)\n"

re: fclean all
# ------------------ #

# --- # Extras # --- #
-include $(DEPS)

.PHONY: all \
		clean \
		fclean \
		re

.SILENT:
# ------------------ #
