/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:45:44 by mgaspa            #+#    #+#             */
/*   Updated: 2018/05/10 20:27:26 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
static	char	*str;

char	*ft_read(char **str, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	size_t	ret;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		*str = ft_strjoin(*str, buff);
	}
	return (*str);
}

int	get_next_line(const int fd, char **line)
{
	size_t	i;
	char	*tmp;

	if (fd == -1 || line == NULL)
		return (-1);
	if (str == NULL)
	{
		str = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		if (str == NULL)
			return (-1);
	}
	if ((i = read(fd, str, 0)) != 0)
		return (-1);
	str = ft_read(&str, fd)	;
	i = 0;
	if (str[i] != '\0')
	{
		while (str[i] != '\n' && str[i] != '\0')
			++i;
		if (i == 0)
			*line = ft_strdup("");
		else
		{
			*line = ft_strsub(str, 0, i);
			if ((tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1))) == NULL)
				return (-1);
			free(str);
			str = ft_strdup(tmp);
		}
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}
