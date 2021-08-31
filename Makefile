NAME= push_swap

CC= Clang
CFLAGS= -Wall -Werror -Wextra -fsanitize=address -g3
RM= rm -rf
AR= ar rcs

LIBFT= -Llibft -lft

FILES= push_swap \
	   sort_moves \
	   sort_list \
	   print

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(MAKE) -C Libft/
	$(MAKE) -C Libft/ bonus
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean: 
	$(RM) $(OBJ)
	$(MAKE) -C Libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C Libft/ fclean

all: $(NAME)

re: fclean all

bonus: all

.PHONY: all bonus clean fclean re
