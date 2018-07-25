/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numullen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:46:35 by agrosset          #+#    #+#             */
/*   Updated: 2017/06/06 12:46:38 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_numullen(unsigned long long n)
{
	unsigned long long	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}
