/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_feigenbaum.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:07:41 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 08:49:09 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_feigenbaum_i(t_frac_win *win, t_calc *calc)
{
	calc->cr = calc->x * win->frac[6].zoom_x + win->frac[6].x1;
	calc->ci = calc->y * win->frac[6].zoom_y + win->frac[6].y1;
	calc->cr2 = calc->cr * calc->cr;
	calc->ci2 = calc->ci * calc->ci;
	calc->cr = calc->cr * (calc->cr2 - 3 * calc->ci2);
	calc->ci = calc->ci * (3 * calc->cr2 - calc->ci2);
	calc->zr = calc->cr;
	calc->zi = calc->ci;
	calc->zr2 = calc->zr * calc->zr;
	calc->zi2 = calc->zi * calc->zi;
	calc->i = 0;
}

static void	fractol_pix_feigenbaum(t_frac_win *win, t_calc *calc)
{
	while (calc->x < win->frac[6].width)
	{
		calc->y = 0;
		while (calc->y < win->frac[6].heigth)
		{
			fractol_feigenbaum_i(win, calc);
			while (calc->i < win->frac[6].iter && calc->zi2 + calc->zr2 < 4)
			{
				calc->zi = 2 * calc->zi * calc->zr + calc->ci;
				calc->zr = calc->zr2 - calc->zi2 + calc->cr - 1.401155;
				calc->zr2 = calc->zr * calc->zr;
				calc->zi2 = calc->zi * calc->zi;
				calc->i++;
			}
			if (calc->i < win->frac[6].iter)
				fractol_color_pixel(win, calc, calc->zr2 + calc->zi2);
			calc->y++;
		}
		calc->x += THREADS_NB;
	}
}

void		fractol_draw_feigenbaum(t_frac_win *win, int i, t_calc *calc)
{
	calc->x = i;
	fractol_pix_feigenbaum(win, calc);
}
