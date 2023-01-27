NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRCPATH = ./srcs/

RM = rm -rf

SRCS = $(addprefix $(SRCPATH), 	\
			ft_printf.c ft_itoa_pf.c ft_putchar.c ft_putstr.c \
			ft_utoa.c ft_printhex.c ft_pflag.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

.o: .c
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

git:
	git add libs/ $(SRCS) Makefile
	sleep 5
	git commit -m "Automated commit from Makefile"
	git push

