/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:00:14 by oelbied           #+#    #+#             */
/*   Updated: 2025/09/19 16:40:00 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_tcheck_ziro(int lin, int li, char *lineTow)
{
	int	i;

	i = 0;
	if (lin > 0)
		i = lin - 1;
	else
		i = lin;
	while (i <= li)
	{
		if (lineTow[i] == '0' || lineTow[i] == 'N'
			|| lineTow[i] == 'S' || lineTow[i] == 'W' || lineTow[i] == 'E')
			return (0);
		i++;
	}
	return (1);
}

int	ft_tcheck_ziro_he(int lin, int li, char *lineTow, char *hd)
{
	int	i;

	i = 0;
	if (lin > 0 && ft_strchr(hd, '\n'))
		i = lin - 1;
	else
		i = lin;
	while (i <= li)
	{
		if (lineTow[i] == '0' || lineTow[i] == 'N'
			|| lineTow[i] == 'S' || lineTow[i] == 'W' || lineTow[i] == 'E')
			return (0);
		i++;
	}
	return (1);
}

int	ft_tchklast_laine(char *line, char *lineTow, char *linThre)
{
	int	lin_one;
	int	li;
	int	linethre;

	lin_one = 0;
	li = 0;
	linethre = 0;
	lin_one = ft_strlen(line);
	li = ft_strlen(lineTow);
	linethre = ft_strlen(linThre);
	if (lin_one < li)
	{
		if (ft_tcheck_ziro(lin_one, li, lineTow) == 0)
			return (0);
	}
	if (li > linethre)
	{
		if (ft_tcheck_ziro_he(linethre, li, lineTow, linThre) == 0)
			return (0);
	}
	return (1);
}
