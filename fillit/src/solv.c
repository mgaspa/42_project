#include <header.h>

int	ft_solvemap(t_etris *tetris, int size, uint16_t map[16])
{
	int	pos;

	if (tetris->lettre == 0)
		return (1);
	pos = (tetris->next ? (tetris->next->x + tetris->next->y * size) : 0);
	teris->y = pos /size;
	while (tetris->y++ <= size - tetris->hauteur)
	{
		tetris->x = (tetris->y == pos ? pos % size : 0);
		while (tetris->x++ <= size - tetris->largeur)
			if(!(*(uint64_t *)(map + tetris->y) & (tetris->value >> tetris->x)))
			{
				*(uint64_t *)(map + tetris->y) ^= tetris-> value >> tetris->x;
				if (ft_solvemap(tetris + 1, size, map))
					return (1);
				*(uint64_t *)(map + tetris->y) ^= tetris-> value >> tetris->x;
			}
	}
	tetris->x = 0;
	tetris->y = 0;
	return (0);
}

int	ft_solve(t_etris *tetris, int nb, uint16_t map[16])
{
	int	size;

	size = 2;
	while (size * size <= nb * 4)
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
