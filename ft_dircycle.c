/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dircycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 05:40:58 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/26 05:41:09 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_tmpsec(t_trpointers *tp, char *name)
{
	struct stat				stbuf;

	tp->tmp = ft_strjoinp(name, tp->dp->d_name);
	(lstat(tp->tmp, &stbuf) != -1) ? tp->tsec = stbuf.st_ctime : 0;
	free(tp->tmp);
}

int			ft_dircycle(t_ree_dir *td, char *dpname, char *name, \
		t_trpointers *tp)
{
	while (1)
	{
		if (ft_strcmp(td->dname, dpname) >= 0)
		{
			if (td->left == NULL)
			{
				td->left = filltd(td, dpname, name, tp);
				return (0);
			}
			else
				td = td->left;
		}
		if (ft_strcmp(td->dname, dpname) < 0)
		{
			if (td->right == NULL)
			{
				td->right = filltd(td, dpname, name, tp);
				return (0);
			}
			else
				td = td->right;
		}
	}
}

int			ft_dircycler(t_ree_dir *td, char *dpname, char *name, \
		t_trpointers *tp)
{
	while (1)
	{
		if (ft_strcmp(td->dname, tp->dp->d_name) < 0)
		{
			if (td->left == NULL)
			{
				td->left = filltd(td, tp->dp->d_name, name, tp);
				break ;
			}
			else
				td = td->left;
		}
		if (ft_strcmp(td->dname, tp->dp->d_name) >= 0)
		{
			if (td->right == NULL)
			{
				td->right = filltd(td, tp->dp->d_name, name, tp);
				break ;
			}
			else
				td = td->right;
		}
	}
}

int			ft_dircyclet(t_ree_dir *td, char *name, t_trpointers *tp)
{
	while (1)
	{
		ft_tmpsec(tp, name);
		if (td->sec < tp->tsec)
		{
			if (td->left == NULL)
			{
				td->left = filltd(td, tp->dp->d_name, name, tp);
				return (0);
			}
			else
				td = td->left;
		}
		if (td->sec >= tp->tsec)
		{
			if (td->right == NULL)
			{
				td->right = filltd(td, tp->dp->d_name, name, tp);
				return (0);
			}
			else
				td = td->right;
		}
	}
}

int			ft_dircycletr(t_ree_dir *td, char *name, t_trpointers *tp)
{
	while (1)
	{
		ft_tmpsec(tp, name);
		if (td->sec >= tp->tsec)
		{
			if (td->left == NULL)
			{
				td->left = filltd(td, tp->dp->d_name, name, tp);
				return (0);
			}
			else
				td = td->left;
		}
		if (td->sec < tp->tsec)
		{
			if (td->right == NULL)
			{
				td->right = filltd(td, tp->dp->d_name, name, tp);
				return (0);
			}
			else
				td = td->right;
		}
	}
}
