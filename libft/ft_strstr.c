/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:02:47 by jijerde           #+#    #+#             */
/*   Updated: 2019/01/14 19:03:25 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
	while (haystack[h])
		h++;
	while (needle[n])
		n++;
	while (h - i - n >= 0)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
			if (needle[++j] == '\0')
				return ((char *)haystack + i);
		i++;
	}
	return (0);
}
