/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:39:10 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/05 12:24:49 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*sortie;

	sortie = malloc(size);
	if (sortie == NULL)
		return (NULL);
	ft_bzero(sortie, size);
	return (sortie);
}
