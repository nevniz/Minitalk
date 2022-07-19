/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:12:52 by llawrenc          #+#    #+#             */
/*   Updated: 2021/10/21 21:30:56 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	search_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] != set[j])
		{
			while (s1[i] != set[j])
			{
				if (j == ft_strlen(set) - 1)
					return (i);
				j++;
			}
		}
		else
		{
			i++;
			j = 0;
		}
	}
	return (i);
}

static size_t	search_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] != set[j])
		{
			while (s1[i] != set[j])
			{
				if (j == ft_strlen(set) - 1)
					return (i);
				j++;
			}
		}
		else
		{
			i--;
			j = 0;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = search_start(s1, set);
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = search_end(s1, set);
	str = malloc(sizeof(char) * (end - start + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
