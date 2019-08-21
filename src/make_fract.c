/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 03:14:50 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/30 19:37:24 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		make_color(t_store *s, int iter)
{
	int	current;

	current = 0;
	if (iter == s->max_iter)
		current = s->color;
	return (current);
}

int		calc_fract(t_store *s, double re, double im)
{
	int	iter;

	iter = 0;
	if (!(ft_strcmp(s->f_n, MB)))
		iter = mandelbrot(re, im, s->max_iter);
	else if (!(ft_strcmp(s->f_n, J)))
		iter = julia(re, im, s);
	else if (!(ft_strcmp(s->f_n, B)))
		iter = burning_ship(re, im, s->max_iter);
	return (make_color(s, iter));
}

void	make_fract(t_store *s)
{
	int		x;
	int		y;
	double	c_re;
	double	c_im;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		c_im = s->min_im + (double)y * s->del_y;
		x = 0;
		while (x < WIN_WIDTH)
		{
			c_re = s->min_re + (double)x * s->del_x;
			s->f_i[x + y * WIN_HEIGHT] = calc_fract(s, c_re, c_im);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
}
