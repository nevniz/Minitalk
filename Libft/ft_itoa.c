/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:43:33 by llawrenc          #+#    #+#             */
/*   Updated: 2021/10/20 21:23:17 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len++;
		num = num * (-1);
	}
	while (num / 10 > 0)
	{
		len++;
		num = num / 10;
	}
	return (++len);
}

static void	ft_putnb(long int num, char *str, int *len)
{
	if (num > 9)
	{
		ft_putnb(num / 10, str, len);
		ft_putnb(num % 10, str, len);
	}
	else
		str[(*len)++] = num + '0';
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*str;
	int			len;

	num = n;
	len = count_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len = 0;
	if (num < 0)
	{
		num = num * (-1);
		str[len] = '-';
		len++;
	}
	ft_putnb(num, str, &len);
	return (str);
}	
