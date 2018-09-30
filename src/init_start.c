/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:51:18 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/30 07:06:26 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

int		exit_x(t_store *s)
{
	s = NULL;
	exit(1);
	return (0);
}

int catch_hooks(int key, t_store *s)
{
	s = NULL;
	if (key == 53)
		exit(1);
	return (0);
}

void	start_loop(t_store *s)
{
	mlx_hook(s->win, 2, 5, catch_hooks, s);
	mlx_hook(s->win, 17, 1L << 17, exit_x, s);
	mlx_loop(s->mlx);
}

void	init_start(char *fract_name)
{
	t_store	sf;

	if (!(sf.mlx = mlx_init()))
		exit(1);
	if (!(sf.win = mlx_new_window(sf.mlx, WIN_WIDTH, WIN_HEIGHT, fract_name)))
		exit(1);
	sf.img = mlx_new_image(sf.mlx, WIN_WIDTH, WIN_HEIGHT);
	sf.f_i = (int*)mlx_get_data_addr(sf.img, &sf.bpp, &sf.sl, &sf.e);
	set_data(&sf, fract_name);
	make_fract(&sf);
	start_loop(&sf);
}
