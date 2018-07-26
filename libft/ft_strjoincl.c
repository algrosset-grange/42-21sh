/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:30:53 by agrosset          #+#    #+#             */
/*   Updated: 2017/05/19 10:59:24 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoincl(char *s1, char *s2, int free_both)
{
	char	*new;

	if ((new = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	ft_memdel((void**)&s1);
	if (free_both)
		ft_memdel((void**)&s2);
	return (new);
}
