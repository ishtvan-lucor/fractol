/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 02:37:58 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/30 06:44:21 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_mb(t_store	*s, char *fract_name)
{
	s->min_re = -2.0;
	s->max_re = 1.0;
	s->min_im = -1.2;
	s->max_im = s->min_im + (s->max_re - s->min_re) * WIN_HEIGHT / WIN_WIDTH;
	s->max_iter = 50;
	s->f_n = fract_name;
	s->del_x = (s->max_re - s->min_re) / (double)(WIN_WIDTH - 1);
	s->del_y = (s->max_im - s->min_im) / (double)(WIN_HEIGHT - 1);
	s->color.rgb = 0xffffff;
}

void	set_data(t_store *store, char *f_name)
{
	if (!(ft_strcmp(f_name, MB)))
			set_mb(store, MB);
}
