/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:48:44 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 10:40:18 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include "libft.h"

static void		fractol_create_display(t_frac_win *win)
{
	int	x;
	int	y;

	y = win->heigth + 1;
	x = 0;
	while (x < win->totalwidth)
	{
		*((unsigned int *)(win->data + x * win->bpp / 8
					+ y * win->sizeline)) = 0xFFFFFF;
		x++;
	}
	y = 0;
	x = win->width + 1;
	while (y < win->heigth + 1)
	{
		*((unsigned int *)(win->data + x * win->bpp / 8
					+ y * win->sizeline)) = 0xFFFFFF;
		y++;
	}
	fractol_putstr_win(win);
}

static int		fractol_create_image(t_frac_win *win)
{
	if (!(win->ima = mlx_new_image(win->mlx, win->totalwidth,
					win->heigth + 2)))
	{
		mlx_destroy_window(win->mlx, win->win);
		return (ft_msg_int(2, "Failed mlx_new_ima.\n", -1));
	}
	if (!(win->data = mlx_get_data_addr(win->ima, &win->bpp,\
					&win->sizeline, &win->endian)))
	{
		mlx_destroy_image(win->mlx, win->ima);
		mlx_destroy_window(win->mlx, win->win);
		return (ft_msg_int(2, "Failed mlx_get_data_addr.\n", -1));
	}
	fractol_create_display(win);
	return (1);
}

static int		fractol_create_win(t_frac_win *win)
{
	win->width = 800;
	win->totalwidth = 1202;
	win->heigth = 800;
	win->totalheigth = 850;
	win->itersep = 10;
	if (!(win->mlx = mlx_init()))
		return (ft_msg_int(2, "Failed mlx_init.\n", -1));
	if (!(win->win = mlx_new_window(win->mlx, win->totalwidth,
					win->totalheigth, "fractol")))
		return (ft_msg_int(2, "failed mlx_new_win.\n", -1));
	if (fractol_create_image(win) == -1)
		return (-1);
	return (1);
}

static int		fractol_choice(char *argv)
{
	if (ft_strcmp(argv, "Mandelbrot") == 0)
		return (0);
	if (ft_strcmp(argv, "Julia") == 0)
		return (1);
	if (ft_strcmp(argv, "Mandelbar") == 0)
		return (2);
	if (ft_strcmp(argv, "Mandeldrop") == 0)
		return (3);
	if (ft_strcmp(argv, "Batman") == 0)
		return (4);
	if (ft_strcmp(argv, "BurningShip") == 0)
		return (5);
	if (ft_strcmp(argv, "Feigenbaum") == 0)
		return (6);
	if (ft_strcmp(argv, "Duobrot") == 0)
		return (7);
	return (-1);
}

int				main(int argc, char **argv)
{
	t_frac_win	win[1];
	int			frac;

	ft_bzero(win, (sizeof(t_frac_win)));
	if (argc != 2 || (win->tfrac = fractol_choice(argv[1])) == -1)
	{
		ft_putstr("usage: ./fractol Mandelbrot/Julia/Mandelbar/");
		ft_putstr("Mandeldrop/Batman/BurningShip/Feigenbaum/Duobrot\n");
		return (0);
	}
	if (fractol_create_win(win) == -1)
		return (-1);
	frac = win->tfrac;
	fractol_init_colors(win);
	fractol_create_mini(win);
	fractol_init_fract(win);
	win->tfrac = frac;
	fractol_manage_frac(win);
	return (0);
}
