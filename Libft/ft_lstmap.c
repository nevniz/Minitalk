/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:00:48 by llawrenc          #+#    #+#             */
/*   Updated: 2021/10/24 10:42:56 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_clear(t_list **list, void *del_f)
{
	ft_lstclear(list, del_f);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*new_e;

	if (lst == NULL)
		return (NULL);
	new_e = ft_lstnew(f(lst->content));
	if (new_e == NULL)
		return (ft_clear(&new_e, del));
	new_l = new_e;
	lst = lst->next;
	while (lst != NULL)
	{
		new_e = ft_lstnew(f(lst->content));
		if (new_e == NULL)
			return (ft_clear(&new_l, del));
		ft_lstadd_back(&new_l, new_e);
		new_e = new_e->next;
		lst = lst->next;
	}
	return (new_l);
}
