/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:08:23 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/28 18:48:37 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"
#include "../../includes/filler.h"

char	*ft_strnstartcpy(char *s, size_t i);
char	*ft_strnstartcpy(char *s, size_t i)
{
	size_t	len;
	char	*str;
	size_t	j;

	str = NULL;
	len = ft_strlen(s) - i;
	j = 0;
	str = malloc(sizeof(char) * len + 1);
	while (s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

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
		free(line);
	}
	get_next_line_backslash(STDIN_FILENO, &line);
	get_player_name(line, &v->p1);
	v->p1 = ft_strjoin_proper("p1 = ", 0, v->p1, 1);

	get_next_line_backslash(STDIN_FILENO, &line);
	get_next_line_backslash(STDIN_FILENO, &line);
	get_player_name(line, &v->p2);
	v->p2 = ft_strjoin_proper("p2 = ", 0, v->p2, 1);

//	printf("%s\n", v->p2);
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

int	main(void)
{
	t_visu	v;
	int	w;
	int	h;
	
	init_struct_visu(&v);
	init_SDL(&v);
	get_players(&v);


	v.surf = SDL_GetWindowSurface(v.window);
	SDL_FillRect(v.surf, NULL, SDL_MapRGB(v.surf->format, 65, 51, 51));

	TTF_SizeText(v.title, "Filler", &w, &h);
	put_on_screen_sdl(&v, TTF_RenderText_Blended(v.title, "Filler", v.white), (WIDTH_W / 2 - w / 2), 20);

	TTF_SizeText(v.police, v.p1, &w, &h);
	put_on_screen_sdl(&v, TTF_RenderText_Blended(v.police, v.p1, v.purple), (WIDTH_W / 2 - w - 100), 100);
	put_on_screen_sdl(&v, TTF_RenderText_Blended(v.police, v.p2, v.pink), (WIDTH_W / 2 + 100), 100);


	SDL_Surface		*pink;
	SDL_Rect		rect;

	rect.x = 252;
	rect.y = 200;
	rect.w = 50;
	rect.h = 50;

	
	pink = SDL_CreateRGBSurface(0, 50, 50, 32, 0, 0, 0, 0);
	SDL_FillRect(pink, NULL, SDL_MapRGB(pink->format, 207, 71, 132));
	SDL_BlitSurface(pink, NULL, v.surf, &rect);

	SDL_Surface		*purple;
	SDL_Rect		rect2;

	rect2.x = 200;
	rect2.y = 200;

	purple = SDL_CreateRGBSurface(0, 50, 50, 32, 0, 0, 0, 0);
	SDL_FillRect(purple, NULL, SDL_MapRGB(purple->format, 185, 119, 212));
	SDL_BlitSurface(purple, NULL, v.surf, &rect2);



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
