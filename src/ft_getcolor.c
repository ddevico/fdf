/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/19 11:58:21 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	ft_getcolor2(int x)
{
	if (x > 15)
		return (24861);
	else if (x > 7)
		return (31269);
	else if (x > 5)
		return (37164);
	else if (x > 2)
		return (173619);
	else if (x > 0)
		return (42546);
	return (53567);
}

int			ft_getcolor1(int x)
{
	x *= 10;
	if (x > 85)
		return (16777215);
	else if (x > 80)
		return (14729391);
	else if (x > 75)
		return (13736315);
	else if (x > 65)
		return (12548950);
	else if (x > 50)
		return (11034424);
	else if (x > 40)
		return (6365696);
	else if (x > 25)
		return (8400129);
	else if (x > 25)
		return (18197);
	return (ft_getcolor2(x));
}
