/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:07:15 by jijerde           #+#    #+#             */
/*   Updated: 2019/01/14 21:43:16 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *f;
	char *k;

	if (size + 1 == 0)
		return (NULL);
	f = (char *)malloc(sizeof(char) * (size + 1));
	if (f == 0)
		return (NULL);
	k = f;
	while (size)
	{
		*f = '\0';
		f++;
		size--;
	}
	*f = '\0';
	return (k);
}
