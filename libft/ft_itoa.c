/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:52:01 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/20 19:47:08 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_razryad(int n)
{
	long int	nb;
	int			r;

	nb = n;
	r = 1;
	if (nb < 0)
	{
		nb *= -1;
		r++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		r++;
	}
	return (r);
}

static char		*ft_str(char *str, int nb)
{
	char		*finish;
	long int	nb2;

	nb2 = nb;
	finish = str;
	if (nb2 < 0)
		nb2 *= -1;
	while (nb2 > 9)
	{
		*str = nb2 % 10 + '0';
		nb2 = nb2 / 10;
		str++;
	}
	*str = nb2 + '0';
	str++;
	if (nb < 0)
		*str++ = '-';
	*str = '\0';
	return (finish);
}

static char		*ft_rev(char *str)
{
	char	*start;
	char	*end;
	char	*finish;
	char	c;

	start = str;
	finish = str;
	while (*str)
		str++;
	str--;
	end = str;
	while (start < end)
	{
		c = *start;
		*start = *end;
		*end = c;
		end--;
		start++;
	}
	return (finish);
}

char			*ft_itoa(int n)
{
	int		razryad;
	char	*str;
	char	*fin;

	razryad = ft_razryad(n);
	if (!(str = (char *)malloc(sizeof(char) * (razryad + 1))))
		return (NULL);
	ft_str(str, n);
	fin = ft_rev(str);
	free(str);
	return (fin);
}
