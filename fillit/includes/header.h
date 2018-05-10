/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:52:55 by mgaspa            #+#    #+#             */
/*   Updated: 2018/05/10 16:59:57 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 22

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft.h"

typedef	struct s_etris		t_etris;
struct						s_etris
{
	uint64_t				value;
	unsigned char			lettre;
	unsigned char			x;
	unsigned char			y;
	unsigned char			largeur;
	unsigned char			hauteur;
	t_etris					*next;
};

int							ft_read(int fd, t_etris *tetris, int nb_last);
int							ft_solve(t_etris *tetris, int nb, uint16_t *map);
#endif
