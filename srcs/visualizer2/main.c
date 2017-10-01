/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:08:23 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/01 15:33:12 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

int	stock_map_in_list(t_visu *v, t_v *t, char **line);
int	stock_map_in_list(t_visu *v, t_v *t, char **line)
{
	int	i;

	i = 0;
	t->tab = (char**)malloc(sizeof(char*) * (v->nb_y + 1));
	while (i < v->nb_y - 1)
	{
		if (ft_strlen(*line) != (size_t)v->nb_x + 5)
			exit (1);
		t->tab[i++] = ft_strsub(*line, 4, v->nb_x);
		free(*line);
		v->ret = get_next_line_backslash(STDIN_FILENO, line);
		if (v->ret == 0)
			return (1); // a modifier
	}
	t->tab[i] = NULL;
	return (0);
}

void	case_ennemy_lost(char **line, t_visu *v);
void	case_ennemy_lost(char **line, t_visu *v)
{
	char	**tab;
	int	nb_y_piece;

	tab = ft_strsplit(*line, ' ');
	nb_y_piece = ft_atoi(tab[1]);
	ft_free_tab_char(&tab);

	while (nb_y_piece > 0)
	{
		v->ret = get_next_line_backslash(STDIN_FILENO, line);
//		ft_putstr(*line);
		nb_y_piece--;
	}
	v->ret = get_next_line_backslash(STDIN_FILENO, line);
//	ft_putstr(*line);
	v->ret = get_next_line_backslash(STDIN_FILENO, line);
//	ft_putstr(*line);
}

int	pass_piece(char **line)
{
	char	**tab;
	int		nb_y_piece;
	
	tab = ft_strsplit(*line, ' ');
	nb_y_piece = ft_atoi(tab[1]);
	ft_free_tab_char(&tab);
	
	while (nb_y_piece > 0)
	{
		if (get_next_line_backslash(STDIN_FILENO, line) == 0)
			return (1);
//		ft_putstr(*line);
		nb_y_piece--;
	}
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		return (1);
	return (0);
}

int		stock_map(t_visu *v, t_v **t, char **line)
{
	// Penser a free *line a chaque fois
	// Penser a check le retour de v->ret
	int		i;

	i = 0;
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		return (1);
	if (ft_strstr(*line, "Piece") != 0) // Ennemi a perdu
	{
		case_ennemy_lost(line, v);
	}
	else if (ft_strstr(*line, "Plateau") == 0 || ft_strstr(*line, "fin") != 0)
	{
//		ft_putstr(*line);
//		ft_putendl("1 - Plateau");
		return (1);
	}
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		return (1);
//	ft_putstr(*line); // numeros de lignes en X
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		return (1);
//	ft_putstr(*line); // Premiere ligne du platea

	stock_map_in_list(v, *t, line);

	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		return (1);
//	ft_putstr(*line); // Piece
	if (ft_strstr(*line, "Piece") == 0)
	{
//		ft_putendl("1 - Piece");
		return (1);
	}

	if (pass_piece(line) == 1)
		return (1);
//	ft_putstr(*line); // Got
	if (ft_strstr(*line, "got") == 0)
	{
		ft_putendl("1 - got");
		return (1);
	}
	if (ft_strstr(*line, "X") != 0)
		(*t)->current_player = 2;
	else if (ft_strstr(*line, "O") != 0)
		(*t)->current_player = 1;

	return (0);
}

void	init_first_link(char **line, t_v **t, t_v **begin, t_visu *v)
{
	int	i;

	i = 0;
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
	{
		free(*line);
		exit(1);
	}
//	ft_putendl("\nfirst line");
//	ft_putstr(*line);
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
	{
		free(*line);
		exit(1);
	}
	*t = malloc(sizeof(t));
	*begin = *t;
	stock_map_in_list(v, *t, line);

	// PRINT
	while ((*t)->tab[i] && (*t)->tab[i] != NULL)
		ft_putendl((*t)->tab[i++]);
	ft_putchar('\n');
	//
	
	if (v->ret != 1)
		(*t)->next = NULL;
	while (ft_strstr(*line, "got") == 0)
	{
		if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		{
			free(*line);
			exit (1);
		}
	}
	if (ft_strstr(*line, "X") != 0)
		(*t)->current_player = 2;
	else if (ft_strstr(*line, "O") != 0)
		(*t)->current_player = 1;
}

