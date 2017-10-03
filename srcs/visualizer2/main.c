/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:08:23 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/03 11:37:13 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

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
