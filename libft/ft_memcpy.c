/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 01:33:16 by jijerde           #+#    #+#             */
/*   Updated: 2019/01/14 01:34:20 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*j;
	size_t			i;

	if (dst == src)
		return (dst);
	p = (unsigned char *)dst;
	j = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = j[i];
		i++;
	}
	return (dst);
}
