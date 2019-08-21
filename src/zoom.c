/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 09:48:11 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/30 17:00:07 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	interpolate(double begin, double end, double i)
{
	return (begin + ((end - begin) * i));
}

int		zoom(int key, int x, int y, t_store *s)
{
	double	m_re;
	double	m_im;
	double	interp;
	double	zoom_f;

	if (key == 4)
		zoom_f = 1.1;
	else if (key == 5)
		zoom_f = 0.9;
	else
		return (0);
	m_re = (double)x / (WIN_WIDTH / (s->max_re - s->min_re)) + s->min_re;
	m_im = (double)y / (WIN_HEIGHT / (s->max_im - s->min_im)) + s->min_im;
	interp = 1.0 / zoom_f;
	s->min_re = interpolate(m_re, s->min_re, interp);
	s->min_im = interpolate(m_im, s->min_im, interp);
	s->max_re = interpolate(m_re, s->max_re, interp);
	s->max_im = interpolate(m_im, s->max_im, interp);
	s->del_x = (s->max_re - s->min_re) / (double)(WIN_WIDTH - 1);
	s->del_y = (s->max_im - s->min_im) / (double)(WIN_HEIGHT - 1);
	ft_bzero(s->f_i, (WIN_WIDTH * WIN_HEIGHT * 4));
	make_fract(s);
	return (0);
}
