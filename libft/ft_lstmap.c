/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_lstmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:47:34 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/10 12:13:00 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*tmp2;

	if (f == NULL || lst == NULL)
		return (NULL);
	tmp = (*f)(lst);
	if ((new = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		return (NULL);
	lst = lst->next;
	tmp2 = new;
	while (lst)
	{
		tmp = (*f)(lst);
		if ((tmp2->next = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
			return (NULL);
		lst = lst->next;
		tmp2 = tmp2->next;
	}
	return (new);
}
