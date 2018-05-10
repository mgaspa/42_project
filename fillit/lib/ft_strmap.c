/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:59:41 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/09 14:11:19 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*sortie;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	sortie = ft_strnew(ft_strlen(s));
	if (sortie == NULL)
		return (NULL);
	i = 0;
	sortie = ft_strcpy(sortie, s);
	while (sortie[i])
	{
		sortie[i] = f(s[i]);
		i++;
	}
	return (sortie);
}
