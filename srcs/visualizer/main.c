/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:08:23 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/29 20:25:36 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"
#include "../../includes/filler.h"

void	get_player_name(char *line, char **player);
void	get_player_name(char *line, char **player)
{
	char	**tab;
	char	**tab2;
	int		i;
	int		j;

	if (ft_strstr(line, "bad player") != 0)
		exit(1);
	tab = NULL;
	tab2 = NULL;
	i = 0;
	j = 0;
	tab = ft_strsplit(line, '/');
	while (ft_strstr(tab[i], ".filler") == 0)
		i++;
	tab2 = ft_strsplit(tab[i], '.');
	while (ft_strstr(tab2[j], "filler") == 0)
		j++;
	*player = ft_strdup(tab2[j - 1]);
	ft_free_tab_char(&tab);
	ft_free_tab_char(&tab2);
	free(line);
}

void	get_players(t_visu *v);
void	get_players(t_visu *v)
{
	char	*line;
	int		i;
	int		j;

	line = NULL;

	i = 6;
	j = 0;
	while (i-- > 0)
	{
		get_next_line_backslash(STDIN_FILENO, &line);
		if (ft_strstr("error:", line) != 0)
			exit(1);
		free(line);
	}
	get_next_line_backslash(STDIN_FILENO, &line);
	get_player_name(line, &v->p1);
	v->p1 = ft_strjoin_proper("p1 = ", 0, v->p1, 1);

	get_next_line_backslash(STDIN_FILENO, &line);
	get_next_line_backslash(STDIN_FILENO, &line);
	get_player_name(line, &v->p2);
	v->p2 = ft_strjoin_proper("p2 = ", 0, v->p2, 1);
}

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

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

void	set_header(t_visu *v);
void	set_header(t_visu *v)
{
	int	w;
	int	h;

	v->surf = SDL_GetWindowSurface(v->window);
	SDL_FillRect(v->surf, NULL, SDL_MapRGB(v->surf->format, 65, 51, 51));

	TTF_SizeText(v->title, "Filler", &w, &h);
	put_on_screen_sdl(v, TTF_RenderText_Blended(v->title, "Filler", v->white), (v->width_w / 2 - w / 2), 20);

	TTF_SizeText(v->police, v->p1, &w, &h);
	put_on_screen_sdl(v, TTF_RenderText_Blended(v->police, v->p1, v->purple), (v->width_w / 2 - w - 100), 100);

	put_on_screen_sdl(v, TTF_RenderText_Blended(v->police, v->p2, v->pink), (v->width_w / 2 + 100), 100);
}

void	set_params_rects(t_visu *v, int width_w, int width_r, char **tab);
void	set_params_rects(t_visu *v, int width_w, int width_r, char **tab)
{
		v->width_w = width_w;
		v->height_w = width_w;
		v->rect.w = width_r;
		v->rect.h = width_r;
		v->nb_x = ft_atoi(tab[2]);
		v->nb_y = ft_atoi(tab[1]);
}

void	get_window_size(t_visu *v);
void	get_window_size(t_visu *v)
{
	char	*line;
	char	**tab;

	tab = NULL;
	line = NULL;

	get_next_line_backslash(STDIN_FILENO, &line);
	tab = ft_strsplit(line, ' ');
	free(line);
	if (ft_strstr(tab[0], "Plateau") == 0)
		exit(1);
	if (ft_atoi(tab[1]) <= 20 && ft_atoi(tab[2]) <= 20)
		set_params_rects(v, 800, 28, tab);
	else if (ft_atoi(tab[1]) <= 50 && ft_atoi(tab[2]) <= 50)
		set_params_rects(v, 1000, 18, tab);
	else if (ft_atoi(tab[1]) <= 100 && ft_atoi(tab[2]) <= 100)
		set_params_rects(v, 1200, 25, tab);
	else
	{
		ft_free_tab_char(&tab);
		exit(1);
	}
	ft_free_tab_char(&tab);
}

int	main(void)
{
	t_visu	v;

	
	init_struct_visu(&v);
	get_players(&v);
	get_window_size(&v);
	




	
	init_SDL(&v);
	set_header(&v);

	SDL_Rect	border;
	SDL_Surface		*sborder;
	int	width_line;
	int	height_line;

	width_line = v.nb_x * v.rect.w + (v.nb_x - 1) * 2;
	height_line = v.nb_y * v.rect.h + (v.nb_y - 1) * 2;
//	printf("%d\n", width_line);

	int nb_x;

	nb_x = v.nb_x;

	border.x = (v.width_w - width_line) / 2;
	border.y = 180 - 2;
	border.h = height_line + 4;
	border.w = 2;

	sborder = SDL_CreateRGBSurface(0, border.w, border.h, 32, 0, 0, 0, 0);
	while (nb_x >= 0)
	{
	// Verticale Gauche
	SDL_FillRect(sborder, NULL, SDL_MapRGB(sborder->format, 250, 227, 227));
	SDL_BlitSurface(sborder, NULL, v.surf, &border);
	border.x += v.rect.w + 2;
	nb_x--;
	}
	SDL_FreeSurface(sborder);




	int	nb_y;

	nb_y = v.nb_y;

	// Horizontale haut
	border.x = (v.width_w - width_line) / 2;
	border.y = 180 - 2;
	border.h = 2;
	border.w = width_line + 4;
	
	sborder = SDL_CreateRGBSurface(0, border.w, border.h, 32, 0, 0, 0, 0);

	while (nb_y >= 0)
	{
	SDL_FillRect(sborder, NULL, SDL_MapRGB(sborder->format, 250, 227, 227));
	SDL_BlitSurface(sborder, NULL, v.surf, &border);
	border.y += v.rect.h + 2;
	nb_y--;
	}
	SDL_FreeSurface(sborder);
	
	
	
	
	
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
				v.loop = false;
		}
	}
	if (v.loop == false)
	{
		TTF_CloseFont(v.police);
		TTF_CloseFont(v.title);
		SDL_DestroyWindow(v.window);
		SDL_Quit();
	}
	return EXIT_SUCCESS;
}
