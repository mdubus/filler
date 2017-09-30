/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:08:23 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/30 21:07:41 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	put_on_screen_sdl(t_visu *v, SDL_Surface *texte, int x, int y)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	SDL_BlitSurface(texte, NULL, v->surf, &rect);
	SDL_FreeSurface(texte);
}

SDL_Color	init_color(int r, int g, int b, int a)
{
	SDL_Color	color;

	color.r = (Uint8)r;
	color.g = (Uint8)g;
	color.b = (Uint8)b;
	color.a = (Uint8)a;
	return (color);
}

void	set_params_rects(t_visu *v, int width_w, int width_r, char **tab)
{
	v->width_w = width_w;
	if (width_w == 800)
		v->height_w = width_w + 100;
	else if (width_w == 1000)
		v->height_w = width_w + 50;
	else if (width_w == 1200)
		v->height_w = width_w;
	v->nb_x = ft_atoi(tab[2]);
	v->nb_y = ft_atoi(tab[1]);
	if (v->nb_x > v->nb_y)
		width_r = (width_w - 200 - v->nb_x) / v->nb_x;
	else
		width_r = (width_w - 350 - v->nb_y) / v->nb_y;
	v->rect.w = width_r;
	v->rect.h = width_r;
}

int		stock_map(t_visu *v, t_v **t, char **line)
{
	int		i;

	i = 0;
	v->ret = get_next_line_backslash(STDIN_FILENO, line);
	if (ft_strstr(*line, "Plateau") == 0 || ft_strstr(*line, "fin") != 0)
		return (1);
	v->ret = get_next_line_backslash(STDIN_FILENO, line);
	v->ret = get_next_line_backslash(STDIN_FILENO, line);
	ft_putstr(*line);

/*	while (ft_strstr(*line, "000") == 0)
	{
		free(*line);
		v->ret = get_next_line_backslash(STDIN_FILENO, line);
		if (v->ret == -1)
		{
			free(*line);
			exit(1);
		}
		if (v->ret == 0 || ft_strstr(*line, "fin") != 0)
		{
			*t = NULL;
			return (1);
		}
	}*/
	(*t)->tab = (char**)malloc(sizeof(char*) * (v->nb_y + 1));
	while (i < v->nb_y - 1)
	{
		if (ft_strlen(*line) != (size_t)v->nb_x + 5)
			exit (1);
		(*t)->tab[i++] = ft_strsub(*line, 4, v->nb_x);
		free(*line);
		v->ret = get_next_line_backslash(STDIN_FILENO, line);
		ft_putstr(*line);
		if (v->ret == 0)
			return (1);

	}
	(*t)->tab[i] = NULL;
	

	//// Piece
	// Les pieces
	// got
	// Plateau
	return (0);
}

int	main(void)
{
/*	
char	*line;

line = NULL;

while (get_next_line_backslash(STDIN_FILENO, &line) != 0)
	ft_putstr(line);
*/
	
	t_visu	v;
	t_v		*t;
	t_v *begin;

	init_struct_visu(&v);
	get_players(&v);
	get_window_size(&v);

	init_SDL(&v);
	set_header(&v);
	put_grid_vertic(&v);
	put_grid_horiz(&v);



(void)t;

	char	*line;
	int		i;

	line = NULL;
	i = 0;
	get_next_line_backslash(STDIN_FILENO, &line);
//	ft_putendl("\nfirst line");
	get_next_line_backslash(STDIN_FILENO, &line);
	t = malloc(sizeof(t));
	begin = t;
	
	stock_map(&v, &t, &line);

	if (v.ret != 1)
		t->next = NULL;

	while (ft_strstr(line, "got") == 0)
		get_next_line_backslash(STDIN_FILENO, &line);
	

//	get_next_line_backslash(STDIN_FILENO, &line);
//	ft_putendl(line);

	// PLateau ou fin
	
	//	}
	//	t->next = NULL;
	/*
	   while (begin->next != NULL)
	   {
	   i = 0;
	   while (begin->tab[i] != NULL)
	   printf("%s\n", begin->tab[i++]);
	   begin = begin->next;
	   printf("\n");
	   }
	   
*/



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
						ft_putendl("Enter here");
						t->next = malloc(sizeof(*t));
						t->next->prev = t;
						t = t->next;
//						i = 0;
//						while (t->prev->tab[i] && t->prev->tab[i] != NULL)
//							ft_putendl(t->prev->tab[i++]);
						ft_putstr(line);
						if (stock_map(&v, &t, &line) == 1)
						{
							v.ret = 0;
							t->next = NULL;
						}
					}
					else
					{
						ft_putendl("FIN !");
						t->next = NULL;
					}
					ft_putchar('\n');
					

				}
				else if (event.key.keysym.sym == CLOSE)
					v.loop = false;
			}
		}
	}
/*	while (begin->next != NULL)
	{
	i = 0;
	while (begin->tab[i] != NULL)
		ft_putendl(begin->tab[i++]);
	begin = begin->next;
	ft_putchar('\n');
	}*/


	if (v.loop == false)
	{
		TTF_CloseFont(v.police);
		TTF_CloseFont(v.title);
		SDL_DestroyWindow(v.window);
		SDL_Quit();
	}
	return EXIT_SUCCESS;
}
