/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_create_mini.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:30:53 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 08:14:39 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_line_mini2(t_frac_win *win)
{
	int		x;
	int		y;

	y = 0;
	x = 1002;
	while (y < 801)
	{
		*((unsigned int *)(win->data + x * win->bpp / 8
					+ y * win->sizeline)) = 0xFFFFFF;
		y++;
	}
	x = 1201;
	y = 0;
	while (y < 801)
	{
		*((unsigned int *)(win->data + x * win->bpp / 8
					+ y * win->sizeline)) = 0xFFFFFF;
		y++;
	}
}

static void	fractol_line_mini(t_frac_win *win)
{
	int		x;
	int		y;

	y = 0;
	while (y < 801)
	{
		x = 801;
		while (x < 1202)
		{
			*((unsigned int *)(win->data + x * win->bpp / 8
						+ y * win->sizeline)) = 0xFFFFFF;
			x++;
		}
		y += 200;
	}
	fractol_line_mini2(win);
}

void		fractol_create_mini(t_frac_win *win)
{
	int	i;

	fractol_init_mini(win);
	i = 0;
	while (i < 8)
	{
		win->tfrac = i;
		fractol_display(win, 0);
		i++;
	}
	fractol_line_mini(win);
}
