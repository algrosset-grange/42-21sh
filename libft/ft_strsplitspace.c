/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:18:35 by agrosset          #+#    #+#             */
/*   Updated: 2017/05/11 00:24:28 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_word_len(char const *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (IS_SPACE(str[i]))
		i++;
	while (!IS_SPACE(str[i]) && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplitspace(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	**str2;
	int		countwords;

	if (!s || !(str2 = (char **)ft_memalloc(sizeof(*str2) *
				(countwords = ft_countwordsspace(s)) + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < countwords)
	{
		k = 0;
		if (!(str2[i] = ft_strnew(get_word_len(&s[j]) + 1)))
			return (ft_memdeltabchar(str2, countwords));
		while (IS_SPACE(s[j]))
			j++;
		while (!IS_SPACE(s[j]) && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = NULL;
	return (str2);
}
