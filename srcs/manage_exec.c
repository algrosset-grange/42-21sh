/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fork.c									  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubalest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:43:13 by jubalest          #+#    #+#             */
/*   Updated: 2015/12/03 15:43:14 by jubalest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

int			is_exec(const char *command)
{
	struct stat	*st;

	if (access(command, X_OK) == 0)
	{
		if (command && (st = (struct stat *)malloc(sizeof(struct stat))))
		{
			if (stat(command, st) == 0)
			{
				if (S_ISDIR(st->st_mode))
				{
					display_is_directory(command);
					free(st);
					return (0);
				}
			}
			free(st);
			return (1);
		}
	}
	display_permission_denied(command);
	return (0);
}

void		do_exec(const char **str, t_sh *shell,
				char **mock_environ, int mock)
{
	char	**ptr;

	ptr = (char **)str;
	if (mock == 0)
		mock_environ = shell->l_env;
	execve(str[0], ptr, mock_environ);
	ft_putstr_fd("error execve\n", 2);
	exit(2);
}

int			start_exec(const char **str, t_sh *shell,
						char **mock_environ, int mock)
{
	if (is_exec(str[0]) == 0)
		return (0);
	do_exec(str, shell, mock_environ, mock);
	return (1);
}
