/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:04:13 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/30 15:47:41 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(t_str *s_char, unsigned int start, size_t len)
{
	char	*str;
	char	*s;
	int		i;
	int		s_len;

	i = 0;
	s_len = s_char->len;
	if (!(s_char->s) || start > (unsigned int)s_len)
		return (0);
	s = s_char->s;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	s += start;
	while (len-- && s_len--)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		is_line(t_str *str)
{
	int	i;
	int	len;

	if (!str || !str->s)
		return (-1);
	len = str->len;
	i = 0;
	while (len--)
	{
		if (str->s[i++] == '\n')
			return (i);
	}
	return (-1);
}

int		ft_error(t_str *str, char *line, char *buf)
{
	if (str)
	{
		if(str->s)
			free(str->s);
		free(str);
		str = 0;
	}
	if (line)
		free(line);
	if (buf)
		free(buf);
	buf = 0;
	line = 0;
	return (-1);
}

int		ft_sub_vect(t_str *str, int start, int new_len)
{
	int		i;
	int		l;
	char	*tmp;

	if (!str || start > str->len)
		return (0);
	if(!(tmp = (char *)malloc(sizeof(char) * (new_len + 1))))
		return (0);
	str->len = new_len;
	l = start;
	i = 0;
	while (new_len--)
	{
		tmp[i] = str->s[l];
		l++;
		i++;
	}
	free(str->s);
	str->s = tmp;
	return (1);
}

char	*ft_free(char *str)
{
	free(str);
	return (0);
}
