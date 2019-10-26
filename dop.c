/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 09:30:00 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/26 09:30:14 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_filelprint(t_ree_files *tf, t_trpointers *tp)
{
	ft_printf("%s  ", tf->rwx);
	ft_printf("%*d ", tp->lenc.c2, tf->nl);
	ft_printf("%-*s  ", (int)tp->lenc.c3, tf->uid);
	ft_printf("%-*s  ", (int)tp->lenc.c4, tf->gid);
	if (tf->rwx[0] == 'c' || tf->rwx[0] == 'b')
	{
		ft_printf(" %*d, ", tp->lenc.cmajor, tf->major);
		ft_printf("%*d ", tp->lenc.cminor, tf->minor);
	}
	else
	{
		if ((tp->lenc.cmajor > 0 || tp->lenc.cminor > 0) &&
			(tp->lenc.cmajor + tp->lenc.cminor + 2) > tp->lenc.c5)
			ft_printf(" %*lld", (tp->lenc.cmajor + tp->lenc.cminor + 2),
					tf->size);
		else
			ft_printf("%*lld ", (int)tp->lenc.c5, tf->size);
	}
	ft_printf("%s ", tf->time);
	if (tf->rwx[0] == 'l')
		ft_printf("%s -> %s\n", tf->fname, tf->buff);
	else
		ft_printf("%s\n", tf->fname);
}

int		ft_nachalo(t_trpointers *tp, t_signs *fl, int argc, char **argv)
{
	t_ree_dir	*t;
	int			i;

	i = 1;
	ft_fillfl(fl, tp);
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		ft_signs(fl, tp, argv[i]);
		i++;
	}
	fl->ac = argc - (i - 1);
	if (argc - i == 0)
	{
		t = ft_treedirs(".", fl, tp);
		if (fl->rec && fl->tdr)
		{
			ft_r(t, fl, tp);
			freememdir(t, fl, tp);
		}
		else
			freememdir(t, fl, tp);
		exit(0);
	}
	return (i);
}

void	conti(t_trpointers *tp, t_signs *fl, char **argv, int i)
{
	tp->dirs = NULL;
	while (argv[i])
	{
		ft_ls(argv[i], fl, tp);
		i++;
	}
	if (tp->dirs)
	{
		if (!fl->r)
			ft_lstsort(tp->first);
		else
			ft_lstsortr(tp->first);
	}
	if (fl->ter)
		errprint(tp->teroot);
	if (fl->tfr)
		filesprint(tp->tfroot, fl, tp);
}

void	end(t_trpointers *tp, t_ree_dir *t, t_signs *fl)
{
	while (tp->first)
	{
		t = ft_treedirs(tp->first->name, fl, tp);
		if (fl->rec && fl->tdr)
		{
			ft_r(t, fl, tp);
			freememdir(t, fl, tp);
		}
		else
			freememdir(t, fl, tp);
		tp->first = tp->first->next;
		if (!tp->first)
			break ;
		fl->tdr = 0;
		fl->tds = 0;
		fl->fir = 0;
	}
}

void	permit(int mode, char *str)
{
	if (S_ISDIR(mode))
		str[0] = 'd';
	else if (S_ISLNK(mode))
		str[0] = 'l';
	else if (S_ISBLK(mode))
		str[0] = 'b';
	else if (S_ISCHR(mode))
		str[0] = 'c';
	else if (S_ISFIFO(mode))
		str[0] = 'p';
	else if (S_ISSOCK(mode))
		str[0] = 's';
	else
		str[0] = '-';
}
