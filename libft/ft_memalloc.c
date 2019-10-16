/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:02:33 by jijerde           #+#    #+#             */
/*   Updated: 2018/12/17 20:36:15 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *f;
	char *fin;

	f = (char *)malloc(size);
	if (f == 0)
		return (NULL);
	fin = f;
	while (size)
	{
		*f = 0;
		f++;
		size--;
	}
	return (fin);
}
