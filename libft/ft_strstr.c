/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:36:38 by agrosset          #+#    #+#             */
/*   Updated: 2015/11/29 11:39:15 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;
	size_t i2;
	size_t s2len;

	s2len = ft_strlen(s2);
	if (s2len == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i])
	{
		i2 = 0;
		while (s2[i2])
		{
			if (s1[i + i2] != s2[i2])
				break ;
			i2++;
		}
		if (i2 == s2len)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
