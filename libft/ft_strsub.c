/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:18:36 by jijerde           #+#    #+#             */
/*   Updated: 2018/12/28 01:47:20 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	char	*n;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (fresh == 0)
		return (NULL);
	n = fresh;
	while (s[i] != s[start])
		i++;
	while (len && s[i])
	{
		*fresh = s[start];
		fresh++;
		start++;
		len--;
		i++;
	}
	*fresh = '\0';
	return (n);
}
