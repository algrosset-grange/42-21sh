/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdeltabchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:18:35 by agrosset          #+#    #+#             */
/*   Updated: 2017/05/11 00:24:28 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdeltabchar(char **str, int countwords)
{
	int	i;

	i = -1;
	while (++i <= countwords)
		ft_memdel((void **)&(str[i]));
	ft_memdel((void **)&str);
	return (NULL);
}
