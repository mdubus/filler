# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdubus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:19:44 by mdubus            #+#    #+#              #
#    Updated: 2017/09/28 14:19:43 by mdubus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		= gcc

NAME	=	libft.a

FLAGS = -Wall -Werror -Wextra

INCLUDES	=	-I ./includes

OBJDIR	=	objs

SRC =	ft_absolute.c ft_absolute_double.c ft_atoi.c ft_atoi_base.c\
		ft_binary_to_decimal.c ft_bzero.c ft_countwords.c\
		ft_count_nb_occurence.c get_next_line.c ft_fill_with.c ft_isalnum.c\
		ft_isalpha.c ft_isascii.c ft_isblank.c ft_isdigit.c ft_islower.c\
		ft_isprint.c ft_isupper.c ft_itoa.c ft_itoa_base.c ft_itoa_b_llint.c\
		ft_itoa_b_ullint.c ft_itoa_llint.c ft_itoa_ullint.c\
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c\
		ft_lstnew.c ft_lstsize.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
		ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
		ft_nb_puissance_nb.c ft_print_error_exit.c\
		ft_printf.c ft_printf_call_format.c ft_printf_colors.c\
		ft_printf_count_args.c ft_printf_cs.c ft_printf_dioux.c\
		ft_printf_do_flag_hash.c ft_printf_do_flag_zero.c ft_printf_do_flags.c\
		ft_printf_do_parsing.c ft_printf_flags.c ft_printf_getwchar.c\
		ft_printf_getwstring.c ft_printf_is.c ft_printf_is_colors.c\
		ft_printf_parsing.c ft_printf_pourcent_p.c ft_printf_precision.c\
		ft_printf_precision_width.c ft_printf_recup_args.c\
		ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
		ft_putwchar.c ft_putwstr.c ft_replace_char_with_char_in_str.c\
		ft_search_and_replace_one.c ft_search_and_replace_all.c\
		ft_strcat.c ft_strchr.c ft_strclr.c ft_strclen.c\
		ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c\
		ft_strequ.c ft_strislower.c ft_strisupper.c ft_striter.c ft_striteri.c\
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strlen_secure.c ft_strmap.c\
		ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
		ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c\
		ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtoupper.c\
		ft_strtrim.c ft_swap_adress.c ft_tolower.c ft_toupper.c\
		get_next_line_backslash.c ft_nb_occur_char_in_str.c\
		ft_print_error_fd_exit.c ft_strjoin_proper.c ft_free_tab_char.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(FLAGS) -c $(SRC) $(INCLUDES)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all	

.PHONY: all clean fclean re
