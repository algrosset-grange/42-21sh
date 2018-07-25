/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:58:27 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/03 13:13:41 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **alst)
{
	t_list	*tmp;
	t_list	*reverse;

	if (alst == NULL)
		return ;
	reverse = NULL;
	tmp = *alst;
	while (tmp != NULL)
	{
		ft_lstadd(&reverse, ft_lstnew(tmp->content, tmp->content_size));
		tmp = tmp->next;
	}
	ft_lstdel(alst, &ft_lstdelcontent);
	*alst = reverse;
	tmp = *alst;
}
