/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:20:50 by jijerde           #+#    #+#             */
/*   Updated: 2018/12/28 01:47:39 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*fresh;
	char	*finish;
	int		len;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	fresh = (char *)malloc(sizeof(char) * len);
	if (fresh == 0)
		return (NULL);
	finish = fresh;
	while (s1[++i])
		fresh[i] = s1[i];
	while (*s2)
	{
		fresh[i] = *s2;
		i++;
		s2++;
	}
	fresh[i] = '\0';
	return (finish);
}
