/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:36:51 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/03 10:54:57 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	getlength_int(unsigned int n)
{
	int				length;
	unsigned int	absn;

	absn = n;
	length = 0;
	while (absn > 0)
	{
		length++;
		absn /= 10;
	}
	return (length);
}

static int	getlength_double(double n)
{
	int		symb;
	double	absn;

	symb = (n <= 0.0) ? 1 : 0;
	absn = ft_f_abs(n);
	while (absn - (int)absn != absn - absn)
		absn *= 10;
	return (getlength_int((int)absn + symb + 1));
}

int			ft_ftoa_p3(char **ch, double absn, int pos_point, int length)
{
	int		length_dou;
	double	p_deci;

	p_deci = absn - (int)absn;
	length_dou = pos_point + 1;
	while (length_dou < length)
	{
		(*ch)[length_dou] = '0' + (int)p_deci % 10;
		p_deci *= 10;
		length_dou++;
	}
	return (pos_point);
}

int			ft_ftoa_p2(char **ch, double absn, int negative)
{
	int	length_int;
	int	pos_point;
	int p_real;

	p_real = (int)absn;
	pos_point = getlength_int((unsigned int)p_real);
	if (negative)
		pos_point++;
	(*ch)[pos_point] = '.';
	length_int = pos_point - 1;
	while (length_int >= 0)
	{
		(*ch)[length_int] = '0' + p_real % 10;
		p_real /= 10;
		length_int--;
	}
	return (pos_point);
}

char		*ft_ftoa(double n)
{
	int		length;
	char	*ch;
	int		negative;
	double	absn;

	if (n - (int)n == n - n)
		return (ft_itoa((int)n));
	length = getlength_double(n);
	negative = (n < 0) ? 1 : 0;
	if ((ch = ft_strnew(length)) == NULL)
		return (NULL);
	if (negative)
		ch[0] = '-';
	absn = ft_f_abs(n);
	negative = ft_ftoa_p2(&ch, absn, negative);
	ft_ftoa_p3(&ch, absn, negative, length);
	ch[length] = '\0';
	return (ch);
}
