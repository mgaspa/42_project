/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:42:04 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/04 16:44:53 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*temp1;
	char	*temp2;
	size_t	i;

	if (n < 1 || dst == src)
		return (dst);
	temp1 = (char *)dst;
	temp2 = (char *)src;
	i = 0;
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (dst);
}
