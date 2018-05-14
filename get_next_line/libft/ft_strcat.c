/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:08:15 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/04 17:11:12 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int	i;
	int	n;

	n = 0;
	i = ft_strlen(s1);
	while (s2[n] != '\0')
	{
		s1[i + n] = s2[n];
		n++;
	}
	s1[i + n] = '\0';
	return (s1);
}
