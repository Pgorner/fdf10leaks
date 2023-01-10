/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:17:15 by pgorner           #+#    #+#             */
/*   Updated: 2023/01/10 17:45:22 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_s *ms)
{
	int pixels;
	double	deltaX;
	double	deltaY;
	double	pixelX;
	double	pixelY;

	deltaX = ms->eX - ms->bX;
	deltaY = ms->eY - ms->bY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = ms->bX;
	pixelY = ms->bY;
	while (pixels)
	{
		if ((pixelX > 1 && pixelX < WIDTH - 1)
			&& (pixelY > 1 && pixelY < HEIGHT - 1))
			mlx_put_pixel(ms->win, pixelX, pixelY, ms->color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void	draw(t_s *ms)
{
	int	i;
	int	j;

	j = 0;

	while (j < ms->height)
	{
		i = 0;
		while (i < ms->width)
		{
			ms->bX = (ms->x[j][i]*cos(ms->ang)) - (ms->y[j][i]*cos(ms->ang));
			ms->bY = (ms->x[j][i]*sin(ms->ang)) + (ms->y[j][i]*sin(ms->ang)) - ms->z[j][i];
			ms->eX = (ms->x[j][i + 1]*cos(ms->ang)) - (ms->y[j][i + 1]*cos(ms->ang));
			ms->eY = (ms->x[j][i + 1]*sin(ms->ang)) + (ms->y[j][i + 1]*sin(ms->ang)) - ms->z[j][i + 1];
			if (i < ms->width - 1)
			{
				if (ms->z[j][i] != 0 || ms->z[j][i + 1] != 0)
					ms->color = ms->col;
				draw_line(ms);
				ms->color = 0xFFFFFFFF;
			}
			ms->bX = (ms->x[j][i]*cos(ms->ang)) - (ms->y[j][i]*cos(ms->ang));
			ms->bY = (ms->x[j][i]*sin(ms->ang)) + (ms->y[j][i]*sin(ms->ang)) - ms->z[j][i];
			ms->eX = (ms->x[j + 1][i]*cos(ms->ang)) - (ms->y[j + 1][i]*cos(ms->ang));
			ms->eY = (ms->x[j + 1][i]*sin(ms->ang)) + (ms->y[j + 1][i]*sin(ms->ang)) - ms->z[j + 1][i];
			if (j < ms->height - 1)
			{
				if (ms->z[j][i] != 0 || ms->z[j + 1][i] != 0)
					ms->color = ms->col;
				draw_line(ms);
				ms->color = 0xFFFFFFFF;
			}
			i++;
		}
		++j;
	}
}
/* void	draw(t_s *ms)
{
	int	i;
	int	j;

	j = 0;
	ms->ang = 0.4;
	while (j < ms->height)
	{
		i = 0;
		while (i < ms->width)
		{
			ms->bX = ms->x[j][i];
			ms->bY = ms->y[j][i];
			ms->eX = ms->x[j][i + 1];
			ms->eY = ms->y[j][i + 1];
			if (i < ms->width - 1)
			{
				if (ms->z[j][i] != 0 || ms->z[j][i + 1] != 0)
					ms->color = ms->col;
				draw_line(ms);
				ms->color = 0xFFFFFFFF;
			}
			ms->bX = ms->x[j][i];
			ms->bY = ms->y[j][i];
			ms->eX = ms->x[j + 1][i];
			ms->eY = ms->y[j + 1][i];
			//printf("line between x(j%ii%i) %i and x1(j%ii%i) %i\n",j, i, ms->x[j][i],j+1, i, ms->x[j + 1][i]);
			if (j < ms->height - 1)
			{
				if (ms->z[j][i] != 0 || ms->z[j + 1][i] != 0)
					ms->color = ms->col;
				draw_line(ms);
				ms->color = 0xFFFFFFFF;
			}
			i++;
		}
		++j;
	}
} */

void	free_ms(t_s *ms)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i <= ms->height)
	{
			free(ms->x[i]);
			free(ms->y[i]);
			/* free(ms->z[i]); */
		++i;
	}
	free(ms->x);
	free(ms->y);
/* 	free(ms->z); */
/* 	free(ms->file); */
}

void	safe_exit(t_s *ms)
{
	mlx_close_window(ms->mlx);
	mlx_terminate(ms->mlx);
	free_ms(ms);
	system("leaks fdf");
	exit(EXIT_SUCCESS);
}

void	key_input(void *tmp)
{
	t_s	*ms;

	ms = (t_s *)tmp;
	if (mlx_is_key_down(ms->mlx, MLX_KEY_ESCAPE))
		safe_exit(ms);
}



int	start_mlx(t_s *ms)
{
	ms->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	ms->win = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(ms->mlx, ms->win, 0 , 0);
	draw(ms);
	mlx_loop_hook(ms->mlx, key_input, ms);
	mlx_loop(ms->mlx);
	mlx_terminate(ms->mlx);
	free_ms(ms);
	return (EXIT_SUCCESS);
}
