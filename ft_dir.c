/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 00:09:56 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/26 02:38:05 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		dirsprint(t_signs *fl, char *name, t_trpointers *tp, \
		t_ree_dir *tr_trees)
{
	if (fl->rec && fl->fir)
		ft_printf("\n%s:\n", name);
	else if (fl->ac > 2)
	{
		if (tp->i >= 1 && !tp->ifile)
		{
			ft_printf("%s:\n", name);
			tp->i = 0;
		}
		else
			ft_printf("\n%s:\n", name);
	}
	if (fl->tds && fl->l)
		ft_printf("total %lld\n", totaltotal(name, tp, fl));
	fl->fir = 1;
	if (fl->tds)
		treeprint(tr_trees, fl, tp);
	fl->tds = 0;
}

void		ft_dirtdsa(t_ree_dir *tr_trees, t_signs *fl)
{
	fl->tds = 1;
	tr_trees->fofreetd = tr_trees;
	tr_trees->fft = 1;
}

t_ree_dir	*ft_notds(char *name, t_signs *fl, t_ree_dir *tr_trees, \
		t_trpointers *tp)
{
	tr_trees = filltd(tr_trees, tp->dp->d_name, name, tp);
	ft_dirtdsa(tr_trees, fl);
	return (tr_trees);
}

t_ree_dir	*ft_diremp(t_ree_dir *tr_trees)
{
	tr_trees = fillemp(tr_trees);
	tr_trees->fofreetd = tr_trees;
	tr_trees->fft = 1;
	return (tr_trees);
}

t_ree_dir	*ft_dir(char *name, t_signs *fl, t_ree_dir *tr_trees, \
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
					ft_dircycle(tr_trees, tp->dp->d_name, name, tp);
			}
		}
		closedir(tp->di);
		(fl->tds == 0) ? tr_trees = ft_diremp(tr_trees) : 0;
	}
	dirsprint(fl, name, tp, tr_trees);
	return (tr_trees);
}
