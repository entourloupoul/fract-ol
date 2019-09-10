/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_batman.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:55:27 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 08:35:46 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

static void	fractol_draw_batman2(t_frac_win *win, t_calc *calc)
{
	double	div2;

	calc->cr = calc->x * win->frac[4].zoom_x + win->frac[4].x1;
	calc->zr = calc->cr;
	calc->cr2 = calc->cr * calc->cr;
	calc->ci = calc->y * win->frac[4].zoom_y + win->frac[4].y1;
	calc->zi = calc->ci;
	calc->ci2 = calc->ci * calc->ci;
	div2 = calc->cr2 + calc->ci2;
	if (div2 != 0)
	{
		calc->cr = calc->cr / div2;
		calc->ci = -calc->ci / div2;
	}
	calc->zr2 = calc->zr * calc->zr;
	calc->zi2 = calc->zi * calc->zi;
	calc->i = 0;
}

static void	fractol_draw_batman3(t_calc *calc)
{
	double	tmp;

	tmp = calc->zi;
	calc->zi = -sin(calc->zr) * sinh(calc->zi) + calc->ci;
	calc->zr = cos(calc->zr) * cosh(tmp) + calc->cr;
	calc->zr2 = calc->zr * calc->zr;
	calc->zi2 = calc->zi * calc->zi;
	calc->i++;
}

static void	fractol_pix_batman(t_frac_win *win, t_calc *calc)
{
	while (calc->x < win->frac[4].width)
	{
		calc->y = 0;
		if (calc->x * win->frac[4].zoom_x + win->frac[4].x1 >= -0.77
				&& calc->x * win->frac[4].zoom_x + win->frac[4].x1 <= 0.84)
		{
			while (calc->y < win->frac[4].heigth)
			{
				if (calc->y * win->frac[4].zoom_y + win->frac[4].y1 >= -0.935
						&& calc->y * win->frac[4].zoom_y
						+ win->frac[4].y1 <= 0.935)
				{
					fractol_draw_batman2(win, calc);
					while (calc->i < win->frac[4].iter && calc->zi2
							+ calc->zr2 < 50)
						fractol_draw_batman3(calc);
					if (calc->i < win->frac[4].iter)
						fractol_color_pixel(win, calc, calc->zr2 + calc->zi2);
				}
				calc->y++;
			}
		}
		calc->x += THREADS_NB;
	}
}

void		fractol_draw_batman(t_frac_win *win, int i, t_calc *calc)
{
	calc->x = i;
	fractol_pix_batman(win, calc);
}
