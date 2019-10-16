/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:40:32 by jijerde           #+#    #+#             */
/*   Updated: 2019/01/14 18:43:16 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;

	i = 0;
	if (dst == src)
		return (dst);
	sr = (unsigned char *)src;
	ds = (unsigned char *)dst;
	if (sr < ds)
	{
		i = len;
		while (i-- > 0)
			ds[i] = sr[i];
	}
	else if (sr > ds)
	{
		while (i < len)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	return (dst);
}
