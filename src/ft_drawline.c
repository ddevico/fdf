/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/19 11:58:21 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

static void		print_point(t_struct *data, t_point *point, int i)
{
	double		factor;
	int			color;

	factor = 0.0;
	point->dx = (point->x1 - point->x0);
	point->dy = (point->y1 - point->y0);
	while (factor <= 1)
	{
		color = ft_getcolor1(i);
		data->x = point->x0 + point->dx * factor;
		data->y = point->y0 + point->dy * factor;
		mlx_pixel_put(data->mlx, data->win, data->y, data->x, color);
		factor += 1. / sqrt((point->dx * point->dx) + (point->dy * point->dy));
	}
}

static void		ft_to_iso(t_point *point)
{
	double		x0;
	double		y0;
	double		x1;
	double		y1;

	x0 = point->x0;
	y0 = point->y0;
	x1 = point->x1;
	y1 = point->y1;
	point->x0 = (x0 + y0);
	point->x1 = (x1 + y1);
	point->y0 = (y0 * 1. / 2) - (1. / 2. * (x0 + point->z0));
	point->y1 = (y1 * 1. / 2) - (1. / 2. * (x1 + point->z1));
}

static void		ft_horizontal(t_struct *data, t_point *point, int i, int j)
{
	double		x0;
	double		x1;
	double		y0;
	double		y1;

	point->x0 = -300 + i * 20;
	point->x1 = -300 + (i + 1) * 20;
	point->y0 = 375 + j * 20;
	point->y1 = 375 + j * 20;
	point->z0 = (5 * data->map[i][j]);
	point->z1 = 5 * data->map[i + 1][j];
	ft_to_iso(point);
	print_point(data, point, data->map[i][j]);
}

static void		ft_vertical(t_struct *data, t_point *point, int i, int j)
{
	double		x0;
	double		x1;
	double		y0;
	double		y1;

	point->x0 = -300 + i * 20;
	point->x1 = -300 + i * 20;
	point->y0 = 375 + j * 20;
	point->y1 = 375 + (j + 1) * 20;
	point->z0 = 5 * data->map[i][j];
	point->z1 = 5 * data->map[i][j + 1];
	ft_to_iso(point);
	print_point(data, point, data->map[i][j]);
}

void			ft_draw(t_struct *data)
{
	int			i;
	int			j;
	t_point		*point;

	i = 0;
	if (!(point = malloc(sizeof(t_point))))
		return ;
	while (i < data->map_x)
	{
		j = 0;
		while (j < data->map_y)
		{
			if (i < data->map_x - 1)
				ft_horizontal(data, point, i, j);
			if (j < data->map_y - 1)
				ft_vertical(data, point, i, j);
			j++;
		}
		i++;
	}
}
