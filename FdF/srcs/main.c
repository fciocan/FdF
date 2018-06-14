/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:49:33 by fciocan           #+#    #+#             */
/*   Updated: 2018/02/09 17:28:18 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			**ft_newtab(char *buf, int nbl, int nbi, int j)
{
	int		i;
	int		k;
	int		**tab;

	k = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * nbl)))
		return (NULL);
	while (buf[k] != '\0' && j < nbl)
	{
		i = 0;
		if (!(tab[j] = (int *)malloc(sizeof(int) * nbi)))
			return (NULL);
		while (buf[k] != '\n' && buf[k] != '\0' && j < nbl)
		{
			tab[j][i++] = ft_atoi(buf, &k);
			while (buf[k] == ' ')
				k++;
		}
		k++;
		j++;
	}
	return (tab);
}

static void	ft_indicate_error(char *file)
{
	char	*message;

	message = ft_strnew(1);
	message = ft_strjoin(message, "error: ");
	message = ft_strjoin(message, strerror(errno));
	message = ft_strjoin(message, " for ");
	message = ft_strjoin(message, file);
	message = ft_strjoin(message, "\n");
	ft_putstr_fd(message, 2);
}

static int	ft_start(char *argv, int argc, int *fd)
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./FdF input_file\n", 2);
		return (-1);
	}
	if (BUFF_SIZE < 1)
	{
		ft_putstr_fd("error: BUFF_SIZE must be greater than 0\n", 2);
		return (-1);
	}
	if ((*fd = open(argv, O_RDONLY)) == -1)
	{
		ft_indicate_error(argv);
		return (-1);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;

	g_nbl = 0;
	g_buf = ft_strnew(1);
	if (ft_start(argv[1], argc, &fd) == -1)
		return (0);
	while (get_next_line(fd, &line) > 0 && g_nbl++ > -1)
		g_buf = ft_strjoin(ft_strjoin(g_buf, line), "\n");
	if (get_next_line(fd, &line) != 0)
	{
		ft_putstr_fd("error: get_next_line returned -1\n", 2);
		free(g_buf);
		return (0);
	}
	if (ft_endbuf(g_buf, &g_nbi) != NULL)
		ft_init_struct(g_buf, g_nbl, g_nbi);
	if (close(fd) == -1)
		ft_indicate_error(argv[1]);
	return (0);
}
