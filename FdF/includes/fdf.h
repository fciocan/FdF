/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:14:33 by fciocan           #+#    #+#             */
/*   Updated: 2018/02/09 17:28:25 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <errno.h>
# include <mlx.h>

# define OP_COLOR 0x6CD2A6

typedef struct	s_var
{
	int			l;
	int			i;
	int			length;
	int			zoom;
	int			xmove;
	int			ymove;
	int			**tab;
	int			c1;
	int			c2;
	int			c3;
	int			c4;
	double		x;
	double		y;
	double		z;
	double		x0;
	double		x1;
	double		y0;
	double		y1;
	void		*mlx;
	void		*win;
}				t_var;

int			g_nbl;
int			g_nbi;
char		*g_buf;

int				ft_call(t_var *f);
int				ft_expose_hook(t_var *f);
int				ft_key_hook(int keycode, t_var *f);
int				ft_init_struct(char *buf, int nbl, int nbi);
int				**ft_newtab(char *buf, int nbl, int nbi, int j);
char			*ft_endbuf(char *buf, int *length);

#endif
