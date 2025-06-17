# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
NAME    := get_next_line.a

# Directories
OBJ_DIR := obj

# Source and object files
SRC_FILES := get_next_line.c get_next_line_utils.c
OBJ_FILES := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Include directories
INCLUDES := -I.

# Default target
all: $(NAME)

# Archive object files into static library
$(NAME): $(OBJ_FILES)
	@echo "Compiling get_next_line..."
	@ar rcs $(NAME) $(OBJ_FILES)

# Compile .c into .o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create object directory if not exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	@echo "Cleaning get_next_line..."
	@rm -rf $(OBJ_DIR)

# Clean all
fclean: clean
	@echo "Full clean get_next_line..."
	@rm -f $(NAME)

# Rebuild all
re: fclean all

.PHONY: all clean fclean re
