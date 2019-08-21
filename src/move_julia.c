/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:04:30 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/30 19:25:48 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	convertor(double c, double len, double min, double max)
{
	return (min + (max - min) * (c / len));
}

int	move_julia(int x, int y, t_store *s)
{
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (0);
	if (!(ft_strcmp(s->f_n, J)))
	{
		s->k_re = convertor(x, WIN_WIDTH, s->min_re, s->max_re);
		s->k_im = convertor(y, WIN_HEIGHT, s->min_im, s->max_im);
		bzero(s->f_i, (WIN_WIDTH * WIN_HEIGHT * 4));
		make_fract(s);
	}
	return (0);
}
