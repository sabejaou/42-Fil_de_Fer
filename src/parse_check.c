/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_count_nbs(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line && line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			while (line[i] >= '0' && line[i] <= '9')
				i++;
			j++;
		}
		if (line[i])
			i++;
	}
	return (j);
}

int	ft_check_line(char *line)
{
	int	i;
	int	max;

	max = ft_strlen(line);
	i = 0;
	while (line[i])
	{
		while (line[i] == '+' || line[i] == '-')
			i++;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		if (i < max)
			i++;
		if (i < max && (line[i] < '0' || line[i] > '9') && line[i] != ' '
			&& line[i] != '\n' && line[i] != '+' && line[i] != '-' && line[i])
			return (-1);
		if (line[i])
			i++;
	}
	if (max > 1 && ((line[i - 1] == '\n' && (line[i - 2] < '0'
					|| line[i - 2] > '9')) || (line[i - 1] != '\n'
				&& (line[i - 1] < '0' || line[i - 1] > '9'))))
		return (-1);
	return (0);
}

int	ft_checkmap(const char *filename)
{
	int		fd;
	char	*line;
	int		max;

	fd = open(filename, O_RDONLY);
	if (fd <= 2)
		return (-1);
	line = get_next_line(fd);
	max = ft_count_nbs(line);
	while (line)
	{
		if (line[0] == '\n' || ft_check_line(line) || ft_count_nbs(line) != max)
		{
			close(fd);
			if (line)
				free(line);
			return (-1);
		}
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
