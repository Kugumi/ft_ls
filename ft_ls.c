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

int	ft_flags(t_flags *fl, char *s)
{
	int i;

	i = 1;
	while(s[i])
	{
		if (s[i] == 't')
			fl->t = 1;
		else if (s[i] == 'l')
			fl->l = 1;
		else if (s[i] == 'r')
			fl->r = 1;
		else if (s[i] == 'R')
			fl->rec = 1;
		else if (s[i] == 'a')
			fl->a = 1;
		else
		{
			printf("ls: illegal option -- %c\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", s[i]);
				exit(-1);
		}
		i++;
	}
	return (0);
}
t_ree_dir	*ft_dir(char *name, t_flags *fl, t_ree_dir	*tr_trees)
{
	DIR 			*di;
	struct dirent 	*dp;
	t_ree_dir				*td_root;
	t_ree_dir				*td;

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
		treeprint(tr_trees, fl);
		write(1, "\n", 1);
		return (tr_trees);
	}
	if ((dp = readdir(di)) != NULL)
	{
		if (!fl->tds && fl->a)
		{
			fl->tds = 1;
			tr_trees = filltd(tr_trees, dp->d_name, name);
			td = tr_trees;
			td_root = td;
			tr_trees->fofreetd = tr_trees;
			tr_trees->fft = 1;
		}
		while ((dp = readdir(di)) != NULL)
		{
			if (dp->d_name[0] == '.' && !(fl->a))
				;
			else
			{
				if (!fl->tds)
				{
					fl->tds = 1;
					tr_trees = filltd(tr_trees, dp->d_name, name);
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
						if (strcmp(td->dname, dp->d_name) >= 0)
						{
							if (td->left == NULL)
							{
								td->left = filltd(td, dp->d_name, name);
								//if (fl->reci)
								/*tr_trees->fofreetdr = td->left;
								tr_trees->fft = 1;*/
								break;
							}
							else
								td = td->left;
						}
						if (strcmp(td->dname, dp->d_name) < 0)
						{
							if (td->right == NULL)
							{
								td->right = filltd(td, dp->d_name, name);
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
		else
			fl->tds = 0;
	}
	if (fl->rec && fl->fir)
		printf("%s:\n", name);
	else if (fl->ac > 2)
		printf("%s:\n", name);
	fl->fir = 1;
	if (!fl->r)
		treeprint(tr_trees, fl);
	else
		treeprintr(tr_trees, fl);
	write(1, "\n", 1);
	return (tr_trees);
}

void	ft_ls(char *name, t_flags *fl, t_trpointers *tp)
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
            tp->dirs = (t_dirs *) malloc(sizeof(t_dirs));
			tp->dirs->name = ft_strdup(name);
			tp->first = tp->dirs;
			tp->dirs->next = NULL;
			tp->firstforfree = tp->dirs;
        }
    	else
        {
			tp->dirs->next = (t_dirs *) malloc(sizeof(t_dirs));
			tp->dirs = tp->dirs->next;
    	    tp->dirs->name = ft_strdup(name);
    	    tp->dirs->next = NULL;
        }
        return ;
    }
    else
        ft_files(tp, name, fl);
}

int	main(int argc, char **argv)
{
	int		i;
	int 	ac;
	t_flags	fl;
	t_trpointers	tp;
//	t_ree_errors	te;
	t_ree_dir		*t;
	t_ree_dir		*temp;

	i = 1;
	ft_fillfl(&fl);
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		if ((ft_flags(&fl, argv[i])) == -1)
			return (0);
		i++;
	}
	fl.ac = argc - (i - 1);
	if (argc - i == 0)
	{
		t = ft_treedirs(".", &fl);
		if (fl.rec && fl.tdr)
		{
			ft_r(t, &fl, &tp);
			freememdir(t, &fl);
		}
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
    	errprint(tp.te);
    if (fl.tfr)
		filesprint(tp.tf);
    if (tp.dirs)
	{
		while (tp.first)
		{
			t = ft_treedirs(tp.first->name, &fl);
			//ft_ls(tp.first->name, &fl, &tp);
			if (fl.rec && fl.tdr)
			{
				//if (!fl.r)
					ft_r(t, &fl, &tp);
					freememdir(t, &fl);
				/*else
					ft_r1(tp.tr_tdroot, &fl, &tp);*/
			}
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
		freememerr(tp.te, &fl);
	if (fl.tfr)
		freememfiles(tp.tf, &fl);
	return (0);
}
