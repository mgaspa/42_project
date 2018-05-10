/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:34:08 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/04 16:37:53 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = n;
	temp = (unsigned char*)s;
	while (n > 0)
	{
		*temp = '\0';
		n--;
		temp++;
	}
	while (i > n)
	{
		n++;
		s--;
	}
	temp = s;
}
