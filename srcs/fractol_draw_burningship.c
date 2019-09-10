/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_burningship.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:54:36 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 08:46:53 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void	fractol_burningship_i(t_frac_win *win, t_calc *calc)
{
	calc->cr = calc->x * win->frac[5].zoom_x + win->frac[5].x1;
	calc->y = 0;
}

static void	fractol_pix_burningship(t_frac_win *win, t_calc *calc)
{
	while (calc->x < win->frac[5].width)
	{
		fractol_burningship_i(win, calc);
		while (calc->y < win->frac[5].heigth)
		{
			calc->ci = calc->y * win->frac[5].zoom_y + win->frac[5].y1;
			calc->zr = calc->cr;
			calc->zi = calc->ci;
			calc->zr2 = calc->zr * calc->zr;
			calc->zi2 = calc->zi * calc->zi;
			calc->i = 0;
			while (calc->i < win->frac[5].iter && calc->zi2 + calc->zr2 < 4)
			{
				calc->zi = 2 * fabs(calc->zi) * fabs(calc->zr) + calc->ci;
				calc->zr = calc->zr2 - calc->zi2 + calc->cr;
				calc->zr2 = calc->zr * calc->zr;
				calc->zi2 = calc->zi * calc->zi;
				calc->i++;
			}
			if (calc->i < win->frac[5].iter)
				fractol_color_pixel(win, calc, calc->zr2 + calc->zi2);
			calc->y++;
		}
		calc->x += THREADS_NB;
	}
}

void		fractol_draw_burningship(t_frac_win *win, int i, t_calc *calc)
{
	calc->x = i;
	fractol_pix_burningship(win, calc);
}
