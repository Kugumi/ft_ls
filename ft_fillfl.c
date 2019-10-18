/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillfl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 00:53:34 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/27 00:58:39 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fillfl(t_flags *fl)
{
	fl->t = 0;
	fl->r = 0;
	fl->l = 0;
	fl->rec = 0;
	fl->a = 0;
	fl->tdr = 0;
	fl->tds = 0;
	fl->ter = 0;
	fl->tfr = 0;
	fl->terd = 0;
	fl->fir = 0;
	fl->reci = 0;
}

/*void	ft_filldirs(t_dirs	*dirs)
{
	dirs->name = NULL;
	dirs->next = NULL;
}*/
