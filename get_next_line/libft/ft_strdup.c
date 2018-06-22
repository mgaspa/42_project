/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:00:22 by mgaspa            #+#    #+#             */
/*   Updated: 2018/06/22 15:16:10 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sortie;
	int		i;

	i = 0;
	sortie = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sortie)
		return (NULL);
	while (s[i] != '\0')
	{
		sortie[i] = s[i];
		i++;
	}
	sortie[i] = '\0';
	return (sortie);
}
