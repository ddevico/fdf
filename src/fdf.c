/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/03/02 15:23:17 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

static void		ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

static int		key_funct(int keycode)
{
	if (keycode == 53)
		exit(0);
	ft_printf("coucou !! %d\n", keycode);
	return (0);
}

static int		mouse_funct(int button, int x, int y)
{
	ft_printf("Mouse : %d (%d, %d)\n", button, x, y);
	return (0);
}

static t_struct	*ft_map(t_struct *data, char *str)
{
	char		*line;
	int			fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("File error");
	data->map_x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((*line + 1))
			data->map_y = 0;
		while (*line)
		{
			while (*line == ' ')
				line++;
			line += ft_countnumber(line);
			if (*line != '-')
				data->map_y++;
			line++;
		}
		data->map_x++;
	}
	data = ft_readmap(data, data->map_x, data->map_y, str);
	return (data);
}

int				main(int argc, char **argv)
{
	t_struct	*data;
	int			fd;

	if (!(data = (t_struct*)malloc(1 * sizeof(t_struct))))
		return (0);
	if (argc == 2 && *argv != NULL)
	{
		data = ft_map(data, argv[1]);
		if (!(data->mlx = mlx_init()))
			ft_error("mlx_init: error, couln't initialize mlx");
		if (!(data->win = mlx_new_window(data->mlx, 1500, 800, "42")))
			ft_error("mlx_new_window: couldn't initialize window");
		ft_draw(data);
		mlx_key_hook(data->win, key_funct, data->mlx);
		mlx_mouse_hook(data->win, mouse_funct, data->mlx);
		mlx_loop(data->mlx);
	}
	else if (argc > 2)
		ft_error("Warning: too many arguments");
	else
		ft_error("Error: give a map in parameters");
	return (0);
}
