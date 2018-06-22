/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:11:47 by mgaspa            #+#    #+#             */
/*   Updated: 2018/06/22 17:18:53 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_fichier(t_list **fichier, int fd)
{
	t_list			*tmp;

	if (*fichier == NULL)
		*fichier = ft_lstnew("", fd);
	tmp = *fichier;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(fichier, tmp);
	tmp = *fichier;
	return (tmp);
}

static int		ft_sendtoline(char **line, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			break ;
	if ((*line = ft_strndup(str, i - 1)) == NULL)
		return (-1);
	return (i);
}

int				faut_savoir_lire(t_list *actualy_reading, int fd, char *buff)
{
	int		ret;
	char	*tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if ((tmp = ft_strjoin(actualy_reading->content, buff)) == NULL)
			return (-1);
		free(actualy_reading->content);
		if ((actualy_reading->content = ft_strdup(tmp)) == NULL)
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ret);
}

int				faut_de_la_place(int ret, t_list *actualy_reading, char **line)
{
	char	*tmp;

	if (ret < BUFF_SIZE && ft_strlen(actualy_reading->content) == 0)
		return (0);
	if ((ret = ft_sendtoline(line, actualy_reading->content)) == -1)
		return (-1);
	if (ret < (int)ft_strlen(actualy_reading->content))
	{
		if ((tmp = ft_strpart(actualy_reading->content, ret + 1)) == NULL)
			return (-1);
		free(actualy_reading->content);
		actualy_reading->content = ft_strdup(tmp);
		free(tmp);
	}
	else
		ft_strclr(actualy_reading->content);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_list	*fichier;
	t_list			*actualy_reading;
	int				ret;

	if (fd < 0 || line == NULL || read(fd, buff, 0 < 0))
		return (-1);
	if ((actualy_reading = get_fichier(&fichier, fd)) == NULL)
		return (-1);
	if ((ret = faut_savoir_lire(actualy_reading, fd, buff)) == -1)
		return (-1);
	return (faut_de_la_place(ret, actualy_reading, line));
}
