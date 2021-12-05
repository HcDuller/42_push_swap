/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:44:01 by hcduller          #+#    #+#             */
/*   Updated: 2021/12/05 00:00:49 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_append(char *base, char *append, int clean_append)
{
	char	*new_str;
	char	*aux;
	char	*freer;

	if (append && base)
	{
		new_str = (char *)ft_calloc(ft_strlen(base) + ft_strlen(append) + 1, 1);
		if (!new_str)
			return (NULL);
		aux = new_str;
		freer = base;
		while (*base)
			*aux++ = *base++;
		while (*append)
		{
			*aux++ = *append;
			if (clean_append)
				*append = (char)0;
			append++;
		}
		free(freer);
		return (new_str);
	}
	return (base);
}

char	*str_pre_pend(char *base, char *pre)
{
	char	*new_str;
	char	*aux;

	if (base && pre)
	{
		new_str = (char *)ft_calloc(ft_strlen(base) + ft_strlen(pre) + 1, 1);
		if (!new_str)
			return (NULL);
		aux = new_str;
		while (*pre)
			*aux++ = *pre++;
		while (*base)
			*aux++ = *base++;
		free(base);
		return (new_str);
	}
	return (base);
}

int	shoul_it_run(int fd, char **line, char **buf, char **t_buf)
{
	if (fd < 0 || !line)
		return (0);
	if (!*buf)
		*buf = (char *)ft_calloc(1, 1);
	if (!*buf)
		return (0);
	*t_buf = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!*t_buf)
	{
		free(*buf);
		return (0);
	}
	return (1);
}

int	str_handler(char **line, char **my_line, int r_size, char **readings)
{
	if (r_size == -1)
	{
		*line = NULL;
		free(*readings);
		free(*my_line);
		return (-1);
	}
	if (r_size == 0)
	{
		free(*readings);
		if (**my_line == 0)
		{
			*line = str_append(*my_line, "", 0);
			*my_line = NULL;
		}
		else
		{
			*line = pre_break(*my_line);
			*my_line = pos_break(*my_line);
		}
		return (0);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*my_line;
	char		*readings;
	int			r_size;

	if (shoul_it_run(fd, line, &my_line, &readings))
	{	
		while (!has_break(my_line))
		{
			r_size = read(fd, readings, BUFFER_SIZE);
			if (r_size <= 0)
				return (str_handler(line, &my_line, r_size, &readings));
			my_line = str_append(my_line, readings, 1);
		}
		*line = pre_break(my_line);
		my_line = pos_break(my_line);
		free(readings);
		return (1);
	}
	return (-1);
}
