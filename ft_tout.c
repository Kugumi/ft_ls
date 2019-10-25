/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 02:17:05 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/28 01:57:00 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	treeprint(t_ree_dir *td, t_signs *fl, t_trpointers *tp)
{
	if (td != NULL)
	{
		treeprint (td->left, fl, tp);
		if (td->s != NULL)
		{
			printf("ls: %s: %s\n", td->dname, td->s);
		}
		else if (td->dname != NULL && !fl->l)
			printf("%s\n", td->dname);
		else if (td->dname != NULL && fl->l && td->gg)
		{
//			printf("total %lld\n", tp->lenc.total);
			printf("%s  ", td->rwx);
			printf("%*d ",tp->lenc.c2, td->nl);
			printf("%-*s  ", (int)tp->lenc.c3, td->uid);
			printf("%-*s  ", (int)tp->lenc.c4, td->gid);
			if (td->rwx[0] == 'c' || td->rwx[0] == 'b')
			{
				printf(" %*d, ", tp->lenc.cmajor, td->major);
				printf("%*d ", tp->lenc.cminor, td->minor);
			}
			else
			{
				if ((tp->lenc.cmajor > 0 || tp->lenc.cminor > 0) && (tp->lenc.cmajor + tp->lenc.cminor + 2) > tp->lenc.c5)
					printf(" %*lld ", (tp->lenc.cmajor + tp->lenc.cminor + 2), td->size);
				else
					printf("%*lld ", (int)tp->lenc.c5, td->size);
			}
			printf("%s ", td->time);
			if (td->rwx[0] == 'l')
				printf("%s -> %s\n", td->dname, td->buff);
			else
				printf("%s\n", td->dname);
		}
		treeprint(td->right, fl, tp);
	}
}

/*void	findtree(t_ree_trdirs *tua, t_signs *fl, int argc)
{
	if (tua != NULL)
	{
		findtree(tua->left, fl, argc);
		if (fl->rec && fl->fir)
			printf("%s:\n", tua->tdname);
		else if (argc > 2)
            printf("%s:\n", tua->tdname);
		fl->fir = 1;
		treeprint(&(tua->tr_dir), fl, tp);
		write(1, "\n", 1);
		findtree(tua->right, fl, argc);
	}
}*/
