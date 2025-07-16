/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_freeall(t_view *view)
{
	mlx_destroy_image(view->mlx_ptr, view->img);
	mlx_destroy_window(view->mlx_ptr, view->win_ptr);
	mlx_destroy_display(view->mlx_ptr);
	free(view->mlx_ptr);
	free(view->map->tab);
	free(view->map);
	exit(0);
}

int	key_press(int keycode, t_view *view)
{
	if (keycode == ESC_KEY)
		ft_freeall(view);
	else if (keycode == PLUS_KEY)
		view->zoom *= 1.5;
	else if (keycode == MINUS_KEY)
		view->zoom *= 0.75;
	else if (keycode == TRANSLATE_UP_KEY)
		view->translate_y -= TRANSLATION_STEP;
	else if (keycode == TRANSLATE_DOWN_KEY)
		view->translate_y += TRANSLATION_STEP;
	else if (keycode == TRANSLATE_LEFT_KEY)
		view->translate_x -= TRANSLATION_STEP;
	else if (keycode == TRANSLATE_RIGHT_KEY)
		view->translate_x += TRANSLATION_STEP;
	mlx_destroy_image(view->mlx_ptr, view->img);
	draw_map(view);
	return (0);
}
