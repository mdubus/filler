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
VISU		=	visu
#FLAGS		=	-Wall -Wextra -Werror -g -Weverything -fsanitize=address
FLAGS		=	-Wall -Wextra -Werror
LIBDIR		=	libft
LIBLINK		=	-L $(LIBDIR) -lft
LIB 		=	$(LIBDIR)/libft.a
LIB_VISU	=	-L ~/.brew/lib -lSDL2 -lSDL2_ttf

INCLUDES	= 	-I ./includes
INCLUDE		=	./includes
INCLUDES_VISU	=	-I ~/.brew/include/SDL2/ -D_THREAD_SAFE

OBJDIR		= 	objs

OBJDIR_ALGO	=	objs/algorithm
OBJDIR_VISU	=	objs/visualizer

SRCDIR_ALGO	=	srcs/algorithm
SRCDIR_VISU	=	srcs/visualizer

SRC_ALGO	=	main.c init_struct_filler.c free.c get_player_info.c\
				useful.c get_map_info.c create_heat_map.c\
				init_heat_map.c do_heat_map.c get_piece.c stock_piece.c\
				search_next_star.c count_score.c resolve.c

SRC_VISU	=	main.c get_players_vm.c init.c useful.c get_board_infos.c\
				get_result.c stock_link.c stock_links.c get_screen_dimensions.c\
				write_players.c write_filler.c put_grid.c

OBJ_ALGO	=	$(SRC_ALGO:.c=.o)
OBJ_VISU	=	$(SRC_VISU:.c=.o)

SRCS_ALGO	=	$(addprefix $(SRCDIR_ALGO)/, $(SRC_ALGO))
OBJS_ALGO	=	$(addprefix $(OBJDIR_ALGO)/, $(SRC_ALGO:.c=.o))

SRCS_VISU	=	$(addprefix $(SRCDIR_VISU)/, $(SRC_VISU))
OBJS_VISU	=	$(addprefix $(OBJDIR_VISU)/, $(SRC_VISU:.c=.o))


all: directory $(NAME) $(VISU)

$(NAME): $(OBJDIR_ALGO) $(LIB) $(OBJS_ALGO) $(INCLUDE)
	@$(CC) $(FLAGS) -o $@ $(OBJS_ALGO) $(LIBLINK)

$(VISU): $(OBJDIR_VISU) $(LIB) $(OBJS_VISU) $(INCLUDE)
	@$(CC) $(FLAGS) -o $@ $(OBJS_VISU) $(LIBLINK) $(LIB_VISU)

$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR_ALGO)/%.o: $(SRCDIR_ALGO)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES)

$(OBJDIR_VISU)/%.o: $(SRCDIR_VISU)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES) $(INCLUDES_VISU)

directory: $(OBJDIR) $(OBJDIR_ALGO) $(OBJDIR_VISU)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR_ALGO):
	@mkdir -p $(OBJDIR_ALGO)

$(OBJDIR_VISU):
	@mkdir -p $(OBJDIR_VISU)

clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(OBJS_ALGO)
	@make -C $(LIBDIR) clean
	@rm -rf $(OBJDIR_ALGO)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(VISU)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean all re fclean directory
