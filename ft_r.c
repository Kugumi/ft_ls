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

void	ft_rr(t_ree_dir *td, t_flags *fl, t_trpointers *tp)
{
	struct stat	stbuf;
	char *tmp;

	if (td != NULL)
	{
		ft_rr(td->left, fl, tp);
		if (td->dname != NULL)
		{
			if ((strcmp(td->dname, ".") != 0 && strcmp(td->dname, "..") != 0) && !(td->s))
			{
				tmp = ft_strjoinp(td->path, td->dname);
				free(td->path);
				td->path = tmp;
				lstat(td->path, &stbuf);
				/*if (lstat(td->path, &stbuf) == -1)
				{
					//ft_errd(tp->tr_tda.tr_dir.tr_err, td->path, strerror(errno), fl);
					//printf("ft_ls: %s: %s\n", td->path, strerror(errno));
					return;
				}*/
				if ((stbuf.st_mode & S_IFMT) == S_IFDIR && (strcmp(td->dname, ".") != 0 && strcmp(td->dname, "..") != 0))
				{
					fl->reci = 1;
					ft_treedirs(td->path, fl, tp);
				}
			}
		}
		ft_rr(td->right, fl, tp);
	}
}

void	ft_r(t_ree_trdirs *tua, t_flags *fl, t_trpointers *tp)
{
	if (tua != NULL)
	{
		ft_r(tua->left, fl, tp);
		ft_rr(&(tua->tr_dir), fl, tp);
		ft_r(tua->right, fl, tp);
	}
}
