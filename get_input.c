/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:36:36 by pgorner           #+#    #+#             */
/*   Updated: 2023/01/11 17:58:41 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x(t_s *ms)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	ms->x = ft_calloc(sizeof(int), ms->width*ms->height);
	while (i <= ms->height)
		ms->x[i++] = ft_calloc(sizeof(int), ms->width);
	i = 0;
	while (i < ms->height)
	{
		j = 0;
		while (j < ms->width)
		{
			if (j == 0)
				ms->x[i][j] = ms->sX;
			else
				ms->x[i][j] += ms->sX + (ms->offset * j);
			++j;
		}
		++i;
	}
}

void	y(t_s *ms)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	ms->y = ft_calloc(sizeof(int), ms->width*ms->height);
	while (i <= ms->height)
		ms->y[i++] = ft_calloc(sizeof(int), ms->width);
	i = 0;
	while (i < ms->height)
	{
		j = 0;
		while (j < ms->width)
		{
			ms->y[i][j] = ms->sY + (ms->offset * i);
			++j;
		}
		++i;
	}
}

void	get_input(t_s *ms, int fd)
{
	char	*i;
	int		j;
	int		c;
	char	**z;
	char	*tmp;

	j = 0;
	c = 0;
	ms->line = get_next_line(fd);
	i = ms->line;
	z = ft_calloc(sizeof(int), (unsigned long)CHAR_MAX);
	free(z);
	ms->z = malloc(sizeof(int)*ms->size);
	while (c <= ms->size)
		ms->z[c++] = malloc(sizeof(int)*ms->size);
	while (i)
	{
		tmp = ft_strtrim(ms->line, "\n");
		free(ms->line);
		z = ft_split(tmp, ' ');
		free(tmp);
		c = 0;
		/* printf("j%i\n", j); */
		while (z[c] != NULL)
		{
			ms->z[j][c] = ft_atoi(z[c]); // LEAK LEAK LEAK LEAK
			free(z[c]);
			if (j == 0)
				ms->width++;
			c++;
		}
		j++;
		free(z);
		ms->line = get_next_line(fd);
		i = ms->line;
		ms->height++;
	}

	ms->sX = (WIDTH/2 - ((ms->width/2)* ms->offset));
	ms->sY = (HEIGHT/2 - ((ms->height/2)* ms->offset));
	x(ms);
	y(ms);
	close(fd);
}
/* void	get_input(t_s *ms, int fd)
{
	char	*i;

	int		j;
	int		c;
	char	**z;
	char	*tmp;

	j = 0;
	c = 0;
	ms->line = get_next_line(fd);
	i = ms->line;
	z = ft_calloc(sizeof(int), (unsigned long)CHAR_MAX);
	free(z);
	ms->z = ft_calloc(sizeof(int), ms->size);
	while (c <= ms->size)
		ms->z[c++] = ft_calloc(sizeof(int), ms->size);
	while (i)
	{
		tmp = ft_strtrim(ms->line, "\n");
		free(ms->line);
		z = ft_split(tmp, ' ');
		free(tmp);
		c = 0;
		printf("j%i\n", j);
		while (z[c] != NULL)
		{
			ms->z[j][c] = ft_atoi(z[c]); // LEAK LEAK LEAK LEAK
			free(z[c]);
			if (j == 0  && (ft_strchr(z[c], '\n') == 0))
				ms->width++;
			c++;
		}
		j++;
		free(z);
		ms->line = get_next_line(fd);
		i = ms->line;
		ms->height++;
	}
	c = 0;
	while (test[c])
	{
		free(test[c]);
		c++;
	}
	free(test);
	ms->sX = (WIDTH/2 - ((ms->width/2)* ms->offset));
	ms->sY = (HEIGHT/2 - ((ms->height/2)* ms->offset));
	x(ms);
	y(ms);
	close(fd);
}
 */
