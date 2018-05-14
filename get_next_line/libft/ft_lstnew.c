/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:32:54 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/07 16:14:19 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*sortie;

	sortie = (t_list *)malloc(sizeof(t_list));
	if (sortie == NULL)
		return (NULL);
	if (content == NULL)
	{
		sortie->content = NULL;
		sortie->content_size = 0;
		sortie->next = NULL;
		return (sortie);
	}
	sortie->content = malloc(content_size);
	ft_memcpy(sortie->content, content, content_size);
	sortie->content_size = content_size;
	sortie->next = NULL;
	return (sortie);
}
