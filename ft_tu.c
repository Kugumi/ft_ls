/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:42:18 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/26 10:42:25 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ree_dir	*ft_treedirs(char *name, t_signs *fl, t_trpointers *tp)
{
	t_ree_dir		*t;

	t = NULL;
	if (fl->r)
	{
		if (fl->t)
			t = ft_dirrt(name, fl, t, tp);
		else
			t = ft_dirr(name, fl, t, tp);
	}
	else if (fl->t)
	{
		if (fl->r)
			t = ft_dirrt(name, fl, t, tp);
		else
			t = ft_dirt(name, fl, t, tp);
	}
	else
		t = ft_dir(name, fl, t, tp);
	fl->tdr = 1;
	return (t);
}
