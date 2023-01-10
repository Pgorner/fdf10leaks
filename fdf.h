/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:29:25 by pgorner           #+#    #+#             */
/*   Updated: 2023/01/10 16:47:50 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//				██╗  ██╗███████╗ █████╗ ██████╗ ███████╗██████╗
//				██║  ██║██╔════╝██╔══██╗██╔══██╗██╔════╝██╔══██╗
//				███████║█████╗  ███████║██║  ██║█████╗  ██████╔╝
//				██╔══██║██╔══╝  ██╔══██║██║  ██║██╔══╝  ██╔══██╗
//				██║  ██║███████╗██║  ██║██████╔╝███████╗██║  ██║
//				╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝
#ifndef FDF_H
# define FDF_H
# define WIDTH 1980
# define HEIGHT 1200
# include "42-libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
//==============================================================================
//-------------------------------DEFINED_VALUES---------------------------------
//==============================================================================
//-----------------------------------FLAGS--------------------------------------
/* # define */
//----------------------------------RETURNS-------------------------------------
/* # define */
//==============================================================================
//----------------------------------STRUCTS-------------------------------------
//==============================================================================
typedef struct ms
{
	uint32_t	color;
	uint32_t	col;
	char		*line;
	char		*file;
	char		**map;
	int			**z;
	void		*mlx;
	void		*win;
	int			offset;
	int			height;
	int			width;
	int			size;
	int			**x;
	int			**y;
	int			bX;
	int			eX;
	int			bY;
	int			eY;
	int			sX;
	int			sY;
	double		ang;
}	t_s;

//==============================================================================
//------------------------------------FDF---------------------------------------
//==============================================================================
//	starts the whole program
int		main(int argc, char *argv[]);
void	get_input(t_s *ms, int fd);
int		start_mlx(t_s *ms);
void	set_values(t_s *ms);
void	draw_line(t_s *ms);
void	draw_raster(t_s *ms);
void	x(t_s *ms);
void	y(t_s *ms);
void	z(t_s *ms);
void	free_ms(t_s *ms);
#endif
