/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:32:32 by mgaspa            #+#    #+#             */
/*   Updated: 2018/06/22 16:42:40 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **alst)
{
	while ((*alst)->next != NULL)
	{
		free((*alst)->content);
		free(*alst);
		*alst = (*alst)->next;
	}
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
}
