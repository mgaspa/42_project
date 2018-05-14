/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:45:16 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/04 16:48:31 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	char		*temp1;
	char		*temp2;
	size_t		i;

	if (n < 1 || dst == src)
		return (NULL);
	temp1 = (char *)dst;
	temp2 = (char *)src;
	i = 0;
	while (i < n)
	{
		temp1[i] = temp2[i];
		if (temp2[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
