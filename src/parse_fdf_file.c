/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	parse_init(int *fd, t_tab3x1 **map, const char *filename, size_t *y)
{
	if (ft_checkmap(filename))
		return (-1);
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (-1);
	(*map) = malloc(sizeof(t_tab3x1));
	if (!(*map))
	{
		close(*fd);
		return (-1);
	}
	(*map)->tab = NULL;
	(*map)->max_size = 0;
	(*map)->maxx = 0;
	(*map)->maxy = 0;
	*y = 0;
	return (0);
}

void	*close_free_parse(t_utils *u, t_tab3x1 *map)
{
	if (u->fd > 2)
		close(u->fd);
	if (map->tab)
		free(map->tab);
	if (map)
		free(map);
	return (NULL);
}

t_tab3x1	*parse_fdf_file_pt2(t_utils *u, t_tab3x1 *map)
{
	u->values = ft_split(u->line, ' ');
	if (u->line)
		free(u->line);
	if (!u->values)
		close_free_parse(u, map);
	u->x_count = 0;
	while ((u->values)[u->x_count])
		u->x_count++;
	if (!map->maxx)
		map->maxx = u->x_count;
	else if (map->maxx != u->x_count)
		return (NULL);
	if (!parse_line(map, u->values, u->y++))
		close_free_parse(u, map);
	if (u->fd > 2)
		u->line = get_next_line(u->fd);
	return (map);
}

int	ft_check_ext(const char *filename)
{
	int	i;

	i = ft_strlen(filename) - 1;
	if (i <= 3)
		return (-1);
	if (filename[i] == 'f' && filename[i - 1] == 'd' && filename[i - 2] == 'f'
		&& filename[i - 3] == '.')
		return (0);
	return (-1);
}

t_tab3x1	*parse_fdf_file(const char *filename)
{
	t_utils		u;
	t_tab3x1	*map;
	void		*verif;

	map = NULL;
	verif = map;
	if (!filename || parse_init(&u.fd, &map, filename, &u.y)
		|| ft_checkmap(filename) || ft_check_ext(filename))
	{
		if (u.fd > 2)
			close(u.fd);
		if (map)
			free(map);
		return (NULL);
	}
	u.line = get_next_line(u.fd);
	while (u.line)
		verif = parse_fdf_file_pt2(&u, map);
	if (!verif)
		return (NULL);
	map->maxy = u.y;
	close(u.fd);
	return (map);
}
