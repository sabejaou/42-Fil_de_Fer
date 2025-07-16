/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec3x1	iso_projection(t_vec3x1 point, t_view *view)
{
	t_vec3x1	transformed;
	double		iso_x;
	double		iso_y;

	iso_x = point.x;
	iso_y = point.y;
	point.x *= view->zoom;
	point.y *= view->zoom;
	point.z *= view->zoom;
	iso_x = (sqrt(2) / 2.) * (point.x - point.y);
	iso_y = (1. / sqrt(6)) * (point.x + point.y) - sqrt(2 / 3.0f) * point.z;
	iso_x += view->translate_x;
	iso_y += view->translate_y;
	transformed.x = iso_x + WINDOW_WIDTH / 2;
	transformed.y = iso_y + WINDOW_HEIGHT / 2;
	return (transformed);
}
