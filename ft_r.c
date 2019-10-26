/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:07:46 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/30 21:41:55 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	ft_path(t_ree_dir *td)
{
	char		*tmp;

	tmp = ft_strjoinp(td->path, td->dname);
	free(td->path);
	td->path = tmp;
}

void	ft_rr(t_ree_dir *td, t_signs *fl, t_trpointers *tp)
{
	struct stat	stbuf;
	t_ree_dir	*t;

	t = NULL;
	if (td != NULL)
	{
		ft_rr(td->left, fl, tp);
		if (td->dname != NULL)
		{
			if ((ft_strcmp(td->dname, ".") != 0 &&
			ft_strcmp(td->dname, "..") != 0) && !(td->s))
			{
				ft_path(td);
				if (lstat(td->path, &stbuf) != -1)
				{
					if ((stbuf.st_mode & S_IFMT) == S_IFDIR &&
					(ft_strcmp(td->dname, ".") != 0 &&
					ft_strcmp(td->dname, "..") != 0))
						opas(td, fl, tp, t);
				}
			}
		}
		ft_rr(td->right, fl, tp);
	}
}

void	opas(t_ree_dir *td, t_signs *fl, t_trpointers *tp, t_ree_dir *t)
{
	t = ft_treedirs(td->path, fl, tp);
	ft_rr(t, fl, tp);
	freememdir(t, fl, tp);
}

void	ft_r(t_ree_dir *t, t_signs *fl, t_trpointers *tp)
{
	ft_rr(t, fl, tp);
}
