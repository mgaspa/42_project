/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:05:25 by mgaspa            #+#    #+#             */
/*   Updated: 2018/05/10 17:34:05 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	ft_onoff(const t_etris *tetris, uint16_t map[16])
{
	*(uint64_t *)(map + tetris->y) ^= tetris->value >> tetris->x;
}

static void	ft_xy_zero(t_etris *tetris)
{
	tetris->x = 0;
	tetris->y = 0;
}

static int	ft_solvemap(t_etris *tetris, const int size, uint16_t *map)
{
	int pos;

	if (tetris->lettre == 0)
		return (1);
	pos = (tetris->next ? (tetris->next->x + tetris->next->y * size) : 0);
	tetris->y = pos / size;
	while (tetris->y <= size - tetris->hauteur)
	{
		tetris->x = (tetris->y == pos / size ? pos % size : 0);
		while (tetris->x <= size - tetris->largeur)
		{
			if (!(*(uint64_t *)(map + tetris->y) &
						(tetris->value >> tetris->x)))
			{
				ft_onoff(tetris, map);
				if (ft_solvemap(tetris + 1, size, map))
					return (1);
				ft_onoff(tetris, map);
			}
			++tetris->x;
		}
		++tetris->y;
	}
	ft_xy_zero(tetris);
	return (0);
}

int			ft_solve(t_etris *tetris, int nb, uint16_t map[16])
{
	int		size;

	size = 2;
	while (size * size < nb * 4)
		++size;
	while (!ft_solvemap(tetris, size, map) && size <= 16)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		++size;
	}
	if (size == 17)
		return (0);
	return (size);
}
