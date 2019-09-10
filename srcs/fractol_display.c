/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:06:56 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 08:17:35 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>
#include <libft.h>

void			fractol_clear_image(t_frac_win *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < win->frac[win->tfrac].heigth)
	{
		x = 0;
		while (x < win->frac[win->tfrac].width)
		{
			*((unsigned int *)(win->data + x * win->bpp / 8
						+ y * win->sizeline)) = 0x000000;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->ima, 0, 0);
}

int				fractol_destroy_window(t_frac_win *win, int fail)
{
	if (fail == 1)
		ft_putendl_fd("failed thread creation", 2);
	if (fail == 2)
		ft_putendl_fd("failed thread join", 2);
	mlx_destroy_image(win->mlx, win->ima);
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
}

static void		fractol_draw2(t_frac_win *win, int i, t_calc *calc)
{
	if (win->tfrac == 5)
		fractol_draw_burningship(win, i, calc);
	if (win->tfrac == 6)
		fractol_draw_feigenbaum(win, i, calc);
	if (win->tfrac == 7)
		fractol_draw_tridelbrot(win, i, calc);
}

static void		*fractol_draw(void *arg)
{
	t_calc		calc[1];
	int			i;
	t_frac_win	*win;

	win = (t_frac_win *)arg;
	i = 0;
	ft_bzero(calc, sizeof(t_calc));
	while (win->thcr == 0)
		i = 0;
	while (pthread_self() != win->threads[i])
		i++;
	if (win->tfrac == 0)
		fractol_draw_mandelbrot(win, i, calc);
	if (win->tfrac == 1)
		fractol_draw_julia(win, i, calc);
	if (win->tfrac == 2)
		fractol_draw_invdelbrot(win, i, calc);
	if (win->tfrac == 3)
		fractol_draw_mandeldrop(win, i, calc);
	if (win->tfrac == 4)
		fractol_draw_batman(win, i, calc);
	if (win->tfrac > 4)
		fractol_draw2(win, i, calc);
	pthread_exit(NULL);
}

void			fractol_display(t_frac_win *win, int i)
{
	pthread_t	threads[THREADS_NB];

	win->frac[win->tfrac].zoom_x = (win->frac[win->tfrac].x2
			- win->frac[win->tfrac].x1) / win->frac[win->tfrac].width;
	win->frac[win->tfrac].zoom_y = (win->frac[win->tfrac].y2
			- win->frac[win->tfrac].y1) / win->frac[win->tfrac].heigth;
	fractol_clear_image(win);
	win->thcr = 0;
	while (i < THREADS_NB)
	{
		if (pthread_create(&threads[i], NULL, fractol_draw, win) == -1)
			fractol_destroy_window(win, 1);
		i++;
	}
	win->threads = threads;
	win->thcr = 1;
	i = 0;
	while (i < THREADS_NB)
	{
		if (pthread_join(threads[i], NULL))
			fractol_destroy_window(win, 2);
		i++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->ima, 0, 0);
}
