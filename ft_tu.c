/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedirs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 07:38:54 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/27 06:17:24 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ree_dir *ft_treedirs(char *name, t_signs *fl, t_trpointers *tp)
{
	t_ree_dir		*t;
	/*if (!fl->tdr)
	{*/
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
	//tm = filltu(tp->tr_td, name, fl);
		/*if (tp->tr_tda.tr_dir.dname == 0)
		{
			free(tp->tr_tda.tdname);
			free(&(tp->tr_tda));
			return ;
		}*/
		//tp->tr_td = &(tp->tr_tda);
		//t = &(tm->tr_dir);
		//tp->tr_temp = &(tp->tr_td->tr_dir);
		//tp->tr_tdroot = tp->tr_td;
		fl->tdr = 1;
		return (t);
	//}
	/*tp->tr_td = tp->tr_tdroot;
	while(1)
	{
		if (strcmp(tp->tr_td->tdname,name) >= 0)
		{
			if (tp->tr_td->left ==  NULL)
			{
				tp->tr_td->left = filltu(tp->tr_td, name, fl);
				tp->tr_temp = &(tp->tr_td->left->tr_dir);
				*//*if (tp->tr_td->left->tr_dir.dname == 0)
				{
					free(tp->tr_td->left->tdname);
					free(tp->tr_td->left);
					tp->tr_td->left = NULL;
					return ;
				}*//*
				break ;
			}
			else
				tp->tr_td = tp->tr_td->left;
		}
		if (strcmp(tp->tr_td->tdname, name) < 0)
		{
			if (tp->tr_td->right == NULL)
			{
				tp->tr_td->right = filltu(tp->tr_td, name, fl);
				tp->tr_temp = &(tp->tr_td->right->tr_dir);
				*//*if (tp->tr_td->right->tr_dir.dname == 0)
				{

					return ;
				}*//*
				break ;
			}
			else
				tp->tr_td = tp->tr_td->right;
		}
	}*/
}
