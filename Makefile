# Project name
NAME    := cub3d

# Compiler and flags
CC      := cc
CFLAGS  := -Werror -Wextra -Wall -Wunreachable-code -Ofast -g

# Libraries and paths
LIBMLX      := ./MLX42
LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

GNL_DIR     := get_next_line
GNL_LIB     := $(GNL_DIR)/get_next_line.a

# Headers and libs
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT_DIR) -I $(GNL_DIR)
LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Sources
SRCS    := src/main.c
OBJS    := ${SRCS:.c=.o}

# Default target
all: libmlx42.a $(LIBFT) $(GNL_LIB) $(NAME)

# Compile main executable
$(NAME): $(OBJS) $(LIBFT) $(GNL_LIB)
	@echo "Compiling $(NAME)..."
	@$(CC) $(OBJS) $(LIBS) $(LIBFT) $(GNL_LIB) $(HEADERS) -o $(NAME)

# Compile MLX
libmlx42.a: $(LIBMLX) $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a:
	@echo "Compiling MLX42..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build >/dev/null
	@make -C $(LIBMLX)/build -j4 > /dev/null

$(LIBMLX):
	@echo "Cloning MLX42..."
	@git clone https://github.com/codam-coding-college/MLX42 2> /dev/null

# Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

# Compile libft
$(LIBFT):
	@echo "Compiling libft..."
	@make -sC $(LIBFT_DIR)

# Compile get_next_line
$(GNL_LIB):
	@echo "Compiling get_next_line..."
	@make -sC $(GNL_DIR)

# Clean
clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(GNL_DIR) clean

# Full clean
fclean: clean
	@echo "Removing all built files..."
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(GNL_LIB)
	@rm -rf $(LIBMLX)

# Rebuild
re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
