/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:25:03 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/30 19:12:03 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define UC unsigned char
# define WIN_WIDTH 780
# define WIN_HEIGHT 780
# define MB "mandelbrot"
# define J "julia"
# define B "bsh"
# include <math.h>
# include "../libft/libft.h"
# include "mlx.h"

typedef struct	s_store
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*f_n;
	int			*f_i;
	int			bpp;
	int			sl;
	int			e;
	int			max_iter;
	int			color;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		k_re;
	double		k_im;
	double		del_x;
	double		del_y;
}				t_store;

int				main(int argc, char **argv);
void			init_start(char *fract_name);
void			set_data(t_store *store, char *f_name);
void			make_fract(t_store *s);
int				zoom(int key, int x, int y, t_store *s);
int				main(int argc, char **argv);
int				mandelbrot(double c_re, double c_im, int max_iter);
int				julia(double z_re, double z_im, t_store *s);
int				move_julia(int x, int y, t_store *s);
int				burning_ship(double c_re, double c_im, int max_iter);

#endif
