/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubalest <jubalest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:00:50 by jubalest          #+#    #+#             */
/*   Updated: 2015/02/20 09:03:14 by jubalest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_absint(int n)
{
	if (n < 0)
		return (unsigned int)-n;
	else
		return (unsigned int)n;
}