int	main(void)
{
	t_visu	v;
	t_v		*t;
	t_v		*begin;
	char	*line;
	int		i;

	t = NULL;
	begin = NULL;
	line = NULL;
	i = 0;

	init_struct_visu(&v);
	get_players(&v);
	get_window_size(&v);
	init_SDL(&v);

	init_first_link(&line, &t, &begin, &v);
	set_header(&v);
	put_grid_vertic(&v);
	put_grid_horiz(&v);



	/*
	   int	w;
	   int	h;
	   SDL_Surface		*pink;

	   v.rect.x = 252;
	   v.rect.y = 200;


	   pink = SDL_CreateRGBSurface(0, v.rect.w, v.rect.h, 32, 0, 0, 0, 0);
	   SDL_FillRect(pink, NULL, SDL_MapRGB(pink->format, 207, 71, 132));
	   SDL_BlitSurface(pink, NULL, v.surf, &v.rect);

	   SDL_Surface		*purple;

	   v.rect.x = 200;
	   v.rect.y = 200;

	   purple = SDL_CreateRGBSurface(0, v.rect.w, v.rect.h, 32, 0, 0, 0, 0);
	   SDL_FillRect(purple, NULL, SDL_MapRGB(purple->format, 185, 119, 212));
	   SDL_BlitSurface(purple, NULL, v.surf, &v.rect);

	   TTF_SizeText(v.police, "X", &w, &h);
	   put_on_screen_sdl(&v, TTF_RenderText_Blended(v.police, "X", v.white), 252 + w / 2, 205);

	   TTF_SizeText(v.police, "O", &w, &h);
	   put_on_screen_sdl(&v, TTF_RenderText_Blended(v.police, "O", v.white), 200 + w / 2, 205);
	   */

	SDL_UpdateWindowSurface(v.window);

	while (v.loop)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				v.loop = false;
			}
			else if(event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == LEFT)
					printf("LEFT");
				else if (event.key.keysym.sym == RIGHT)
				{
					if (v.ret != 0)
					{
						t->next = malloc(sizeof(*t));
						t->next->prev = t;


						t = t->next;
										//	ft_putstr(line);
						if (stock_map(&v, &t, &line) == 1)
						{
							free(line);
							v.ret = 0;
							t->next = NULL;
						}
					/*	if (t != NULL && v.ret != 0) // print
						{
							ft_putendl("**************************");
							ft_putstr("Player ");
							ft_putnbr(t->prev->current_player);
							ft_putendl(" plays");
							i = 0;
							while (t->tab[i] && t->tab[i] != NULL)
								ft_putendl(t->tab[i++]);
						}*/
					}
					else
					{
						ft_putendl("FIN !");
						t->next = NULL;
					}
				//	ft_putchar('\n');
					

				}
				else if (event.key.keysym.sym == CLOSE)
				{
					ft_putendl("ici");
					v.loop = false;
				}
			}
		}
	}
/*	while (begin->next != NULL)
	{
		if (begin->prev)
		{
	ft_putendl("**************************");
	ft_putstr("Player ");
	ft_putnbr(begin->prev->current_player);
	ft_putendl(" plays");
		}

	i = 0;
	while (begin->tab[i] != NULL)
		ft_putendl(begin->tab[i++]);
	begin = begin->next;
	ft_putchar('\n');
	}
*/

	if (v.loop == false)
	{
		TTF_CloseFont(v.police);
		TTF_CloseFont(v.title);
		SDL_DestroyWindow(v.window); // SEGFAULT ICI
		SDL_Quit();

	}
	return EXIT_SUCCESS;
}
