/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:53:02 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/07 16:53:43 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"

# define NUMBER = "0123456789"

typedef struct		s_struct
{
	int				**map;
	int				map_x;
	int				map_y;
	double			x;
	double			y;
	void			*mlx;
	void			*win;
}					t_struct;

typedef struct		s_point
{
	float			z0;
	float			z1;
	float			x0;
	float			x1;
	float			dx;
	float			y0;
	float			y1;
	float			dy;
}					t_point;

t_struct			*ft_readmap(t_struct *data, int len_x, int len_y,
					char *str);

void				ft_draw(t_struct *data);

int					ft_getcolor1(int x);

#endif
