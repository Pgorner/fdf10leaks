void	width(t_s *ms)
{
	char	**res;
	char	*str;
	char	*tmp;
	int		i;
	int		fd;

	i = 0;
	ms->width = 0;
	ms->height = 0;
	fd = open(ms->file, O_RDONLY);
	tmp = get_next_line(fd);
	str = ft_strtrim(tmp, "\n");
	while (tmp)
	{
		tmp = get_next_line(fd);
		ms->height++;
	}
	free(tmp);
	res = ft_split(str, ' ');
	free(str);
	while (res[i] != NULL)
	{
		free(res[i]);
		ms->width += 1;
		i++;
	}
	free(res);
}
