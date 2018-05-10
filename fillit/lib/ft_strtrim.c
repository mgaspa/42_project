/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:32:59 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/09 14:09:08 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cb_debut(char const *s)
{
	int		i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (i);
}

static size_t	ft_cb_fin(char const *s)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		j++;
		i--;
	}
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*sortie;
	size_t	i;
	size_t	j;
	size_t	z;

	if (s == NULL)
		return (NULL);
	i = ft_cb_debut(s);
	if (i == ft_strlen(s))
	{
		sortie = ft_strnew(0);
		return (sortie);
	}
	z = ft_cb_fin(s);
	sortie = ft_strnew(ft_strlen(s) - i - z);
	if (sortie == NULL)
		return (NULL);
	j = 0;
	while (s[i] && i < ft_strlen(s) - ft_cb_fin(s))
	{
		sortie[j] = s[i];
		j++;
		i++;
	}
	return (sortie);
}
