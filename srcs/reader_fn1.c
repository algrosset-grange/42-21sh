/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   reader.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jubalest <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2015/12/03 15:45:40 by jubalest		  #+#	#+#			 */
/*   Updated: 2015/12/03 15:45:42 by jubalest		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

char	*compile(char *left, char *buf)
{
	char	*tmp;

	tmp = buf;
	buf = ft_strjoin(left, buf);
	free(tmp);
	ft_strdel(&left);
	return (buf);
}

void	again(char *buf)
{
	ft_strclr(buf);
}

char	*move_and_clean(char *buf)
{
	char	*left;
	int		i;

	i = 0;
	left = ft_strdup(buf);
	while (i < READ - 1)
	{
		buf[i] = '\0';
		i++;
	}
	return (left);
}
