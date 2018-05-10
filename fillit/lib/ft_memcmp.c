/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:56:46 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/04 16:57:43 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*n1;
	unsigned char	*n2;
	size_t			i;

	i = 0;
	n1 = (unsigned char *)s1;
	n2 = (unsigned char *)s2;
	while (n--)
	{
		if (n1[i] != n2[i])
			return (n1[i] - n2[i]);
		if (n)
			i++;
	}
	return (0);
}
