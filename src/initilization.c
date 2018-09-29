/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:51:18 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/29 20:03:00 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractols.h"

int		exit_x(t_store *s)
{
	exit(1);
	return (0);
}

void	start_loop(t_store *s)
{


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
	sf.img = mlx_new_image(sf.mlx, WIN_WIDTH, WIN_HIGHT);
	sf.f_i = (int*)mlx_get_data_addr(sf.img, &sf.bpp, &sf.sl, &sf.e);
//------
	int		x;
	int		y = 0;

	while (y < WIN_HIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			map[x + y * WIN_WIDTH] = #ffffff;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(sf.mlx, sf.win, sf.f_i, 0, 0);
//-----
	start_loop(&sf);
}
