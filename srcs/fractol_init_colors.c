/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:36:56 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 09:28:04 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init_colors2(t_frac_win *win)
{
	win->color[2].modul = 8;
	win->color[2].color[0] = 0x00;
	win->color[2].color[1] = 0x6FF;
	win->color[2].color[2] = 0xFF0000;
	win->color[2].color[3] = 0x4FF0DFF;
	win->color[2].color[4] = 0xFFFFFF;
	win->color[2].color[5] = 0xFF09FF;
	win->color[2].color[6] = 0xFF0000;
	win->color[2].color[7] = 0x2FF;
	win->color[3].modul = 12;
	win->color[3].color[0] = 0x00;
	win->color[3].color[1] = 0x6FF;
	win->color[3].color[2] = 0xFF0000;
	win->color[3].color[3] = 0x5FF;
	win->color[3].color[4] = 0xFFFF00;
	win->color[3].color[5] = 0x2FF;
	win->color[3].color[6] = 0xFF00;
	win->color[3].color[7] = 0x4FF;
	win->color[3].color[8] = 0xFFFF;
	win->color[3].color[9] = 0x1FF;
	win->color[3].color[10] = 0xFF;
	win->color[3].color[11] = 0x0FF;
}

void	fractol_init_colors(t_frac_win *win)
{
	win->color[0].modul = 8;
	win->color[0].color[0] = 0x00;
	win->color[0].color[1] = 1279;
	win->color[0].color[2] = 0xFF;
	win->color[0].color[3] = 117378559;
	win->color[0].color[4] = 0xFFFFFF;
	win->color[0].color[5] = 21104895;
	win->color[0].color[6] = 0xFFBD00;
	win->color[0].color[7] = 50268605;
	win->color[1].modul = 10;
	win->color[1].color[0] = 0x00;
	win->color[1].color[1] = 0x5FF;
	win->color[1].color[2] = 0xFF00;
	win->color[1].color[3] = 1791;
	win->color[1].color[4] = 0xFFFF00;
	win->color[1].color[5] = 0x9FF;
	win->color[1].color[6] = 0xFF0000;
	win->color[1].color[7] = 0x4FF;
	win->color[1].color[8] = 0xFF00FF;
	win->color[1].color[9] = 0x02FF08FF;
	fractol_init_colors2(win);
}
