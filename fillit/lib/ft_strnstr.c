/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:13:42 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/05 11:54:58 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_n;

	if (*needle == '\0')
		return ((char *)haystack);
	len_n = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= len_n)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, len_n) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
