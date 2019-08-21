/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:55:44 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/30 19:33:26 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(double c_re, double c_im, int max_iter)
{
	int		iter;
	double	z_re;
	double	z_im;
	double	z2_re;
	double	z2_im;

	iter = 0;
	z_re = c_re;
	z_im = c_im;
	while (iter < max_iter)
	{
		z2_re = z_re * z_re;
		z2_im = z_im * z_im;
		if (z2_re + z2_im > 4.0)
			break ;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z2_re - z2_im + c_re;
		iter++;
	}
	return (iter);
}

int	julia(double z_re, double z_im, t_store *s)
{
	int		iter;
	double	z2_re;
	double	z2_im;

	iter = 0;
	while (iter < s->max_iter)
	{
		z2_re = z_re * z_re;
		z2_im = z_im * z_im;
		if (z2_re - z2_im > 4.0)
			break ;
		z_im = 2 * z_re * z_im + s->k_im;
		z_re = z2_re - z2_im + s->k_re;
		iter++;
	}
	return (iter);
}

int	burning_ship(double c_re, double c_im, int max_iter)
{
	int		iter;
	double	z_re;
	double	z_im;
	double	z2_re;
	double	z2_im;

	iter = 0;
	z_re = c_re;
	z_im = c_im;
	while (iter < max_iter)
	{
		z2_re = z_re * z_re;
		z2_im = z_im * z_im;
		if (z2_re + z2_im > 4.0)
			break ;
		z_im = fabs(2 * z_re * z_im) + c_im;
		z_re = fabs(z2_re - z2_im + c_re);
		iter++;
	}
	return (iter);
}
