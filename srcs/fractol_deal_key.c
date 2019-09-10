/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_deal_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:08:03 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 10:17:36 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_trans(t_frac_win *win, int key)
{
	double	inc_trans;

	inc_trans = (win->frac[win->tfrac].x2 - win->frac[win->tfrac].x1) * 0.02;
	if (key == 126)
	{
		win->frac[win->tfrac].y1 += inc_trans;
		win->frac[win->tfrac].y2 += inc_trans;
	}
	if (key == 125)
	{
		win->frac[win->tfrac].y1 -= inc_trans;
		win->frac[win->tfrac].y2 -= inc_trans;
	}
	if (key == 124)
	{
		win->frac[win->tfrac].x1 -= inc_trans;
		win->frac[win->tfrac].x2 -= inc_trans;
	}
	if (key == 123)
	{
		win->frac[win->tfrac].x1 += inc_trans;
		win->frac[win->tfrac].x2 += inc_trans;
	}
	fractol_display(win, 0);
}

static void	fractol_manage_julia(t_frac_win *win, int key)
{
	if (key == 12)
	{
		win->frac[1].cr = 0.285;
		win->frac[1].ci = 0.01;
	}
	if (key == 13)
	{
		win->frac[1].cr = -1.416;
		win->frac[1].ci = 0;
	}
	if (key == 14)
	{
		win->frac[1].cr = -0.4;
		win->frac[1].ci = 0.6;
	}
	if (key == 15)
	{
		win->frac[1].cr = -0.8;
		win->frac[1].ci = 0.156;
	}
	fractol_display(win, 0);
}

static void	fractol_iter(t_frac_win *win, int key)
{
	if (key == 11)
		fractol_init_fract(win);
	else
		win->frac[win->tfrac].iter = key == 69 ? win->frac[win->tfrac].iter
			+ 1 : win->frac[win->tfrac].iter - 1;
	fractol_display(win, 0);
}

int			fractol_deal_key(int key, t_frac_win *win)
{
	if (key == 82 || key == 83 || key == 84 || key == 85)
	{
		win->tcolor = key % 82;
		fractol_display(win, 0);
	}
	if (win->tfrac == 1 && (key == 12 || key == 13 || key == 14 || key == 15))
		fractol_manage_julia(win, key);
	if (key == 37)
	{
		win->smooth = win->smooth == 1 ? 0 : 1;
		fractol_display(win, 0);
	}
	if (key == 49 && win->tfrac == 1)
		win->trc = win->trc == 0 ? 1 : 0;
	if (key == 126 || key == 125 || key == 124 || key == 123)
		fractol_trans(win, key);
	if (key == 69 || key == 78 || key == 11)
		fractol_iter(win, key);
	else if (key == 53)
		fractol_destroy_window(win, 0);
	return (0);
}
