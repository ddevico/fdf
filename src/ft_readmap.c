/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:53:02 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/07 16:53:43 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_struct		*ft_init_tab(t_struct *data, int len_x, int len_y)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!(data->map = (int **)malloc(len_x * sizeof(int *))))
		return (NULL);
	while (i < len_x)
	{
		if (!(data->map[i] = (int *)malloc(len_y * sizeof(int))))
			return (NULL);
		i++;
	}
	return (data);
}

t_struct			*ft_readmap(t_struct *data, int len_x, int len_y, char *str)
{
	int				i;
	int				j;
	char			*line;
	int				fd;
	int				nb;

	i = 0;
	fd = open(str, O_RDONLY);
	data = ft_init_tab(data, len_x, len_y);
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		while (*line)
		{
			while (*line == ' ')
				line++;
			nb = ft_atoi(line);
			if (nb < 0)
				line++;
			line += ft_countnumber(line);
			data->map[i][j++] = nb;
		}
		i++;
	}
	return (data);
}
