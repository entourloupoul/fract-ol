/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_mini.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:24:01 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 10:01:45 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_init_mini_mandelbrot(t_frac_win *win)
{
	win->frac[0].width = 135;
	win->frac[0].heigth = 120;
	win->frac[0].x1 = -2.1;
	win->frac[0].x2 = 0.6;
	win->frac[0].y1 = -1.2;
	win->frac[0].y2 = 1.2;
	win->frac[0].dx = win->frac[0].x2 - win->frac[0].x1;
	win->frac[0].dy = win->frac[0].y2 - win->frac[0].y1;
	win->dx2 = win->frac[0].dx * 200 / win->frac[0].width;
	win->frac[0].x1 = -2.1 + (win->frac[0].dx - win->dx2) / 2;
	win->frac[0].x2 = 0.6 - (win->frac[0].dx - win->dx2) / 2;
	win->frac[0].width = 200;
	win->dy2 = win->frac[0].dy * 200 / win->frac[0].heigth;
	win->frac[0].y1 = -1.2 + (win->frac[0].dy - win->dy2) / 2;
	win->frac[0].y2 = 1.2 - (win->frac[0].dy - win->dy2) / 2;
	win->frac[0].heigth = 200;
	win->frac[0].inc_iter = 1;
	win->frac[0].iter = 40;
	win->frac[0].xmini = 802;
	win->frac[0].ymini = 0;
}

static void	fractol_init_mini_julia(t_frac_win *win)
{
	win->frac[1].width = 130;
	win->frac[1].heigth = 130;
	win->frac[1].x1 = -1.3;
	win->frac[1].x2 = 1.3;
	win->frac[1].y1 = -1.3;
	win->frac[1].y2 = 1.3;
	win->frac[1].dx = win->frac[1].x2 - win->frac[1].x1;
	win->frac[1].dy = win->frac[1].y2 - win->frac[1].y1;
	win->dx2 = win->frac[1].dx * 200 / win->frac[1].width;
	win->frac[1].x1 = -1.3 + (win->frac[1].dx - win->dx2) / 2;
	win->frac[1].x2 = 1.3 - (win->frac[1].dx - win->dx2) / 2;
	win->frac[1].width = 200;
	win->dy2 = win->frac[1].dy * 200 / win->frac[1].heigth;
	win->frac[1].y1 = -1.3 + (win->frac[1].dy - win->dy2) / 2;
	win->frac[1].y2 = 1.3 - (win->frac[1].dy - win->dy2) / 2;
	win->frac[1].heigth = 200;
	win->frac[1].inc_iter = 1;
	win->frac[1].cr = 0.285;
	win->frac[1].ci = 0.01;
	win->frac[1].iter = 50;
	win->frac[1].xmini = 1002;
	win->frac[1].ymini = 0;
}

static void	fractol_init_mini_invdelbrot(t_frac_win *win)
{
	win->frac[2].width = 175;
	win->frac[2].heigth = 180;
	win->frac[2].x1 = -1.5;
	win->frac[2].x2 = 2;
	win->frac[2].y1 = -1.8;
	win->frac[2].y2 = 1.8;
	win->frac[2].dx = win->frac[2].x2 - win->frac[2].x1;
	win->frac[2].dy = win->frac[2].y2 - win->frac[2].y1;
	win->dx2 = win->frac[2].dx * 200 / win->frac[2].width;
	win->frac[2].x1 = -1.5 + (win->frac[2].dx - win->dx2) / 2;
	win->frac[2].x2 = 2 - (win->frac[2].dx - win->dx2) / 2;
	win->frac[2].width = 200;
	win->dy2 = win->frac[2].dy * 200 / win->frac[2].heigth;
	win->frac[2].y1 = -1.8 + (win->frac[2].dy - win->dy2) / 2;
	win->frac[2].y2 = 1.8 - (win->frac[2].dy - win->dy2) / 2;
	win->frac[2].heigth = 200;
	win->frac[2].inc_iter = 1;
	win->frac[2].iter = 50;
	win->frac[2].xmini = 802;
	win->frac[2].ymini = 200;
}

static void	fractol_init_mini_mandeldrop(t_frac_win *win)
{
	win->frac[3].width = 142;
	win->frac[3].heigth = 145;
	win->frac[3].x1 = -1.6;
	win->frac[3].x2 = 4.1;
	win->frac[3].y1 = -2.9;
	win->frac[3].y2 = 2.9;
	win->frac[3].dx = win->frac[3].x2 - win->frac[3].x1;
	win->frac[3].dy = win->frac[3].y2 - win->frac[3].y1;
	win->dx2 = win->frac[3].dx * 200 / win->frac[3].width;
	win->frac[3].x1 = -1.6 + (win->frac[3].dx - win->dx2) / 2;
	win->frac[3].x2 = 4.1 - (win->frac[3].dx - win->dx2) / 2;
	win->frac[3].width = 200;
	win->dy2 = win->frac[3].dy * 200 / win->frac[3].heigth;
	win->frac[3].y1 = -2.9 + (win->frac[3].dy - win->dy2) / 2;
	win->frac[3].y2 = 2.9 - (win->frac[3].dy - win->dy2) / 2;
	win->frac[3].heigth = 200;
	win->frac[3].inc_iter = 1;
	win->frac[3].iter = 50;
	win->frac[3].xmini = 1002;
	win->frac[3].ymini = 200;
}

void		fractol_init_mini(t_frac_win *win)
{
	fractol_init_mini_mandelbrot(win);
	fractol_init_mini_julia(win);
	fractol_init_mini_invdelbrot(win);
	fractol_init_mini_mandeldrop(win);
	fractol_init_mini2(win);
}
