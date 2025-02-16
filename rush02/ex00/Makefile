CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c atoa.c file_content.c ft_split.c ft_strlen.c print_num.c sep_key_value.c validate_input.c ft_atoi.c ft_itoa.c ft_strcmp.c ft_putstr.c print_small_digit.c dict_check.c
OBJS = $(SRCS:.c=.o)
NAME = rush-02

.PHONY: all clean fclean re

all: $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -c

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
