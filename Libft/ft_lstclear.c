/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:41:47 by llawrenc          #+#    #+#             */
/*   Updated: 2021/10/22 21:27:37 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*temp;

	temp = *lst;
	if (lst && del)
	{
		while (temp)
		{
			p = temp->next;
			del(temp->content);
			free(temp);
			temp = p;
		}
		*lst = NULL;
	}
}
