/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:11:09 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 08:56:39 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_julia_i(t_frac_win *win, t_calc *calc)
{
	calc->zi = calc->y * win->frac[1].zoom_y + win->frac[1].y1;
	calc->i = 0;
	calc->zr2 = calc->zr * calc->zr;
	calc->zi2 = calc->zi * calc->zi;
}

static void	fractol_pix_julia(t_frac_win *win, t_calc *calc)
{
	while (calc->x < win->frac[1].width)
	{
		calc->zr = calc->x * win->frac[1].zoom_x + win->frac[1].x1;
		calc->y = 0;
		while (calc->y < win->frac[1].heigth)
		{
			fractol_julia_i(win, calc);
			while (calc->i < win->frac[1].iter && calc->zi2 + calc->zr2 < 4)
			{
				calc->zi = 2 * calc->zi * calc->zr + win->frac[1].ci;
				calc->zr = calc->zr2 - calc->zi2 + win->frac[1].cr;
				calc->zr2 = calc->zr * calc->zr;
				calc->zi2 = calc->zi * calc->zi;
				calc->i++;
			}
			if (calc->i < win->frac[1].iter)
			{
				fractol_color_pixel(win, calc, calc->zr2 + calc->zi2);
			}
			calc->zr = calc->x * win->frac[1].zoom_x + win->frac[1].x1;
			calc->y++;
		}
		calc->x += THREADS_NB;
	}
}

void		fractol_draw_julia(t_frac_win *win, int i, t_calc *calc)
{
	calc->x = i;
	fractol_pix_julia(win, calc);
}
