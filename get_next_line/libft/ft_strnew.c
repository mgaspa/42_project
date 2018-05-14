/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:42:15 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/05 15:37:17 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*sortie;

	sortie = (char *)malloc(sizeof(char) * (size + 1));
	if (sortie == NULL)
		return (NULL);
	ft_memset(sortie, 0, (sizeof(char) * (size + 1)));
	return (sortie);
}
