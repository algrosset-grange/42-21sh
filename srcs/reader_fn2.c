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

void	init_current_console(t_sh *shell, t_term *end)
{
	display_prompt(shell);
	raw_terminal_mode(shell);
	end->cursor = 1;
	end->c = '\n';
	CONSOLE->line_position = 1;
	CONSOLE->total_lines = 1;
	CONSOLE->char_position = shell->len_ps1;
}

void	end_of_reading(t_sh *shell, char *buf)
{
	default_terminal_mode(shell);
	while (CONSOLE->total_lines-- > 1)
		ft_putchar('\n');
	ft_putchar('\n');
	(void)buf;
}

char	*recurse_get_line(t_sh *shell, char *buf, t_term *end)
{
	ft_strdel(&buf);
	safe_free_term(end);
	return (get_line(shell));
}

char	*end_of_file_recvd(t_sh *shell, char *buf, char *left, int limit)
{
	if (left)
		ft_strdel(&left);
	free(buf);
	if (shell)
		shell->close_program = 1;
	if (limit >= MAX_READ)
		ft_putstr_fd("ERROR max number of characters inside the buffer\n", 2);
	return (NULL);
}
