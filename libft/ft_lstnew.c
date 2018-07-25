/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:58:27 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/03 13:13:41 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*content_cpy;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		if ((content_cpy = malloc(content_size)) == NULL)
		{
			free(lst);
			return (NULL);
		}
		lst->content = ft_memcpy(content_cpy, content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
