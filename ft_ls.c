/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 04:51:57 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/12 01:45:50 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int	ft_signs(t_signs *fl, t_trpointers	*tp, char *s)
{
	int i;

	i = 1;
	while(s[i])
	{
		if (s[i] == 't')
		{
			fl->t = 1;
			tp->l = 1;
		}
		else if (s[i] == 'l')
		{
			fl->l = 1;
			tp->l = 1;
		}
		else if (s[i] == 'r')
			fl->r = 1;
		else if (s[i] == 'R')
			fl->rec = 1;
		else if (s[i] == 'a')
			fl->a = 1;
		else if (s[i] == 'A')
			fl->abig = 1;
		else
		{
			printf("ls: illegal option -- %c\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", s[i]);
				exit(-1);
		}
		i++;
	}
	return (0);
}
t_ree_dir	*ft_dir(char *name, t_signs *fl, t_ree_dir	*tr_trees, t_trpointers *tp)
{
	DIR 			*di;
	struct dirent 	*dp;
	t_ree_dir				*td_root;
	t_ree_dir				*td;

	tp->lenc = zerostruct(tp->lenc);
	if ((di = opendir(name)) == NULL)
	{
		fl->terd = 1;
		tr_trees = ft_errd(tr_trees, strerror(errno), name, fl);
		tr_trees->fofreetd = tr_trees;
		tr_trees->fft = 1;
		if (fl->rec && fl->fir)
			printf("%s:\n", name);
		else if (fl->ac > 2)
			printf("%s:\n", name);
		fl->fir = 1;
		treeprint(tr_trees, fl, tp);
		write(1, "\n", 1);
		return (tr_trees);
	}
	if ((dp = readdir(di)) != NULL)
	{
		if (!fl->tds && fl->a)
		{
			fl->tds = 1;
			tr_trees = filltd(tr_trees, dp->d_name, name, tp);
			td = tr_trees;
			td_root = td;
			tr_trees->fofreetd = tr_trees;
			tr_trees->fft = 1;
		}
		while ((dp = readdir(di)) != NULL)
		{
			if ((dp->d_name[0] == '.' && !(fl->a) && !(fl->abig)) || (dp->d_name[0] == '.' && dp->d_name[1] == '.' && fl->abig))
				;
			else
			{
				if (!fl->tds)
				{
					fl->tds = 1;
					tr_trees = filltd(tr_trees, dp->d_name, name, tp);
					td = tr_trees;
					td_root = td;
					tr_trees->fofreetd = tr_trees;
					tr_trees->fft = 1;
				}
				else
				{
					td = td_root;
					while (1)
					{
						if (ft_strcmp(td->dname, dp->d_name) >= 0)
						{
							if (td->left == NULL)
							{
								td->left = filltd(td, dp->d_name, name, tp);
								//if (fl->reci)
								/*tr_trees->fofreetdr = td->left;
								tr_trees->fft = 1;*/
								break;
							}
							else
								td = td->left;
						}
						if (ft_strcmp(td->dname, dp->d_name) < 0)
						{
							if (td->right == NULL)
							{
								td->right = filltd(td, dp->d_name, name, tp);
								//if (fl->reci)
								/*tr_trees->fofreetdr = td->right;
								tr_trees->fft = 1;*/
								break;
							}
							else
								td = td->right;
						}
					}
				}
			}
		}
		closedir(di);
		if (fl->tds == 0)
		{
			tr_trees = fillemp(tr_trees);
			tr_trees->fofreetd = tr_trees;
			tr_trees->fft = 1;
		}
	}
	if (fl->rec && fl->fir)
		printf("%s:\n", name);
	else if (fl->ac > 2)
		printf("%s:\n", name);
	if (fl->tds)
		printf("total %lld\n", totaltotal(name, tp, fl));
	fl->fir = 1;
	if (fl->tds)
		treeprint(tr_trees, fl, tp);
	fl->tds = 0;
	write(1, "\n", 1);
	return (tr_trees);
}

