/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:29:02 by llawrenc          #+#    #+#             */
/*   Updated: 2021/10/21 08:58:12 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	buf;

	i = 0;
	k = 0;
	if (needle[k] == '\0')
		return ((char *)haystack);
	while (i < len && haystack [i] != '\0')
	{
		buf = i;
		while (needle[k] == haystack[i] && needle[k] && haystack[i] && i < len)
		{
			i++;
			k++;
		}
		if (needle[k] == '\0')
			return ((char *)&haystack[buf]);
		i = buf + 1;
		k = 0;
	}
	return (NULL);
}
