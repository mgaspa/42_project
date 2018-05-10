/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:51:38 by mgaspa            #+#    #+#             */
/*   Updated: 2018/05/10 17:37:42 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void		ft_pos(const char *str, char pos[4])
{
	unsigned char i;

	i = 0;
	pos[0] = 3;
	pos[1] = 0;
	pos[2] = 3;
	pos[3] = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < pos[0])
				pos[0] = i % 5;
			if (i % 5 > pos[1])
				pos[1] = i % 5;
			if (i / 5 < pos[2])
				pos[2] = i / 5;
			if (i / 5 > pos[3])
				pos[3] = i / 5;
		}
		++i;
	}
}

static t_etris	ft_get(const char *str, const char lettre)
{
	t_etris	tetris;
	char	pos[4];
	int		x;
	int		y;

	ft_pos(str, pos);
	tetris.largeur = pos[1] - pos[0] + 1;
	tetris.hauteur = pos[3] - pos[2] + 1;
	tetris.lettre = lettre;
	tetris.value = 0;
	tetris.next = NULL;
	y = 0;
	while (y < tetris.hauteur)
	{
		x = 0;
		while (x < tetris.largeur)
		{
			if (str[(pos[0] + x) + (pos[2] + y) * 5] == '#')
				tetris.value |= (1L << (16 * (y + 1) - 1 - x));
			++x;
		}
		++y;
	}
	return (tetris);
}

static int		ft_connec(const char *str)
{
	int connec;
	int i;

	connec = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				++connec;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				++connec;
			if ((i + 5) < 20 && str[i + 5] == '#')
				++connec;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				++connec;
		}
		++i;
	}
	if (connec == 6 || connec == 8)
		return (1);
	return (0);
}

int				ft_check(char *str, int nb)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++count > 4)
				return (1);
		}
		else if (str[i] != '\n')
			return (1);
		++i;
	}
	if (nb == 21 && str[20] != '\n')
		return (1);
	if (!ft_connec(str))
		return (1);
	return (0);
}

int				ft_read(const int fd, t_etris *tetris, int nb_last)
{
	char	buf[22];
	int		nb;
	int		i;
	int		j;
	char	lettre;

	lettre = 'A';
	i = 0;
	while ((nb = read(fd, buf, 21)) >= 20)
	{
		if (ft_check(buf, nb) != 0)
			return (0);
		tetris[i] = ft_get(buf, lettre++);
		j = i;
		while (--j >= 0)
			if (tetris[j].value == tetris[i].value)
				tetris[i].next = tetris + j;
		++i;
		nb_last = nb;
	}
	if (nb != 0 || nb_last != 20)
		return (0);
	return (lettre - 'A');
}
