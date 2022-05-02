##
##
## arthur.viard@ynov.com
## Makefile
##
##

NAME_ASTAR	= final_astar/astar

SRCS_A		= sources/main.c\
		  sources/astar.c\
		  sources/list.c\
		  sources/map.c\
		  sources/open_close.c

OBJS_A		= $(SRCS_A:.c=.o)

CC		= gcc -g3

RM		= rm -rf

CFLAGS		= -Wall -Wextra -Iinclude

all:		$(NAME_A) $(NAME_GEN) $(NAME_ASTAR)

$(NAME_ASTAR): $(OBJS_A)
	mkdir -p final_astar
	$(CC) -o $(NAME_ASTAR) $(OBJS_A) $(CFLAGS)

clean:
	$(RM) $(OBJS_A)

fclean:		clean
	$(RM) $(NAME_GEN) $(NAME_ASTAR)
	$(RM) final_astar

re:		fclean all

.PHONY:		all clean fclean re
