/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:27:25 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/03 20:48:13 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"
#pragma GCC diagnostic error "-Weverything"

void	put_on_screen_sdl(t_visu *v, SDL_Surface *surface, int x, int y)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	if (SDL_BlitSurface(surface, NULL, v->surf, &rect) < 0)
	{
		SDL_FreeSurface(surface);
		ft_putstr("Error on TTF_RenderText_Blended : ");
		free_all_visu(v->begin, v, SDL_GetError());
	}
	SDL_FreeSurface(surface);
}

void	put_header(t_visu *v, t_v *begin);
void	put_header(t_visu *v, t_v *begin)
{
	SDL_Surface	*temp;

	write_filler(&temp, v, begin);
	write_p1(&temp, v, begin);
	write_p2(&temp, v, begin);
}

void	free_everything(t_visu *v, t_v *begin)__attribute__((noreturn));
void	free_everything(t_visu *v, t_v *begin)
{
	int		i;
	char	c;

	c = 0;
	free(v->p1);
	free(v->p2);
	while (begin->next != NULL)
	{
		i = 0;
		while (begin->tab[i] != NULL)
			free(begin->tab[i++]);
		begin = begin->next;
		if (begin->prev)
			free(begin->prev);
	}
	i = 0;
	while (begin->tab[i] != NULL)
		free(begin->tab[i++]);
	free(begin);
	exit(1);
}

int		main(void)
{
	t_visu	v;
	t_v		*t;
	t_v		*begin;

	init_struct_visu(&v);
	verif_header_vm();
	get_players_vm(&v);
	printf("\n%s, %s\n", v.p1, v.p2);
	get_board_infos(&t, &v);
	printf("nbx = %d, nby = %d\n", v.nb_x, v.nb_y);
	begin = t;
	stock_links(&v, &t, begin);

	v.begin = begin;
	ft_printf("current player = %d\n", v.begin->current_player);
	get_screen_dimensions(&v, begin);
	init_sdl(&v, begin);
	printf("Width = %d, Height = %d\n\n", v.width_w, v.height_w);
	put_header(&v, begin);

	put_grid_vertic(&v, begin);
	put_grid_horiz(&v, begin);

	SDL_UpdateWindowSurface(v.window);
	/*
	   int		i;
	   while (begin != NULL)
	   {
	   ft_printf("{yellow}Player %d plays !{eoc}\n", begin->current_player);
	   i = 0;
	   while (begin->tab[i] != NULL)
	   {
	   ft_putendl(begin->tab[i++]);
	   }
	   begin = begin->next;
	   ft_putchar('\n');
	   }
	   ft_printf("p1 = %d\n", v.resultp1);
	   ft_printf("p2 = %d\n", v.resultp2);
	   
	//	sleep(1);
	*/

	while (v.loop)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				v.loop = false;
			else if(event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == LEFT)
					ft_printf("LEFT\n");
				else if (event.key.keysym.sym == RIGHT)
				{
					ft_printf("RIGHT\n");

	SDL_Rect	border;
	SDL_Surface	*sborder;

	border.x = v.startx + 1;
	border.y = v.starty + 1;
	border.h = v.square;
	border.w = v.square;
	if ((sborder = SDL_CreateRGBSurface(0, border.w, border.h, 32, 0, 0, 0, 0)) == NULL)
		free_all_visu(begin, &v, "Create RGB Surface failed");
	if (SDL_FillRect(sborder, NULL, SDL_MapRGB(sborder->format, 215, 149, 242)) < 0)
		free_all_visu(begin, &v, "SDL_FillRect failed");
	if (SDL_BlitSurface(sborder, NULL, v.surf, &border) < 0)
		free_all_visu(begin, &v, "SDL_BlitSurface failed");
	SDL_FreeSurface(sborder);
	SDL_UpdateWindowSurface(v.window);
	
				
				}
				else if (event.key.keysym.sym == CLOSE)
					v.loop = false;
			}
		}
	}
	if (v.loop == false)
	{
		free_everything(&v, begin);
		TTF_CloseFont(v.police);
		TTF_CloseFont(v.police_big);
		TTF_CloseFont(v.title);
		SDL_DestroyWindow(v.window);
		SDL_Quit();

	}

	return (0);
}
