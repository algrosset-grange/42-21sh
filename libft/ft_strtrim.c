/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:14:48 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/09 12:43:45 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static size_t	getstart(char const *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			return (i);
		}
		i++;
	}
	return (0);
}

static size_t	getend(char const *s)
{
	size_t i;

	i = ft_strlen(s);
	if (i == 0)
		return (0);
	i--;
	while (i > 0)
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			return (i);
		}
		i--;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*ch;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len == 0)
		return (ft_strdup(s));
	start = getstart(s);
	end = getend(s);
	if (start == 0 && end == 0)
		return (ft_strdup(""));
	if ((start == 0 && end == ft_strlen(s)))
		ch = ft_strdup(s);
	else
		ch = ft_strsub(s, (unsigned int)start, end - start + 1);
	if (ch == NULL)
		return (NULL);
	return (ch);
}
