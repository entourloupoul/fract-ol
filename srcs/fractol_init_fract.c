/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_fract.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:35:50 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 10:01:20 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_init_mandelbrot(t_frac_win *win)
{
	win->frac[0].width = 810;
	win->frac[0].heigth = 720;
	win->frac[0].x1 = -2.1;
	win->frac[0].x2 = 0.6;
	win->frac[0].y1 = -1.2;
	win->frac[0].y2 = 1.2;
	win->frac[0].dx = win->frac[0].x2 - win->frac[0].x1;
	win->frac[0].dy = win->frac[0].y2 - win->frac[0].y1;
	win->dx2 = win->frac[0].dx * win->width / win->frac[0].width;
	win->frac[0].x1 = -2.1 + (win->frac[0].dx - win->dx2) / 2;
	win->frac[0].x2 = 0.6 - (win->frac[0].dx - win->dx2) / 2;
	win->frac[0].width = win->width;
	win->dy2 = win->frac[0].dy * win->heigth / win->frac[0].heigth;
	win->frac[0].y1 = -1.2 + (win->frac[0].dy - win->dy2) / 2;
	win->frac[0].y2 = 1.2 - (win->frac[0].dy - win->dy2) / 2;
	win->frac[0].heigth = win->heigth;
	win->frac[0].inc_iter = 1;
	win->frac[0].iter = 40;
	win->frac[0].xmini = 0;
	win->frac[0].ymini = 0;
}

static void	fractol_init_julia(t_frac_win *win)
{
	win->frac[1].width = 650;
	win->frac[1].heigth = 650;
	win->frac[1].x1 = -1.3;
	win->frac[1].x2 = 1.3;
	win->frac[1].y1 = -1.3;
	win->frac[1].y2 = 1.3;
	win->frac[1].dx = win->frac[1].x2 - win->frac[1].x1;
	win->frac[1].dy = win->frac[1].y2 - win->frac[1].y1;
	win->dx2 = win->frac[1].dx * win->width / win->frac[1].width;
	win->frac[1].x1 = -1.3 + (win->frac[1].dx - win->dx2) / 2;
	win->frac[1].x2 = 1.3 - (win->frac[1].dx - win->dx2) / 2;
	win->frac[1].width = win->width;
	win->dy2 = win->frac[1].dy * win->heigth / win->frac[1].heigth;
	win->frac[1].y1 = -1.3 + (win->frac[1].dy - win->dy2) / 2;
	win->frac[1].y2 = 1.3 - (win->frac[1].dy - win->dy2) / 2;
	win->frac[1].heigth = win->heigth;
	win->frac[1].inc_iter = 1;
	win->frac[1].cr = 0.285;
	win->frac[1].ci = 0.01;
	win->frac[1].iter = 50;
	win->frac[1].xmini = 0;
	win->frac[1].ymini = 0;
}

static void	fractol_init_invdelbrot(t_frac_win *win)
{
	win->frac[2].width = 700;
	win->frac[2].heigth = 720;
	win->frac[2].x1 = -1.5;
	win->frac[2].x2 = 2;
	win->frac[2].y1 = -1.8;
	win->frac[2].y2 = 1.8;
	win->frac[2].dx = win->frac[2].x2 - win->frac[2].x1;
	win->frac[2].dy = win->frac[2].y2 - win->frac[2].y1;
	win->dx2 = win->frac[2].dx * win->width / win->frac[2].width;
	win->frac[2].x1 = -1.5 + (win->frac[2].dx - win->dx2) / 2;
	win->frac[2].x2 = 2 - (win->frac[2].dx - win->dx2) / 2;
	win->frac[2].width = win->width;
	win->dy2 = win->frac[2].dy * win->heigth / win->frac[2].heigth;
	win->frac[2].y1 = -1.8 + (win->frac[2].dy - win->dy2) / 2;
	win->frac[2].y2 = 1.8 - (win->frac[2].dy - win->dy2) / 2;
	win->frac[2].heigth = win->heigth;
	win->frac[2].inc_iter = 1;
	win->frac[2].iter = 50;
	win->frac[2].xmini = 0;
	win->frac[2].ymini = 0;
}

static void	fractol_init_mandeldrop(t_frac_win *win)
{
	win->frac[3].width = 570;
	win->frac[3].heigth = 580;
	win->frac[3].x1 = -1.6;
	win->frac[3].x2 = 4.1;
	win->frac[3].y1 = -2.9;
	win->frac[3].y2 = 2.9;
	win->frac[3].dx = win->frac[3].x2 - win->frac[3].x1;
	win->frac[3].dy = win->frac[3].y2 - win->frac[3].y1;
	win->dx2 = win->frac[3].dx * win->width / win->frac[3].width;
	win->frac[3].x1 = -1.6 + (win->frac[3].dx - win->dx2) / 2;
	win->frac[3].x2 = 4.1 - (win->frac[3].dx - win->dx2) / 2;
	win->frac[3].width = win->width;
	win->dy2 = win->frac[3].dy * win->heigth / win->frac[3].heigth;
	win->frac[3].y1 = -2.9 + (win->frac[3].dy - win->dy2) / 2;
	win->frac[3].y2 = 2.9 - (win->frac[3].dy - win->dy2) / 2;
	win->frac[3].heigth = win->heigth;
	win->frac[3].inc_iter = 1;
	win->frac[3].iter = 50;
	win->frac[3].xmini = 0;
	win->frac[3].ymini = 0;
}

void		fractol_init_fract(t_frac_win *win)
{
	fractol_init_mandelbrot(win);
	fractol_init_julia(win);
	fractol_init_invdelbrot(win);
	fractol_init_mandeldrop(win);
	fractol_init_fract2(win);
}
