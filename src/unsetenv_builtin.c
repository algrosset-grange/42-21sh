/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:35:14 by agrosset          #+#    #+#             */
/*   Updated: 2018/07/21 01:33:22 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_env(void)
{
	int		i;

	i = -1;
	while (g_envv[++i])
		ft_putendl(g_envv[i]);
}

static int	envv_len(char **envv)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (envv[++i])
		count++;
	return (count);
}

int			init_envv(int ac, char **av, char **envv)
{
	int		i;

	(void)ac;
	(void)av;
	if ((g_envv = (char **)ft_memalloc(sizeof(char *) * (envv_len(envv) + 1)))
		== NULL)
		return (ERROR);
	i = -1;
	while (envv[++i])
	{
		if (!(g_envv[i] = ft_strdup(envv[i])))
			exit_shell();
	}
	return (0);
}

static int	remove_env_var(int var_pos)
{
	int		i;
	int		var_count;

	ft_memdel((void **)&(g_envv[var_pos]));
	g_envv[var_pos] = NULL;
	i = var_pos;
	var_count = var_pos + 1;
	while (g_envv[i + 1])
	{
		if ((g_envv[i] = ft_strdup(g_envv[i + 1])) == NULL)
			return (ERROR);
		ft_memdel((void **)&(g_envv[i + 1]));
		i++;
		var_count++;
	}
	if ((g_envv = realloc_envv(var_count - 1)) == NULL)
		return (ERROR);
	return (0);
}

int			unsetenv_builtin(char **args)
{
	int			i;
	int			var_pos;

	if (!args[0])
	{
		ft_putendl("unsetenv: Too few arguments.");
		return (1);
	}
	i = -1;
	while (args[++i])
	{
		if ((var_pos = find_env_var(args[i])) == ERROR)
			return (ERROR);
		if (g_envv[var_pos])
			if (remove_env_var(var_pos) == ERROR)
				return (ERROR);
	}
	return (1);
}
