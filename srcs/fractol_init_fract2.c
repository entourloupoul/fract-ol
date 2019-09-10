/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_fract2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 09:29:10 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 09:54:38 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_init_batman(t_frac_win *win)
{
	win->frac[4].width = 654;
	win->frac[4].heigth = 660;
	win->frac[4].x1 = -1.14;
	win->frac[4].x2 = 1.04;
	win->frac[4].y1 = -1.1;
	win->frac[4].y2 = 1.1;
	win->frac[4].dx = win->frac[4].x2 - win->frac[4].x1;
	win->frac[4].dy = win->frac[4].y2 - win->frac[4].y1;
	win->dx2 = win->frac[4].dx * win->width / win->frac[4].width;
	win->frac[4].x1 = -1.14 + (win->frac[4].dx - win->dx2) / 2;
	win->frac[4].x2 = 1.04 - (win->frac[4].dx - win->dx2) / 2;
	win->frac[4].width = win->width;
	win->dy2 = win->frac[4].dy * win->heigth / win->frac[4].heigth;
	win->frac[4].y1 = -1.1 + (win->frac[4].dy - win->dy2) / 2;
	win->frac[4].y2 = 1.1 - (win->frac[4].dy - win->dy2) / 2;
	win->frac[4].heigth = win->heigth;
	win->frac[4].inc_iter = 1;
	win->frac[4].iter = 50;
	win->frac[4].xmini = 0;
	win->frac[4].ymini = 0;
}

static void	fractol_init_burningship(t_frac_win *win)
{
	win->frac[5].width = 760;
	win->frac[5].heigth = 760;
	win->frac[5].x1 = -2.3;
	win->frac[5].x2 = 1.5;
	win->frac[5].y1 = -2.5;
	win->frac[5].y2 = 1.3;
	win->frac[5].dx = win->frac[5].x2 - win->frac[5].x1;
	win->frac[5].dy = win->frac[5].y2 - win->frac[5].y1;
	win->dx2 = win->frac[5].dx * win->width / win->frac[5].width;
	win->frac[5].x1 = -2.3 + (win->frac[5].dx - win->dx2) / 2;
	win->frac[5].x2 = 1.5 - (win->frac[5].dx - win->dx2) / 2;
	win->frac[5].width = win->width;
	win->dy2 = win->frac[5].dy * win->heigth / win->frac[5].heigth;
	win->frac[5].y1 = -2.5 + (win->frac[5].dy - win->dy2) / 2;
	win->frac[5].y2 = 1.3 - (win->frac[5].dy - win->dy2) / 2;
	win->frac[5].heigth = win->heigth;
	win->frac[5].inc_iter = 1;
	win->frac[5].iter = 40;
	win->frac[5].xmini = 0;
	win->frac[5].ymini = 0;
}

static void	fractol_init_feigenbaum(t_frac_win *win)
{
	win->frac[6].width = 810;
	win->frac[6].heigth = 810;
	win->frac[6].x1 = -1.4;
	win->frac[6].x2 = 1.3;
	win->frac[6].y1 = -1.35;
	win->frac[6].y2 = 1.35;
	win->frac[6].dx = win->frac[6].x2 - win->frac[6].x1;
	win->frac[6].dy = win->frac[6].y2 - win->frac[6].y1;
	win->dx2 = win->frac[6].dx * win->width / win->frac[6].width;
	win->frac[6].x1 = -1.4 + (win->frac[6].dx - win->dx2) / 2;
	win->frac[6].x2 = 1.3 - (win->frac[6].dx - win->dx2) / 2;
	win->frac[6].width = win->width;
	win->dy2 = win->frac[6].dy * win->heigth / win->frac[6].heigth;
	win->frac[6].y1 = -1.35 + (win->frac[6].dy - win->dy2) / 2;
	win->frac[6].y2 = 1.35 - (win->frac[6].dy - win->dy2) / 2;
	win->frac[6].heigth = win->heigth;
	win->frac[6].inc_iter = 1;
	win->frac[6].iter = 40;
	win->frac[6].xmini = 0;
	win->frac[6].ymini = 0;
}

static void	fractol_init_tridelbrot(t_frac_win *win)
{
	win->frac[7].width = 750;
	win->frac[7].heigth = 750;
	win->frac[7].x1 = -1.6;
	win->frac[7].x2 = 1.4;
	win->frac[7].y1 = -1.5;
	win->frac[7].y2 = 1.5;
	win->frac[7].dx = win->frac[7].x2 - win->frac[7].x1;
	win->frac[7].dy = win->frac[7].y2 - win->frac[7].y1;
	win->dx2 = win->frac[7].dx * win->width / win->frac[7].width;
	win->frac[7].x1 = -1.6 + (win->frac[7].dx - win->dx2) / 2;
	win->frac[7].x2 = 1.4 - (win->frac[7].dx - win->dx2) / 2;
	win->frac[7].width = win->width;
	win->dy2 = win->frac[7].dy * win->heigth / win->frac[7].heigth;
	win->frac[7].y1 = -1.5 + (win->frac[7].dy - win->dy2) / 2;
	win->frac[7].y2 = 1.5 - (win->frac[7].dy - win->dy2) / 2;
	win->frac[7].heigth = win->heigth;
	win->frac[7].inc_iter = 1;
	win->frac[7].iter = 40;
	win->frac[7].xmini = 0;
	win->frac[7].ymini = 0;
}

void		fractol_init_fract2(t_frac_win *win)
{
	fractol_init_batman(win);
	fractol_init_burningship(win);
	fractol_init_feigenbaum(win);
	fractol_init_tridelbrot(win);
}
