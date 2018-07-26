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

static int	is_executable(char *bin_path, struct stat f, char **command)
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

static int	check_bins_p3(char **command, char ***path, int i, char **bin_path)
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

static int	check_bins_p2(char **command, char **path)
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

int			check_bins(char **command)
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
