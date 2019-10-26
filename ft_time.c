/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 08:01:27 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/25 08:03:08 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ree_dir	*ft_dirt(char *name, t_signs *fl, t_ree_dir *tr_trees, \
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
					ft_dircyclet(tr_trees, name, tp);
			}
		}
		closedir(tp->di);
		(fl->tds == 0) ? tr_trees = ft_diremp(tr_trees) : 0;
	}
	dirsprint(fl, name, tp, tr_trees);
	return (tr_trees);
}

t_ree_dir	*ft_dirrt(char *name, t_signs *fl, t_ree_dir *tr_trees, \
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
					ft_dircycletr(tr_trees, name, tp);
			}
		}
		closedir(tp->di);
		(fl->tds == 0) ? tr_trees = ft_diremp(tr_trees) : 0;
	}
	dirsprint(fl, name, tp, tr_trees);
	return (tr_trees);
}
