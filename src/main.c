/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_error_main(t_view view, char *message)
{
	ft_putstr_fd(message, 2);
	ft_freeall(&view);
	return (EXIT_FAILURE);
}

int	close_window(t_view *view)
{
	ft_freeall(view);
	return (0);
}

int	main(int argc, char **argv)
{
	t_view	view;

	if (argc != 2)
		return (ft_putstr_fd("Usage: ./fdf <filename>\n", 2), EXIT_FAILURE);
	view = (t_view){0};
	view.map = parse_fdf_file(argv[1]);
	if (!view.map)
		return (ft_error_main(view, "Failed to parse file\n"));
	view.zoom = WINDOW_WIDTH / (view.map->maxx + view.map->maxy);
	view.translate_x = 0.0;
	view.translate_y = 0.0;
	view.mlx_ptr = mlx_init();
	if (view.mlx_ptr == NULL)
		return (ft_error_main(view, "Failed to initialize MLX\n"));
	view.win_ptr = mlx_new_window(view.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF - 42");
	if (view.win_ptr == NULL)
		return (ft_error_main(view, "Failed to create window\n"));
	draw_map(&view);
	mlx_hook(view.win_ptr, 2, 1L << 0, (int (*)())key_press, &view);
	mlx_hook(view.win_ptr, 17, 0, close_window, &view);
	mlx_loop(view.mlx_ptr);
	return (EXIT_SUCCESS);
}
