/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:39:23 by jijerde           #+#    #+#             */
/*   Updated: 2019/01/14 18:39:54 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*d;
	size_t			i;

	i = 0;
	p = (unsigned char *)s1;
	d = (unsigned char *)s2;
	while (i < n)
	{
		if (p[i] != d[i])
			return (p[i] - d[i]);
		i++;
	}
	return (0);
}
