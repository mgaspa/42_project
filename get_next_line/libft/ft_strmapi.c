/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:39:00 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/09 14:03:13 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*sortie;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	sortie = ft_strnew(ft_strlen(s));
	if (sortie == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sortie[i] = f(i, s[i]);
		i++;
	}
	return (sortie);
}
