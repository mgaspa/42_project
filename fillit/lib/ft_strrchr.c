/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:06:34 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/05 11:07:31 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != (char)c && i != 0)
		i--;
	if (i == 0 && s[i] != (char)c)
		return (NULL);
	while (i != 0)
	{
		s++;
		i--;
	}
	return ((char *)s);
}
