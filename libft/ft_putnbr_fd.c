/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:18:39 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/03 11:48:35 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char c;

	c = '0';
	if (n < 0)
	{
		write(fd, "-", 1);
		c -= (n % 10);
		if (n < -9)
			ft_putnbr_fd(-(n / 10), fd);
		write(fd, &c, 1);
	}
	if (n > 0)
	{
		c += n % 10;
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
	else if (n == 0)
		write(fd, &c, 1);
}
