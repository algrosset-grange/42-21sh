/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 16:22:40 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/16 16:24:48 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list **first)
{
	void	*c;

	c = (*first)->content;
	(*first)->content = (*first)->next->content;
	(*first)->next->content = c;
}

/*
**	void	ft_lstswap(t_list **before)
**	{
**		t_list	*first;
**		t_list	*second;
**
**		first = *before;
**		second = first->next;
**
**		*before = second;
**		first->next = second->next;
**		second->next = first;
**	}
*/
