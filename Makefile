SOURCE	=	push_swap.c operation_push.c
SOURCE	+=	operation_rotate.c operation_swap.c
SOURCE	+=	operation_reverse_rotate.c push_swap_utils.c

OBJECTS	=	$(SOURCE:.c=.o)

LIBFTPATH		=	./libft

LIBFT			=	$(LIBFTPATH)/libft.a

MAKE	=	make -C

NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -Werror -g

CC	=	gcc

RM	=	rm -f

.c.o:	
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(LIBFT):
	@$(MAKE) $(LIBFTPATH)

$(NAME):	$(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
	@echo 'Push_swap done'


clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) $(LIBFTPATH) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) $(LIBFTPATH) fclean

re:	fclean
	make
