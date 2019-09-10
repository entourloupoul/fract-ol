/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:48:26 by pmasson           #+#    #+#             */
/*   Updated: 2019/03/06 11:04:00 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <pthread.h>
# define THREADS_NB 8
# define MBLUE 1
# define MGREE 256
# define MRED 65536
# define CHANGE_I "change iterations : + -"
# define MOVE "move : arrow keys"
# define INIT "reinitialize : b"
# define COLORS "change colors : 0 1 2 3"
# define SMOOTH "smooth colors : l"
# define PART_C " particular c : q w e r"
# define ALL_C " all c : space and mouse move"

typedef struct	s_fractal
{
	int		width;
	int		heigth;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	dx;
	double	dy;
	double	cr;
	double	ci;
	int		iter;
	int		inc_iter;
	int		xmini;
	int		ymini;
	double	zoom_x;
	double	zoom_y;
}				t_fractal;
typedef struct	s_calc
{
	double	zr;
	double	zi;
	double	cr;
	double	cr2;
	double	ci;
	double	ci2;
	double	zr2;
	double	zr4;
	double	zi2;
	double	zi4;
	int		i;
	int		x;
	int		y;
}				t_calc;
typedef struct	s_color
{
	int			modul;
	int			color[12];
}				t_color;
typedef struct	s_frac_win
{
	void				*mlx;
	void				*win;
	void				*ima;
	void				*data;
	int					sizeline;
	int					bpp;
	int					endian;
	int					width;
	int					totalwidth;
	int					heigth;
	int					totalheigth;
	int					tfrac;
	struct s_fractal	frac[8];
	double				dx2;
	double				dy2;
	int					thcr;
	int					trc;
	struct s_color		color[4];
	int					tcolor;
	int					itersep;
	int					smooth;
	pthread_t			*threads;
}				t_frac_win;
void			fractol_draw_mandelbrot(t_frac_win *wini, int i, t_calc *calc);
int				fractol_manage_frac(t_frac_win *win);
void			fractol_init_fract(t_frac_win *win);
void			fractol_init_fract2(t_frac_win *win);
void			fractol_init_mini(t_frac_win *win);
void			fractol_init_mini2(t_frac_win *win);
void			fractol_init_colors(t_frac_win *win);
void			fractol_display(t_frac_win *win, int i);
int				fractol_destroy_window(t_frac_win *win, int fail);
void			fractol_clear_image(t_frac_win *win);
void			fractol_manage_zoom(t_frac_win *win, int button, int x, int y);
void			fractol_color_pixel(t_frac_win *win, t_calc *calc, double z);
void			fractol_draw_julia(t_frac_win *wini, int i, t_calc *calc);
void			fractol_draw_invdelbrot(t_frac_win *wini, int i, t_calc *calc);
void			fractol_draw_mandeldrop(t_frac_win *wini, int i, t_calc *calc);
void			fractol_draw_batman(t_frac_win *wini, int i, t_calc *calc);
void			fractol_draw_burningship(t_frac_win *wini, int i, t_calc *calc);
void			fractol_draw_feigenbaum(t_frac_win *wini, int i, t_calc *calc);
void			fractol_draw_tridelbrot(t_frac_win *wini, int i, t_calc *calc);
void			fractol_create_mini(t_frac_win *win);
int				fractol_deal_key(int key, t_frac_win *win);
void			fractol_putstr_win(t_frac_win *win);
#endif
