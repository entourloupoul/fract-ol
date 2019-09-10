/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 07:38:40 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 10:59:55 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static double	fractol_color_a2(t_frac_win *win, int a, double i2)
{
	double	color2;
	double	m1;
	double	m2;

	color2 = (win->color[win->tcolor].color[a + 1] & 255 << 16) / 65536;
	m1 = (win->color[win->tcolor].color[a + 1] & 1 << 26) == 1 << 26 ? 1 : -1;
	m2 = (win->color[win->tcolor].color[a + 1] & 2 << 24) == 2 << 24 ? MRED : 1;
	m2 = (win->color[win->tcolor].color[a + 1] & 1 << 24)
				== 1 << 24 ? MGREE : m2;
	return (round(m1 * color2 / (double)win->itersep * i2) * m2);
}

static double	fractol_color_a(int a, t_frac_win *win, int i, double z)
{
	unsigned int		color1;
	double				m1;
	double				m2;
	double				i2;
	int					color2;

	z = log(z) / 2;
	z = log(z / log(2)) / log(2);
	i2 = win->smooth == 0 ? (double)i + 1 - z : (double)i;
	if (i2 < (double)i)
		i2 = (double)i;
	if (i2 > (double)i + 1)
		i2 = (double)i + 1;
	m1 = (win->color[win->tcolor].color[a + 1] & 1 << 10) == 1 << 10 ? 1 : -1;
	m2 = (win->color[win->tcolor].color[a + 1] & 2 << 8) == 2 << 8 ? MRED : 1;
	m2 = (win->color[win->tcolor].color[a + 1] & 1 << 8) == 1 << 8 ? MGREE : m2;
	color2 = win->color[win->tcolor].color[a + 1] & 255;
	color1 = win->color[win->tcolor].color[a] + round(m1 * (double)color2
			/ (double)win->itersep * i2) * m2;
	if ((win->color[win->tcolor].color[a + 1] & 1 << 11) == 1 << 11)
		color1 += fractol_color_a2(win, a, i2);
	return (color1);
}

void			fractol_color_pixel(t_frac_win *win, t_calc *calc, double z)
{
	int					a;
	int					x;
	int					y;
	unsigned int		color;

	a = 0;
	color = 0;
	if (calc->i == 0)
		return ;
	x = calc->x + win->frac[win->tfrac].xmini;
	y = calc->y + win->frac[win->tfrac].ymini;
	while (calc->i >= a * win->itersep)
		a++;
	color = round(fractol_color_a((2 * (a - 1))
				% win->color[win->tcolor].modul, win,
				calc->i % win->itersep, z));
	*((unsigned int *)(win->data + x * win->bpp / 8
				+ y * win->sizeline)) = color;
}
