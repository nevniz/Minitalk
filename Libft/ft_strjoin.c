/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:53:49 by llawrenc          #+#    #+#             */
/*   Updated: 2021/10/20 19:52:43 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	news1 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (news1 == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		news1[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		news1[i++] = s2[j++];
	news1[i] = '\0';
	return (news1);
}
