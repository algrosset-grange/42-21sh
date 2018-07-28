/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c										   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubalest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:45:40 by jubalest          #+#    #+#             */
/*   Updated: 2015/12/03 15:45:42 by jubalest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

int		is_print_buf(char *buf)
{
	int	i;

	i = 0;
	while (i < READ)
	{
		if (!ft_isprint(buf[i]) && buf[i] != '\n')
		{
			ft_putstr_fd(
					"ERROR not readable characters inside the buffer\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int		process_signal(t_sh *shell, int catch_signal, t_term *end)
{
	if (catch_signal)
	{
		while (shell->console->total_lines > 1)
		{
			shell->console->total_lines--;
		}
		nobody_from_tail(end);
	}
	return (0);
}

char	*error_get_line(t_sh *shell)
{
	ft_putstr_fd("ERROR: TERM=", 2);
	if (get_env_value("TERM", shell->env))
		ft_putstr_fd(get_env_value("TERM", shell->env), 2);
	ft_putstr_fd(" not valid\n", 2);
	shell->close_program = 1;
	return (NULL);
}

char	*process_if_exist(t_sh *shell, char *buf)
{
	if (shell->close_program || buf == NULL)
	{
		if (buf)
			ft_strdel(&buf);
		buf = ft_strdup("exit");
	}
	return (buf);
}

int		starts_with(const char *pre, const char *str)
{
	size_t	lenpre;
	size_t	lenstr;

	if (pre && str)
	{
		lenpre = ft_strlen(pre);
		lenstr = ft_strlen(str);
		return (lenstr < lenpre ? 0 : ft_strncmp(pre, str, lenpre) == 0);
	}
	return (0);
}
