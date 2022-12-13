NAME = pipex

INCLPATH = ./includes/
SRCPATH = ./srcs/
FTPATH = ./libft/libft.a
PRINTPATH = ./ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = $(addprefix $(SRCPATH), \
								pipex.c \
								pipex_utils.c )

all: $(NAME)

$(NAME): $(FTPATH) $(PRINTPATH)
	$(CC) -I $(INCLPATH) $(CFLAGS) $(SRCS) $(FTPATH) $(PRINTPATH) -o $@

$(FTPATH):
	$(MAKE) all -C ./libft/ && $(MAKE) clean -C ./libft/

$(PRINTPATH):
	$(MAKE) all -C ./ft_printf/ && $(MAKE) clean -C ./ft_printf/

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

git: fclean
	git add *
	sleep 5
	git commit -m "Automatic commit from Makefile."
	git push

.PHONY: all $(NAME) clean fclean re git