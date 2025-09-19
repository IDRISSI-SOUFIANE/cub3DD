/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:42:47 by oelbied           #+#    #+#             */
/*   Updated: 2025/09/19 22:14:46 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_tchking_player(char **maps, int contLaien)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (contLaien < 3)
		return (0);
	if (!chick_all_line(maps[0]) || !chick_all_line(maps[contLaien - 1]))
		return (0);
	contLaien -= 1;
	while (i < contLaien)
	{
		if (ft_tchklast_laine(maps[i - 1], maps[i], maps[i + 1]) == 0)
			return (0);
		if (maps[i][0] != ' ' && maps[i][0] != '1')
			return (0);
		j = 1;
		if (tchk_fixsed_mapp(maps, contLaien, j, i) == 0)
			return (0);
		i++;
	}
	if (ft_tchklast_laine(maps[i - 1], maps[i], maps[i + 1]) == 0)
		return (0);
	return (1);
}

static char	*skep_spas_line(char *line_reading, int fd, int *i)
{
	char	*new_line;

	while (line_reading)
	{
		new_line = ft_strtrim(line_reading, " ");
		if (ft_strcmp(new_line, "\n") == 0)
		{
			free(new_line);
			free(line_reading);
			(*i)--;
			line_reading = get_next_line(fd);
		}
		else
		{
			free(new_line);
			break ;
		}
	}
	return (line_reading);
}

char	**copy_tcheck(char **maps, char *line_reading, int fd, int i)
{
	int	j;

	j = 0;
	line_reading = skep_spas_line(line_reading, fd, &i);
	if (line_reading == NULL)
		return (NULL);
	maps = malloc(sizeof(char *) * (i + 1));
	maps[j] = ft_strdup(line_reading);
	free(line_reading);
	j++;
	line_reading = get_next_line(fd);
	while (line_reading != NULL)
	{
		maps[j++] = ft_strdup(line_reading);
		free(line_reading);
		line_reading = get_next_line(fd);
	}
	maps[j] = NULL;
	if (ft_tchking_player(maps, i))
		return (maps);
	else
		return (free_2d_array(maps), NULL);
}

static char	*skep_spas(char *line_reading, int fd, int *i)
{
	int		cont;
	char	*re;

	cont = 0;
	line_reading = get_next_line(fd);
	while (line_reading != NULL && cont < 6)
	{
		re = ft_strtrim(line_reading, " ");
		if (ft_strcmp(re, "\n") == 0)
		{
			free(line_reading);
			free(re);
			(*i)--;
		}
		else
		{
			free(re);
			cont++;
			(*i)--;
			free(line_reading);
		}
		line_reading = get_next_line(fd);
	}
	return (line_reading);
}

char	**men(void)
{
	char	*line_reading;
	char	**maps;
	int		i;
	int		fd;

	maps = NULL;
	i = 0;
	fd = open("./map/map.cub", O_RDONLY);
	line_reading = get_next_line(fd);
	while (line_reading != NULL)
	{
		i++;
		free(line_reading);
		line_reading = get_next_line(fd);
	}
	close(fd);
	fd = open("./map/map.cub", O_RDONLY);
	line_reading = skep_spas(line_reading, fd, &i);
	return (copy_tcheck(maps, line_reading, fd, i));
}
