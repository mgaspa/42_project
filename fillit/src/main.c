/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:49:37 by mgaspa            #+#    #+#             */
/*   Updated: 2018/05/10 17:34:12 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static char	*ft_newmap(int size)
{
	char	*str;
	int		x;
	int		y;

	str = ft_strnew((size + 1) * size);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			str[y * (size + 1) + x] = '.';
			++x;
		}
		str[y * (size + 1) + x] = '\n';
		++y;
	}
	return (str);
}

static void	ft_print(t_etris *tetris, int nb, int size)
{
	char	*str;
	int		x;
	int		y;

	str = ft_newmap(size);
	while (nb > 0)
	{
		y = 0;
		while (y < tetris->hauteur)
		{
			x = 0;
			while (x < tetris->largeur)
			{
				if ((tetris->value >> (16 * (y + 1) - 1 - x)) & 1)
					str[(tetris->y + y) * (size + 1) + x + tetris->x] =
						tetris->lettre;
				++x;
			}
			++y;
		}
		--nb;
		++tetris;
	}
	ft_putstr(str);
	ft_strdel(&str);
}

static void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int			main(int argc, char **argv)
{
	t_etris		tetris[27];
	uint16_t	map[16];
	int			nb;
	int			size;
	int			nb_last;

	nb_last = 0;
	if (argc != 2)
		ft_error("usage: ./fillit [file]");
	ft_bzero(tetris, sizeof(t_etris) * 27);
	if ((nb = ft_read(open(argv[1], O_RDONLY), tetris, nb_last)) == 0)
		ft_error("error");
	ft_bzero(map, sizeof(uint16_t) * 16);
	if ((size = ft_solve(tetris, nb, map)) == 0)
		ft_error("error");
	ft_print(tetris, nb, size);
	return (0);
}
