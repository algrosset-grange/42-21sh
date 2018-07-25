/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:28:21 by agrosset          #+#    #+#             */
/*   Updated: 2016/04/08 14:18:48 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_isnumber(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	while (ft_isspace(*str))
		str++;
	return (*str == 0);
}
