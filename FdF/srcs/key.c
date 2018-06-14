/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:49:22 by fciocan           #+#    #+#             */
/*   Updated: 2018/02/09 17:28:21 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_expose_hook(t_var *f)
{
	int	x;
	int	y;

	x = 27;
	y = 34;
	while (x <= 180)
		mlx_pixel_put(f->mlx, f->win, x++, y, OP_COLOR);
	while (y <= 140)
		mlx_pixel_put(f->mlx, f->win, x, y++, OP_COLOR);
	while (x >= 27)
		mlx_pixel_put(f->mlx, f->win, x--, y, OP_COLOR);
	while (y >= 34)
		mlx_pixel_put(f->mlx, f->win, x, y--, OP_COLOR);
	mlx_string_put(f->mlx, f->win, 35, 35, OP_COLOR, "Quit = ESC");
	mlx_string_put(f->mlx, f->win, 35, 55, OP_COLOR, "Move = ^ v < >");
	mlx_string_put(f->mlx, f->win, 35, 75, OP_COLOR, "Zoom = + -");
	mlx_string_put(f->mlx, f->win, 35, 95, OP_COLOR, "Depth = W S");
	mlx_string_put(f->mlx, f->win, 35, 115, OP_COLOR, "Reset = R");
	ft_call(f);
	return (0);
}

void		ft_init(t_var *f)
{
	f->z = 2.0;
	f->xmove = 0;
	f->ymove = 0;
	f->tab = ft_newtab(g_buf, g_nbl, g_nbi, 0);
	f->l = g_nbl;
	f->i = g_nbi;
	f->c1 = 0x800000;
	f->c2 = 0x00ff00;
	f->c3 = 0x00ffff;
	f->c4 = 0xc0c0c0;
	if (f->l >= f->i)
		f->zoom = 400 / f->l;
	else
		f->zoom = 400 / f->i;
}

static int	ft_key3(int keycode, t_var *f)
{
	if (keycode == 13)
	{
		if (f->z <= 30.)
			f->z += 1;
		mlx_clear_window(f->mlx, f->win);
		ft_expose_hook(f);
	}
	if (keycode == 1)
	{
		if (f->z >= -30.)
			f->z -= 1;
		mlx_clear_window(f->mlx, f->win);
		ft_expose_hook(f);
	}
	if (keycode == 15)
	{
		ft_init(f);
		mlx_clear_window(f->mlx, f->win);
		ft_expose_hook(f);
	}
	return (0);
}

static int	ft_key2(int keycode, t_var *f)
{
	if (keycode == 126)
	{
		f->ymove += 30;
		mlx_clear_window(f->mlx, f->win);
		ft_expose_hook(f);
	}
	if (keycode == 69)
	{
		if (f->zoom <= 95)
			f->zoom += 1;
		mlx_clear_window(f->mlx, f->win);
		ft_expose_hook(f);
	}
	if (keycode == 78)
	{
		if (f->zoom >= -35)
			f->zoom -= 1;
		mlx_clear_window(f->mlx, f->win);
		ft_expose_hook(f);
	}
	ft_key3(keycode, f);
	return (0);
}

int			ft_key_hook(int keycode, t_var *f)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		f->xmove += 30;
		mlx_clear_window(f->mlx, f->win);
		ft_expose_hook(f);
	}
	if (keycode == 124)
	{
		f->xmove -= 30;
		mlx_clear_window(f->mlx, f->win);
		ft_expose_hook(f);
	}
	if (keycode == 125)
	{
		f->ymove -= 30;
		mlx_clear_window(f->mlx, f->win);
		ft_expose_hook(f);
	}
	ft_key2(keycode, f);
	return (0);
}
