/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_mini2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 09:56:12 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 10:01:18 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_init_mini_batman(t_frac_win *win)
{
	win->frac[4].width = 218;
	win->frac[4].heigth = 220;
	win->frac[4].x1 = -1.14;
	win->frac[4].x2 = 1.04;
	win->frac[4].y1 = -1.1;
	win->frac[4].y2 = 1.1;
	win->frac[4].dx = win->frac[4].x2 - win->frac[4].x1;
	win->frac[4].dy = win->frac[4].y2 - win->frac[4].y1;
	win->dx2 = win->frac[4].dx * 200 / win->frac[4].width;
	win->frac[4].x1 = -1.14 + (win->frac[4].dx - win->dx2) / 2;
	win->frac[4].x2 = 1.04 - (win->frac[4].dx - win->dx2) / 2;
	win->frac[4].width = 200;
	win->dy2 = win->frac[4].dy * 200 / win->frac[4].heigth;
	win->frac[4].y1 = -1.1 + (win->frac[4].dy - win->dy2) / 2;
	win->frac[4].y2 = 1.1 - (win->frac[4].dy - win->dy2) / 2;
	win->frac[4].heigth = 200;
	win->frac[4].inc_iter = 1;
	win->frac[4].iter = 40;
	win->frac[4].xmini = 802;
	win->frac[4].ymini = 400;
}

static void	fractol_init_mini_burningship(t_frac_win *win)
{
	win->frac[5].width = 190;
	win->frac[5].heigth = 190;
	win->frac[5].x1 = -2.3;
	win->frac[5].x2 = 1.5;
	win->frac[5].y1 = -2.5;
	win->frac[5].y2 = 1.3;
	win->frac[5].dx = win->frac[5].x2 - win->frac[5].x1;
	win->frac[5].dy = win->frac[5].y2 - win->frac[5].y1;
	win->dx2 = win->frac[5].dx * 200 / win->frac[5].width;
	win->frac[5].x1 = -2.3 + (win->frac[5].dx - win->dx2) / 2;
	win->frac[5].x2 = 1.5 - (win->frac[5].dx - win->dx2) / 2;
	win->frac[5].width = 200;
	win->dy2 = win->frac[5].dy * 200 / win->frac[5].heigth;
	win->frac[5].y1 = -2.5 + (win->frac[5].dy - win->dy2) / 2;
	win->frac[5].y2 = 1.3 - (win->frac[5].dy - win->dy2) / 2;
	win->frac[5].heigth = 200;
	win->frac[5].inc_iter = 1;
	win->frac[5].iter = 40;
	win->frac[5].xmini = 1002;
	win->frac[5].ymini = 400;
}

static void	fractol_init_mini_feigenbaum(t_frac_win *win)
{
	win->frac[6].width = 135;
	win->frac[6].heigth = 135;
	win->frac[6].x1 = -1.4;
	win->frac[6].x2 = 1.3;
	win->frac[6].y1 = -1.35;
	win->frac[6].y2 = 1.35;
	win->frac[6].dx = win->frac[6].x2 - win->frac[6].x1;
	win->frac[6].dy = win->frac[6].y2 - win->frac[6].y1;
	win->dx2 = win->frac[6].dx * 200 / win->frac[6].width;
	win->frac[6].x1 = -1.4 + (win->frac[6].dx - win->dx2) / 2;
	win->frac[6].x2 = 1.3 - (win->frac[6].dx - win->dx2) / 2;
	win->frac[6].width = 200;
	win->dy2 = win->frac[6].dy * 200 / win->frac[6].heigth;
	win->frac[6].y1 = -1.35 + (win->frac[6].dy - win->dy2) / 2;
	win->frac[6].y2 = 1.35 - (win->frac[6].dy - win->dy2) / 2;
	win->frac[6].heigth = 200;
	win->frac[6].inc_iter = 1;
	win->frac[6].iter = 40;
	win->frac[6].xmini = 802;
	win->frac[6].ymini = 600;
}

static void	fractol_init_mini_tridelbrot(t_frac_win *win)
{
	win->frac[7].width = 150;
	win->frac[7].heigth = 150;
	win->frac[7].x1 = -1.6;
	win->frac[7].x2 = 1.4;
	win->frac[7].y1 = -1.5;
	win->frac[7].y2 = 1.5;
	win->frac[7].dx = win->frac[7].x2 - win->frac[7].x1;
	win->frac[7].dy = win->frac[7].y2 - win->frac[7].y1;
	win->dx2 = win->frac[7].dx * 200 / win->frac[7].width;
	win->frac[7].x1 = -1.6 + (win->frac[7].dx - win->dx2) / 2;
	win->frac[7].x2 = 1.4 - (win->frac[7].dx - win->dx2) / 2;
	win->frac[7].width = 200;
	win->dy2 = win->frac[7].dy * 200 / win->frac[7].heigth;
	win->frac[7].y1 = -1.5 + (win->frac[7].dy - win->dy2) / 2;
	win->frac[7].y2 = 1.5 - (win->frac[7].dy - win->dy2) / 2;
	win->frac[7].heigth = 200;
	win->frac[7].inc_iter = 1;
	win->frac[7].iter = 40;
	win->frac[7].xmini = 1002;
	win->frac[7].ymini = 600;
}

void		fractol_init_mini2(t_frac_win *win)
{
	fractol_init_mini_batman(win);
	fractol_init_mini_burningship(win);
	fractol_init_mini_feigenbaum(win);
	fractol_init_mini_tridelbrot(win);
}
