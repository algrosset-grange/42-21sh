/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt_msg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 04:49:25 by agrosset          #+#    #+#             */
/*   Updated: 2018/07/21 01:04:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(void)
{
	ft_freestrarr(g_envv);
	write(1, "\n", 1);
	exit(0);
}

char	*parse_home_path(char *path, int reverse_parse)
{
	char	*home_path;
	char	*new;

	if (!path)
		return (NULL);
	if (get_env_var("HOME", &home_path) == ERROR)
		return (NULL);
	else if (home_path == NULL)
		return (" ");
	if (!ft_strstartswith(path, reverse_parse ? "~" : home_path))
		return (ft_strdup(path));
	if (reverse_parse)
		new = ft_pathjoin(home_path, path + 1);
	else
	{
		if (*(path + ft_strlen(home_path)) == '\0')
			new = ft_strdup("~");
		else
			new = ft_pathjoin("~", path + ft_strlen(home_path));
	}
	return (new);
}

int		display_prompt_msg(void)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*parsed_cwd;

	cwd = getcwd(buff, 4096);
	if (((cwd = getcwd(buff, 4096)) == NULL)
		|| ((parsed_cwd = parse_home_path(cwd, 0)) == NULL))
		return (ERROR);
	ft_putstr(parsed_cwd);
	free(parsed_cwd);
	ft_putstr(" $> ");
	return (NO_ERROR);
}
