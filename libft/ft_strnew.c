/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 10:10:24 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/09 13:58:50 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if ((str = (char *)ft_memalloc(size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
