/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 04:35:10 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/22 04:35:34 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_params(int size, char **s)
{
	int		i;
	int		ii;
	int		iii;
	char	*temp;

	i = 0;
	while (++i < size)
	{
		ii = 0;
		while (++ii < size - 1)
		{
			iii = 0;
			while (s[ii][iii] == s[ii + 1][iii] && s[ii][iii]
					&& s[ii + 1][iii])
			{
				iii++;
			}
			if (s[ii][iii] > s[ii + 1][iii])
			{
				temp = s[ii + 1];
				s[ii + 1] = s[ii];
				s[ii] = temp;
			}
		}
	}
}
