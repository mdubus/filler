# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 14:11:57 by gpouyat           #+#    #+#              #
#*   Updated: 2016/12/01 11:50:27 by gpouyat          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC			=	clang
NAME		=	mdubus.filler
FLAGS		=	-Wall -Wextra -Werror -g -Weverything -fsanitize=address
#FLAGS		=	-Wall -Wextra -Werror
LIBDIR		=	libft
LIBLINK		=	-L $(LIBDIR) -lft
LIB 		=	$(LIBDIR)/libft.a

INCLUDES	= 	-I ./includes
INCLUDE		=	./includes

OBJDIR		=	objs
SRCDIR		=	srcs
SRC			=	main.c init_struct_filler.c free_tab_char.c get_player_info.c\
				useful.c get_map_info.c search_ennemy.c create_heat_map.c\
				init_heat_map.c do_heat_map.c get_piece.c stock_piece.c\
				get_distance_piece_form.c

OBJ			= $(SRC:.c=.o)
SRCS		=	$(addprefix $(SRCDIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))


all: directory $(NAME)

$(NAME): $(OBJDIR) $(LIB) $(OBJS) $(INCLUDE)
	@$(CC) $(FLAGS) -o $@ $(OBJS) $(LIBLINK)

$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES)

directory: $(OBJDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBDIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean all re fclean directory
