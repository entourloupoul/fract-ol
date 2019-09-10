/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_manage_frac.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:18:27 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 10:14:15 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static int		fractol_deal_mouse(int button, int x, int y, t_frac_win *win)
{
	if (button == 4 || button == 5)
	{
		fractol_manage_zoom(win, button, x, y);
		fractol_display(win, 0);
	}
	if (button == 1)
	{
		if (x > 801 && x < 1002)
		{
			win->tfrac = y >= 0 && y < 200 ? 0 : win->tfrac;
			win->tfrac = y >= 200 && y < 400 ? 2 : win->tfrac;
			win->tfrac = y >= 400 && y < 600 ? 4 : win->tfrac;
			win->tfrac = y >= 600 && y <= 800 ? 6 : win->tfrac;
		}
		if (x >= 1002 && x < 1202)
		{
			win->tfrac = y >= 0 && y < 200 ? 1 : win->tfrac;
			win->tfrac = y >= 200 && y < 400 ? 3 : win->tfrac;
			win->tfrac = y >= 400 && y < 600 ? 5 : win->tfrac;
			win->tfrac = y >= 600 && y <= 800 ? 7 : win->tfrac;
		}
		fractol_display(win, 0);
	}
	return (0);
}

static int		fractol_change_c(int x, int y, t_frac_win *win)
{
	if (win->trc == 1 && win->tfrac == 1)
	{
		win->frac[1].cr = x * win->frac[1].zoom_x + win->frac[1].x1;
		win->frac[1].ci = y * win->frac[1].zoom_y + win->frac[1].y1;
		fractol_display(win, 0);
	}
	return (0);
}

int				fractol_manage_frac(t_frac_win *win)
{
	fractol_display(win, 0);
	mlx_hook(win->win, 17, 0, fractol_destroy_window, win);
	mlx_hook(win->win, 6, 1L << 6, fractol_change_c, win);
	mlx_mouse_hook(win->win, fractol_deal_mouse, win);
	mlx_key_hook(win->win, fractol_deal_key, win);
	mlx_loop(win->mlx);
	return (1);
}
