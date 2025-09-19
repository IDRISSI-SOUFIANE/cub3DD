/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:34:25 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/19 21:36:51 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	fd_player(char p)
{
	return ((p == 'N' || p == 'S' || p == 'W' || p == 'E'));
}

int	found_player(char **map)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (fd_player(map[i][j]))
				flag += 1;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (1);
	return (0);
}

char	**check_map(char **map)
{
	if (!map)
		return (NULL);
	if (found_player(map))
		return (free_2d_array(map), NULL);
	return (map);
}

void	free_all(t_data *data)
{
	if (data->map)
	{
		free_2d_array(data->map);
		data->map = NULL;
	}
	free_v_map(&data->v_map);
}
