/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwordsspace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 15:17:40 by agrosset          #+#    #+#             */
/*   Updated: 2017/05/11 00:23:19 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwordsspace(char const *str)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (IS_SPACE(str[i]))
			i++;
		if (!IS_SPACE(str[i]) && str[i] != '\0')
			count++;
		while (!IS_SPACE(str[i]) && str[i] != '\0')
			i++;
	}
	return (count);
}
