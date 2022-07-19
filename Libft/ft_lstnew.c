/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:11:36 by llawrenc          #+#    #+#             */
/*   Updated: 2021/10/22 19:32:34 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_e;

	new_e = (t_list *)malloc(sizeof(t_list));
	if (!new_e)
		return (NULL);
	new_e->content = content;
	new_e->next = NULL;
	return (new_e);
}
