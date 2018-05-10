/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:56:38 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/09 14:11:51 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sortie;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (start + len > ft_strlen(s))
		return (NULL);
	sortie = ft_strnew(len);
	if (sortie == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sortie[i] = s[start + i];
		i++;
	}
	return (sortie);
}
