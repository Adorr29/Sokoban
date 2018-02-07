##
## EPITECH PROJECT, 2017
## my_sokoban
## File description:
## Makefile
##

NAME	=	sokoban

SRCDIR	=	src/
LIBDIR	=	lib/

SRC	=	$(SRCDIR)main.c \
		$(SRCDIR)$(LIBDIR)my_strlen.c \
		$(SRCDIR)$(LIBDIR)my_putstr.c \
		$(SRCDIR)$(LIBDIR)open_file.c \
		$(SRCDIR)$(LIBDIR)map_get.c \
		$(SRCDIR)$(LIBDIR)map_destroy.c \
		$(SRCDIR)$(LIBDIR)map_aff.c \
		$(SRCDIR)$(LIBDIR)play_get.c \
		$(SRCDIR)$(LIBDIR)move_player.c \
		$(SRCDIR)$(LIBDIR)check_end.c \
		$(SRCDIR)$(LIBDIR)map_reset.c \
		$(SRCDIR)$(LIBDIR)game.c \
		$(SRCDIR)$(LIBDIR)menu.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-l c_graph_prog

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		cc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
