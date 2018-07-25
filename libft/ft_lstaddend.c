/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 16:22:40 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/16 16:24:48 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*maillon;

	if (new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		maillon = *alst;
		while (maillon->next != NULL)
			maillon = maillon->next;
		maillon->next = new;
	}
}
