/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:31:06 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/09/30 18:53:40 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	error_usage(void)
{
	ft_putstr("Incorrect input! Usage:\n");
	ft_putstr("./fractol mandelbrot\n");
	ft_putstr("./fractol julia\n");
	ft_putstr("./bsh\n");
}

void	check_fract(char *cur_fract)
{
	if (!ft_strcmp(cur_fract, MB))
		init_start(MB);
	else if (!ft_strcmp(cur_fract, J))
		init_start(J);
	else if (!ft_strcmp(cur_fract, B))
		init_start(B);
	else
		error_usage();
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		check_fract(argv[1]);
	else
		error_usage();
	return (0);
}
