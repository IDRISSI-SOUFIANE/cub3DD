/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:11:36 by oelbied           #+#    #+#             */
/*   Updated: 2025/09/19 16:35:41 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	chick_all_line(char *str)
{
	int	i;
	int	j;
	int	lin;

	i = 0;
	j = 0;
	lin = 0;
	if (str == NULL)
		return (0);
	lin = ft_strlen(str);
	while (lin > i && str[i])
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

int	tchick_in_map(char c)
{
	if (c != '0' && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E' && c != '\n'
		&& c != ' ' && c != '\0' && c != '1')
		return (0);
	return (1);
}

int	tchk_fixsed_mapp(char **maps, int contLaien, int j, int i)
{
	while ((maps[i][j] != '\0'))
	{
		if (tchick_in_map(maps[i][j]) == 0)
			return (0);
		if (maps[i][j + 1] != '\0')
		{
			if (maps[i][j] == '0' || maps[i][j] == 'N'
				|| maps[i][j] == 'S' || maps[i][j] == 'W' || maps[i][j] == 'E')
			{
				if ((maps[i][j + 1] == ' ')
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
