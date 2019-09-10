/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_invdelbrot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:25:29 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 08:52:18 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_invdelbrot_i(t_frac_win *win, t_calc *calc)
{
	calc->cr = calc->x * win->frac[2].zoom_x + win->frac[2].x1;
	calc->y = 0;
}

static void	fractol_pix_invdelbrot(t_frac_win *win, t_calc *calc)
{
	while (calc->x < win->frac[2].width)
	{
		fractol_invdelbrot_i(win, calc);
		while (calc->y < win->frac[2].heigth)
		{
			calc->ci = calc->y * win->frac[2].zoom_y + win->frac[2].y1;
			calc->i = 0;
			while (calc->i < win->frac[2].iter && calc->zi2 + calc->zr2 < 4)
			{
				calc->zi = 2 * calc->zi * calc->zr + calc->ci;
				calc->zr = calc->zi2 - calc->zr2 + calc->cr;
				calc->zr2 = calc->zr * calc->zr;
				calc->zi2 = calc->zi * calc->zi;
				calc->i++;
			}
			if (calc->i < win->frac[2].iter)
				fractol_color_pixel(win, calc, calc->zr2 + calc->zi2);
			calc->zr2 = 0;
			calc->zi2 = 0;
			calc->zr = 0;
			calc->zi = 0;
			calc->y++;
		}
		calc->x += THREADS_NB;
	}
}

void		fractol_draw_invdelbrot(t_frac_win *win, int i, t_calc *calc)
{
	calc->x = i;
	fractol_pix_invdelbrot(win, calc);
}
