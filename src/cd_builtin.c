/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:56:23 by agrosset          #+#    #+#             */
/*   Updated: 2018/07/21 15:10:32 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_two_args_p2(char **args)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*tmp;

	if (args[2])
	{
		ft_putendl("cd: too many arguments");
		return (1);
	}
	cwd = getcwd(buff, 4096);
	if (!(tmp = ft_strreplace(cwd, args[0], args[1])))
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putendl(args[0]);
		ft_memdel((void **)&tmp);
		return (1);
	}
	if (change_dir(tmp, 1))
	{
		ft_memdel((void **)&tmp);
		return (ERROR);
	}
	ft_memdel((void **)&tmp);
	return (1);
}

static int	has_two_args(char **args)
{
	if (args[1])
		return (has_two_args_p2(args));
	return (0);
}

static int	cd_builtin_p2(char **home_path, int ret)
{
	if (change_dir(*home_path, ret) == ERROR)
	{
		ft_memdel((void **)home_path);
		return (ERROR);
	}
	return (1);
}

static int	cd_builtin_p3(char **args, char *home_path)
{
	char	*rep;

	if (ft_strequ(args[0], "--"))
	{
		if (change_dir(home_path, 0))
			return (ERROR);
		return (1);
	}
	else if (args[0][0] == '-' && !args[0][2])
	{
		if (get_env_var("OLDPWD", &rep) == ERROR)
		{
			ft_memdel((void **)&rep);
			return (ERROR);
		}
		else if (rep == NULL)
			return (0);
		return (cd_builtin_p2(&rep, 1));
	}
	if (change_dir(args[0], 0))
		return (ERROR);
	return (0);
}

int			cd_builtin(char **args)
{
	char	*home_path;

	if (get_env_var("HOME", &home_path) == ERROR)
		return (ERROR);
	else if (home_path == NULL)
		return (0);
	if (!args[0])
		return (cd_builtin_p2(&home_path, 0));
	if (has_two_args(args))
	{
		ft_memdel((void **)&home_path);
		return (1);
	}
	else if (cd_builtin_p3(args, home_path) == ERROR)
	{
		ft_memdel((void **)&home_path);
		return (ERROR);
	}
	return (1);
}
