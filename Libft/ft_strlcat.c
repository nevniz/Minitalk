/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:53:50 by llawrenc          #+#    #+#             */
/*   Updated: 2021/10/17 15:41:53 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	lensrc;
	size_t	lendst;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (dstsize < lendst)
		return (lensrc + dstsize);
	else
	{
		dst += lendst;
		ft_strlcpy(dst, src, dstsize - lendst);
		return (lendst + lensrc);
	}
}
