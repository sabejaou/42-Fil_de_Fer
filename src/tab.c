/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_tab3x1	*resize_map_tab(t_tab3x1 *map, size_t new_size)
{
	t_vec3x1	*new_tab;
	size_t		i;

	new_tab = malloc(new_size * sizeof(t_vec3x1));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < map->max_size)
	{
		new_tab[i] = map->tab[i];
		i++;
	}
	free(map->tab);
	map->tab = new_tab;
	return (map);
}

t_tab3x1	*parse_line(t_tab3x1 *map, char **values, size_t y)
{
	size_t	x;

	x = 0;
	while (values[x])
	{
		if (resize_map_tab(map, map->max_size + 1) == NULL)
			return (NULL);
		map->tab[map->max_size].x = x;
		map->tab[map->max_size].y = y;
		map->tab[map->max_size].z = atof(values[x]);
		free(values[x]);
		x++;
		map->max_size++;
	}
	free(values);
	return (map);
}
