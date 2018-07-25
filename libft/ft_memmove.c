/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:00:58 by agrosset          #+#    #+#             */
/*   Updated: 2015/11/29 11:23:02 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*srce;
	unsigned char	*dest;

	i = 0;
	srce = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if ((tmp = ft_memalloc(len)) == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = srce[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dest[i] = tmp[i];
		i++;
	}
	ft_memdel((void **)&tmp);
	return (dst);
}
