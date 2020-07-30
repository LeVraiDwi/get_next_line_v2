/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:04:13 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/30 16:21:58 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_vect_cat(t_str *str, char *buf, int len_buf)
{
	char	*tmp;
	int		max_len;
	int		l;
	int		i;

	max_len = str->len + len_buf;
	l = 0;
	i = 0;
	if(!(tmp = (char *)malloc(sizeof(char) * (max_len + 1))))
		return (-1);
	while(str->len--)
		tmp[l++] = str->s[i++];
	i = 0;
	while(len_buf--)
		tmp[l++] = buf[i++];
	tmp[l] = 0;
	str->s = ft_free(str->s);
	str->s = tmp;
	str->len = max_len;
	return(1);
}

int	ft_read(int fd, t_str *str, char *buf)
{
	int	len_buf;

	if ((len_buf = read(fd, buf, BUFFER_SIZE)) == -1)
		return(-1);
	buf[len_buf] = 0;
	if (len_buf)
		if(ft_vect_cat(str, buf, len_buf) == -1)
			return(-1);
	return(len_buf);
}

int	ft_vect_init(t_str **str)
{
	if(!(*str = (t_str *)malloc(sizeof(t_str) * 1)))
		return (0);
	(*str)->len = 0;
	(*str)->s = 0;
	return(1);
}

int	ft_flush(t_str *str, char **line, int len_line)
{
	if (len_line != -1)
	{
		if (!(*line = ft_substr(str, 0, len_line - 1)))
			return (ft_error(str, 0, *line));
		if (!(ft_sub_vect(str, len_line, str->len - len_line)))
			return (ft_error(str, 0, *line));
		return(1);
	}	
	if (str->len == 0)
	{
		if (!(*line = (char *)malloc(sizeof(char ) * 1)))
			return (ft_error(str, 0, *line));
		**line = 0;
	}
	else
	{
		if (!(*line = ft_substr(str, 0, str->len)))
			return (ft_error(str, 0, *line));
	}
	free(str->s);
	free(str);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_str	*str;
	char			*buf;
	int				len_buf;
	int				len_line;

	if (BUFFER_SIZE < 1)
		return (-1);
	if(!(buf = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (ft_error(str, buf, 0));
	if (!str)
		if(!(ft_vect_init(&str)))
			return (ft_error(str, buf, 0));
	len_line = is_line(str);
	while (len_line == -1 && (len_buf = ft_read(fd, str, buf)) > 0)
		len_line = is_line(str);
	if (len_buf == -1)
		return (ft_error(str, buf, *line));
	buf = ft_free(buf);
	return(ft_flush(str, line, len_line));
}
