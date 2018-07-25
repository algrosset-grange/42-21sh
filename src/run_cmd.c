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

int		run_cmd(char *path, char **args)
{
	pid_t	pid;

	if (path == NULL)
		return (ERROR);
	pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (pid == 0)
	{
		if (execve(path, args, g_envv) == -1)
			return (ERROR);
	}
	else if (pid < 0)
	{
		ft_memdel((void **)&path);
		ft_putendl("Fork failed to create a new process.");
		return (-1);
	}
	wait(&pid);
	if (path)
		ft_memdel((void **)&path);
	return (1);
}
