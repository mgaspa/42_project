/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:18:46 by mgaspa            #+#    #+#             */
/*   Updated: 2018/04/09 14:07:39 by mgaspa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nb_mot(char const *s, char c)
{
	int		sortie;
	int		new;

	new = 0;
	sortie = 0;
	while (*s != '\0')
	{
		if (new == 1 && *s == c)
			new = 0;
		if (new == 0 && *s != c)
		{
			new = 1;
			sortie++;
		}
		s++;
	}
	return (sortie);
}

static	int		ft_lenmot(char const *s, char c)
{
	int		sortie;

	sortie = 0;
	while (*s != c && *s != '\0')
	{
		sortie++;
		s++;
	}
	return (sortie);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb_mot;
	char	**sortie;

	if (s == NULL)
		return (NULL);
	i = 0;
	nb_mot = ft_nb_mot(s, c);
	sortie = (char **)malloc(sizeof(char *) * (nb_mot + 1));
	if (sortie == NULL)
		return (NULL);
	while (nb_mot--)
	{
		while (*s == c && *s != '\0')
			s++;
		sortie[i] = ft_strsub(s, 0,
				ft_lenmot(s, c));
		if (sortie[i] == NULL)
			return (NULL);
		s = s + ft_lenmot(s, c);
		i++;
	}
	sortie[i] = NULL;
	return (sortie);
}
