/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 07:46:16 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/25 23:30:55 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ree_dir	*ft_direrr(char *name, t_signs *fl, t_ree_dir *tr_trees,\
		t_trpointers *tp)
{
	fl->terd = 1;
	tr_trees = ft_errd(tr_trees, strerror(errno), name);
	tr_trees->fofreetd = tr_trees;
	tr_trees->fft = 1;
	if (fl->rec && fl->fir)
		ft_printf("\n%s:\n", name);
	else if (fl->ac > 2)
		ft_printf("\n%s:\n", name);
	fl->fir = 1;
	treeprint(tr_trees, fl, tp);
	return (tr_trees);
}

t_ree_dir	*ft_dirr(char *name, t_signs *fl, t_ree_dir *tr_trees,\
		t_trpointers *tp)
{
	tp->lenc = zerostruct(tp->lenc);
	if ((tp->di = opendir(name)) == NULL)
		return (ft_direrr(name, fl, tr_trees, tp));
	if ((tp->dp = readdir(tp->di)) != NULL)
	{
		if (!fl->tds && fl->a)
			tr_trees = ft_notds(name, fl, tr_trees, tp);
		while ((tp->dp = readdir(tp->di)) != NULL)
		{
			if ((tp->dp->d_name[0] == '.' && !(fl->a) && !(fl->abig)) ||
			(tp->dp->d_name[0] == '.' && tp->dp->d_name[1] == '.' && fl->abig))
				;
			else
			{
				if (!fl->tds)
					tr_trees = ft_notds(name, fl, tr_trees, tp);
				else
					ft_dircycler(tr_trees, name, tp);
			}
		}
		closedir(tp->di);
		(fl->tds == 0) ? tr_trees = ft_diremp(tr_trees) : 0;
	}
	dirsprint(fl, name, tp, tr_trees);
	return (tr_trees);
}
