/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 02:06:53 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/09 11:39:21 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# define BUFFER_SIZE 1

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*pre_break(char *str);
char	*pos_break(char *str);
int		has_break(char *p);
int		get_next_line(int fd, char **line);

#endif