/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:55:44 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/30 07:02:14 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(double c_re, double c_im, int max_iter)
{
	int		iter;
	double	z_re;
	double	z_im;

	iter = 0;
	z_re = c_re;
	z_im = c_im;
	while (iter < max_iter)
	{
		double  z2_re;
		double	z2_im;

		z2_re = z_re * z_re;
		z2_im = z_im * z_im;
		if (z2_re + z2_im > 4.0)
			break;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z2_re - z2_im + c_re;
		iter++;
	}
	return (iter);
}
