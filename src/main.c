/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 04:17:47 by agrosset          #+#    #+#             */
/*   Updated: 2018/07/21 01:04:34 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_input_p2(char **input, char buf, int *i, int *count)
{
	(*input)[(*i)++] = buf;
	if ((*input = ft_realloc(*input, *count, *count + 1)) == NULL)
	{
		ft_memdel((void **)input);
		return (ERROR);
	}
	(*count)++;
	return (0);
}

static int	get_input(char **input)
{
	int		ret;
	char	buf;
	int		i;
	int		count;

	if ((*input = ft_strnew(1)) == NULL)
		return (ERROR);
	count = 1;
	i = 0;
	while ((ret = read(0, &buf, 1)) && buf != '\n')
		if (get_input_p2(input, buf, &i, &count) == ERROR)
			return (ERROR);
	*(*input + i) = '\0';
	if (!ret)
	{
		ft_memdel((void **)input);
		exit_shell();
	}
	if ((ft_strchr(*input, '$') != NULL) || (ft_strchr(*input, '~') != NULL))
		if ((*input = parse_input(*input)) == NULL)
			return (ERROR);
	return (1);
}

int			exec_commands(char **commands)
{
	int		i;
	int		ret;
	char	**command;

	i = -1;
	ret = 0;
	while (commands[++i])
	{
		if ((command = ft_strsplitspace(commands[i])) == NULL)
			return (ERROR);
		if ((ret = exec_command(command)) == ERROR)
			return (ret);
		ft_freestrarr(command);
		if (ret == -1)
			break ;
	}
	return (ret);
}

int			take_command(char ***commands)
{
	char	*input;

	if (display_prompt_msg() == ERROR)
	{
		ft_freestrarr(*commands);
		return (ERROR);
	}
	signal(SIGINT, signal_handler);
	get_input(&input);
	if (ft_isemptystr(input, 1))
	{
		free(input);
		return (NO_COMMAND);
	}
	*commands = ft_strsplit(input, ';');
	ft_memdel((void **)&input);
	return (NO_ERROR);
}

int			main(int ac, char **av, char **envv)
{
	int		ret;
	char	**commands;
	int		i;

	if (init_envv(ac, av, envv) == ERROR)
		return (0);
	while (1)
	{
		if ((i = take_command(&commands)) != NO_ERROR)
		{
			if (i == ERROR)
				break ;
			else
				continue ;
		}
		ret = exec_commands(commands);
		ft_freestrarr(commands);
		if (ret == -1 || ret == ERROR)
			break ;
	}
	ft_freestrarr(g_envv);
	return (0);
}
