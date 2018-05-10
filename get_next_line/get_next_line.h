/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:45:32 by mgaspa            #+#    #+#             */
/*   Updated: 2018/05/10 20:27:28 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# define BUFF_SIZE 20
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>



typedef struct s_fichier	t_fichier;
struct	s_fichier
{
	int			fd;
	char		buff[BUFF_SIZE];
	int			len;
	t_fichier	*next;
}

int	get_next_line(const int fd, char **line);

