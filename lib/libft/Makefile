NAME = libft.a
CC = gcc
FLAG = -Wall -Werror -Wextra 
BFILE = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstnew.c ft_lstmap.c ft_lstiter.c ft_lstlast.c ft_lstsize.c ft_lstdisplay.c
FILE = ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c ft_calloc.c ft_memchr.c ft_putnbr_fd.c  ft_strlcat.c ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_strtrim.c ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_substr.c ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_tolower.c ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_add.c ft_apply.c ft_loop.c ft_manage_2.c ft_manage.c ft_printf.c ft_printf_less_line.c ft_putnstr.c ft_size.c ft_str_utils.c ft_utils.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_sort_int_tab.c 
OBJ=$(FILE:.c=.o)
BOBJ=$(BFILE:.c=.o)

ifdef TEST
OBJ += $(BOBJ)
endif

all: $(NAME)

bonus: 
	$(MAKE) TEST=1 all

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
