/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_manage_zoom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 09:21:20 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 10:18:32 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_manage_zoom(t_frac_win *win, int button, int x, int y)
{
	double	ratiox;
	double	ratioy;
	double	zoom;
	double	zoom_inc;

	zoom_inc = (win->frac[win->tfrac].x2 - win->frac[win->tfrac].x1) * 0.05;
	zoom = button == 4 ? 1 : -1;
	ratiox = (double)x / (double)win->frac[win->tfrac].width;
	ratioy = (double)y / (double)win->frac[win->tfrac].heigth;
	win->frac[win->tfrac].x1 += zoom * zoom_inc * ratiox;
	win->frac[win->tfrac].x2 -= zoom * zoom_inc * (1 - ratiox);
	win->frac[win->tfrac].y1 += zoom * zoom_inc * ratioy;
	win->frac[win->tfrac].y2 -= zoom * zoom_inc * (1 - ratioy);
}
