/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:06:07 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/30 13:12:24 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static ssize_t	find_pos(char *str, char c, ssize_t pos)
{
	if (pos == -1)
		pos++;
	while (str[pos])
	{
		if (str[pos] == c)
		{
			return (pos);
		}
		pos++;
	}
	return (-1);
}

static ssize_t	load_buffer(int fd, t_static *s, char **line)
{
	s->bytes_loaded = read(fd, s->buffer, BUFFER_SIZE);
	if (s->bytes_loaded <= 0)
	{
		free(s->buffer);
		s->buffer = NULL;
		if (gnl_ft_strlen(*line) == 0 || s->bytes_loaded == -1)
		{
			free(*line);
			*line = NULL;
		}
	}
	else
	{
		(s->buffer)[s->bytes_loaded] = '\0';
		s->pos0 = 0;
	}
	return (s->bytes_loaded);
}

static char	*calc_line(t_static *s, int fd, char *line)
{
	s->pos1 = find_pos(s->buffer, '\n', s->pos0);
	while (s->pos1 == -1)
	{
		line = gnl_strjoin_free(line, &s->buffer[s->pos0], 1);
		s->bytes_loaded = load_buffer(fd, s, &line);
		if ((s->bytes_loaded == -1) || ((s->bytes_loaded == 0) && !line))
			return (NULL);
		else if (s->bytes_loaded == 0)
			break ;
		s->pos1 = find_pos(s->buffer, '\n', s->pos0);
	}
	line = gnl_strjoin_free(line, \
		gnl_ft_substr(s->buffer, s->pos0, s->pos1 - s->pos0 + 1), 3);
	if (s->bytes_loaded == 0)
		s->pos0 = -1;
	else
		s->pos0 = s->pos1 + 1;
	return (line);
}

static void	initialize_static(t_static store[MAX_FILES_OPEN])
{
	unsigned int	i;

	store[0].init_if = 1;
	i = 0;
	while (i < MAX_FILES_OPEN)
	{
		store[i].pos0 = -1;
		i++;
	}
}

char	*get_next_line(int fd)
{
	char			*line;
	t_static		*s;
	static t_static	store[MAX_FILES_OPEN];

	if (store[0].init_if == 0)
		initialize_static(store);
	s = &store[fd];
	line = NULL;
	if (s->pos0 == -1)
	{
		s->buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!(s->buffer))
			return (NULL);
		s->bytes_loaded = load_buffer(fd, s, &line);
		if (s->bytes_loaded <= 0)
			return (NULL);
	}
	if (s->buffer)
		line = calc_line(s, fd, line);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*str;
	int	flag;

	if (argc != 2)
		return (1);
	flag = 1;
	fd = open(argv[1], O_RDONLY);
	while (flag)
	{
		str = get_next_line(fd);
		if (!str)
		{
			flag = 0;
		}
		printf("%s", str);
		free(str);
	}
}
*/
/*
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd[2];
	char	*str1;
	char	*str2;
	int	flag;

	flag = 1;
	fd[0] = open("test1.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	while (flag)
	{
		str1 = get_next_line(fd[0]);
		str2 = get_next_line(fd[1]);
		if (!str1 && !str2)
		{
			flag = 0;
		}
		if (str1)
			printf("%s", str1);
		if (str2)
			printf("%s", str2);
		if (str1)
			free(str1);
		if (str2)
			free(str2);
	}
}
*/
