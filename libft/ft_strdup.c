/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:35:32 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 16:07:28 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*s2;

	len = ft_strlen(s1) + 1;
	if (!(s2 = (char *)ft_memalloc(len)))
		return (NULL);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
