/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbied <oelbied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:55:25 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/17 11:21:23 by oelbied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	unsigned char	cc;

	s = (unsigned char *)b;
	cc = (unsigned char)c;
	while (len--)
	{
		s[len] = cc;
	}
	return (b);
}
