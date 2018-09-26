/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:25:03 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/26 21:24:58 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_L
# define WIN_WIDTH 1300
# define WIN_HEIGHT 900
# define BORDER_W 200
# define MB "mandelbrot"
# define J "julia"
# include <math.h>
# include "../libft/libft.h"
# include "mlx.h"

typedef struct	s_store
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*f_i;
	int			bpp;
	int			sl;
	int			e;
	int			img_w;
}				t_store;

int				main(int argc, char **argv);
void			initilization(char *fract_name);

#endif
