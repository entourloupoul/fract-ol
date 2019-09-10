/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_putstr_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:30:03 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 10:40:02 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void	fractol_putstr_win(t_frac_win *win)
{
	mlx_string_put(win->mlx, win->win, 10, 805, 0xFFFFFF, CHANGE_I);
	mlx_string_put(win->mlx, win->win, 10, 825, 0xFFFFFF, MOVE);
	mlx_string_put(win->mlx, win->win, 250, 805, 0xFFFFFF, INIT);
	mlx_string_put(win->mlx, win->win, 250, 825, 0xFFFFFF, "zoom: mouse wheel");
	mlx_string_put(win->mlx, win->win, 450, 805, 0xFFFFFF, COLORS);
	mlx_string_put(win->mlx, win->win, 450, 825, 0xFFFFFF, SMOOTH);
	mlx_string_put(win->mlx, win->win, 730, 805, 0xFFFFFF, "julia :");
	mlx_string_put(win->mlx, win->win, 800, 805, 0xFFFFFF, PART_C);
	mlx_string_put(win->mlx, win->win, 800, 825, 0xFFFFFF, ALL_C);
}
