# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
NAME    := libft.a

# Directories
OBJ_DIR := obj

# Source and object files
SRC_FILES := ft_abs.c ft_aish.c ft_aisi.c ft_atocolor.c ft_atoi.c ft_bzero.c ft_calloc.c ft_free_ints.c ft_free_strs.c ft_htoi.c ft_in_charset.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_max.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_min.c ft_print_strs.c ft_printstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_remove_charackter.c ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_write_bytes.c
OBJ_FILES := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Include directories
INCLUDES := -I.

# Default target
all: $(NAME)

# Archive object files into static library
$(NAME): $(OBJ_FILES)
	@echo "Compiling libft..."
	@ar rcs $(NAME) $(OBJ_FILES)

# Compile .c into .o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create object directory if not exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	@echo "Cleaning libft..."
	@rm -rf $(OBJ_DIR)

# Clean all
fclean: clean
	@echo "Full clean libft..."
	@rm -f $(NAME)

# Rebuild all
re: fclean all

.PHONY: all clean fclean re
