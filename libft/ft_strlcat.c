/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:08:40 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/03 11:48:59 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size > dstlen + 1)
	{
		while (i < (size - dstlen - 1))
		{
			dst[i + dstlen] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
	}
	if (size >= dstlen)
		return (dstlen + srclen);
	return (srclen + size);
}