void	ft_ls(char *name, t_signs *fl, t_trpointers *tp)
{
    struct stat stbuf;

    if (lstat(name, &stbuf) == -1)
    {
    	fl->terd = 1;
        ft_err(tp, name, strerror(errno), fl);
        return ;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    {
    	if (!tp->dirs)
    	{
            tp->dirs = (t_dirs *)malloc(sizeof(t_dirs));
			tp->dirs->name = ft_strdup(name);
			tp->first = tp->dirs;
			tp->dirs->next = NULL;
			tp->firstforfree = tp->dirs;
        }
    	else
        {
			tp->dirs->next = (t_dirs *)malloc(sizeof(t_dirs));
			tp->dirs = tp->dirs->next;
    	    tp->dirs->name = ft_strdup(name);
    	    tp->dirs->next = NULL;
        }
        return ;
    }
    else
    	if (!fl->r)
        	ft_files(tp, name, fl);
    	else
			ft_filesr(tp, name, fl);
}

int	main(int argc, char **argv)
{
	int		i;
	int 	ac;
	t_signs	fl;
	t_trpointers	tp;
//	t_ree_errors	te;
	t_ree_dir		*t;
	t_ree_dir		*temp;

	i = 1;
	ft_fillfl(&fl, &tp);
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		if (ft_signs(&fl, &tp, argv[i]) == -1)
			return (0);
		i++;
	}
	fl.ac = argc - (i - 1);
	if (argc - i == 0)
	{
		t = ft_treedirs(".", &fl, &tp);
		if (fl.rec && fl.tdr)
		{
			ft_r(t, &fl, &tp);
			freememdir(t, &fl, &tp);
		}
		else
			freememdir(t, &fl, &tp);
		/*if (fl.tdr)
			findtree(tp.tr_tdroot, &fl, fl.ac);
		//ft_trfree(&(tp.tr_tda));
		if (fl.tdr)
		    freemem(tp.tr_tdroot, &fl);*/
		return (0);
	}
	tp.dirs = NULL;
    while (argv[i])
    {
        ft_ls(argv[i], &fl, &tp);
        i++;
    }
    if (tp.dirs)
	{
    	if (!fl.r)
    		ft_lstsort(tp.first);
    	else
			ft_lstsortr(tp.first);
	}
    if (fl.ter)
    	errprint(tp.teroot);
    if (fl.tfr)
		filesprint(tp.tfroot, &fl, &tp);
    if (tp.dirs)
	{
		while (tp.first)
		{
			t = ft_treedirs(tp.first->name, &fl, &tp);
			//ft_ls(tp.first->name, &fl, &tp);
			if (fl.rec && fl.tdr)
			{
				//if (!fl.r)
					ft_r(t, &fl, &tp);
					freememdir(t, &fl, &tp);
				/*else
					ft_r1(tp.tr_tdroot, &fl, &tp);*/
			}
			else
				freememdir(t, &fl, &tp);
			/*if (fl.tdr)
			{
				if (!fl.r)
					findtree(tp.tr_tdroot, &fl, ac);
				else
					findtreer(tp.tr_tdroot, &fl, ac);
			}
			if (fl.tdr)
				freemem(tp.tr_tdroot, &fl);
			//free(tp.tr_tdroot->tr_dir.fofreetdr);
			//free(tp.tr_td->tr_dir.fofreetd);
			//ft_trfree(&(tp.tr_tda));*/
			tp.first = tp.first->next;
			if (!tp.first)
				break;
			fl.tdr = 0;
			fl.tds = 0;
			fl.fir = 0;
			fl.reci = 0;
		}
	}
	if (fl.tdr)
		freedirs(tp.firstforfree);
	if (fl.ter)
		freememerr(tp.teroot, &fl);
	if (fl.tfr)
		freememfiles(tp.tfroot, &fl);
	return (0);
}
