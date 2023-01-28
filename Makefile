NAME = pipex

INCLPATH = ./includes/
SRCPATH = ./srcs/
FTPATH = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = $(addprefix $(SRCPATH), \
								pipex.c \
								pipex_utils.c )

all: $(NAME)

$(NAME): $(FTPATH) $(SRCS)
	$(CC) -I $(INCLPATH) $(CFLAGS) $(SRCS) $(FTPATH) -o $@

$(FTPATH):
	$(MAKE) all -C ./libft/

clean:
	$(RM) *.o
	$(MAKE) clean -C ./libft/

fclean: clean
	$(RM) $(NAME)
	$(RM) $(FTPATH)

re: fclean all

git: fclean
	git add *
	sleep 5
	git commit -m "Automatic commit from Makefile."
	git push

.PHONY: all clean fclean re git