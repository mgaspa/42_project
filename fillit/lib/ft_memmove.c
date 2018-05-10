/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:49:28 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/04 16:52:48 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*desti;
	char	*source;

	desti = (char*)dst;
	source = (char*)src;
	if (source < desti)
		while (len--)
			desti[len] = source[len];
	else
		ft_memcpy(desti, source, len);
	return (desti);
}
