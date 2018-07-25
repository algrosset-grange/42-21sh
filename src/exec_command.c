/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 05:44:00 by agrosset          #+#    #+#             */
/*   Updated: 2018/07/21 01:01:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_executable(char *bin_path, struct stat f, char **command)
{
	if (f.st_mode & S_IFREG)
	{
		if (f.st_mode & S_IXUSR)
			return (run_cmd(bin_path, command));
		else
		{
			ft_putstr("minishell: permission denied: ");
			ft_putendl(bin_path);
		}
		ft_memdel((void **)&bin_path);
		return (1);
	}
	ft_memdel((void **)&bin_path);
	return (0);
}

static int		check_bins_p3(char **command, char ***path, int i,
	char **bin_path)
{
	if (ft_strstartswith(command[0], (*path)[i]))
	{
		if ((*bin_path = ft_strdup(command[0])) == NULL)
		{
			ft_freestrarr(*path);
			return (ERROR);
		}
	}
	else if ((*bin_path = ft_pathjoin((*path)[i], command[0])) == NULL)
	{
		ft_freestrarr(*path);
		return (ERROR);
	}
	return (0);
}

static int		check_bins_p2(char **command, char **path)
{
	int			i;
	struct stat	f;
	char		*bin_path;

	i = -1;
	while (path && path[++i])
	{
		if (check_bins_p3(command, &path, i, &bin_path) == ERROR)
			return (ERROR);
		if (lstat(bin_path, &f) == -1)
			ft_memdel((void **)&bin_path);
		else
		{
			ft_freestrarr(path);
			return (is_executable(bin_path, f, command));
		}
	}
	ft_freestrarr(path);
	return (0);
}

static int		check_bins(char **command)
{
	char			**path;
	char			*rep;

	rep = NULL;
	if (get_env_var("PATH", &rep) == ERROR)
	{
		ft_memdel((void **)&rep);
		return (ERROR);
	}
	else if (rep == NULL)
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(command[0]);
		return (1);
	}
	else
	{
		if ((path = ft_strsplit(rep, ':')) == NULL)
			return (ERROR);
	}
	return (check_bins_p2(command, path));
}

static int		check_builtins(char **command)
{
	if (ft_strequ(command[0], "exit"))
		return (-1);
	else if (ft_strequ(command[0], "echo"))
		return (echo_builtin(command + 1));
	else if (ft_strequ(command[0], "cd"))
		return (cd_builtin(command + 1));
	else if (ft_strequ(command[0], "setenv"))
		return (setenv_builtin(command + 1));
	else if (ft_strequ(command[0], "unsetenv"))
		return (unsetenv_builtin(command + 1));
	else if (ft_strequ(command[0], "env"))
	{
		print_env();
		return (1);
	}
	return (0);
}

int				exec_command(char **command)
{
	struct stat	f;
	int			is_builtin;
	int			berror;

	if ((is_builtin = check_builtins(command)) == 1
		|| ((berror = check_bins(command)) && berror != ERROR))
		return (0);
	if (is_builtin == ERROR || berror == ERROR)
		return (ERROR);
	if (is_builtin < 0)
		return (-1);
	if (lstat(command[0], &f) != -1)
	{
		if (f.st_mode & S_IFDIR)
		{
			if (change_dir(command[0], 0))
				return (ERROR);
			return (0);
		}
		else if (f.st_mode & S_IXUSR)
			return (run_cmd(ft_strdup(command[0]), command));
	}
	ft_putstr("minishell: command not found: ");
	ft_putendl(command[0]);
	return (0);
}
