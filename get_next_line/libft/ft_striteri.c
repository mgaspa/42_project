/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:45:23 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/09 14:01:11 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	ln;

	if (s != NULL && f != NULL)
	{
		ln = (unsigned int)ft_strlen(s);
		i = 0;
		while (i < ln)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
