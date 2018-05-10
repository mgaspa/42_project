#include <header.h>

static char	*ft_newmap(int size)
{
	char	*str;
	int	x;
	int	y;

	str = ft_strnew((size + 1) * size);
	y = -1;
	while (++y < size && (x = -1))
	{
		while (++x < size)
			str[y * (size + 1) + x] = '.';
		str[y * (size + 1) +x] = '\n';
	}
	return (str);
}

static void	ft_print(t_etris *tetris, int nb, int size)
{
	char	*str;
	int	x;
	int	y;

	str = ft_newmap(size);
	while (--nb >= 0 && (y = -1))
	{
		while (++y < tetris->hauteur && (x = -1))
			while (++x < tetris->largeur)
				if (tetris->value >> (16 * (y + 1) - 1 -x)) & 1)
					str[(tetris->y + y) * (size + 1) + x + tetris->x] = tetris->lettre;
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

int		main(int argc, char **argv)
{
	t_etris		tetris[27];
	uint16_t	map[16];
	int		nb;
	int		size;

	if (argc != 2)
		ft_error("usage: ./fillit [file]");
	ft_bzero(tetris, sizeof(t_etris) * 27);
	if ((nb = ft_read(open(argv[1], O_RDONLY), tetris)) == 0)
		ft_error("error");
	ft_bzero(map, sizeof(uint16_t) * 16);
	if ((size = ft_solve(tetris, nb, map)) == 0)
		ft_error("error");
	ft_print(tetri, nb, size);
	return (0);
}

