/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:48:46 by fciocan           #+#    #+#             */
/*   Updated: 2018/02/09 15:37:41 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line(t_var *f)
{
	double	tx;
	float	dx;
	float	dy;
	int		cl;

	tx = 0.0;
	dx = f->x1 - f->x0;
	dy = f->y1 - f->y0;
	while (tx <= 1)
	{
		f->x = f->x0 + (dx * tx);
		f->y = f->y0 + (dy * tx);
		cl = f->c2;
		if (f->z > 3)
			cl = f->c1;
		if (f->z < -3)
			cl = f->c3;
		if (f->z == 0)
			cl = f->c4;
		mlx_pixel_put(f->mlx, f->win, f->x + f->xmove,\
				f->y + f->ymove, cl);
		tx += 1. / ft_sqrt((dx * dx) + (dy * dy));
	}
}

static void	ft_vertical(t_var *f, int j, int i)
{
	f->x0 = 50 + (i * f->zoom) + (j * f->zoom);
	f->x1 = 50 + (i * f->zoom) + ((j + 1) * f->zoom);
	f->y0 = ((700 + (j * f->zoom)) * 1. / 2.) - (((i * f->zoom)
				+ (f->z * f->tab[j][i])) * 1. / 2.);
	f->y1 = ((700 + ((j + 1) * f->zoom)) * 1. / 2.) - (((i * f->zoom)
				+ (f->z * f->tab[j + 1][i])) * 1. / 2.);
	ft_draw_line(f);
}

static void	ft_horizontal(t_var *f, int j, int i)
{
	f->x0 = 50 + (i * f->zoom) + (j * f->zoom);
	f->x1 = 50 + ((i + 1) * f->zoom) + (j * f->zoom);
	f->y0 = ((700 + (j * f->zoom)) * 1. / 2.) - (((i * f->zoom)
				+ (f->z * f->tab[j][i])) * 1. / 2.);
	f->y1 = ((700 + (j * f->zoom)) * 1. / 2.) - ((((i + 1) * f->zoom)
				+ (f->z * f->tab[j][i + 1])) * 1. / 2.);
	ft_draw_line(f);
}

int			ft_call(t_var *f)
{
	int	i;
	int	j;

	j = 0;
	while (j < f->l)
	{
		i = 0;
		while (i < f->i - 1)
			ft_horizontal(f, j, i++);
		j++;
	}
	j = 0;
	while (j < f->l - 1)
	{
		i = 0;
		while (i < f->i)
			ft_vertical(f, j, i++);
		j++;
	}
	return (0);
}

int			ft_init_struct(char *buf, int nbl, int nbi)
{
	t_var	f;

	f.z = 2.0;
	f.xmove = 0;
	f.ymove = 0;
	f.tab = ft_newtab(buf, nbl, nbi, 0);
	f.l = nbl;
	f.i = nbi;
	f.c1 = 0x800000;
	f.c2 = 0x00ff00;
	f.c3 = 0x00ffff;
	f.c4 = 0xc0c0c0;
	if (f.l >= f.i)
		f.zoom = 400 / f.l;
	else
		f.zoom = 400 / f.i;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, 800, 800, "fdf");
	mlx_expose_hook(f.win, &ft_expose_hook, &f);
	mlx_key_hook(f.win, &ft_key_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
