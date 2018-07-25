/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:16:55 by agrosset          #+#    #+#             */
/*   Updated: 2018/07/20 20:38:04 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			find_env_var(char *var)
{
	int		i;
	char	*tmp;

	i = -1;
	while (g_envv[++i])
	{
		if ((tmp = ft_strjoinch(var, '=')) == NULL)
			return (ERROR);
		if (ft_strstartswith(g_envv[i], tmp))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
	}
	return (i);
}

static int	set_env_var_p3(int pos, char *value, char *key, char *tmp)
{
	if (value)
	{
		if ((g_envv[pos] = ft_strjoin(key, tmp)) == NULL)
			return (ERROR);
	}
	else if ((g_envv[pos] = ft_strjoin(key, "=")) == NULL)
		return (ERROR);
	return (0);
}

static int	set_env_var_p2(int pos, char *value, char *key, char *tmp)
{
	if (g_envv[pos])
	{
		ft_memdel((void **)&(g_envv[pos]));
		if (set_env_var_p3(pos, value, key, tmp) == ERROR)
		{
			ft_memdel((void **)&tmp);
			return (ERROR);
		}
	}
	else
	{
		if ((g_envv = realloc_envv(pos + 1)) == NULL)
		{
			ft_memdel((void **)&tmp);
			return (ERROR);
		}
		if (set_env_var_p3(pos, value, key, tmp) == ERROR)
		{
			ft_memdel((void **)&tmp);
			return (ERROR);
		}
	}
	return (0);
}

int			set_env_var(char *key, char *value)
{
	int		pos;
	char	*tmp;

	pos = find_env_var(key);
	if ((tmp = ft_strjoin("=", value)) == NULL)
		return (ERROR);
	if (set_env_var_p2(pos, value, key, tmp) == ERROR)
		return (ERROR);
	ft_memdel((void **)&tmp);
	return (0);
}
