/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:30:47 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/09 12:59:14 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static unsigned int	countparts(char const *s, char c)
{
	int				mode;
	unsigned int	parts;
	unsigned int	i;

	mode = 1;
	parts = 0;
	i = 0;
	while (s[i])
	{
		if (mode == 1 && s[i] != c)
		{
			mode = 0;
			parts++;
		}
		else if (mode == 0 && s[i] == c)
			mode = 1;
		i++;
	}
	return (parts);
}

static unsigned int	getpartlength(char const *s, char c, unsigned int n)
{
	int				mode;
	unsigned int	part;
	unsigned int	len;

	mode = 1;
	part = -1;
	len = 0;
	while (*s)
	{
		if (mode == 1 && *s != c)
		{
			mode = 0;
			part++;
			if (part == n)
				len++;
		}
		else if (mode == 0 && *s != c && part == n)
			len++;
		else if (mode == 0 && *s == c)
			mode = 1;
		if (mode == 1 && len != 0)
			return (len);
		s++;
	}
	return (len);
}

static unsigned int	getpartstart(char const *s, char c, unsigned int n)
{
	int				mode;
	unsigned int	part;
	unsigned int	i;

	mode = 1;
	part = -1;
	i = 0;
	while (s[i])
	{
		if (mode == 1 && s[i] != c)
		{
			mode = 0;
			part++;
			if (part == n)
				return (i);
		}
		else if (mode == 0 && s[i] == c)
			mode = 1;
		i++;
	}
	return (0);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	parts;
	unsigned int	i;

	if (!s)
		return (NULL);
	parts = countparts(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (parts + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < parts)
	{
		if ((tab[i] = ft_strsub(s, getpartstart(s, c, i),
			getpartlength(s, c, i))) == NULL)
		{
			return (tab);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
