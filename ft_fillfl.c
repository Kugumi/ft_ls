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

void	ft_fillfl(t_signs *fl, t_trpointers *tp)
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
	fl->ac = 0;
	fl->abig = 0;
	tp->t = 0;
	tp->l = 0;
	tp->gg = 0;
}

int		ft_notfr(t_trpointers *tp, char *name, t_signs *fl)
{
	tp->lenc = zerostruct(tp->lenc);
	fl->tfr = 1;
	tp->tfroot = filltf(tp->tfroot, name, fl, tp);
	tp->tf = tp->tfroot;
	return (1);
}

void	tplf(t_ree_files *tf, struct stat stbuf)
{
	tf->rwx = drwx(stbuf.st_mode);
	tf->nl = stbuf.st_nlink;
	tf->uid = ft_strdup(getpwuid(stbuf.st_uid)->pw_name);
	tf->gid = ft_strdup(getgrgid(stbuf.st_gid)->gr_name);
	tf->major = major(stbuf.st_rdev);
	tf->minor = minor(stbuf.st_rdev);
	tf->size = stbuf.st_size;
	tf->buff = NULL;
	if (tf->rwx[0] == 'l')
	{
		tf->buff = ft_strnew(1025);
		readlink(tf->fname, tf->buff, 1024);
		tf->buff[ft_strlen(tf->buff)] = '\0';
	}
}

int 	ft_ls1(char *name, t_signs *fl, t_trpointers *tp)
{
	struct stat stbuf;

	if (lstat(name, &stbuf) == -1)
	{
		fl->terd = 1;
		ft_err(tp, name, strerror(errno), fl);
		return (1);
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
	{
		tp->i++;
		tpdirs(name, tp);
		return (1);
	}
	return (0);
}

void	ft_usage(char i)
{
	ft_printf("ls: illegal option -- %c\n"
		   "usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", i);
}
