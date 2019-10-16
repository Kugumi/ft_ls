/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:01:01 by jijerde           #+#    #+#             */
/*   Updated: 2019/01/14 19:01:16 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	h;
	int	n;

	i = 0;
	j = 0;
	h = 0;
	n = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	h = ft_strlen((char *)haystack);
	n = ft_strlen((char *)needle);
	while ((h - i - n >= 0) && (i < (int)len))
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (i + j < (int)len))
		{
			if (needle[++j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
