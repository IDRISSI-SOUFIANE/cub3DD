/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbied <oelbied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:11:36 by oelbied           #+#    #+#             */
/*   Updated: 2025/09/14 09:15:55 by oelbied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	chick_all_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			j++;
		}
		if ((str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			|| (i > 1 && str[i] != '1' && str[i - 1] != ' ' && str[i] != '\n'))
			return (0);
		if (str[i] == ' ')
			j++;
		i++;
	}
	return (1);
}

int	ft_tcheck_ziro(int lin, int i, int li, char *lineTow)
{
	if (lin > 0)
		i = lin - 1;
	else
		i = lin;
	while (i <= li)
	{
		if (lineTow[i] == '0')
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
	int	i;

	lin_one = 0;
	li = 0;
	linethre = 0;
	i = 0;
	lin_one = ft_strlen(line);
	li = ft_strlen(lineTow);
	linethre = ft_strlen(linThre);
	if (lin_one < li)
	{
		if (ft_tcheck_ziro(lin_one, i, li, lineTow) == 0)
			return (0);
	}
	if (li > linethre)
	{
		if (ft_tcheck_ziro(linethre, i, li, lineTow) == 0)
			return (0);
	}
	return (1);
}

int	tchk_fixsed_mapp(char **maps, int contLaien, int j, int i)
{
	int	flags;

	flags = 0;
	while ((maps[i][j] != '\0'))
	{
		if (maps[i][j + 1] != '\0')
		{
			if (maps[i][j] == '0' || maps[i][j] == 'N'
				|| maps[i][j] == 'S' || maps[i][j] == 'W' || maps[i][j] == 'E')
			{
				if (maps[i][j] == 'N' || maps[i][j] == 'S'
					|| maps[i][j] == 'W' || maps[i][j] == 'E')
					flags++;
				if (flags > 1 || (maps[i][j + 1] == ' ')
					|| (maps[i][j + 1] == '\n')
					|| (j > 0 && maps[i][j - 1] == ' ')
					|| (i > 0 && (maps[i + 1][j] != '\0')
					&& maps[i - 1][j] == ' ')
						|| ((i) < contLaien && maps[i + 1][j] == ' '))
					return (0);
			}
		}
		j++;
	}
	return (1);
}
