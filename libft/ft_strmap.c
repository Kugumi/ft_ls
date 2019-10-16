/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:12:21 by jijerde           #+#    #+#             */
/*   Updated: 2018/12/28 01:46:33 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*j;
	const char	*n;
	char		*fin;
	int			slen;

	n = s;
	slen = 1;
	if (!n || !f)
		return (NULL);
	while (*n++)
		slen++;
	j = (char *)malloc(sizeof(char) * slen);
	if (j == 0)
		return (NULL);
	fin = j;
	while (*s)
	{
		*j = f(*s);
		s++;
		j++;
	}
	*j = '\0';
	return (fin);
}
