/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:16:55 by agrosset          #+#    #+#             */
/*   Updated: 2018/07/20 20:38:04 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			get_env_var(char *var, char **rep)
{
	int		i;
	char	*tmp;

	i = -1;
	*rep = NULL;
	while (g_envv[++i])
	{
		if ((tmp = ft_strjoinch(var, '=')) == NULL)
			return (ERROR);
		if (ft_strstartswith(g_envv[i], tmp))
		{
			ft_memdel((void **)&tmp);
			*rep = ft_strchr(g_envv[i], '=') + 1;
			return (0);
		}
		ft_memdel((void **)&tmp);
	}
	return (1);
}

static char	**ft_free_realloc(int i, char ***new)
{
	int a;

	a = -1;
	while (*(new[++a]))
	{
		ft_memdel((void **)&(*new[a]));
	}
	while (g_envv[++i])
	{
		ft_memdel((void **)&(g_envv[i]));
	}
	ft_memdel((void **)&g_envv);
	ft_memdel((void **)&new);
	return (NULL);
}

char		**realloc_envv(int new_size)
{
	char	**new;
	int		i;

	if ((new = (char **)ft_memalloc(sizeof(char *) * (new_size + 1))) == NULL)
		return (NULL);
	i = -1;
	while (g_envv[++i] && i < new_size)
	{
		if ((new[i] = ft_strdup(g_envv[i])) == NULL)
			return (ft_free_realloc(i, &new));
		ft_memdel((void **)&(g_envv[i]));
	}
	ft_memdel((void **)&(g_envv));
	return (new);
}

int			setenv_builtin(char **args)
{
	if (!args[0])
	{
		print_env();
		return (1);
	}
	if (args[1])
	{
		if (args[2])
		{
			ft_putendl("setenv: Too many arguments.");
			return (1);
		}
	}
	if (set_env_var(args[0], args[1]) == ERROR)
		return (ERROR);
	return (1);
}
