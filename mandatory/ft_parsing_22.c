/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_22.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:42:13 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/18 18:41:21 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_extention(char *map)
{
	char	*ext;
	int		i;
	int		j;

	ext = ".cub";
	i = ft_strlen(map) - 1;
	j = ft_strlen(ext) - 1;
	while (j > -1)
	{
		if (map[i] != ext[j] && j > -1)
			return (1);
		else if (map[i] == ext[j])
		{
			i--;
			j--;
		}
	}
	return (0);
}

char	*get_word(char *line, int count)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = malloc(sizeof(char) * (count + 1));
	if (NULL == str)
		return (NULL);
	j = 0;
	while (j < count && line[i])
	{
		if (line[i] == '\t')
			return (free(str), NULL);
		str[j++] = line[i++];
	}
	str[j] = '\0';
	return (str);
}

int	check_element(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1337);
		i++;
	}
	return (0);
}

int	check_res(char **res)
{
	int	i;

	if (ft_count_2d_array(res) != 3)
		return (1);
	i = 0;
	while (res[i] != NULL)
	{
		if (check_element(res[i]))
			return (1337);
		i++;
	}
	return (0);
}
