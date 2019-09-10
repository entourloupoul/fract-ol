/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_mandeldrop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:18:53 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 09:11:34 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_mandeldrop_i(t_frac_win *win, t_calc *calc)
{
	double	div2;

	calc->cr = calc->x * win->frac[3].zoom_x + win->frac[3].x1;
	calc->cr2 = calc->cr * calc->cr;
	calc->ci = calc->y * win->frac[3].zoom_y + win->frac[3].y1;
	calc->ci2 = calc->ci * calc->ci;
	div2 = calc->cr2 + calc->ci2;
	if (div2 != 0)
	{
		calc->cr = calc->cr / div2;
		calc->ci = -calc->ci / div2;
	}
	calc->zr = calc->cr;
	calc->zi = calc->ci;
	calc->zr2 = calc->zr * calc->zr;
	calc->zi2 = calc->zi * calc->zi;
	calc->i = 0;
}

static void	fractol_pix_mandeldrop(t_frac_win *win, t_calc *calc)
{
	while (calc->x < win->frac[3].width)
	{
		calc->cr = calc->x * win->frac[3].zoom_x + win->frac[3].x1;
		calc->cr2 = calc->cr * calc->cr;
		calc->y = 0;
		while (calc->y < win->frac[3].heigth)
		{
			fractol_mandeldrop_i(win, calc);
			while (calc->i < win->frac[3].iter && calc->zi2 + calc->zr2 < 4)
			{
				calc->zi = 2 * calc->zi * calc->zr + calc->ci;
				calc->zr = calc->zr2 - calc->zi2 + calc->cr;
				calc->zr2 = calc->zr * calc->zr;
				calc->zi2 = calc->zi * calc->zi;
				calc->i++;
			}
			if (calc->i < win->frac[3].iter)
				fractol_color_pixel(win, calc, calc->zr2 + calc->zi2);
			calc->y++;
		}
		calc->x += THREADS_NB;
	}
}

void		fractol_draw_mandeldrop(t_frac_win *win, int i, t_calc *calc)
{
	calc->x = i;
	fractol_pix_mandeldrop(win, calc);
}
