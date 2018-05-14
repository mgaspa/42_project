/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:25:41 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/09 14:11:00 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sortie;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sortie = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (sortie == NULL)
		return (NULL);
	sortie = ft_strcpy(sortie, s1);
	sortie = ft_strcat(sortie, s2);
	return (sortie);
}
