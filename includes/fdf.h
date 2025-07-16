/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:33:33 by sbejaoui          #+#    #+#             */
/*   Updated: 2024/02/13 14:31:15 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <math.h>
# include "../libmlx/mlx.h"
# include "../libft/libft.h"
# define PERSPECTIVE_DISTANCE 500
# define VIEWER_DISTANCE 1000
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define TRANSLATION_STEP 50
# define TRANSLATION_STEP 50
# define TRANSLATE_UP_KEY    65362
# define TRANSLATE_DOWN_KEY  65364
# define TRANSLATE_LEFT_KEY 65361
# define TRANSLATE_RIGHT_KEY 65363
# define ESC_KEY 65307
# define PLUS_KEY 65451
# define MINUS_KEY 65453
# define LEFT_ARROW_KEY 65430
# define RIGHT_ARROW_KEY 65432
# define UP_ARROW_KEY 65437
# define DOWN_ARROW_KEY 65433

typedef struct s_vec3x1
{
	double	x;
	double	y;
	double	z;
}	t_vec3x1;

typedef struct s_tab3x1
{
	t_vec3x1	*tab;
	size_t		max_size;
	size_t		maxx;
	size_t		maxy;
}	t_tab3x1;

typedef struct s_view
{
	t_tab3x1	*map;
	double		zoom;
	double		translate_x;
	double		translate_y;
	int			bpp;
	int			sl;
	int			endian;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
}	t_view;

typedef struct s_rotation
{
	double	temp_x;
	double	temp_y;
	double	rotated_x;
	double	rotated_y;
}	t_rotation;

typedef struct s_line
{
	double	dx;
	double	dy;
	double	steps;
	double	x_inc;
	double	y_inc;
}	t_line;

typedef struct s_draw_data
{
	size_t		x;
	size_t		y;
	size_t		next_x;
	size_t		next_y;
	t_vec3x1	start;
	t_vec3x1	end;
}	t_draw_data;

typedef struct s_utils
{
	int		fd;
	char	*line;
	char	**values;
	size_t	y;
	size_t	x_count;
}	t_utils;

typedef struct s_drawlineutils
{
	double	dx;
	double	dy;
	double	steps;
	double	y_inc;
	double	x_inc;
	double	y;
	double	x;
	int		i;
}	t_drawlineutils;

typedef struct s_drawmaputils
{
	size_t		x;
	size_t		y;
	size_t		next_x;
	size_t		next_y;
	t_vec3x1	start;
	t_vec3x1	end;
}	t_drawmaputils;

t_vec3x1	iso_projection(t_vec3x1 point, t_view *view);
t_tab3x1	*parse_fdf_file(const char *filename);
void		draw_map(t_view *view);
t_tab3x1	*parse_fdf_file(const char *filename);
int			key_press(int keycode, t_view *view);
t_tab3x1	*parse_line(t_tab3x1 *map, char **values, size_t y);
int			ft_checkmap(const char *filename);
void		ft_freeall(t_view *view);

#endif