/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:30:57 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/05 12:36:54 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		sortie;

	sortie = 0;
	neg = 1;
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
				|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		sortie = sortie * 10 + str[i] - '0';
		i++;
	}
	return (sortie * neg);
}
