/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_tridelbrot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:30:47 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 09:23:22 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_tridelbrot_i(t_frac_win *win, t_calc *calc)
{
	calc->cr = calc->x * win->frac[7].zoom_x + win->frac[7].x1;
	calc->y = 0;
}

static void	fractol_pix_tridelbrot(t_frac_win *win, t_calc *calc)
{
	while (calc->x < win->frac[7].width)
	{
		fractol_tridelbrot_i(win, calc);
		while (calc->y < win->frac[7].heigth)
		{
			calc->ci = calc->y * win->frac[7].zoom_y + win->frac[7].y1;
			calc->zr = calc->cr;
			calc->zi = calc->ci;
			calc->zr2 = calc->zr * calc->zr;
			calc->zi2 = calc->zi * calc->zi;
			calc->i = 0;
			while (calc->i < win->frac[7].iter && calc->zi2 + calc->zr2 < 4)
			{
				calc->zi = calc->zi * (3 * calc->zr2 - calc->zi2) + calc->ci;
				calc->zr = calc->zr * (calc->zr2 - 3 * calc->zi2) + calc->cr;
				calc->zr2 = calc->zr * calc->zr;
				calc->zi2 = calc->zi * calc->zi;
				calc->i++;
			}
			if (calc->i < win->frac[7].iter)
				fractol_color_pixel(win, calc, calc->zr2 + calc->zi2);
			calc->y++;
		}
		calc->x += THREADS_NB;
	}
}

void		fractol_draw_tridelbrot(t_frac_win *win, int i, t_calc *calc)
{
	calc->x = i;
	fractol_pix_tridelbrot(win, calc);
}
