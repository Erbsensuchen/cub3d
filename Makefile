# Project name
NAME        := cub3d
DEBUG_NAME  := cub3d_debug

# Compiler and flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Wunreachable-code -Ofast -MMD -MP -fsanitize=address -g
# CFLAGS 		+= -Wno-unused-parameter -Wno-unused-function -Wno-unused-variable
DEBUG_FLAGS := -g -O0 -DDEBUG=1

# Directories
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
LIBS        := $(LIBMLX)/build/libmlx42.a -lglfw -lm

vpath %.c src
vpath %.c src/parsing
vpath %.c src/texture
vpath %.c src/game
vpath %.c src/color
vpath %.c src/movement
vpath %.c src/hooks
vpath %.c src/minimap
vpath %.c src/rendering
vpath %.c src/utils
vpath %.c src/goose

# Source and object files
SRC_FILES := main.c \
			print_color.c \
			free_game.c \
			init_game.c \
			print_game.c \
			parsing_map.c \
			parsing.c \
			validate_grid.c \
			parsing_utils.c \
			free_texture.c \
			init_texture.c \
			load_textures.c \
			print_texture.c \
			get_pixel_color.c \
			move.c \
			hooks.c \
			keyhook.c \
			loophook.c \
			cursorhook.c \
			resizehook.c \
			mousehook.c \
			rendering.c \
			render_goose.c \
			cast_ray.c \
			pre_render.c \
			angle_utils.c \
			minimap.c \
			draw_player_triangle.c \
			double_utils.c \
			random.c \
			update_goose.c \

OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_DEBUG_FILES := $(addprefix $(OBJ_DEBUG_DIR)/, $(SRC_FILES:.c=.o))

# Default
all: $(NAME)

# Main binary
$(NAME): $(LIBFT) $(GNL_LIB) $(LIBMLX) $(LIBMLX)/build/libmlx42.a $(OBJ_FILES)
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJ_FILES) $(CFLAGS) $(LIBS) $(LIBFT) $(GNL_LIB) -o $(NAME)

# Debug binary
debug: $(LIBFT) $(GNL_LIB) $(LIBMLX) $(LIBMLX)/build/libmlx42.a $(OBJ_DEBUG_FILES)
	@echo "Linking debug build..."
	@$(CC) $(OBJ_DEBUG_FILES) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS) $(LIBFT) $(GNL_LIB) -o $(DEBUG_NAME)

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
mlx: $(LIBMLX) $(LIBMLX)/build/libmlx42.a

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

# bonus rule
bonus: all

# Debug-specific cleaning
debug_clean:
	@rm -rf $(OBJ_DEBUG_DIR)

debug_fclean:
	@rm -rf $(OBJ_DEBUG_DIR)
	@rm -f $(LIBFT) $(GNL_LIB)
	@rm -f $(DEBUG_NAME)

debug_re: debug_fclean debug

# Run the program
run: all
	@./$(NAME) maps/test.cub

# Run the debug program
debug_run: debug
	@./$(DEBUG_NAME)

# Automatically include dependency files
-include $(OBJ_FILES:.o=.d)
-include $(OBJ_DEBUG_FILES:.o=.d)

.PHONY: all debug clean fclean re debug_clean debug_fclean debug_re run debug_run
