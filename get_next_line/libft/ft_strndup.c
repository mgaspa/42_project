/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:12:30 by mgaspa            #+#    #+#             */
/*   Updated: 2018/06/22 16:43:24 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	char	*sortie;
	int		i;

	i = 0;
	if ((sortie = ft_strnew(n + 1)) == NULL)
		return (NULL);
	while (i <= n)
	{
		sortie[i] = s[i];
		++i;
	}
	sortie[i] = '\0';
	return (sortie);
}
