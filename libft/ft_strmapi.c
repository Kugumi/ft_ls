/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:14:40 by jijerde           #+#    #+#             */
/*   Updated: 2018/12/28 01:46:57 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*j;
	char			*fin;
	int				slen;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	slen = ft_strlen(s) + 1;
	j = (char *)malloc(sizeof(char) * slen);
	if (j == 0)
		return (NULL);
	fin = j;
	while (*s)
	{
		*j = f(i, *s);
		i++;
		s++;
		j++;
	}
	*j = '\0';
	return (fin);
}
