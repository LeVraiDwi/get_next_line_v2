/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:04:05 by tcosse            #+#    #+#             */
/*   Updated: 2020/07/30 16:44:56 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_str
{
	char	*s;
	int		len;
}		t_str;

int		ft_vect_cat(t_str *str, char *buf, int len);
int		ft_sub_vect(t_str *str, int start, int new_len);
int		ft_read(int fd, t_str *str, char *buf);
int		ft_vect_init(t_str	**str);
int		ft_flush(t_str *str, char **line, int len_line);
int		is_line(t_str *str);
int		ft_error(t_str *str, char *line, char *buf);
int		get_next_line(int fd, char **line);
char	*ft_free(char *str);
char	*ft_substr(t_str *s_char, unsigned int start, size_t len);
#endif
