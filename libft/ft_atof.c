/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:57:50 by agrosset          #+#    #+#             */
/*   Updated: 2016/04/07 12:21:41 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_after_dot(const char *str)
{
	double			nbr;
	unsigned int	div;

	div = 10;
	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr += (*str - '0') / (double)div;
		div *= 10;
		str++;
	}
	return (nbr);
}

double			ft_atof(const char *str)
{
	double			nbr;
	int				isnegative;

	nbr = 0;
	while (ft_isspace(*str))
		str++;
	isnegative = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = 10 * nbr + *str - '0';
		str++;
	}
	if (*str == '.')
		nbr += get_after_dot(++str);
	nbr *= isnegative;
	return (nbr);
}
