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

static int	print_pth(char *path)
{
	char	*parsed_home;

	if ((parsed_home = parse_home_path(path, 0)) == NULL)
		return (ERROR);
	ft_putstr(parsed_home);
	ft_memdel((void **)&parsed_home);
	return (0);
}

static void	change_dir_p2(char *path)
{
	ft_putstr("cd: ");
	if (access(path, F_OK) == -1)
		ft_putstr("no such file or directory: ");
	else if (access(path, R_OK) == -1)
		ft_putstr("permission denied: ");
	else
		ft_putstr("not a directory: ");
	ft_putendl(path);
}

int			change_dir(char *path, int print_path)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		if (print_path)
		{
			if (print_pth(path) == ERROR)
				return (ERROR);
			ft_putchar('\n');
		}
		if (set_env_var("OLDPWD", cwd) == ERROR)
			return (ERROR);
	}
	else
		change_dir_p2(path);
	return (0);
}
