NAME = libftprintf.a

SOURCES = ft_printf.c \
		ft_putstuff.c \
		ft_printf_utils.c \
		ft_setflags.c \
		ft_sort.c



MY_SOURCES = $(addprefix libft/, ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c )

BSRC = $(addsuffix _bonus.c, ft_sort\
			ft_putstuff \
			ft_putnbr \
			ft_putunbr \
			ft_puthex \
			ft_sort \
			ft_put_ptr)

OBJECTS = $(SOURCES:.c=.o)
MY_OBJECTS = $(MY_SOURCES:.c=.o)
BOBJ = $(BSRC:.c=.o)
BSORTO = $(BSORT:.c=.o)


CFLAGS = -Werror -Wextra -Wall

.PHONY:
	all clean libft.a fclean re test bonus

all: $(NAME)

$(NAME): $(OBJECTS)
	cd ./libft && make bonus
	ar -rsc $(NAME) $(OBJECTS) $(MY_OBJECTS)

bonus: $(BOBJ) all 
	@ar -rsc $(NAME) ft_sort.o 
	@ar -d $(NAME) ft_sort.o
	@ar -rsc $(NAME) $(BOBJ) 

clean: 
	@rm -f $(OBJECTS) $(BOBJ) && cd libft && make fclean

fclean: clean 
	@rm -f $(NAME)

re: fclean all

test: bonus
	@cc $(CFLAGS) main.c libftprintf.a  -fsanitize=address