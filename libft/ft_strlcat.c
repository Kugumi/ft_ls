/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:53:41 by jijerde           #+#    #+#             */
/*   Updated: 2019/01/14 19:34:47 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t i;

	i = 0;
	len_dst = 0;
	while ((dst[i]) && i < size)
		i++;
	len_dst = i;
	if (len_dst == size)
		return (len_dst + ft_strlen((char *)src));
	while ((i < size - 1) && (src[i - len_dst]))
	{
		dst[i] = src[i - len_dst];
		i++;
	}
	dst[i] = '\0';
	return (len_dst + ft_strlen((char *)src));
}
