# Project name
NAME        := cub3d
DEBUG_NAME  := cub3d_debug

# Compiler and flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Wunreachable-code -Ofast
DEBUG_FLAGS := -g -O0

# Directories
SRC_DIR     := src
OBJ_DIR     := obj
OBJ_DEBUG_DIR := obj_debug

# Libraries
LIBMLX      := ./MLX42
LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a
GNL_DIR     := get_next_line
GNL_LIB     := $(GNL_DIR)/get_next_line.a

# Include and linking
INCLUDES    := -I include -I $(LIBMLX)/include -I $(LIBFT_DIR) -I $(GNL_DIR)
LIBS        := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Source and object files
SRC_FILES := main.c
VPATH := $(SRC_DIR)
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_DEBUG_FILES := $(addprefix $(OBJ_DEBUG_DIR)/, $(SRC_FILES:.c=.o))

# Default
all: $(NAME)

# Main binary
$(NAME): $(LIBFT) $(GNL_LIB) libmlx42.a $(OBJ_FILES)
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJ_FILES) $(LIBS) $(LIBFT) $(GNL_LIB) -o $(NAME)

# Debug binary
debug: $(LIBFT) $(GNL_LIB) libmlx42.a $(OBJ_DEBUG_FILES)
	@echo "Linking debug build..."
	@$(CC) $(OBJ_DEBUG_FILES) $(LIBS) $(LIBFT) $(GNL_LIB) -o $(DEBUG_NAME)

# Compile .o files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile debug .o files
$(OBJ_DEBUG_DIR)/%.o: %.c | $(OBJ_DEBUG_DIR)
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INCLUDES) -c $< -o $@

# Create obj directories
$(OBJ_DIR) $(OBJ_DEBUG_DIR):
	@mkdir -p $@

# Build MLX42
libmlx42.a: $(LIBMLX) $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a:
	@echo "Building MLX42..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null
	@make -C $(LIBMLX)/build -j4 > /dev/null

$(LIBMLX):
	@echo "Cloning MLX42..."
	@git clone https://github.com/codam-coding-college/MLX42 2> /dev/null

# Build libft
$(LIBFT):
	@echo "Building libft..."
	@make -sC $(LIBFT_DIR)

# Build get_next_line
$(GNL_LIB):
	@echo "Building get_next_line..."
	@make -sC $(GNL_DIR)

# Clean object files
clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR) $(OBJ_DEBUG_DIR)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(GNL_DIR) clean
	@rm -rf $(LIBMLX)/build

# Full clean
fclean: clean
	@echo "Removing binaries..."
	@rm -f $(NAME) $(DEBUG_NAME)
	@rm -f $(LIBFT) $(GNL_LIB)
	@rm -rf $(LIBMLX)

# Rebuild all
re: fclean all

# Debug-specific cleaning
debug_clean:
	@rm -rf $(OBJ_DEBUG_DIR)

debug_fclean:
	@rm -rf $(OBJ_DEBUG_DIR)
	@rm -f $(DEBUG_NAME)

debug_re: debug_fclean debug

.PHONY: all debug clean fclean re debug_clean debug_fclean debug_re
