/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:51:18 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/26 21:24:44 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractols.h"

void	initilization(char *fract_name)
{
	t_store	sf;

	if (!(sf.mlx = mlx_init()))
		exit(1);
	if (!(sf.win = mlx_new_window(sf.mlx, WIN_WIDTH, WIN_HEIGHT, fract_name)))
		exit(1);	
	sf.img_w = WIN_WIDTH - (2 * BORDER_W);
	sf.img = mlx_new_image(sf.mlx, sf.img_w, WIN_HIGHT);
	sf.f_i = (int*)mlx_get_data_addr(sf.img, &sf.bpp, &sf.sl, &sf.e);
}
