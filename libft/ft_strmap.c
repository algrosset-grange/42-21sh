/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:07:24 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/09 16:01:46 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	length;
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	if ((str = ft_strnew(length)) == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
