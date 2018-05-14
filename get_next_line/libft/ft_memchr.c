/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:54:13 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/04 16:55:41 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*sortie;
	unsigned char	chocolat;
	size_t			i;

	i = 0;
	chocolat = (unsigned char)c;
	sortie = (unsigned char *)src;
	while (n--)
	{
		if (sortie[i] == chocolat)
			return (sortie + i);
		i++;
	}
	return (NULL);
}
