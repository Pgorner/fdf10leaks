/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:48:52 by pgorner           #+#    #+#             */
/*   Updated: 2023/01/10 17:52:59 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_values(t_s *ms)
{
	ms->color = 0xFFFFFFFF;
	ms->col = 0xFF1010FF;
	ms->offset = 8;
	ms->width = 0;
	ms->height = 0;
	ms->size = 1000;
	ms->ang = 0.4;
	ms->sX = (WIDTH/2 - ((ms->width/2)* ms->offset));
	ms->sY = (HEIGHT/2 - ((ms->height/2)* ms->offset));
}

int	main(int argc, char *argv[])
{
	t_s		*ms;
	int		i;
	int		fd;

	ms = malloc(sizeof(t_s));
	i = argc;
	ms->file = ft_strdup(argv[1]);
	fd = open(argv[1], O_RDONLY);
	set_values(ms);
	get_input(ms, fd);
	start_mlx(ms);
	free_ms(ms);
	close(fd);
	system("leaks fdf");
	return (0);
}
