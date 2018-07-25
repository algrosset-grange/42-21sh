/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:55:51 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/13 18:55:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_multi_free(int a, ...)
{
	va_list args;
	int		i;

	i = 0;
	va_start(args, a);
	while (i < a)
	{
		free(va_arg(args, void*));
		i++;
	}
	va_end(args);
	return (NULL);
}
