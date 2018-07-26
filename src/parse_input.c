/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 04:17:47 by agrosset          #+#    #+#             */
/*   Updated: 2018/07/21 01:04:34 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*parse_env_var(char *str, int pos)
{
	char	*value;
	char	*key;
	char	c;

	if ((key = ft_strnew(1)) == NULL)
		return (NULL);
	while (str[pos] && !IS_SPACE(str[pos]))
	{
		c = str[pos];
		if ((key = ft_strjoinchcl(key, c)) == NULL)
		{
			ft_memdel((void **)&key);
			return (NULL);
		}
		pos++;
	}
	if (get_env_var(key, &value) == ERROR)
	{
		ft_memdel((void **)&key);
		return (NULL);
	}
	ft_memdel((void **)&key);
	if (value == NULL)
		return ("");
	return (value);
}

static char	*ft_return_false(char **input, char **new)
{
	ft_memdel((void **)input);
	ft_memdel((void **)new);
	return (NULL);
}

static char	*parse_input_p2(char *input, int *i, char **new)
{
	if (input[*i] == '$' && input[*i + 1])
	{
		if ((*new = ft_strjoincl(*new, parse_env_var(input, *i + 1), 0))
			== NULL)
			return (ft_return_false(&input, new));
		while (input[*i + 1] && !IS_SPACE(input[*i + 1]) &&
			input[*i + 1] != '$')
			(*i)++;
	}
	else if (((*i != 0 && IS_SPACE(input[*i - 1])) || *i == 0) &&
		input[*i] == '~')
	{
		if ((*new = ft_strjoincl(*new, parse_home_path(input + *i, 1), 1))
			== NULL)
			return (ft_return_false(&input, new));
		*i += ft_strlen(input + *i) - 1;
	}
	else if ((*new = ft_strjoinchcl(*new, input[*i])) == NULL)
		return (ft_return_false(&input, new));
	return ((char *)1);
}

char		*parse_input(char *input)
{
	int		i;
	char	*new;

	i = -1;
	if ((new = ft_strnew(1)) == NULL)
		return (NULL);
	while (input[++i])
		if (parse_input_p2(input, &i, &new) == NULL)
			return (NULL);
	ft_memdel((void **)&input);
	return (new);
}
