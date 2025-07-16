/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_vec3x1 *start, t_vec3x1 *end, t_view *view)
{
	t_drawlineutils	u;

	u.i = 0;
	u.dx = end->x - start->x;
	u.dy = end->y - start->y;
	if (fabs(u.dx) > fabs(u.dy))
		u.steps = fabs(u.dx);
	else
		u.steps = fabs(u.dy);
	u.x_inc = u.dx / (float)u.steps;
	u.y_inc = u.dy / (float)u.steps;
	u.x = start->x;
	u.y = start->y;
	while (u.i <= u.steps)
	{
		if (u.x >= 0 && u.y >= 0 && u.x < WINDOW_WIDTH - 4
			&& u.y < WINDOW_HEIGHT - 4)
			((int *)view->addr)[(int)u.y * (view->sl >> 2)
				+ (int)u.x] = 0xFFFFFF;
		u.x += u.x_inc;
		u.y += u.y_inc;
		u.i++;
	}
}

void	draw_map_pt2(t_view *view, t_drawmaputils u)
{
	if (u.x < view->map->maxx - 1)
	{
		u.next_x = u.x + 1;
		u.next_y = u.y;
		u.start = iso_projection(view->map->tab[u.y * view->map->maxx
				+ u.x], view);
		u.end = iso_projection(view->map->tab[u.next_y * view->map->maxx
				+ u.next_x], view);
		draw_line(&u.start, &u.end, view);
	}
	if (u.y < view->map->maxy - 1)
	{
		u.next_x = u.x;
		u.next_y = u.y + 1;
		u.start = iso_projection(view->map->tab[u.y * view->map->maxx
				+ u.x], view);
		u.end = iso_projection(view->map->tab[u.next_y * view->map->maxx
				+ u.next_x], view);
		draw_line(&u.start, &u.end, view);
	}
}

void	draw_map(t_view *view)
{
	t_drawmaputils	u;

	view->img = mlx_new_image(view->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	view->addr = mlx_get_data_addr(view->img, &view->bpp, &view->sl,
			&view->endian);
	if (!view || !view->map)
		return ;
	u.y = 0;
	while (u.y < view->map->maxy)
	{
		u.x = 0;
		while (u.x < view->map->maxx)
		{
			draw_map_pt2(view, u);
			u.x++;
		}
		u.y++;
	}
	mlx_put_image_to_window(view->mlx_ptr, view->win_ptr, view->img, 0, 0);
}
