/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_helper_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:38:13 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/19 17:50:06 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	index_start(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] != ' '))
		i++;
	while (line[i] && (line[i] == ' '))
		i++;
	return (i);
}

int	index_end(char *line)
{
	int	start;

	start = index_start(line);
	while (line[start])
		start++;
	return (start);
}

void	free_v_map(t_vmap *v_map)
{
	if (v_map->north)
		free(v_map->north);
	if (v_map->south)
		free(v_map->south);
	if (v_map->west)
		free(v_map->west);
	if (v_map->east)
		free(v_map->east);
	if (v_map->floor)
		free(v_map->floor);
	if (v_map->ceil)
		free(v_map->ceil);
}
