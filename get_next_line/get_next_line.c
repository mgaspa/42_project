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

static t_fichier	ft_fopen(const int fd)
{
	t_fichier	fichier;

	fichier.fd = fd;
	ft_bzero(fichier.buff, (sizeof(char) * BUFF_SIZE));
	fichier.len = 0;
	fichier.next = NULL;

	open(fd, O_RDONLY);
	return (fichier);
}

int	get_next_line(const int fd, char **line)
{
	t_fichier *fichier;


