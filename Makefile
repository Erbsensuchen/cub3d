NAME	:= cub3d
CFLAGS	:=  -Werror -Wextra -Wall -Wunreachable-code -Ofast -g
LIBMLX	:= ./MLX42
LIBFT 	:= printf/libftprintf.a

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= 
OBJS	:= ${SRCS:.c=.o}

all: libmlx42.a $(NAME)

mlx: libmlx42.a

libmlx42.a: $(LIBMLX) MLX42/build/libmlx42.a

MLX42/build/libmlx42.a:
	@echo "compiling MLX42"
	@cmake $(LIBMLX) -B $(LIBMLX)/build >/dev/null && make -C $(LIBMLX)/build -j4 > /dev/null

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(LIBMLX):
	@echo "getting MLX42"
	@git clone https://github.com/codam-coding-college/MLX42 2> /dev/null

$(NAME): $(OBJS) $(LIBFT)
	@echo "compiling $(NAME)"
	@$(CC) $(OBJS) $(LIBS) $(LIBFT) $(HEADERS) -o $(NAME) 

$(LIBFT): 
	@echo compiling printflibft
	@make bonus -sC printf 2> /dev/null

clean:
	@echo "removing temp files"
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make fclean -sC printf 

fclean: clean
	@echo "removing all files"
	@rm -rf $(LIBMLX)
	@rm -rf $(NAME)

re: fclean all

bonus: all

.PHONY: all, clean, fclean, re, bonus